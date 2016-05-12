//
//  GEDResultsParser.h
//  MesDocuments
//
//  Created by vnext on 05/01/15.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LibraryListResponseParser;

@interface LibraryListResponseParser : NSObject<NSXMLParserDelegate>

@property (nonatomic, retain) NSMutableArray *items;
@property (nonatomic, retain) NSMutableString *curElem;

@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, retain) NSString *errorType;

- (LibraryListResponseParser*) initXMLParser;
@end
