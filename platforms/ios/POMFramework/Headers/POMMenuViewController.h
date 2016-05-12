//
//  POMMenuViewViewController.h
//  POMFramework
//
//  Created by Pupponi Jacques - Société VNEXT on 27/04/2016.
//  Copyright © 2016 Aéroports de Paris. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "POMAuthInfoViewController.h"
#import "POMApplicationListViewController.h"
#import "POMLoginUserViewController.h"
#import "POMMesParametresViewController.h"
#import "POMMonEspaceViewController.h"

@interface POMMenuViewController : UIViewController {
    
    IBOutlet UIToolbar                  *toolbarMenuPom;        // Toolbar de sélection des views
    IBOutlet UIView                     *contentView;           // Container de la view sélectionnée
    CGRect                              contentFrame;           // Frame du container
    
    POMAuthInfoViewController           *authInfoView;          // View Infos d'authentification
    POMApplicationListViewController    *appListView;           // View Liste des applications
    POMLoginUserViewController          *loginView;             // View de connexion niveau 2
    POMMesParametresViewController      *mesParametresView;     // view paramètres et enrollement
    POMMonEspaceViewController          *monEspaceView;         // View mon espace
    
    UserAuthInfo                        *user;                  // user en cours
    
    UIButton                            *quitButton ;            // bouton pour quitter le menu POM
    
    UIButton    *espaceBtnView;
    UIButton    *enrollBtnView;
    UIButton    *appliBtnView;
    
}

@property (nonatomic, strong) UIToolbar *toolbarMenuPom;
@property (nonatomic, strong) UIView    *contentView;
@property (nonatomic, assign) CGRect    contentFrame;
@property (nonatomic, strong) UIButton  *quitButton ;
@property (nonatomic, strong) UIButton  *espaceBtnView ;
@property (nonatomic, strong) UIButton  *enrollBtnView ;
@property (nonatomic, strong) UIButton  *appliBtnView ;

@property (nonatomic, strong) POMAuthInfoViewController             *authInfoView;
@property (nonatomic, strong) POMApplicationListViewController      *appListView;
@property (nonatomic, strong) POMLoginUserViewController            *loginView;
@property (nonatomic, strong) POMMesParametresViewController        *mesParametresView;
@property (nonatomic, strong) UserAuthInfo                          *user;


- (void) onLoginViewNiveau2 ;

@end

