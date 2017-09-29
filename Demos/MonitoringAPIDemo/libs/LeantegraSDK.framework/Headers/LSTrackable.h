//
//  LSTrackable.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 7/24/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSLocationObjectProtocol.h"

@class CLLocation;

/**
 * Possible states of trackable asset
 */
typedef NS_ENUM(NSUInteger, LSTrackableStatusType) {
    LSTrackableStatusUndefined,
    LSTrackableStatusActive,
    LSTrackableStatusInactive,
    LSTrackableStatusPlanned
};

@interface LSTrackable : NSObject <LSLocationObject>

/**
 * A single object array, represents the objectID of Venue, that trackable belongs to.
 */
@property (nullable, nonatomic, strong, readonly) NSArray <NSNumber *> *parents;

/**
 * Represents department name
 */
@property (nullable, nonatomic, strong, readonly) NSString *department;

/**
 * Represents the last time discovered by WiRange
 */
@property (nullable, nonatomic, strong, readonly) NSDate *lastSeen;

/**
 * Represents display note text
 */
@property (nullable, nonatomic, strong, readonly) NSString *note;

@property (nonatomic, assign, readonly) NSInteger powerMoteSerialNumber;

/**
 * Represents current trackable status
 * @see LSTrackableStatusType
 */
@property (nonatomic, assign, readonly) LSTrackableStatusType status;

/**
 * Represents the supervisor
 */
@property (nullable, nonatomic, strong, readonly) NSString *supervisor;

/**
 * Represents path with absolute URL to external image resource
 */
@property (nullable, nonatomic, strong, readonly) NSString *picturePath;

/**
 * Represents last discovered date
 */
@property (nullable, nonatomic, strong, readonly) NSDate *updatedAt;

/**
 * Represents zone ID (ID for LSZone or LSPassage)
 */
@property (nonatomic, assign, readonly) NSInteger venueZoneID;

/**
 * Represents floor ID (ID for LSFloor)
 */
@property (nonatomic, assign, readonly) NSInteger venueFloorID;

/**
 * Represents the serial number of trackable
 */
@property (nullable, nonatomic, strong, readonly) NSString *serial;

/**
 * Represents the mac address of trackable
 */
@property (nullable, nonatomic, strong, readonly) NSString *mac;

@property (nullable, nonatomic, strong, readonly) CLLocation *trackableLocation;

/**
 * Schedules the async loading of trackables from CVO portal
 * @param completion block that is called whe the loading is finished with optionally passed error as an argument
 */
+ (void)loadTrackablesWithCompletion:(void (^_Nullable)(NSError *_Nullable))completion;

+ (void)loadTrackable:(nonnull NSNumber *)trackableUID completion:(void (^_Nullable)(NSError *_Nullable))completion;

/**
 * Schedules the sync load of trackables from cache, if any.
 */
+ (nullable NSArray<LSTrackable *> *)trackables;

/**
 * Schedules the sync load of specific trackable from cache, if any.
 */
+ (nullable LSTrackable *)trackableForUID:(nonnull NSNumber *)trackableUID;

/**
 * Must use initWithDictionary: instead.
 */
- (nonnull instancetype)init __attribute__((unavailable("Must use initWithDictionary: instead.")));

@end
