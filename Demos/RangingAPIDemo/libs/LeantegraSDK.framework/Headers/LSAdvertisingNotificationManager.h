//
//  AdvertisingNotificationManager.h
//  LeantegraSDK
//
//  Created by Artem Drozd on 06/14/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSMonitoringManager.h"
#import "LSLocalNotification.h"
#import "LSWiBeat.h"
#import "LSLocations.h"
#import "LSCategory.h"

@class LSCMSRule;

NS_ASSUME_NONNULL_BEGIN

// Keys for cmsRuleWithOptions

/**
    If @YES is set as a value, Push only rules will not be included in returning rules result
*/
extern NSString *const kLSExcludePushOnlyRulesOptionsKey;

/**
    If @YES is set as a value, Offer list rules will not be included in returning rules result
*/
extern NSString *const kLSExcludeOfferListRulesOptionsKey;

/**
    If array of specific numbers with rules ID is set a as value, will return array of rules for this rules ID
*/
extern NSString *const kLSRulesIDOptionsKey;

/**
    Array of LSCategory objects. Only rules of specified categies will be returned.
*/
extern NSString *const kLSCategoriesOptionsKey;

/**
    Use this key in conjunction with kLSCategoriesOptionsKey.
    Specifies, if rules with no categories should be included in result array.
*/
extern NSString *const kLSAllowsEmptyCategoriesOptionsKey;

/**
 *  Provides callbacks of monitoring errors
 */
@protocol LSAdvertisingNotificationManagerDelegate <NSObject>

/**
 *  Called when monitoring manager gets error
 *
 *  @param error  NSError with LSLeantegraSDKErrorCodeType
 */
- (void)monitoringDidGetError:(NSError *)error;

/**
 *  Called when adverising manager scheduled notification for a particular CMS rule
 *
 *  @param rule Rule, that is scheduled for showing to user
 *  @param success Indicates, if rule was shown successfully
 *  @param error Passed, if any error was occured. Note: this parameter may be nil, even if success == NO (For example, when there is previously presented notification for specific CMS Rule, that is still present in Notification Center, and event occures again for this CMS Rule)
 */
- (void)monitoringDidShowNotificationWithCMSRule:(LSCMSRule *)rule success:(BOOL)success error:(nullable NSError *)error;

@end

/**
 Allows to show notifications when user enter region, which is defined on CMS.
 <b>Note:</b> The LSAdvertisingNotificationManager uses a LSMonitoringManager to detect
 region events. Also uses LSCmsClient to interact with Leantegra CMS API.
 
 SDK generate "LSCMSRulesCacheContentWasChanged" local notification in case of content changing.

 <b>Usage:</b>

    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
        //Initialize manager
        manager=[[LSAdvertisingNotificationManager alloc] initWithNotification:[UILocalNotification new]];
        [manager setDelegate:self];
        [manager startScan];
        //Show content from notification
        UILocalNotification*localNotification = [launchOptions valueForKey:UIApplicationLaunchOptionsLocalNotificationKey];
        if(localNotification){
            LSCMSRule*cmsRule=[[LSCMSRule alloc] initWithNotificationDictionary:localNotification.userInfo];
            [manager sendViewCMSRule:cmsRule];
        }
 
        return YES;
    }

 @see LSMonitoringManager
 @see LSCmsClient
 */
@interface LSAdvertisingNotificationManager : NSObject<LSMonitoringManagerDelegate>

/// Delegate property
@property (nullable, nonatomic, weak) id <LSAdvertisingNotificationManagerDelegate> delegate;

/**
 Constructs monitoring with the background scan in your Application and shown notifications.
 Notification displayed when the user entered the region and it has a content on the server.

 <b>Note:</b> Notification content loaded from Leantegra CMS, therefore you must initialize SDK.

 <b>Note:</b> The baseNotification will be added userInfo data. Extended data is a
 LSCMSRule object, what you can get with [LSCMSRule initWithNotificationDictionary:] putting the userInfo as parameter.
 The LSCMSRule object can used to get advertising content of the notification.
 Also if you want to send view statistic to CMS, you must call the sendViewCMSRule: method when you show content of LSCMSRule.
 
 <b>Note:</b> The alertBody of UILocalNotification will be set in manager. All other parameters you must set manually.

 @param baseNotification UILocalNotification object what be used to show notifications
 */
