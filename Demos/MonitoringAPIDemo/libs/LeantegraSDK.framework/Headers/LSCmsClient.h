//
//  LSCmsClient.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 6/6/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSRangingEnums.h"
#import "LSCMSRule.h"
#import "LSContent.h"
#import "LSWiBeat.h"
#import "LSLocations.h"

/**
 *  API client provides interaction with Leantegra CMS API.
 *  You can set your CMS URL in cmsUrl static variable, client ID in clientId, secret ID in secretId, third party ID in thirdPartyId
 */
@interface LSCmsClient : NSObject

/**
 *  Return all CMSRules without any filters
 */
- (void)contentSuccess:(void (^)(LSContent*))successfulCallback fail:(void (^)(NSError*))failCallback;

/**
 *  Return raw response without any filters
 */
- (void)contentRawCallback:(void (^)(id _Nonnull responseObject))successfulCallback fail:(void (^)(NSError*))failCallback;

/**
 *  Notify server about getting notification
 *
 *  @param rulesIds           array of rules IDs of event
 *  @param channel            which way content was shown to user: LSViewChannelTypeOfferList if user open content from offer list, LSViewChannelTypeNotification if from notification
 *  @param successfulCallback block called if request performs successfully
 *  @param failCallback       block called in case of error
 */
- (void)sendDelivery:(NSArray<NSNumber*>*)rulesIds channel:(NSString*)channel success:(void (^)(void))successfulCallback fail:(void (^)(NSError*))failCallback;

/**
 *  Notify server about showing to user content of event
 *
 *  @param rulesIds           rules IDs of event
 *  @param channel            which way content was shown to user: LSViewChannelTypeOfferList if user open content from offer list, LSViewChannelTypeNotification if from notification
 *  @param successfulCallback block called if request performs successfully
 *  @param failCallback       block called in case of error
 */
- (void)sendView:(NSArray<NSNumber*>*)rulesIds channel:(NSString*)channel success:(void (^)(void))successfulCallback fail:(void (^)(NSError*))failCallback;

/**
 *  Notify server about using content of event
 *
 *  @param rulesIds           rules IDs of event
 *  @param channel            which way content was shown to user: LSViewChannelTypeOfferList if user open content from offer list, LSViewChannelTypeNotification if from notification
 *  @param successfulCallback block called if request performs successfully
 *  @param failCallback       block called in case of error
 */
- (void)sendUsage:(NSArray<NSNumber*>*)rulesIds channel:(NSString*)channel success:(void (^)(void))successfulCallback fail:(void (^)(NSError*))failCallback;

/**
 * Returns LSWiBeat array from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)devices:(void (^)(NSArray<LSWiBeat*>*))successfulCallback fail:(void (^)(NSError*))failCallback;

/**
 * Returns LSLocation info from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)locations:(void (^)(LSLocations*))successfulCallback fail:(void (^)(NSError*))failCallback;

@end
