//
//  ViewFileConnectionDelegate.h
//  POMFramework
//
//  Created by Essam Dahab on 23/02/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "QuickLook/QuickLook.h"

@interface ViewFileConnectionDelegate : NSObject<NSURLConnectionDelegate, QLPreviewControllerDataSource,QLPreviewControllerDelegate, UIAlertViewDelegate>
@property UIAlertView *downloadAlert;
@property NSString *filename;
@property UIViewController *viewController;
-(void)InitViewFile:(NSString *)url inVC:(UIViewController *)viewController;
@end
