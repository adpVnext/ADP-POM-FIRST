//
//  ApplicationListResponseParser.h
//  MesDocuments
//
//  Created by Essam Dahab on 12/01/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ApplicationListResponseParser;

@interface ApplicationListResponseParser : NSObject<NSXMLParserDelegate>

@property (nonatomic, retain) NSMutableArray *items;
@property (nonatomic, retain) NSMutableString *curElem;

@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, retain) NSString *errorType;


- (ApplicationListResponseParser*) initXMLParser;
@end
