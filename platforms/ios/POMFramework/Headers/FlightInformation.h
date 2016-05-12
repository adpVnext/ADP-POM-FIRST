//
//  NSDictionaryExtension.m
//
//
//  Created by vnext on 22/01/2015.
//
//

//#import <Foundation/NSString.h>
#import <Foundation/Foundation.h>

@interface FlightInformation : NSObject <NSCopying>

@property NSString *FormatCode;
@property NSString *NumberOfLeg;
@property NSInteger IndexLegDepartFromParis;
@property NSString *PassagerName;
@property NSString *ElectronicTicketIndicator;
@property NSMutableArray *FlightLegs;

- (void)DecodeFlightLeg:(NSString*)data;
-(NSDictionary*)objectToDictionary;
-(id) copyWithZone:(NSZone *)zone;

@end

