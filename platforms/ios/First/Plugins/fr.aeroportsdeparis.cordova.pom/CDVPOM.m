//
//  CDVPOM.m
//
//  Modified by Essam Dahab on 15/06/2015.
//
// v1.6.4

#import "CDVPOM.h"

// POMFramework

#import "NSDictionaryExtension.h"
#import "JSONHelper.h"
#import "ScanResult.h"
#import "FlightInformation.h"
#import "NSObject+ObjectMap.h"
#import "POMApplication.h"
#import "POMFramework.h"

@implementation CDVPOM

@synthesize scanCallbackId = _scanCallbackId;

#pragma POM Menu

-(void)InitMenu:(CDVInvokedUrlCommand*)command{

    float pomMenuWidth = kPomMenuWidth;
    float pomMenuHeight = kPomMenuHeight;
    float margin = kPomMenuMarginTop;
    
    [POMMenuV2 addMenu:self.viewController.view width:pomMenuWidth height:pomMenuHeight margin:margin];
    
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc addObserver:self selector:@selector(onLevel1SecurityInfoChange:) name:OnLevel1SecurityInfoChange object:nil];
    [nc addObserver:self selector:@selector(onLevel2SecurityInfoChange:) name:OnLevel2SecurityInfoChange object:nil];
    [nc addObserver:self selector:@selector(OnLevel2PreSignOut:) name:OnLevel2PreSignOut object:nil];
    [nc addObserver:self selector:@selector(onMessageRaised:) name:POMMessageRaised object:nil];
}

- (void)InitVPNManager:(CDVInvokedUrlCommand*)command
{
    VPNHelper *vpnManager = [VPNHelper sharedManager];
    [vpnManager InitVPNTimer];
}

#pragma API POM notifications

-(void) onLevel1SecurityInfoChange:(NSNotification *)notice
{
    DeviceAuthInfo *device = notice.object;
    [self.commandDelegate evalJs:[NSString stringWithFormat:@"javascript:cordova.fireDocumentEvent('%@', %@)", @"onLevel1SecurityInfoChanged", [device JSONString]]];
}

-(void) onLevel2SecurityInfoChange:(NSNotification *)notice
{
    UserAuthInfo *user = notice.object;
    [self.commandDelegate evalJs:[NSString stringWithFormat:@"javascript:cordova.fireDocumentEvent('%@', %@)", @"onLevel2SecurityInfoChanged", [user JSONString]]];
}

-(void) OnLevel2PreSignOut:(NSNotification *)notice
{
    [self.commandDelegate evalJs:[NSString stringWithFormat:@"javascript:cordova.fireDocumentEvent('%@', %@)", @"onLevel2PreSignOut", @"{}"]];
}

-(void) onMessageRaised:(NSNotification *)notice
{
    [self.commandDelegate evalJs:[NSString stringWithFormat:@"javascript:cordova.fireDocumentEvent('%@', %@)", @"onMessageRaised", [notice.object JSONString]]];
}

#pragma API POM

- (void)GetFrameworkVersion:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDouble:POMFrameworkVersionNumber];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)CallApplication:(CDVInvokedUrlCommand*)command{
    CDVPluginResult* result;
    NSString *url = [command.arguments objectAtIndex:0];
    if (!url || [url isEqual:@""])
    {
        result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                   messageAsString:@"Invalid argument : Url is null or empty"
                  ];
    }
    else
    {
        [[POMAPI sharedInstance] CallApplication:url];
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Application launched"];
    }
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)Level1SecurityInfo:(CDVInvokedUrlCommand*)command{
    DeviceAuthInfo *device = [[POMAPI sharedInstance] Level1SecurityInfo];
    CDVPluginResult* result;
    if (!device)
    {
        result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                   messageAsString:@"No authentication for level 1"
                  ];
    }
    else
    {
        NSError *error;
        NSDictionary *dictionary = [NSJSONSerialization JSONObjectWithData:[device JSONData] options:kNilOptions error:&error];
        if (error)
        {
            result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                       messageAsString:[NSString stringWithFormat:@"Serialization Level 1 : Code erreur: %ld - %@ %@", (long)error.code, error.localizedDescription, [error.userInfo objectForKey:NSURLErrorFailingURLStringErrorKey]]
                      ];
        }
        else
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dictionary];
    }
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)Level2SecurityInfo:(CDVInvokedUrlCommand*)command{
    UserAuthInfo *user =  [[POMAPI sharedInstance] Level2SecurityInfo];
    CDVPluginResult* result;
    if (!user)
    {
        result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                   messageAsString:@"No authentication for level 2"
                  ];
    }
    else
    {
        NSError *error;
        NSDictionary *dictionary = [NSJSONSerialization JSONObjectWithData:[user JSONData] options:kNilOptions error:&error];
        if (error)
        {
            result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                       messageAsString:[NSString stringWithFormat:@"Serialization Level 2 : Code erreur: %ld - %@ %@", (long)error.code, error.localizedDescription, [error.userInfo objectForKey:NSURLErrorFailingURLStringErrorKey]]
                      ];
        }
        else
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dictionary];
    }
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

