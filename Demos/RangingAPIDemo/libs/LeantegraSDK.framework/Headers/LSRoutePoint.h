//
//  LSRoutePoint.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 6/29/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class LSFloor;

NS_ASSUME_NONNULL_BEGIN

@interface LSRoutePoint : NSObject

/**
 * Floor of Route point.
 */
@property (nonatomic, strong, readonly) LSFloor *floor;

/**
 * Location of Route point.
 */
@property (nonatomic, strong, readonly) CLLocation *location;

/**
 * Designated Initializer
 * Returns the LSRoutePoint object with specified floor and location.
 */
+ (LSRoutePoint *)routePointWithFloor:(LSFloor *)floor location:(CLLocation *)location;

/**
 * Unavailable. Use the -[initWithFloor:location:] Designated Initializer
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Designated Initializer
 * Initializes the LSRoutePoint object with specified floor and location.
 */
- (instancetype)initWithFloor:(LSFloor *)floor location:(CLLocation *)location NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
