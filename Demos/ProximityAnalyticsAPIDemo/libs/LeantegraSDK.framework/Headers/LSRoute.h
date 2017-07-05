//
//  LSRoute.h
//  LeantegraSDK
//
//  Created by Artem Drozd on 6/23/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface LSRoute : NSObject

/**
 * Dictionary with floors indexes as keys. 
 * Values are array of CLLocation points, that describes the path on given floor.
 */
@property (nonatomic, strong) NSDictionary<NSNumber *,NSArray<CLLocation *> *> *floorsPath;

/**
 * Array of floors indexes, that are involved in route.
 */
@property (nonatomic, strong) NSArray<NSNumber *> *floorsIndex;

/**
 * Distance of generated route.
 * -1 is set if distance cannot be calculated.
 */
@property (nonatomic, assign) CLLocationDistance distance;

@end