-(void)RequestLevel2SignIn:(CDVInvokedUrlCommand*)command{
    [[POMAPI sharedInstance] RequestLevel2SignIn];
}

-(void)DisplayMenu:(CDVInvokedUrlCommand*)command{
    BOOL display = [[command.arguments objectAtIndex:0] boolValue];
    self.DisplayStandardMenu = display;
}

-(void)RequestLevel2SignOut:(CDVInvokedUrlCommand*)command{
    [[POMAPI sharedInstance] RequestLevel2SignOut];
}

-(void)ForceRefreshSecurity:(CDVInvokedUrlCommand*)command{
    [[POMAPI sharedInstance] ForceRefreshSecurity];
}

- (void)GetRawClaims:(CDVInvokedUrlCommand*)command{
    TokenContainer *tokens = [[POMAPI sharedInstance] GetRawClaims];
    NSError *error;
    CDVPluginResult* result;
    NSDictionary *dictionary = [NSJSONSerialization JSONObjectWithData:[tokens JSONData] options:kNilOptions error:&error];
    if (error)
    {
        result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                   messageAsString:[NSString stringWithFormat:@"Serialization Claims : Code erreur: %ld - %@ %@", (long)error.code, error.localizedDescription, [error.userInfo objectForKey:NSURLErrorFailingURLStringErrorKey]]
                  ];
    }
    else
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dictionary];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)GetApplicationList:(CDVInvokedUrlCommand*)command{
    POMAPI *service = [POMAPI sharedInstance];
    NSArray *apps = [service GetApplicationList];
    
    NSError *error;
    CDVPluginResult* result;
    
    NSMutableArray *array = [[NSMutableArray alloc] init];
    for (POMApplication *app in apps) {
        [array addObject:[NSJSONSerialization JSONObjectWithData:[app JSONData] options:kNilOptions error:&error]];
    }
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:array];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)GetUserThumbnailURL:(CDVInvokedUrlCommand*)command{
    NSString *url = [[POMAPI sharedInstance] GetUserThumbnailURL];
    CDVPluginResult* result;
    if (!url)
    {
        result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                   messageAsString:[NSString stringWithFormat:@"No user thumbnail"]
                  ];
    }
    else
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:url];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)GetUserThumbnailPicture:(CDVInvokedUrlCommand*)command{
    NSData *picture = [[POMAPI sharedInstance] GetUserThumbnailPicture];
    
    CDVPluginResult* result;
    if (!picture)
    {
        result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                   messageAsString:[NSString stringWithFormat:@"No user thumbnail"]
                  ];
    }
    else
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArrayBuffer:picture];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)IsTokenBlacklisted:(CDVInvokedUrlCommand*)command
{
    NSString* token = [command.arguments objectAtIndex:0];
    BOOL isBlacklisted = [[POMAPI sharedInstance] IsTokenBlackListed:token];
    
    CDVPluginResult* result;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool:isBlacklisted];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (BOOL)DisplayStandardMenu {
    return [[POMService sharedManager] DisplayStandardMenu];
}
- (void)setDisplayStandardMenu:(BOOL)newValue {
    POMService *service = [POMService sharedManager];
    service.DisplayStandardMenu = newValue;
}

#pragma API Document

