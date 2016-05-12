//
//  OUMetierListParser.h
//  POMFramework
//
//  Created by Essam Dahab on 04/05/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OUMetierListParser;

@interface OUMetierListParser : NSObject<NSXMLParserDelegate>

@property (nonatomic, retain) NSMutableArray *uos;
@property (nonatomic, retain) NSMutableArray *metiers;
@property (nonatomic, retain) NSMutableString *curElem;

@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, retain) NSString *errorType;

- (OUMetierListParser*) initXMLParser;

@end


