//
//  LSRegionBuilder.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 5/18/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "LSRangingEnums.h"
@class LSRegion;

/**
 *  Class for building LSRegion
 */
@interface LSRegionBuilder : NSObject

/**
 *  Unique nonnull identifier. Do not use spaces in identifier.
 * <p>
 * Another region with the same identifier will replace previous
 */
@property (nonnull) NSString *identifier;

/**
 *  Represents proximity zone
 *  <p>
 *  If proximity zone will be set IMMEDIATE or NEAR, in background mode application will be able to monitor this region during limited period of time (3 minutes minimum from entering in FAR zone or entering in background mode)
 */
@property LSProximityZone proximityZone;

/**
 *  Returns list of MAC addresses of WiBeats
 *  <p>
 *  If MAC address is set, this region will be monitored only in foreground mode
 */
- (nullable NSArray<NSString *> *)addresses;

/**
 *  Returns list of beacons
 */
- (nullable NSArray<CLBeaconRegion *> *)beacons;

/**
 *  Initialize LSRegionBuilder object
 *
 *  @param identifier    NSString
 *
 *  @return id LSRegionBuilder
 */
- (nullable instancetype)initWithIdentifier:(nonnull NSString *)identifier;

///Must use initWithIdentifier: instead.
- (nullable instancetype)init __attribute__((unavailable("Must use initWithIdentifier instead.")));

/**
   Receive MAC address in format XX:XX:XX:XX:XX:XX and add it into addresses
 
 *  @param address NSString
 *
 *  @return YES if MAC address has valid format
 */
- (BOOL)addBeaconByAddress:(nonnull NSString*)address;

/**
 *  Receive parameters for creating CLBeaconRegion and adding it into beacons array
 *
 *  @param uuid  NSUUID could not be nil
 *  @param major NSNumber could be nil
 *  @param minor NSNumber could be nil
 
 */
- (void)addBeaconByUUID:(nonnull NSUUID *)uuid major:(nullable NSNumber *)major minor:(nullable NSNumber *)minor;

/**
 * Initialise LSRegion object
 */
- (LSRegion *_Nullable)build;

@end
