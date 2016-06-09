//
//  LSRegionBuilder.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 5/18/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSRangingEnums.h"
//#import "LSRegion.h"
@class LSRegion;

/**
 *  Class for building LSRegion
 */
@interface LSRegionBuilder : NSObject

/**
 *  Unique nonnull identifier.
 * <p>
 * Another region wil the same identifier will replace previous
 */
@property NSString *identifier;

/**
 *  Represents proximity zone
 *  <p>
 *  If proximity zone will be set IMMEDIATE or NEAR, in background mode application will be able to monitor this region during limited period of time (3 minutes minimum from entering in FAR zone or entering in background mode)
 */
@property LSProximityZone proximityZone;

/**
 *  Represents MAC address of PowerMote in format XX:XX:XX:XX:XX:XX
 *  <p>
 *  If MAC address is set, this region will be monitored only in foreground mode
 */
@property NSString *address;

/**
 *  Proximity identifier associated with the region.
 */
@property NSUUID *proximityUUID;

/**
 *  Represents major ID
 */
@property NSNumber *major;

/**
 *  Represents minor ID
 */
@property NSNumber *minor;

/**
 *  Initialize LSRegionBuilder object
 *
 *  @param proximityUUID NSUUID
 *  @param identifier    NSString
 *
 *  @return id LSRegionBuilder
 */
- (id)initWithProximityUUID:(NSUUID*)proximityUUID identifier:(NSString*)identifier;

///Must use initWithProximityUUID:identifier: instead.
- (id) init __attribute__((unavailable("Must use initWithProximityUUID:identifier instead.")));

/**
 * Initialise LSRegion object
 */
- (LSRegion*)build;

@end
