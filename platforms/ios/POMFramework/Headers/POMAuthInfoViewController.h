//
//  AuthInfoViewController.h
//  MesDocuments
//
//  Created by vnext on 09/12/14.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//


/**
 *  Gére la tableView des infos d'authentification Device et User
 */


#import <UIKit/UIKit.h>
#import "AuthService.h"

@interface POMAuthInfoViewController : UITableViewController<UITableViewDataSource, UITableViewDelegate>
{
    NSArray         *sectionTitles;             // Tableau des titres de section des infos d'authentification
    UIView          *header;                    // view pour enroller ou admin
    /* NSMutableArray  *sectionStates;          // Pas utilisé ???? */
}

/*   Charge dans la tableview les informations du device et de l'utilisateur
*    Charge les titres de section
*    Affiche les boutons "Rafraichir" et  "gestion uoMetiers" + "Enrollement" groupé dans une view header
*
*    Device:
*     - Id device            => UUID
*     - Contexte             => Permissions
*     - Date d'expiration    => Expiration Date
*
*    User :
*     - Id Utilisateur       => login
*     - Contexte             => Permissions
*     - Date d'expiration    => Expiration Date
*/


/*  Vérifie si le user est Enroller de support
 *  @return TRUE si le user est Enroller
 */
- (Boolean) userIsEnroller;

/*  Vérifie si le user est Admin
 *  @return TRUE si le user est Admin
 */
- (Boolean) userIsAdmin;


/*  Vérifie si l'iPad est enrollé
 *  @return TRUE si l'ipad est enrollé (level security 1 ok)
 */
- (Boolean) isIpadEnrolled;


// Pas utilisé ?
- (void) closeButtonTapped:(UIButton*)button;

/**
 *  Rafraichit le contenu de table des infos d'authentification
 */
-(void) refreshTable;

/**
 *  Rafraichit et réaffiche la vue infos
 */
- (void)RefreshInfo;

/**
 *  Affiche la vue d'enrollement d'un device
 */
-(void) showEnrollView;

/**
 *  Gestion des UO Métiers
 */
-(void) showGestionView;
@end
