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

/**
 *  Prépare la vue du document (Download si nécessaire)
 *
 *  @param url            url du fichier à visualiser
 *  @param viewController view controller où visualiser le document
 */
-(void)InitViewFile:(NSString *)url inVC:(UIViewController *)viewController;

@end
