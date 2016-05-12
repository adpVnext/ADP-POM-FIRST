//
//  POMAPI.h
//  POMFramework
//
//  Created by Essam Dahab on 12/03/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AuthService.h"
#import "POMService.h"
#import "LibraryFileResponseDelegate.h"
#import "WSPomHelper.h"

@interface POMAPI : NSObject

+ (id)sharedInstance;

- (void)CallApplication:(NSString *)destinationAppURL;
- (DeviceAuthInfo*)Level1SecurityInfo;
- (UserAuthInfo*)Level2SecurityInfo;
- (void)RequestLevel2SignIn;
- (void)RequestLevel2SignOut;
- (void)ForceRefreshSecurity;
- (TokenContainer*)GetRawClaims;
- (NSArray*)GetApplicationList;
- (NSString*)GetUserThumbnailURL;
- (NSData*)GetUserThumbnailPicture;
- (BOOL)IsTokenBlackListed:(NSString*)token;

- (void)DidEnterForeground;
- (void)DidEnterBackground;

@property BOOL DisplayStandardMenu;

@end
