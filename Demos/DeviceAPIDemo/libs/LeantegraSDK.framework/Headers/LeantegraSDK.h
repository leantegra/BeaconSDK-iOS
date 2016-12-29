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

#import "LSRangingEnums.h"
#import "LSCloudEnums.h"

//! Project version number for LeantegraSDK.
FOUNDATION_EXPORT double LeantegraSDKVersionNumber;

//! Project version string for LeantegraSDK.
FOUNDATION_EXPORT const unsigned char LeantegraSDKVersionString[];

/**
 *  Represents proximity UUID string value
 */
static NSString *defaultProximityUUIDstring = @"85a99e33-bbbe-4763-a66b-4d3a3edec09b";

// In this header, you should import all the public headers of your framework using statements like #import <LeantegraSDK/PublicHeader.h>
@interface LeantegraSDK : NSObject

/**
 *  Returns server URL
 */
+ (NSString*)serverUrl;

/**
 *  Set new value of server URL
 */
+ (void)setServerUrl:(NSString* _Nonnull)newServerUrl;

/**
 *  Returns current client ID value
 */
+ (NSString*)clientId;

/**
 *  Set new client ID value
 */
+ (void)setClientId:(NSString* _Nonnull)newClientId;

/**
 *  Returns current client secret value
 */
+ (NSString*)clientSecret;

/**
 *  Set new client secret value
 */
+ (void)setClientSecret:(NSString* _Nonnull)newClientSecret;

/**
 *  Returns third party ID value
 */
+ (NSString*)thirdPartyId;

/**
 *  Set new third party ID value
 */
+ (void)setThirdPartyId:(NSString*)newThirdPartyId;

/**
 *  Returns gender
 */
+ (LSGender)gender;

/**
 Set new gender value
 */
+ (void)setGender:(LSGender)newGender;

/**
 Returns age
 */
+ (NSInteger)age;

/**
 Set new age value
 */
+ (void)setAge:(NSInteger)newAge;

/**
 Set new birth date value
 */
+ (void)setBirthDate:(NSDate*)newBirthDate;

/**
 Returns birth date
 */
+ (NSDate*)birthDate;

/**
 Set new radius for IMMEDIATE zone
 if value = nil, monitoring take default value 0.5 meters
 */
+ (void)setImmediateZoneRadius:(NSNumber*)meters;

/**
 Returns value of IMMEDIATE zone radius
 returning value = nil means radius was not customised and monitoring use default value = 0.5 m
 */
+ (NSNumber*)immediateZoneRadius;

/**
 Set new radius for NEAR zone
 if value = nil, monitoring take default value 3 meters
 */
+ (void)setNearZoneRadius:(NSNumber*)meters;

/**
 Returns value of NEAR zone radius
 returning value = nil means radius was not customised and monitoring use default value = 3 m
 */
+ (NSNumber*)nearZoneRadius;

@end


