//
//  POMRessource.h
//  MesDocuments
//
//  Created by Essam Dahab on 12/01/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface POMRessource : NSObject<NSCoding>
@property(assign) NSInteger Id;
@property NSString *Name;
@property int level;
@property int matchContext;
@property NSArray *Contexts;
@end

typedef NS_ENUM(NSInteger, MatchContext) { Device = 0, User = 1, Both = 2  };