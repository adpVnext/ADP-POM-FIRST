//
//  VPNHelper.h
//  POMFramework
//
//  Created by Essam Dahab on 11/06/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VPNHelper : NSObject

-(void)InitVPNTimer;
- (void)CallF5App;
+ (id)sharedManager;

@property(nonatomic) BOOL IsLaunchingF5;

@end
