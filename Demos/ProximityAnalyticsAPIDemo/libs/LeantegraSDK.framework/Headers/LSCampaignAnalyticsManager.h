//
//  LSCampaignAnalyticsManager.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 10/18/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LSCampaignAnalyticsManager, LSCampaignEvent;

NS_ASSUME_NONNULL_BEGIN

@protocol LSCampaignAnalyticsManagerDelegate <NSObject>

/**
 * Informs delegate about synchronization with server.
 * @param events - an array of events dictionaries
 * @param error - error, that was occured during the synchronization, if any.
 */
- (void)campaignAnalyticsManager:(LSCampaignAnalyticsManager *)analyticsManager didSychronizeEventsWithServer:(NSArray<NSDictionary *> *)events error:(nullable NSError *)error;

/**
 * Informs delegate about error, that occured during campaignAnalyticsManager work, that is not related to synchronization process.
 * @param error - error, that was occured during the campaignAnalyticsManager work
 */
- (void)campaignAnalyticsManager:(LSCampaignAnalyticsManager *)analyticsManager didGetError:(nullable NSError *)error;

@end

@interface LSCampaignAnalyticsManager : NSObject

@property (nonatomic, weak, nullable) id<LSCampaignAnalyticsManagerDelegate> delegate;

+ (instancetype)sharedManager;

/**
 * Time interval for synchronization of campaign analytics in seconds. Specify this value before -[LSCampaignAnalyticsManagerDelegate startGatheringCampaignAnalytics] calling
 * If provided value is less than 300 or bigger than 21600, default value will be used.
 * If no value is provided, default value will be used.
 * Default value is 3600.
*/
@property (nonatomic, assign) NSTimeInterval synchronizeTimeInterval;

/**
 * Changes, if -[LSCampaignAnalyticsManager startGatheringCampaignAnalytics], -[LSCampaignAnalyticsManager stopGatheringCampaignAnalytics] are called
*/
@property (nonatomic, assign, readonly) BOOL didStart;

/**
 * Currently stored campaign events
*/
@property (nonatomic, strong, readonly) NSSet<LSCampaignEvent *> *campaignEvents;

/**
 * Adds LSCampaignEvent object to be sent to the server on next synchronization
 * This method will generate error, if -[LSCampaignAnalyticsManager startGatheringCampaignAnalytics] did not called
 * @param campaignEvent - event to add
 */
- (void)insertCampaignEvent:(LSCampaignEvent *)campaignEvent;

/**
 * Removes LSCampaignEvent object to be sent to the server on next synchronization
 * @param campaignEvent - event to remove
 */
- (void)removeCampaignEvent:(LSCampaignEvent *)campaignEvent;

/**
 * Time interval for next synchronization operation.
 * DBL_MAX will be returned, if manager is not started with -[LSCampaignAnalyticsManager startGatheringCampaignAnalytics].
*/
@property (nonatomic, assign, readonly) NSTimeInterval nextSynchronizeAfterTimeInterval;

/**
 * Performs the sending of collected campaign events to server
 * 1000 events is a maximum value of campaign events.
 * If more events is gathered after the last sync - only 1000 last events will be sended.
 * 48 h is a maximum time interval for storing events. Only events, that were collected during last 48 h will be sended.
 */
- (void)synchronizeWithServer;

/**
 * Starts gathering of campaign events
 * Performs calling of <code>-[LSCampaignAnalyticsManager synchronizeWithServer]</code> automatically every 1 h, if other is not specified via <code>synchronizeTimeInterval</code> property.
 */
- (void)startGatheringCampaignAnalytics;

/**
 * Stops gathering campaign events
 * Calling of <code>-[LSCampaignAnalyticsManager synchronizeWithServer]</code> will not occure automatically
 */
- (void)stopGatheringCampaignAnalytics;

@end

NS_ASSUME_NONNULL_END
