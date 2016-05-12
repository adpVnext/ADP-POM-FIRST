//
//  WSPomHelper.h
//  MesDocuments
//
//  Created by vnext on 05/01/15.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WSPomHelper : NSObject
+(NSString *)buildMessage:(NSString *)action;
+(NSMutableURLRequest *)buildRequest:(NSString *)action params:(NSString *)params;
+(NSMutableURLRequest *)buildDownloadRequest:(NSString *)urlToDownload;
+(NSURL *)LocalPathFromUrl:(NSURL *)url;
+(NSData *)ExtractFileFromResponseData:(NSData *)data;
@end
