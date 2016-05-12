//
//  UserAuthInfo.h
//  MesDocuments
//
//  Created by vnext on 27/11/14.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import "BaseAuthInfo.h"

@interface UserAuthInfo : BaseAuthInfo

@property NSString* FullName;
@property NSString* Login;
@property NSString* PicturePath;
@property NSArray* Roles;
@end
