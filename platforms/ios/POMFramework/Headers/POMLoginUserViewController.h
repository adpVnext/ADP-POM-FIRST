//
//  LoginUserViewController.h
//  POMFramework
//
//  Created by Pupponi Jacques - Société VNEXT on 02/05/2016.
//  Copyright © 2016 Aéroports de Paris. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "POMConstants.h"

@interface POMLoginUserViewController : UIViewController {
    
    IBOutlet UILabel            *titreLogin;            // Titre view de login
    IBOutlet UITextField        *identifiant;           // identifiant user niveau 2
    IBOutlet UITextField        *motdepasse;            // mot de passe niveau 2
    IBOutlet UIButton           *sidentifier;           // bouton d'identification
    
    NSString                    *urlToOpen;                         // Url scheme de l'application sélectionée

    
}

@property (nonatomic, strong)  IBOutlet UILabel            *titreLogin;
@property (nonatomic, strong)  IBOutlet UITextField        *identifiant;
@property (nonatomic, strong)  IBOutlet UITextField        *motdepasse;
@property (nonatomic, strong)  IBOutlet UIButton           *sidentifier;
@property (nonatomic, strong)  NSString                    *urlToOpen;


/** Connexion utilisateur niveau2
 *  @param sender Bouton cliqué 
 */
-(IBAction)loginUserNiveau2:(id)sender;

@end
