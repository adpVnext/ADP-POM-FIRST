//
//  URLParser.h
//  MesDocuments
//
//  Created by Essam Dahab on 02/02/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface URLParser : NSObject {
    NSArray *variables;
}

@property (nonatomic, retain) NSArray *variables;

- (id)initWithURLString:(NSString *)url;
- (NSString *)valueForVariable:(NSString *)varName;

@end
