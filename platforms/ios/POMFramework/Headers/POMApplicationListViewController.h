//
//  ApplicationListView.h
//  POMFramework
//
//  Created by Pupponi Jacques - Société VNEXT on 28/04/2016.
//  Copyright © 2016 Aéroports de Paris. All rights reserved.
//

/**
 *  View Controller affichant la liste des applications dans une Collection View
 *  Cette liste est l'une des views incluses dans le menu POM (1.Liste applis, 2.Infos authentification, 3.Enrollement device)
 *  Gère l'appel aux autres applications par un open de l'url scheme de l'application choisie
 */

#import <UIKit/UIKit.h>

@interface POMApplicationListViewController : UIViewController <UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout> {
    
    NSArray     *infos;                             // Tableau des infos de l'application affichée dans la liste (contient le logo en data et l'url scheme)
    NSString    *urlToOpen;                         // Url scheme de l'application sélectionée
    IBOutlet    UICollectionView *collectionView;   // Collection View
}


@property (nonatomic, strong) NSArray       *infos;
@property (nonatomic, strong) NSString      *urlToOpen;
@property (nonatomic, strong) IBOutlet      UICollectionView *collectionView;


/**
 *  Rafraichit la liste des applications à afficher dans la collection view
 *  Fonction appelée lors du chargement de la page
 */
- (void)RefreshAppInfo;

@end
