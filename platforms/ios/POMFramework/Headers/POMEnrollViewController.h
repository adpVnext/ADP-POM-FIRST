//
//  POMEnrollViewController.h
//  POMFramework
//
//  Created by Pupponi Jacques - Société VNEXT on 20/05/2016.
//  Copyright © 2016 Aéroports de Paris. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface POMEnrollViewController : UIViewController {
    
    
    IBOutlet UILabel *IpadNameLabel;
    IBOutlet UIButton *AjoutButton;
    IBOutlet UILabel *IpadIdLabel;
    
}

@property (nonatomic, strong) IBOutlet UILabel  *IpadNameLabel;
@property (nonatomic, strong) IBOutlet UIButton *AjoutButton;
@property (nonatomic, strong) IBOutlet UILabel  *IpadIdLabel;


- (IBAction)AjoutSuppressionClick:(id)sender;
- (IBAction)RetourClick:(id)sender;


@end
