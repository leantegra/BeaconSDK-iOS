//
//  LSiBeaconFrame.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/28/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseFrame.h"
#import "LSRangingEnums.h"
#import "LSFrameProximable.h"

/**
 * Represents iBeacon advertising frame of WiBeat.
 * @see LSBaseFrame
 */
@interface LSiBeaconFrame : LSBaseFrame <LSFrameProximable>

/**
 *  Represents major ID
 */
@property NSInteger major;

/**
 *  Represents minor ID
 */
@property NSInteger minor;

/**
 *  Represents TX power at 1 meter
 */
@property NSInteger txPower;

/**
 *  Represents proximity zone
 *  @see LSProximityZone
 */
@property LSProximityZone proximityZone;

- (instancetype)initWithData:(NSData*)data;

///Must use initWithData: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithData: instead.")));

@end
