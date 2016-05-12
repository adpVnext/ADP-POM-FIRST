//
//  ScanService.h
//  POMFramework
//
//  Created by Essam Dahab on 02/03/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CaptureBarcodesViewController.h"
#import "CaptureBarcodeResultDelegate.h"
#import "CaptureBarcodeTicketDelegate.h"

@interface ScanService : NSObject

-(void)LaunchScan:(UIViewController *)viewController;
-(void)LaunchTicketScan:(UIViewController *)viewController;

+ (id)sharedManager;

@property UIViewController *hostViewController;

@property CaptureBarcodeResultDelegate *resultDelegate;
@property CaptureBarcodeTicketDelegate *ticketResultDelegate;
@end
static NSString * const OnBarcodeScanned = @"OnBarcodeScanned";
static NSString * const OnBarcodeTicketScanned = @"OnBarcodeTicketScanned";
static NSString * const OnBarcodeScanCancelled = @"OnBarcodeScanCancelled";