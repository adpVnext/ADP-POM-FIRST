//
//  ThumbnailURLParser.h
//  POMFramework
//
//  Created by Essam Dahab on 23/02/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ThumbnailURLParser;

@interface ThumbnailURLParser : NSObject<NSXMLParserDelegate>

@property (nonatomic, retain) NSString *pictureURL;
@property (nonatomic, retain) NSMutableString *curElem;

@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, retain) NSString *errorType;

- (ThumbnailURLParser*) initXMLParser;
@end
