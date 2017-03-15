//
//  LSFrameProximable.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 5/6/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSRangingEnums.h"

/**
 *  Describes methods for frames which store data about distance
 */
@protocol LSFrameProximable <NSObject>

/**
 *  Represents TX power
 */
@property (readonly) NSInteger txPower;

/**
 *  Represents proximity zone
 *  @see LSProximityZone
 */
@property LSProximityZone proximityZone;

/**
 *  Represents distance in meters
 */
@property NSNumber *distance;

/**
 *  Represents RSSI level
 */
@property NSInteger rssi;

@end
