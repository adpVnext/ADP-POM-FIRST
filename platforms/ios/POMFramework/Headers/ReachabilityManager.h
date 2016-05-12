//
//  ReachabilityManager.h
//  MesDocuments
//
//  Created by Essam Dahab on 27/01/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Reachability.h"

@class Reachability;

@interface ReachabilityManager : NSObject

@property (strong, nonatomic) Reachability *reachability;
@property (strong, nonatomic) Reachability *pomReachability;
@property (strong, nonatomic) Reachability *stsReachability;

#pragma mark -
#pragma mark Shared Manager
+ (ReachabilityManager *)sharedManager;

#pragma mark -
#pragma mark Class Methods
+ (BOOL)isReachable;
+ (BOOL)isPomReachable;
+ (BOOL)isStsReachable;
+ (BOOL)isUnreachable;
+ (BOOL)isReachableViaWWAN;
+ (BOOL)isReachableViaWiFi;

@end
