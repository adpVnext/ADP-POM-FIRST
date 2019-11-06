//
//  CDVBarcodeScanner.h
//
//
//  Created by vnext on 22/01/2015.
//
//

#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>

/*
#import <POMFramework/CaptureBarcodesViewController.h>
#import <POMFramework/FlightInformation.h>
*/

#import <POMFramework/CaptureBarcodesViewController.h>
//#import "CaptureBarcodesViewController.h"
#import <POMFramework/FlightInformation.h>


@interface CDVBarcodeScanner : CDVPlugin{

}

@property (nonatomic, copy) NSString* callbackId;

- (void)scan:(CDVInvokedUrlCommand*)command;

- (void)returnSuccess:(NSString*)scannedText format:(NSString*)format flightInformation:(NSDictionary*)flightInformation cancelled:(BOOL)cancelled;
- (void)returnError:(NSString*)message;

@end
