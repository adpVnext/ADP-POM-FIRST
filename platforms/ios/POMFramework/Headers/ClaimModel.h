//
//  ClaimModel.h
//  MesDocuments
//
//  Created by vnext on 02/12/14.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ClaimModel : NSObject<NSCoding>
{
    NSString *key;
    NSMutableArray *values;
}

@property (nonatomic, retain) NSString *key;
@property (nonatomic, retain) NSMutableArray *values;
@end
