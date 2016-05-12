//
//  ClaimsParser.h
//  MesDocuments
//
//  Created by vnext on 02/12/14.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ClaimModel.h"

@class ClaimModel, AppDelegate;

@interface ClaimsParser : NSObject<NSXMLParserDelegate>
{
}

@property (nonatomic, retain) ClaimModel *claim;
@property (nonatomic, retain) NSMutableArray *items;
@property (nonatomic, retain) NSMutableString *curElem;
@property (nonatomic, retain) NSMutableString *saml;

@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, retain) NSString *errorType;

- (ClaimsParser*) initXMLParser;
@end

