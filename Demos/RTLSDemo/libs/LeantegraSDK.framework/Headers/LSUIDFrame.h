//
//  LSUIDFrame.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 12/21/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseFrame.h"
#import "LSRangingEnums.h"
#import "LSFrameProximable.h"

@interface LSUIDFrame : LSBaseFrame <LSFrameProximable>

/**
 * Advertisement TX power.
 */
@property (readonly) NSInteger txPower;

/**
 * Namespace
 */
@property (readonly) NSData *nid;

/**
 * Instance
 */
@property (readonly) NSData *bid;

/**
 *  Represents proximity zone
 *  @see LSProximityZone
 */
@property LSProximityZone proximityZone;

- (instancetype)initWithData:(NSData*)data;

///Must use initWithData: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithData: instead.")));

@end