-(id)initWithNotification:(LSLocalNotification*)baseNotification;

/// Start monitoring with the background scan in your Application.
-(void)startScan;

/// Stop monitoring with the background scan in your Application.
-(void)stopScan;

/**
 * Downloads and save in cache content from CMS server.
 * Concrete, initiates the "content" and "categories" requests to CVO portal.
 * @param completion - block, that is called with optionally passed error, if any occured while requests loading
 */
- (void)loadData:(void (^_Nullable)(NSError *_Nullable))completion;

///Send view info about LSCMSRule content to CMS server.
- (void)sendViewCMSRules:(NSArray<LSCMSRule*>*)cmsRules channel:(NSString*)channel __attribute__((deprecated("-[LSAdvertisingNotificationManager sendViewCMSRules] has been deprecated. Please use LSCampaignAnalyticsManager or related LSCmsClient methods directly")));

///Send notification to CMS server about LSCMSRule use
- (void)sendUsageCMSRules:(NSArray<LSCMSRule*>*)cmsRules channel:(NSString*)channel success:(void (^ _Nullable)(void))successfulCallback fail:(void (^ _Nullable)(NSError*))failCallback __attribute__((deprecated("-[LSAdvertisingNotificationManager sendUsageCMSRules:success:fail:] has been deprecated. Please use LSCampaignAnalyticsManager or related LSCmsClient methods directly")));

///Send notification to CMS server about delivery rules in offer list
- (void)sendDeliveryInOfferList:(NSArray<LSCMSRule*>*)rules __attribute__((deprecated("-[LSAdvertisingNotificationManager sendDeliveryInOfferList:] has been deprecated. Please use LSCampaignAnalyticsManager or related LSCmsClient methods directly")));

/**
 *  Returns list of all LSCMSRule enabled for showing in list
 *  SDK generate "LSCMSRulesCacheContentWasChanged" local notification in case of content changing.
 *
 *  @return NSArray<LSCMSRule*>
 */
- (NSArray<LSCMSRule*>*)allCMSRules __attribute__((deprecated("allCMSRules has been deprecated please use cmsRuleWithOptions: instead")));
/**
 *  Returns LSCMSRule* by ruleId
 *
 *  @param ruleId NSNumber*
 *
 *  @return LSCMSRule*
 */
- (nullable LSCMSRule*)cmsRuleById:(NSNumber*)ruleId __attribute__((deprecated("cmsRuleById: has been deprecated please use cmsRuleWithOptions: instead")));

/**
 *  Returns LSCMSRule* by giving options
 *
 *  @param options See Options Keys for supported options and values
 *
 */
- (NSArray<LSCMSRule*>*)cmsRuleWithOptions:(NSDictionary*_Nullable)options;

/**
 *  Returns array of available categories
 *
 */
- (NSArray<LSCategory*>*)categories;

/**
 * Returns LSWiBeat array from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)devices:(void (^_Nullable)(NSArray<LSWiBeat*>*))successfulCallback fail:(void (^_Nullable)(NSError*))failCallback __attribute__((deprecated("devices: has been deprecated. Please use cmsClient class instead")));

/**
 * Returns LSLocation info from CMS server
 *
 * @param successfulCallback block called if request performs successfully
 * @param failCallback       block called in case of error
 */
- (void)locations:(void (^_Nullable)(LSLocations*))successfulCallback fail:(void (^_Nullable)(NSError*))failCallback __attribute__((deprecated("locations: has been deprecated. Please use cmsClient class instead")));

@end

NS_ASSUME_NONNULL_END

