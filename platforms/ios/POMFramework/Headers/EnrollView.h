//
//  EnrollView.h
//  POMFramework
//
//  Created by TIBLE Alix - Société VNEXT on 22/04/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//


#import <UIKit/UIKit.h>

@class EnrollView;

@interface EnrollView : UIView

@property (weak, nonatomic) IBOutlet UILabel *IpadNameLabel;
@property (weak, nonatomic) IBOutlet UIButton *AjoutButton;
@property (weak, nonatomic) IBOutlet UILabel *IpadIdLabel;
- (IBAction)AjoutSuppressionClick:(id)sender;
- (IBAction)RetourClick:(id)sender;

+ (id)enrollView;

@end