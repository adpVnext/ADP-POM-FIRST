//
//  ResourceMatcher.h
//  POMFramework
//
//  Created by vnext on 20/04/15.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString * const Star = @"*";

@interface ResourceMatcher : NSObject
+(NSArray *)GetMatchingResources:(NSArray *)allResources;
@end
