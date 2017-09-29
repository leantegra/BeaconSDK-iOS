//
//  LSEddystoneUrlFrame.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/28/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseFrame.h"
#import "LSRangingEnums.h"
#import "LSFrameProximable.h"

/**
 * Represents Eddystone(URL) advertising frame of WiBeat.
 * @see LSBaseFrame
 */
@interface LSEddystoneUrlFrame : LSBaseFrame <LSFrameProximable>

/**
 * Represents advertising URL.
 */
@property (readonly) NSString *url;

/**
 * Represents calibrated TX power at 0 meter.
 */
@property (readonly) NSInteger txPower;

/**
 *  Represents proximity zone
 *  @see LSProximityZone
 */
@property LSProximityZone proximityZone;

- (instancetype)initWithData:(NSData*)data;

///Must use initWithData: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithData: instead.")));

@end
