//
//  LeantegraSDK.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/6/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreData/CoreData.h>

#import "LSAdvertisingNotificationManager.h"
#import "LSCmsClient.h"

#import "LSMonitoringManager.h"
#import "LSRegion.h"
#import "LSRegionWrapper.h"

#import "LSRangingManager.h"
#import "LSProximityAnalyticsManager.h"

#import "LSBeaconKey.h"
#import "LSWiBeatEnums.h"
#import "LSRangingEnums.h"
#import "LSCloudEnums.h"

#import "LSBeaconURL.h"
#import "LSBaseDeviceInfo.h"
#import "LSWiBeatCharacteristic.h"
#import "LSWiBeatConnection.h"
#import "LSFirmwareUpdater.h"
#import "LSFirmware.h"

#import "LSEddystoneUIDData.h"
#import "LSEddystoneEIDData.h"
#import "LSEddystoneTLMData.h"
#import "LSEddystoneURLData.h"
#import "LSEddystoneURLDeviceInfo.h"

#import "LSTagDeviceInfo.h"
#import "LSHybridDeviceInfo.h"
#import "LSiBeaconDeviceInfo.h"

#import "LSVenuePlanView.h"
#import "LSVenue.h"
#import "LSRoutePoint.h"
#import "LSRouteRequest.h"
#import "LSTrackable.h"
#import "LSTrackablePerson.h"

#import "LSActivityLogger.h"

#import "LSRoute.h"

#import "LeantegraSDKErrors.h"

//! Project version number for LeantegraSDK.
FOUNDATION_EXPORT double LeantegraSDKVersionNumber;

//! Project version string for LeantegraSDK.
FOUNDATION_EXPORT const unsigned char LeantegraSDKVersionString[];

/**
 *  Represents proximity UUID string value
 */
static NSString *_Nonnull defaultProximityUUIDstring = @"85a99e33-bbbe-4763-a66b-4d3a3edec09b";

// In this header, you should import all the public headers of your framework using statements like #import <LeantegraSDK/PublicHeader.h>
@interface LeantegraSDK : NSObject

/**
 *  Value of server URL
 */
@property (class, nonatomic, strong, nonnull) NSString *serverUrl;

/**
 *  Current client ID value
 */
@property (class, nonatomic, strong, nonnull) NSString *clientId;

/**
 *  Current client secret value
 */
@property (class, nonatomic, strong, nonnull) NSString *clientSecret;

/**
 *  Third party ID value
 */
@property (class, nonatomic, strong, nullable) NSString *thirdPartyId;

/**
 *  Gender value
 */
@property (class, nonatomic, assign) LSGender gender;

/**
    Age Value
*/

@property (class, nonatomic, assign) NSInteger age;

/**
 User's birth date
 */
@property (class, nonatomic, strong, nullable) NSDate *birthDate;

/**
    Array of numbers, that represents the user segments Codes
*/
@property (class, nonatomic, strong, nullable) NSArray<NSNumber *> *segments;

/**
 Returns value of IMMEDIATE zone radius
 returning/setting value = nil means radius was not customised and monitoring use default value = 0.5 m
 */
@property (class, nonatomic, strong, nullable) NSNumber *immediateZoneRadius;

/**
 Returns value of NEAR zone radius
 returning/setting value = nil means radius was not customised and monitoring use default value = 3 m
 */
@property (class, nonatomic, strong, nullable) NSNumber *nearZoneRadius;

/**
 Drops CoreData storage and SDK-related keys from UserDefaults
*/
+ (void)clearStorage;

/**
 A dictionary representation of CoreData storage
*/
+ (nullable NSArray <NSDictionary *> *)storageDump;

/**
 Returns SDK version value
 */
+ (nonnull NSString *)SDKVersion;

/**
 Returns SDK build number value
 */
+ (nonnull NSString *)SDKBuildNumber;

@end


