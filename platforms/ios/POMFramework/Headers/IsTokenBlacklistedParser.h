//
//  IsTokenBlacklistedParser.h
//  POMFramework
//
//  Created by Paul-Emile Le Reun on 16/03/2016.
//  Copyright (c) 2016 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IsTokenBlacklistedParser;

@interface IsTokenBlacklistedParser : NSObject<NSXMLParserDelegate>

@property (nonatomic, assign) BOOL isBlacklisted;
@property (nonatomic, retain) NSMutableString *curElem;

@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, retain) NSString *errorType;

- (IsTokenBlacklistedParser*) initXMLParser;

@end