//
//  LibraryFileResponseDelegate.h
//  MesDocuments
//
//  Created by Essam Dahab on 19/01/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LibraryFileResponseDelegate : NSObject<NSURLSessionDataDelegate, NSURLSessionDelegate, NSURLSessionTaskDelegate>

@property (nonatomic, retain) NSMutableDictionary *dataDictionnary;
@property (nonatomic) float downloadSize;

@end

static NSString * const DocumentDownloadStarted = @"DocumentDownloadStarted";
static NSString * const DocumentDownloadFailed = @"DocumentDownloadFailed";
static NSString * const DocumentDownloadCompleted = @"DocumentDownloadCompleted";