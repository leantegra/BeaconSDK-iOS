//
//  LSRegion.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/25/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "LSRangingEnums.h"
#import "LSRegionBuilder.h"

/**
 * Immutable representation of a criteria of fields used to match WiBeat.
 */
@interface LSRegion : NSObject

/**
 Represents identifier
*/
@property (readonly) NSString *identifier;

/**
 Represents proximity zone.
 
 In case of setting proximity zone IMMEDIATE or NEAR enter and exit will call if one of WiBeats will be in this zones. In background application has minimum 3 minutes for monitoring IMMEDIATE or NEAR zone after entering in FAR zone. In addition, if LSMonitoringManager will notified before entering background IMMEDIATE or NEAR zones will be monitoring 3 minutes minimum. After 3 minutes in background will be expired when device located in FAR zone [LSMonitoringManagerDelegate monitoringManager:timeForRangingBeaconsWasExpiredInRegions:] will be called
 @see LSProximityZone
 */
@property (readonly) LSProximityZone proximityZone;

/**
 *  Represents list of MAC addresses of specific WiBeat
 * @discussion In case of setting MAC address, manager will trigger enter and exit region only in foreground mode
 */
@property (readonly) NSArray<NSString*> *addresses;

/**
 Represents list of beacons
 
 @see CLBeaconRegion
 */
@property (readonly) NSArray<CLBeaconRegion*>*beacons;

/**
 *  Creates LSRegion from LSRegionBuilder
 *
 *  @param builder LSRegionBuilder
 *
 *  @return id LSRegion
 */
- (id)initWithBuilder:(LSRegionBuilder *)builder;

///Must use initWithBuilder: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithBuilder: instead.")));

///Must use initWithBuilder: instead.
- (id) initWithProximityUUID:(NSUUID *)proximityUUID identifier:(NSString *)identifier __attribute__((unavailable("Must use initWithBuilder: instead.")));

///Must use initWithBuilder: instead.
-(instancetype)initWithProximityUUID:(NSUUID *)proximityUUID major:(CLBeaconMajorValue)major identifier:(NSString *)identifier __attribute__((unavailable("Must use initWithBuilder: instead.")));

///Must use initWithBuilder: instead.
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID major:(CLBeaconMajorValue)major minor:(CLBeaconMinorValue)minor identifier:(NSString *)identifier __attribute__((unavailable("Must use initWithBuilder: instead.")));

@end