- (void)DownloadFile:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* result;
    NSString *url = [command.arguments objectAtIndex:0];
    if (!url || [url isEqual:@""])
    {
        result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                   messageAsString:@"Invalid argument : Url is null or empty"
                  ];
    }
    else
    {
        DocAPI *service = [DocAPI sharedInstance];
        NSData *fileData = [service DownloadFile:url];
        
        if (!fileData)
        {
            result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR
                                       messageAsString:[NSString stringWithFormat:@"Download failed"]
                      ];
        }
        else
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArrayBuffer:fileData];
    }
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}
-(void)ViewFile:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* result;
    NSString *url = [command.arguments objectAtIndex:0];
    if (!url || [url isEqual:@""])
    {
        result = [CDVPluginResult
                  resultWithStatus: CDVCommandStatus_ERROR
                  messageAsString:@"Invalid argument : Url is null or empty"
                  ];
    }
    else
    {
        [[DocAPI sharedInstance] ViewFile:url inVC:self.viewController];
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"ViewFile launched"];
    }
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}
- (void)GetLibraryList:(CDVInvokedUrlCommand*)command
{
    NSArray *libraries = [[DocAPI sharedInstance] GetLibraryList];
    NSError *error;
    CDVPluginResult* result;
    NSMutableArray *array = [[NSMutableArray alloc] init];
    for (POMApplication *lib in libraries) {
        [array addObject:[NSJSONSerialization JSONObjectWithData:[lib JSONData] options:kNilOptions error:&error]];
    }
    
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:array];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

#pragma API Scan

-(void)LaunchScan:(CDVInvokedUrlCommand*)command
{
    self.scanCallbackId = command.callbackId;
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc addObserver:self selector:@selector(onBarcodeScanned:) name:OnBarcodeScanned object:nil];
    [nc addObserver:self selector:@selector(onBarcodeScanCancelled:) name:OnBarcodeScanCancelled object:nil];
    
    [[ScanAPI sharedInstance] LaunchScan:self.viewController];
}

-(void)LaunchTicketScan:(CDVInvokedUrlCommand*)command
{
    self.scanCallbackId = command.callbackId;
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc addObserver:self selector:@selector(onBarcodeScanned:) name:OnBarcodeScanned object:nil];
    [nc addObserver:self selector:@selector(onBarcodeTicketScanned:) name:OnBarcodeTicketScanned object:nil];
    [nc addObserver:self selector:@selector(onBarcodeScanCancelled:) name:OnBarcodeScanCancelled object:nil];
    
    [[ScanAPI sharedInstance] LaunchTicketScan:self.viewController];
}

#pragma API Scan notifications

-(void) onBarcodeScanned:(NSNotification *)notice
{
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc removeObserver:self name:OnBarcodeScanned object:nil];
    [nc removeObserver:self name:OnBarcodeTicketScanned object:nil];
    [nc removeObserver:self name:OnBarcodeScanCancelled object:nil];
    
    ScanResult *result = notice.object;
    [self returnScanSuccess:result.Value format:result.Format flightInformation:[[NSDictionary alloc]init] cancelled:NO];
}

-(void) onBarcodeTicketScanned:(NSNotification *)notice
{
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc removeObserver:self name:OnBarcodeScanned object:nil];
    [nc removeObserver:self name:OnBarcodeTicketScanned object:nil];
    [nc removeObserver:self name:OnBarcodeScanCancelled object:nil];
    
    ScanResult *result = notice.object;
    [self returnScanSuccess:@"" format:result.Format flightInformation:[result.Value objectToDictionary] cancelled:NO];
}

-(void) onBarcodeScanCancelled:(NSNotification *)notice
{
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc removeObserver:self name:OnBarcodeScanned object:nil];
    [nc removeObserver:self name:OnBarcodeTicketScanned object:nil];
    [nc removeObserver:self name:OnBarcodeScanCancelled object:nil];
    [self returnScanSuccess:@"" format:@"" flightInformation:[[NSDictionary alloc]init] cancelled:YES];
}


- (void)returnScanSuccess:(NSString*)scannedText format:(NSString*)format flightInformation:(NSDictionary *)flightInformation cancelled:(BOOL)cancelled{
    
    
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
    
    [self.commandDelegate sendPluginResult:result callbackId:self.scanCallbackId];
}


@end
