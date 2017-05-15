//
//  LSMonitoringManager.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/25/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LeantegraSDK/LSRegion.h>
#import "LSRangingManager.h"
#import "LSRegionWrapper.h"
@class LSMonitoringManager;

/**
 *  Provides callbacks in case of entering or exit regions, errors and finishing monitoring in background
 */
@protocol LSMonitoringManagerDelegate <NSObject>

/**
 *  Returns callback when device entering in region
 *
 *  @param manager LSMonitoringManager
 *  @param region  LSRegion
 *  @param frame First advertising frame in region.
 */
- (void)monitoringManager:(LSMonitoringManager*)manager didEnterRegion:(LSRegion*)region frame:(LSBaseFrame*)frame;

/**
 *  Returns callback when device exit from region
 *
 *  @param manager LSMonitoringManager
 *  @param region  LSRegion
 *  @param frame First advertising frame in region.
 */
- (void)monitoringManager:(LSMonitoringManager*)manager didExitRegion:(LSRegion*)region frame:(LSBaseFrame*)frame;

/**
 *  Returns callback when monitoring manager generates error
 *
 *  @param manager LSMonitoringManager
 *  @param error  LSWiBeatError
 */
- (void)monitoringManager:(LSMonitoringManager*)manager didGetError:(LSWiBeatError)error;

/**
 *  Returns set of regions, which have LSProximityZone parameter when the time for ranging in background expired
 *
 *  @param manager manager LSMonitoringManager
 *  @param regions NSSet<LSRegionWrapper*> set of regions, which have LSProximityZone parameter when the time for ranging in background expired
 */
- (void)monitoringManager:(LSMonitoringManager*)manager timeForRangingBeaconsWasExpiredInRegions:(NSSet<LSRegionWrapper*>*)regions;

/**
 *  Calls when device enters in region with defaultProximityUUID
 *  You can change this value in LeantegraSDK.h
 *  You can't start or stop service region monitoring manually
 *
 *  @param manager LSMonitoringManager
 *  @param region  CLRegion
 */
@optional
- (void)monitoringManager:(LSMonitoringManager*)manager didEnterServiceRegion:(CLRegion*)region;

/**
 *  Calls when device exit out region with defaultProximityUUID
 *  You can change this value in LeantegraSDK.h
 *  You can't start or stop service region monitoring manually
 *
 *  @param manager LSMonitoringManager
 *  @param region  CLRegion
 */
@optional
- (void)monitoringManager:(LSMonitoringManager*)manager didExitServiceRegion:(CLRegion*)region;

@optional
- (void)monitoringManager:(LSMonitoringManager *)manager didRangeBeacons:(NSArray<CLBeacon *> *)beacons;

@end


/**
 Allows to detect enter/exit events in regions
 
 <b>Usage:</b>
 
    -(void)startMonitoring(){
        monitoringManager = [LSMonitoringManager sharedMonitoringManager];
        [monitoringManager addDelegate:self];

        LSRegionBuilder *builder = [[LSRegionBuilder alloc] initWithIdentifier:@"MyRegion"];
        builder.proximityZone = IMMEDIATE;
 
        NSUUID *uuid = [[NSUUID alloc] initWithUUIDString:@"xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"];
        NSNumber *major = [NSNumber numberWithInteger:1];
        NSNumber *minor = [NSNumber numberWithInteger:1];
 
        [builder addBeaconByUUID:uuid major:major minor:minor];
 
        LSRegion *region = [builder build];
 
        [monitoringManager startMonitoringForRegion:region];
    }
 
    -(void)monitoringManager:(LSMonitoringManager *)manager didEnterRegion:(LSRegion *)region{
        UILocalNotification *notification = [[UILocalNotification alloc] init];
        notification.alertBody = [NSString stringWithFormat:@"Enter region %@",region.identifier];
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
 
    -(void)monitoringManager:(LSMonitoringManager *)manager didExitRegion:(LSRegion *)region{
        UILocalNotification *notification = [[UILocalNotification alloc] init];
        notification.alertBody = [NSString stringWithFormat:@"Exit region %@",region.identifier];
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
 
    -(void)monitoringManager:(LSMonitoringManager *)manager timeForRangingBeaconsWasExpiredInRegions:(NSSet<LSRegionWrapper *> *)regions{
        //Calls when time in background for monitoring <b>regions</b> was expired
    }
 
    -(void)stopMonitoring:(LSRegion*)region {
        [monitoringManager stopMonitoringForRegion:region];
    }
 */
@interface LSMonitoringManager : NSObject <CLLocationManagerDelegate, LSRangingManagerDelegate>

+ (LSMonitoringManager *)sharedMonitoringManager;

/**
 *  Add the new delegate
 *
 *  @param delegate LSMonitoringManagerDelegate
 */
- (void)addDelegate:(id<LSMonitoringManagerDelegate>)delegate;

/**
 *  Removes the delegate
 *
 *  @param delegate LSMonitoringManagerDelegate
 */
- (void)removeDelegate:(id<LSMonitoringManagerDelegate>)delegate;

/**
 *  Add and start region for monitoring. If the region with the same identifier exists, new region will replace it
 *
 *  @param region LSRegion new region
 */
- (void)startMonitoringForRegion:(LSRegion*)region;

/**
 *  Stop and remove region from monitoring
 *
 *  @param region LSRegion new region
 */
- (void)stopMonitoringForRegion:(LSRegion*)region;

/**
 *  Stops monitoring for all regions
 */
- (void)stopMonitoringForAllRegions;

/**
 *  Returns set of regions in monitoring
 *
 *  @return NSSet<LSRegionWrapper *> regions in monitoring
 */
- (NSSet<LSRegionWrapper *>*)monitoredRegions;

///Must use sharedMonitoringManager instead.
- (instancetype)init __attribute__((unavailable("Must use sharedMonitoringManager instead.")));

@end
