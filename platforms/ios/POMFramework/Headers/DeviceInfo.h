//
//  DeviceInfo.h
//  POMFramework
//
//  Created by Essam Dahab on 05/05/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

/**
 *  Informations sur le support (ipad, iphone)
 *
 *  Méthodes de recup et rafraichissement des device infos
 *
 * */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface DeviceInfo : NSObject


/** Enregistre les données du Device en cours dans le fichier user defaults et les retourne
 *  @param deviceInfo Modèle infos device
 *  @return Infos du device
 */
- (DeviceInfo *) GetInfo:(DeviceInfo *) deviceInfo;


/** Vérifie si les infos du device ont plus d'un jour de validité
 *  @return Vrai si les infos ont plus d'un jour, Faux sinon
 */
- (bool) NeedToUpdateInfo;


@property (nonatomic, strong) NSString          *Name;          // Nom du device
@property (nonatomic, strong) NSMutableArray    *UoMetiers;     // Couple UO/Métiers
@property (nonatomic, strong) NSString          *SerialId;      // N° de série
@property (nonatomic, strong) NSString          *VendorId;      // VendorId  = unique ID
@property (nonatomic, strong) NSString          *SystemName;    // Nom de l'OS
@property (nonatomic, strong) NSString          *IosVersion;    // Version iOs
@property (nonatomic, strong) NSString          *DeviceType;    // Type de support
@property (nonatomic, strong) NSString          *LastUser;      // Dernier utilisateur conecté

@end
