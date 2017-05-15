//
//  LSProximityAnalyticsManager.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 2/13/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSMonitoringManager.h"
@class LSProximityAnalyticsManager;

NS_ASSUME_NONNULL_BEGIN

@protocol LSProximityAnalyticsManagerDelegate <NSObject>

/**
 * Informs delegate about gathered proximity event.
 * @param eventDictionary - Dictionary, that contatins information about incoming event, as follows:
 *
 * <code>@"event"</code> - A string representation of occured event type
 *
 * <code>@"timestamp"</code> - Time, when event was occured
 *
 * <code>@"mac"</code> - MAC address of WiBeat that is connected with the incoming event
 *
 * <code>@"wi_beat_id"</code> - ID  of WiBeat that is connected with the incoming event
 */
- (void)proximityAnalyticsManager:(LSProximityAnalyticsManager *)analyticsManager didGatherEvent:(NSDictionary *)eventDictionary;

/**
 * Informs delegate about synchronization with server.
 * @param events - an array of events dictionaries
 * @param error - error, that was occured during the synchronization, if any.
 */
- (void)proximityAnalyticsManager:(LSProximityAnalyticsManager *)analyticsManager didSychronizeEventsWithServer:(NSArray<NSDictionary *> *)events error:(nullable NSError *)error;

@end

@interface LSProximityAnalyticsManager : NSObject <LSMonitoringManagerDelegate>

@property (nonatomic, weak, nullable) id<LSProximityAnalyticsManagerDelegate> delegate;

/**
 * Performs the sending of collected proximity events to server
 * 5000 events is a maximum value of proximity events. 
 * If more events is gathered after the last sync - only 5000 last events will be sended.
 * 48 h is a maximum time interval for storing events. Only events, that were collected during last 48 h will be sended.
 */
- (void)synchronizeWithServer;

/**
 * Starts gathering of proximity events
 * Performs calling of <code>-[LSProximityAnalyticsManager synchronizeWithServer]</code> automatically every 1 h
 */
- (void)startGatheringProximityAnalytics;

/**
 * Stops gathering of proximity events
 * Calling of <code>-[LSProximityAnalyticsManager synchronizeWithServer]</code> will not occure autamatically
 */
- (void)stopGatheringProximityAnalytics;

@end

NS_ASSUME_NONNULL_END
