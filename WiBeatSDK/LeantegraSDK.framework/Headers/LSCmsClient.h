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
#import "LSCategory.h"
#import "LSTrackable.h"
#import "LSTrackablePerson.h"

@class LSCampaignEvent;

/**
 *  API client provides interaction with Leantegra CMS API.
 *  You can set your CMS URL in cmsUrl static variable, client ID in clientId, secret ID in secretId, third party ID in thirdPartyId
 */
@interface LSCmsClient : NSObject

#pragma mark - CVO Campaign content API calls

/**
 *  Return all CMSRules without any filters
 */
- (void)contentSuccess:(void (^_Nonnull)(LSContent *_Nonnull))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

/**
 *  Return raw response without any filters
 */
- (void)contentRawCallback:(void (^_Nonnull)(id _Nonnull responseObject))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

#pragma mark - Device management API calls

/**
 * Returns LSWiBeat array from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)devices:(void (^_Nonnull)(NSArray<LSWiBeat *> *_Nonnull))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

#pragma mark - Venue map API calls

/**
 * Returns LSLocation info from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)locations:(void (^_Nonnull)(LSLocations *_Nonnull))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

#pragma mark - Categories API calls

/**
 * Returns LSCategories info from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)categories:(void (^_Nonnull)(NSArray<LSCategory *> *_Nonnull))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

#pragma mark - Proximity Analytics API calls

/**
 * Sends Proximity analytics to CMS server in JSON format.
 *
 * @param proximityEvents    array of dictionaries events representation
 * @param attemptsCount      how many tries should be performed before failCallback call
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)sendJSONProximityAnalytics:(nonnull NSArray <NSDictionary *>*)proximityEvents attemptsCount:(NSUInteger)attemptsCount success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

/**
 * Sends Proximity analytics to CMS server in CSV format.
 *
 * @param proximityEvents    UTF-8 encoded CSV events representations
 * @param attemptsCount      how many tries should be performed before failCallback call
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)sendCSVProximityAnalytics:(nonnull NSData *)proximityEvents attemptsCount:(NSUInteger)attemptsCount success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

#pragma mark - Campaign Analytics API calls

/**
 * Sends Campaign analytics to CMS server in CSV format.
 *
 * @param campaignEvents    UTF-8 encoded CSV events representations
 * @param channel            channel type
 * @param attemptsCount      how many tries should be performed before failCallback call
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)sendCSVCampaignAnalytics:(nonnull NSData *)campaignEvents attemptsCount:(NSUInteger)attemptsCount channel:(NSString* _Nonnull)channel  success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nonnull))failCallback;

- (void)sendCampaignAnalyticsEvents:(NSArray<LSCampaignEvent *> *_Nonnull)events attemptsCount:(NSUInteger)attemptsCount success:(void (^_Nonnull)(void))callerSuccessfullCallback fail:(void (^_Nonnull)(NSError *_Nonnull, NSArray<LSCampaignEvent *> *_Nonnull))callerFailCallback;

/**
 *  Notify server about showing to user content of event
 *
 *  @param rulesIds           rules IDs of event
 *  @param channel            which way content was shown to user: LSViewChannelTypeOfferList if user open content from offer list, LSViewChannelTypeNotification if from notification
 *  @param successfulCallback block called if request performs successfully
 *  @param failCallback       block called in case of error
 */
- (void)sendView:(NSArray<NSNumber *> *_Nonnull)rulesIds channel:(NSString *_Nonnull)channel success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback __attribute__((deprecated("-[LSCmsClient sendView:channel:success:fail:] has been deprecated please use -[LSCmsClient sendView:channel:attemptsCount:success:fail:] instead")));

/**
 *  Notify server about showing to user content of event
 *
 *  @param events             events to send
 *  @param channel            which way content was shown to user: LSViewChannelTypeOfferList if user open content from offer list, LSViewChannelTypeNotification if from notification
 *  @param attemptsCount      if request failed, specified attempts count will be performed before failCallback calling
 *  @param successfulCallback block called if request performs successfully
 *  @param failCallback       block called in case of error
 */
