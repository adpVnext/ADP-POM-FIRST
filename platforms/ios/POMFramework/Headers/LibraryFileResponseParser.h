//
//  LibraryFileResponseParser.h
//  MesDocuments
//
//  Created by Essam Dahab on 19/01/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LibraryFileResponseParser;

@interface LibraryFileResponseParser : NSObject<NSXMLParserDelegate>

@property (nonatomic, retain) NSData *file;
@property (nonatomic, retain) NSMutableString *curElem;

@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, retain) NSString *errorType;

- (LibraryFileResponseParser*) initXMLParser;
@end
