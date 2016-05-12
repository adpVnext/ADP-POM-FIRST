//
//  StorageHelper.h
//  MesDocuments
//
//  Created by vnext on 30/12/14.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface StorageHelper : NSObject

+ (void)PreventBackup;
+ (void)SaveToLocal:(NSString *)key results:(id)results;
+ (id)GetFromLocal:(NSString *)key;
+ (id)GetDataFromLocal:(NSString *)key;
+ (void)SaveDataToLocal:(NSString *)key results:(id)results;
+ (void)SaveClaimsLevel1:(NSArray *)results;
+ (NSArray *)GetLocalClaimsLevel1;
+ (void)SaveClaimsLevel2:(NSArray *)results;
+ (NSArray *)GetLocalClaimsLevel2;
+ (void)SaveToBoolLocal:(NSString *)key results:(BOOL)results;
+ (BOOL)GetBoolFromLocal:(NSString *)key;

@end

static NSString * const LocalSamlLevel1Key = @"saml1";
static NSString * const LocalSamlLevel2Key = @"saml2";
static NSString * const LocalClaimsLevel1Key = @"claims1";
static NSString * const LocalClaimsLevel2Key = @"claims2";
static NSString * const LocalClaimCreationLevel1 = @"level1creation";
static NSString * const LocalClaimCreationLevel2 = @"level2creation";
static NSString * const LocalNotifiedExpirationLevel1 = @"notifiedLevel1";
static NSString * const LocalNotifiedExpirationLevel2 = @"notifiedLevel2";
static NSString * const LocalApplicationListKey = @"applicationlist";
static NSString * const LocalLevel1ErrorKey = @"errorLevel1";