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
+ (void)setServerUrl:(NSString*)newServerUrl;

/**
 *  Returns current client ID value
 */
+ (NSString*)clientId;

/**
 *  Set new client ID value
 */
+ (void)setClientId:(NSString*)newClientId;

/**
 *  Returns current client secret value
 */
+ (NSString*)clientSecret;

/**
 *  Set new client secret value
 */
+ (void)setClientSecret:(NSString*)newClientSecret;

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

@end


