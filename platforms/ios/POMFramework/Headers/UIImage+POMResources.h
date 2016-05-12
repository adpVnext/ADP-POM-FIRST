//
//  UIImage+POMResources.h
//  POMFramework
//
//  Created by Pupponi Jacques - Société VNEXT on 26/04/2016.
//  Copyright © 2016 Aéroports de Paris. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface UIImage (POMResources)

/** Retourne une image du bundle de l'app ou du bundle POM si pas dans le bundle principal
 *  @param name Nom de l'image
 *  @return Image
 */
+ (UIImage*)POMResourcesImageNamed:(NSString*)name;

@end
