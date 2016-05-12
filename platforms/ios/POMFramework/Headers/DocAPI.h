//
//  DocAPI.h
//  POMFramework
//
//  Created by Essam Dahab on 12/03/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AuthService.h"
#import "POMService.h"
#import "GEDLibrary.h"
#import "GEDDocument.h"

@interface DocAPI : NSObject

- (NSData *)DownloadFile:(NSString *)urlToDownload;
-(void)ViewFile:(NSString *)url inVC:(UIViewController *)viewController;
-(NSArray *)GetLibraryList;

+ (id)sharedInstance;
@end
