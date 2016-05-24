//
//  GEDService.h
//  MesDocuments
//
//  Created by Essam Dahab on 17/10/2014.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ApplicationListConnectionDelegate.h"
#import "ViewFileConnectionDelegate.h"

@class LibraryListConnectionDelegate;
@class ApplicationListConnectionDelegate;

@interface POMService : NSObject
{
    
    BOOL        _DisplayStandardMenu;
    NSString    *urlToOpen;
    
}

-(NSArray *)GetLibraryList;
-(NSArray*)GetApplicationList;
-(void)SyncApplicationList;
-(NSData *)DownloadFile:(NSString *)urlToDownload;
-(void)ViewFile:(NSString *)url inVC:(UIViewController *)viewController;
-(void)CallApplication:(NSString *)destinationAppURL;

+ (id)sharedManager;

@property ApplicationListConnectionDelegate *applicationListDelegate;
@property ViewFileConnectionDelegate *viewFileDelegate;
@property BOOL DisplayStandardMenu;
@property NSOperationQueue *queue;

@end

static NSString * const ApplicationListChanged = @"OnApplicationListChanged";
static NSString * const ShowMenuEvent = @"ShowMenuEvent";
static NSString * const HideMenuEvent = @"HideMenuEvent";
static NSString * const HidePopoverEvent = @"HidePopover";
static NSString * const MovePomToFrontEvent = @"MovePomToFront";