//
//  NSDateHelper.h
//  MesDocuments
//
//  Created by Essam Dahab on 12/01/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDateHelper : NSObject
+ (NSDate *)dateFromUTCString:(NSString *)str;
+ (NSDate *)GetLocalizedDate:(NSDate *)date;
@end
