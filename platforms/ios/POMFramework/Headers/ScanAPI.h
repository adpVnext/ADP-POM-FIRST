//
//  ScanAPI.h
//  POMFramework
//
//  Created by Essam Dahab on 12/03/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ScanAPI : NSObject

-(void)LaunchScan:(UIViewController *)viewController;
-(void)LaunchTicketScan:(UIViewController *)viewController;

+ (id)sharedInstance;
@end
