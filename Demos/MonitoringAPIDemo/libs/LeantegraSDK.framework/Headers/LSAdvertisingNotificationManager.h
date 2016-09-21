//
//  AdvertisingNotificationManager.h
//  LeantegraSDK
//
//  Created by Artem Drozd on 06/14/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSMonitoringManager.h"

@class LSCMSRule;

/**
 *  Provides callbacks of monitoring errors
 */
@protocol LSAdvertisingNotificationManagerDelegate <NSObject>

/**
 *  Returns callback when monitoring manager generates error
 *
 *  @param error  LSWiBeatError
 */
- (void)monitoringDidGetError:(LSWiBeatError)error;

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
@property (nonatomic, weak) id <LSAdvertisingNotificationManagerDelegate> delegate;

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
-(id)initWithNotification:(UILocalNotification*)baseNotification;

/// Start monitoring with the background scan in your Application.
-(void)startScan;

/// Stop monitoring with the background scan in your Application.
-(void)stopScan;

///Send view info about LSCMSRule content to CMS server.
-(void)sendViewCMSRule:(LSCMSRule*)cmsRule;

/**
 *  Returns list of all LSCMSRule enabled for showing in list
 *  SDK generate "LSCMSRulesCacheContentWasChanged" local notification in case of content changing.
 *
 *  @return NSArray<LSCMSRule*>
 */
- (NSArray<LSCMSRule*>*)allCMSRules;

/**
 *  Returns LSCMSRule* by ruleId
 *
 *  @param ruleId NSNumber*
 *
 *  @return LSCMSRule*
 */
- (LSCMSRule*)cmsRuleById:(NSNumber*)ruleId;

@end