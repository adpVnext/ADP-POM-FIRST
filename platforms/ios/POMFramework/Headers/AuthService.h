//
//  AuthService.h
//  MesDocuments
//
//  Created by vnext on 27/11/14.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DeviceAuthInfo.h"
#import "UserAuthInfo.h"
#import "StorageHelper.h"
#import "Level1ConnectionDelegate.h"
#import "Level2ConnectionDelegate.h"
#import "TokenContainer.h"
#import "DeviceInfo.h"
#import "UoMetierContainer.h"
#import "EncodeHelper.h"
#import "IsTokenBlacklistedParser.h"

#define ISO_TIMEZONE_UTC_FORMAT @"Z"
#define ISO_TIMEZONE_OFFSET_FORMAT @"%+02d%02d"

@class Level1ConnectionDelegate;
@class Level2ConnectionDelegate;

@interface AuthService : NSObject

+ (id)sharedManager;

- (void)InitSyncTimer;



- (DeviceAuthInfo*)Level1SecurityInfo;
- (UserAuthInfo*)Level2SecurityInfo;
- (void)ForceRefreshSecurity;
- (void)RequestLevel2SignIn;
- (void)RequestLevel2SignOut;
- (TokenContainer*)GetRawClaims;
- (NSData*)GetUserThumbnailPicture;
- (NSString*)GetUserThumbnailURL;
- (void)Logout;
- (BOOL)IsTokenBlacklisted:(NSString*)token;
- (void)CallLevel1Security;


- (void)CallLevel2Security;
- (void)CallLevel2Security:(NSString*)usr password:(NSString*)pwd ; // appel d'une aute view

- (UoMetierContainer *)GetUoMetierList;
- (DeviceInfo *)EnrollDevice:(NSString *)deviceLabel;
- (DeviceInfo *)UnEnrollDevice:(NSString *)deviceLabel;
- (DeviceInfo *)GetDeviceInfo;
- (void)UpdateDeviceInfo:(DeviceInfo *)deviceInfo;
- (void)UpdateSupportInfo:(DeviceInfo *)supportInfo;

- (void)ShowSignOutAlert;
- (DeviceAuthInfo *)GetStoreLevel1;
- (UserAuthInfo *)GetStoreLevel2;

- (void)ShowNoConnectionAlert;

- (void)DidEnterForeground;
- (void)DidEnterBackground;
- (void)SetTimeBeforeLogout:(double)timeBeforeLogout;

- (void)ClearLevel2;

@property Level1ConnectionDelegate *level1Delegate;
@property Level2ConnectionDelegate *level2Delegate;
@end

static NSString * const OnLevel1SecurityInfoChange = @"OnLevel1SecurityInfoChange";
static NSString * const OnLevel2SecurityInfoChange = @"OnLevel2SecurityInfoChange";
static NSString * const OnLevel1Loaded = @"OnLevel1Loaded";
static NSString * const OnLevel2Loaded = @"OnLevel2Loaded";
static NSString * const OnLevel2PreSignOut = @"OnLevel2PreSignOut";


static NSString * const InvalidSecurityTokenErrorType = @"InvalidSecurityToken";


static NSString * const KeychainID = @"POM";
