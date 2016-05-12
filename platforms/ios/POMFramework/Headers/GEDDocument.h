//
//  GEDDocument.h
//  MesDocuments
//
//  Created by Essam Dahab on 17/10/2014.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface GEDDocument : NSObject
//@property int Id;
@property NSString *Name;
@property NSString *Path;
@property int Size;

@property NSString *Creator;
@property NSDate *Created;
@property NSString *Editor;
@property NSDate *LastModification;
@end