- (void)sendView:(NSArray<LSCampaignEvent *> *_Nonnull)events channel:(NSString *_Nonnull)channel attemptsCount:(NSUInteger)attemptsCount success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable, NSArray *_Nullable))failCallback;

/**
 *  Notify server about using content of event
 *
 *  @param rulesIds           rules IDs of event
 *  @param channel            which way content was shown to user: LSViewChannelTypeOfferList if user open content from offer list, LSViewChannelTypeNotification if from notification
 *  @param successfulCallback block called if request performs successfully
 *  @param failCallback       block called in case of error
 */
- (void)sendUsage:(NSArray<NSNumber *> *_Nonnull)rulesIds channel:(NSString *_Nonnull)channel success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback __attribute__((deprecated("-[LSCmsClient sendUsage:channel:success:fail:] has been deprecated please use -[LSCmsClient sendUsage:channel:attemptsCount:success:fail:] instead")));

/**
 *  Notify server about using content of event
 *
 *  @param events             events to send
 *  @param channel            which way content was shown to user: LSViewChannelTypeOfferList if user open content from offer list, LSViewChannelTypeNotification if from notification
 *  @param attemptsCount      if request failed, specified attempts count will be performed before failCallback calling
 *  @param successfulCallback block called if request performs successfully
 *  @param failCallback       block called in case of error
 */
- (void)sendUsage:(NSArray<LSCampaignEvent *> *_Nonnull)events channel:(NSString *_Nonnull)channel attemptsCount:(NSUInteger)attemptsCount success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable, NSArray *_Nullable))failCallback;
/**
 *  Notify server about getting notification
 *
 *  @param rulesIds           array of rules IDs of event
 *  @param channel            which way content was shown to user: LSViewChannelTypeOfferList if user open content from offer list, LSViewChannelTypeNotification if from notification
 *  @param successfulCallback block called if request performs successfully
 *  @param failCallback       block called in case of error
 */
- (void)sendDelivery:(NSArray<NSNumber *> *_Nonnull)rulesIds channel:(NSString *_Nonnull)channel success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback __attribute__((deprecated("-[LSCmsClient sendDelivery:channel:success:fail:] has been deprecated please use -[LSCmsClient sendDelivery:channel:attemptsCount:success:fail:] instead")));

/**
 *  Notify server about getting notification
 *
 *  @param events             events to send
 *  @param channel            which way content was shown to user: LSViewChannelTypeOfferList if user open content from offer list, LSViewChannelTypeNotification if from notification
 *  @param attemptsCount      if request failed, specified attempts count will be performed before failCallback calling
 *  @param successfulCallback block called if request performs successfully
 *  @param failCallback       block called in case of error
 */
- (void)sendDelivery:(NSArray<LSCampaignEvent *> *_Nonnull)events channel:(NSString *_Nonnull)channel attemptsCount:(NSUInteger)attemptsCount success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable, NSArray *_Nullable))failCallback;

#pragma mark - Trackables API calls

/**
 * Returns LSTrackable info from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)trackables:(void (^_Nonnull)(NSArray<LSTrackable *> *_Nonnull))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

/**
 * Returns LSTrackable info for the single trackableUID from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)trackableByUID:(nonnull NSNumber *)trackableUID success:(void (^_Nonnull)(LSTrackable *_Nullable))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

/**
 * Returns LSTrackablePerson info from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)trackablePersons:(void (^_Nonnull)(NSArray<LSTrackablePerson *> *_Nonnull))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

/**
 * Returns LSTrackablePerson info for the single personUID from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)trackablePersonByUID:(nonnull NSNumber *)personUID success:(void (^_Nonnull)(LSTrackablePerson *_Nullable))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

@end
