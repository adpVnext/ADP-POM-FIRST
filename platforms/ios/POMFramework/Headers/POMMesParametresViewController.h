//
//  POMMesParametresViewController.h
//  POMFramework
//
//  Created by Pupponi Jacques - Société VNEXT on 02/05/2016.
//  Copyright © 2016 Aéroports de Paris. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "POMAuthInfoViewController.h"

@interface POMMesParametresViewController : UIViewController {
    
    
    IBOutlet UIView                 *containerInfos;        // Container des infos d'authentification
    POMAuthInfoViewController       *authInfoView;          // View Infos d'authentification

    IBOutlet UIButton               *refreshBtn;            // Rafraichit les infos
    IBOutlet UIButton               *gestionUoBtn;          // Gère les Uo/Métiers
    IBOutlet UIButton               *enrolementBtn;         // Enrole un device
    
}

@property (nonatomic, strong) IBOutlet UIView               *containerInfos;
@property (nonatomic, strong) POMAuthInfoViewController     *authInfoView;

@property (nonatomic, strong)  IBOutlet UIButton               *refreshBtn;
@property (nonatomic, strong)  IBOutlet UIButton               *gestionUoBtn;
@property (nonatomic, strong)  IBOutlet UIButton               *enrolementBtn;

-(IBAction)refreshInfos:(id)sender;
-(IBAction)gereUoMetier:(id)sender;
-(IBAction)enrollDevice:(id)sender;


@end
