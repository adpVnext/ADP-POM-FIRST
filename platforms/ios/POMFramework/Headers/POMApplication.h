//
//  POMApplication.h
//  MesDocuments
//
//  Created by Essam Dahab on 12/01/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "POMRessource.h"

@interface POMApplication : POMRessource<NSCoding>
@property NSString *Schema;
@property NSString *Logo;
@end
