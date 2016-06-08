//
//  UIPomHelper.h
//  MesDocuments
//
//  Created by Essam Dahab on 22/01/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIPomHelper : NSObject
{
    
}
+(void) ShowLoading:(NSString *)message;
+(void) HideLoading;

/**
 *  Charge des fonts spécifiques au framework à partir du bundle de ressources
 *  Permet de les utiliser avec UIFont sans avoir à les déclarer dans le plist de l'application hôte
 *
 *  @param path Fichier de la police
 *  @param type tye defichier (otf, ttf, ..)
 */
+ (void) loadMyCustomFont:(NSString*)path ofType:(NSString*)type;
+ (UIImage *)imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;
+(void)animateGrowView:(UIView *)theView;
+(void)animateShrinkView:(UIView *)theView;
+(void)animateView:(UIView *)theView toPosition:(CGPoint)thePosition;


@end
static UIAlertView *_alertView;