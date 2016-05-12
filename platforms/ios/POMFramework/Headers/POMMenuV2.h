//
//  POMMenuV2.h
//  POMFramework
//
//  Created by Pupponi Jacques - Société VNEXT on 26/04/2016.
//  Copyright © 2016 Aéroports de Paris. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "AuthService.h"
#import "POMMenuViewController.h"
@interface POMMenuV2 : UIButton {
    
    POMMenuViewController   *pomMenuView ;
    UIImageView             *pictoUser;
    
}

@property (nonatomic, strong)  POMMenuViewController *pomMenuView ;


@property (nonatomic, strong)   UIImageView         *imgView;
@property (nonatomic, strong)   UIImageView         *iconImage;
@property (nonatomic, strong)   UILabel             *warningLabel;
@property (nonatomic, strong)   UIView              *attachingView;
@property (nonatomic,strong)    UIViewController    *enrolmentViewAdd;

@property (nonatomic,strong)    UIImageView         *pictoUser;         // Image user sur bouton connecté


+ (void)addMenu:(UIView *)superview width:(float)width height:(float)height margin:(float)margin;
+ (void)addMenu:(UIView *)superview width:(float)width height:(float)height margin:(float)margin timeBeforeLogout:(double)timeBeforeLogout;


@end
