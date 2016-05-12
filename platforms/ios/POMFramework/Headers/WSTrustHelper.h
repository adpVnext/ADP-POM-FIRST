//
//  WSTrustHelper.h
//  MesDocuments
//
//  Created by vnext on 28/11/14.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ClaimModel.h"
#import "NSArray+LinqExtensions.h"
#import "StorageHelper.h"
#import "AuthService.h"


@interface WSTrustHelper : NSObject
+(NSString *)getPasswordXML:(NSString *)deviceSecret password:(NSString *)password;
+(NSString *)getUsernameXML:(NSString *)vendorID deviceID:(NSString *)deviceID username:(NSString *)username;
+(NSString *)buildMessage:(NSString *)passwordXML userNameXML:(NSString *)userNameXML;
+(NSMutableURLRequest *)buildPostRequest:(NSString *)url;
+(NSMutableURLRequest *)buildRequest:(NSString *)soapMessage;
+(NSString*)ExtractSamlAssertion:(NSMutableData*)webData;
+ (NSArray *)ParseSaml:(NSData*)data;
+ (BOOL)CompareClaims:(NSArray *)localClaims wsClaims:(NSArray *)wsClaims;
+ (void)ImportClaimsLevel1:(NSData *)d;
+ (void)ImportClaimsLevel2:(NSData *)d;
+ (void)ImportClaimsFromQuery:(NSString *)query sourceApplicationID:(NSString *)sourceApplicationID;
@end
