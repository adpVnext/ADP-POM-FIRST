//
//  EnrollDeviceResponseParser.h
//  POMFramework
//
//  Created by Essam Dahab on 05/05/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DeviceInfo.h"

@interface GetDeviceInfoParser : NSObject<NSXMLParserDelegate>

@property (nonatomic, retain) DeviceInfo *deviceInfo;
@property (nonatomic, retain) NSMutableString *curElem;

@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, retain) NSString *errorType;

- (GetDeviceInfoParser*) initXMLParser;
@end
