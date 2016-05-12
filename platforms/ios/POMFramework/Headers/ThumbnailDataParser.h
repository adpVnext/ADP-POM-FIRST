//
//  ThumbnailDataParser.h
//  MesDocuments
//
//  Created by Essam Dahab on 15/01/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ThumbnailDataParser;

@interface ThumbnailDataParser : NSObject<NSXMLParserDelegate>

@property (nonatomic, retain) NSData *picture;
@property (nonatomic, retain) NSMutableString *curElem;

@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, retain) NSString *errorType;

- (ThumbnailDataParser*) initXMLParser;
@end
