//
//  CDVBarcodeScanner.mm
//
//
//  Created by vnext on 22/01/2015.
//
//

#import "CDVBarcodeScanner.h"

#import <POMFramework/NSStringExtension.h>
#import <POMFramework/NSDictionaryExtension.h>
#import <POMFramework/ScanService.h>
#import <POMFramework/ScanResult.h>

// <POMFramework>
//#import "NSStringExtension.h"
//#import "NSDictionaryExtension.h"
//#import "ScanService.h"
//#import "ScanResult.h"

@implementation CDVBarcodeScanner

@synthesize callbackId = _callbackId;

- (void)scan:(CDVInvokedUrlCommand*)command{
    
    self.callbackId = command.callbackId;
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc addObserver:self selector:@selector(onBarcodeScanned:) name:OnBarcodeScanned object:nil];
    [nc addObserver:self selector:@selector(onBarcodeTicketScanned:) name:OnBarcodeTicketScanned object:nil];
    [nc addObserver:self selector:@selector(onBarcodeScanCancelled:) name:OnBarcodeScanCancelled object:nil];

    [[ScanService sharedManager] LaunchTicketScan:self.viewController];
}

-(void) onBarcodeScanned:(NSNotification *)notice
{
    ScanResult *result = notice.object;
    [self returnSuccess:result.Value format:result.Format flightInformation:[[NSDictionary alloc]init] cancelled:NO];
}

-(void) onBarcodeTicketScanned:(NSNotification *)notice
{
    ScanResult *result = notice.object;
    
    FlightInformation *flightInfo = result.Value;
    [self returnSuccess:@"" format:result.Format flightInformation:[flightInfo objectToDictionary] cancelled:NO];
}

-(void) onBarcodeScanCancelled:(NSNotification *)notice
{
    [self returnSuccess:@"" format:@"" flightInformation:[[NSDictionary alloc]init] cancelled:YES];
}


- (void)returnSuccess:(NSString*)scannedText format:(NSString*)format flightInformation:(NSDictionary *)flightInformation cancelled:(BOOL)cancelled{
    

    NSNumber* cancelledNumber = [NSNumber numberWithInt:(cancelled?1:0)];
    
    NSMutableDictionary* resultDict = [[NSMutableDictionary alloc] init];
    [resultDict setObject:scannedText     forKey:@"RawData"];
    [resultDict setObject:flightInformation forKey:@"FlightInformation"];
    [resultDict setObject:format          forKey:@"Format"];
    [resultDict setObject:cancelledNumber forKey:@"Cancelled"];
    
    CDVPluginResult* result = [CDVPluginResult
                               resultWithStatus: CDVCommandStatus_OK
                               messageAsDictionary: resultDict
                               ];
    
    [self.commandDelegate sendPluginResult:result callbackId:self.callbackId];
}

- (void)returnError:(NSString*)message{
    
    CDVPluginResult* result = [CDVPluginResult
                               resultWithStatus: CDVCommandStatus_ERROR
                               messageAsString: message
                               ];
    
    [self.commandDelegate sendPluginResult:result callbackId:self.callbackId];
}

- (BOOL)captureController:(CaptureBarcodesViewController*)controller shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation{
     return [self.viewController shouldAutorotateToInterfaceOrientation: interfaceOrientation];
}




@end
