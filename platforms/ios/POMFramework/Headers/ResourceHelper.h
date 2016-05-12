//
//  ResourceHelper.h
//  POMFramework
//
//  Created by Essam Dahab on 19/02/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ResourceHelper : NSObject

+(NSString *) getConfigurationValue:(NSString *)key;
@end
