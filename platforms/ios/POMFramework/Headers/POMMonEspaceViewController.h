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
    IBOutlet UIImageView            *loginPhoto;            // Photo user si connecté
    IBOutlet UIView                 *bordurePhoto;          // Bordure blanche
    
    IBOutlet UIButton               *deconnexion;           // Bouton de déconnexion
    IBOutlet UIImageView            *ligne;                 // ligne rouge Message plus de réseau
    IBOutlet UILabel                *plusDeReseau;          // Message plus de réseau
    
}

@property (nonatomic, strong) IBOutlet UIView               *containerInfos;
@property (nonatomic, strong) POMAuthInfoViewController     *authInfoView;
@property (nonatomic, strong) IBOutlet UIButton             *deconnexion;
@property (nonatomic, strong) IBOutlet UIImageView          *loginPhoto;
@property (nonatomic, strong) IBOutlet UIView               *bordurePhoto;

@property (nonatomic, strong) IBOutlet UIImageView            *ligne;                 // ligne rouge Message "Vous n'avez plus de réseau"
@property (nonatomic, strong) IBOutlet UILabel                *plusDeReseau;          // Message "Vous n'avez plus de réseau"


/** logout utilisateur niveau2
 *  @param sender Bouton cliqué
 */
-(IBAction)logoutUserNiveau2:(id)sender;

@end
