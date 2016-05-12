//
//  ErrorHelper.h
//  POMFramework
//
//  Created by Essam Dahab on 17/03/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "POMMessage.h"

@interface ErrorHelper : NSObject

+(void)RaiseError:(NSString *)message;
+(void)RaiseWarning:(NSString *)message;
+(void)RaiseInfo:(NSString *)message;

@end

static NSString * const POMMessageRaised = @"POMMessageRaised";
typedef NS_ENUM(NSInteger, MessageType) { POMError, POMWarning, POMInfo };