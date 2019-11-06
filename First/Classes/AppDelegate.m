/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

//
//  AppDelegate.m
//  First
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___ORGANIZATIONNAME___ ___YEAR___. All rights reserved.
//

#import "AppDelegate.h"
#import "MainViewController.h"
//POMFramework
#import <POMFramework/WSTrustHelper.h>

@implementation AppDelegate

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    self.viewController = [[MainViewController alloc] init];
    
     // Settings POM
     // Récupère les infos par défaut au lancement de l'appli
     // Penser à ajouter cette ligne dans la doc d'intégration
     [[POMAPI sharedInstance] registerDefaultsFromSettingsBundle];

     // Installation du Crash Handler KSCrash
     // Penser à ajouter cette ligne dans la doc d'intégration
     [[POMService sharedManager]initTechLog];
    // End First
    
    return [super application:application didFinishLaunchingWithOptions:launchOptions];
}


// this happens while we are running ( in the background, or from within our own app )
// only valid if superhello-Info.plist specifies a protocol to handle
- (BOOL)application:(UIApplication*)application openURL:(NSURL*)url sourceApplication:(NSString*)sourceApplication annotation:(id)annotation
{
    if (!url)
    {
        return NO;
    }

    [WSTrustHelper ImportClaimsFromQuery:[url absoluteString] sourceApplicationID:sourceApplication];
    
    // all plugins will get the notification, and their handlers will be called
    [[NSNotificationCenter defaultCenter] postNotification:[NSNotification notificationWithName:CDVPluginHandleOpenURLNotification object:url]];

    return YES;
}


- (UIInterfaceOrientationMask)application:(UIApplication*)application supportedInterfaceOrientationsForWindow:(UIWindow*)window
{
    // iPhone doesn't support upside down by default, while the iPad does.  Override to allow all orientations always, and let the root view controller decide what's allowed (the supported orientations mask gets intersected).
    UIInterfaceOrientationMask supportedInterfaceOrientations = (1 << UIInterfaceOrientationPortrait) | (1 << UIInterfaceOrientationLandscapeLeft) | (1 << UIInterfaceOrientationLandscapeRight) | (1 << UIInterfaceOrientationPortraitUpsideDown);

    return supportedInterfaceOrientations;
}


- (void)applicationDidReceiveMemoryWarning:(UIApplication*)application
{
    [[NSURLCache sharedURLCache] removeAllCachedResponses];
}

#pragma mark - Gestion du background timeout

- (void)applicationDidEnterBackground:(UIApplication *)application {

    NSLog(@"applicationDidEnterBackground");
    [[POMAPI sharedInstance] DidEnterBackground];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    
    NSLog(@"applicationWillEnterForeground");
    [[POMAPI sharedInstance] DidEnterForeground];
}

#pragma mark - appGroup

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    NSLog(@"applicationDidBecomeActive");
    [[POMAPI sharedInstance]DidBecomeActive];
    
}

- (void)applicationWillResignActive:(UIApplication *)application {
    
    NSLog(@"applicationWillResignActive");
    [[POMAPI sharedInstance]WillResignActive];
    
}

@end
