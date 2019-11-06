//
//  CDVPOM.h
//
//  Modified by Essam Dahab on 15/06/2015.
//
// v1.8.3

#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>

#import <POMFramework/POMFramework.h>
#import <POMFramework/ScanAPI.h>
#import <POMFramework/ScanService.h>


@interface CDVPOM  : CDVPlugin
{}
@property (nonatomic, copy) NSString* scanCallbackId;

- (void)InitMenu:(CDVInvokedUrlCommand*)command;

- (void)InitVPNManager:(CDVInvokedUrlCommand*)command;

- (void)CallApplication:(CDVInvokedUrlCommand*)command;
- (void)Level1SecurityInfo:(CDVInvokedUrlCommand*)command;
- (void)GetFrameworkVersion:(CDVInvokedUrlCommand*)command;
- (void)Level2SecurityInfo:(CDVInvokedUrlCommand*)command;
- (void)RequestLevel2SignIn:(CDVInvokedUrlCommand*)command;
- (void)RequestLevel2SignOut:(CDVInvokedUrlCommand*)command;
- (void)ForceRefreshSecurity:(CDVInvokedUrlCommand*)command;
- (void)GetRawClaims:(CDVInvokedUrlCommand*)command;
- (void)GetApplicationList:(CDVInvokedUrlCommand*)command;
- (void)GetUserThumbnailURL:(CDVInvokedUrlCommand*)command;
- (void)GetUserThumbnailPicture:(CDVInvokedUrlCommand*)command;
- (void)IsTokenBlacklisted:(CDVInvokedUrlCommand*)command;

- (void)DownloadFile:(CDVInvokedUrlCommand*)command;
- (void)ViewFile:(CDVInvokedUrlCommand*)command;
- (void)GetLibraryList:(CDVInvokedUrlCommand*)command;

- (void)LaunchScan:(CDVInvokedUrlCommand*)command;
- (void)LaunchTicketScan:(CDVInvokedUrlCommand*)command;

@end

