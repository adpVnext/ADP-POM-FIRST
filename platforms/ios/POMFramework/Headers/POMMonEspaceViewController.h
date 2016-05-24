//
//  POMMonEspaceViewController.h
//  POMFramework
//
//  Created by Pupponi Jacques - Société VNEXT on 03/05/2016.
//  Copyright © 2016 Aéroports de Paris. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "POMAuthInfoViewController.h"

@interface POMMonEspaceViewController : UIViewController {
    
    IBOutlet UIView                 *containerInfos;        // Container des infos d'authentification
    POMAuthInfoViewController       *authInfoView;          // View Infos d'authentification
     IBOutlet UIButton               *deconnexion;           // Bouton de déconnexion
    IBOutlet UIImageView            *loginPhoto;            // Photo user si connecté
    IBOutlet UIView                 *bordurePhoto;          // Bordure blanche
    
}

@property (nonatomic, strong) IBOutlet UIView               *containerInfos;
@property (nonatomic, strong) POMAuthInfoViewController     *authInfoView;
@property (nonatomic, strong) IBOutlet UIButton             *deconnexion;
@property (nonatomic, strong) IBOutlet UIImageView          *loginPhoto;
@property (nonatomic, strong) IBOutlet UIView               *bordurePhoto;


/** logout utilisateur niveau2
 *  @param sender Bouton cliqué
 */
-(IBAction)logoutUserNiveau2:(id)sender;

@end
