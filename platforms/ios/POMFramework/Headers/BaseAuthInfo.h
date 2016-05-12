//
//  BaseAuthInfo.h
//  MesDocuments
//
//  Created by vnext on 27/11/14.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BaseAuthInfo : NSObject
@property NSArray* Permissions;
@property NSDate* ExpirationDate;
@end
