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
 */
- (void)monitoringManager:(LSMonitoringManager*)manager didEnterRegion:(LSRegion*)region;

/**
 *  Returns callback when device exit from region
 *
 *  @param manager LSMonitoringManager
 *  @param region  LSRegion
 */
- (void)monitoringManager:(LSMonitoringManager*)manager didExitRegion:(LSRegion*)region;

/**
 *  Returns callback when monitoring manager generates error
 *
 *  @param manager LSMonitoringManager
 *  @param error  LSPowerMoteError
 */
- (void)monitoringManager:(LSMonitoringManager*)manager didGetError:(LSPowerMoteError)error;

/**
 *  Returns set of regions, which have LSProximityZone parameter when the time for ranging in background expired
 *
 *  @param manager manager LSMonitoringManager
 *  @param regions NSSet<LSRegionWrapper*> set of regions, which have LSProximityZone parameter when the time for ranging in background expired
 */
- (void)monitoringManager:(LSMonitoringManager*)manager timeForRangingBeaconsWasExpiredInRegions:(NSSet<LSRegionWrapper*>*)regions;

@end


/**
 Allows to detect enter/exit events in regions
 
 <b>Usage:</b>
 
    -(void)startMonitoring(){
        monitoringManager = [[LSMonitoringManager alloc] init];
        [monitoringManager addDelegate:self];

        LSRegionBuilder *builder = [[LSRegionBuilder alloc] init];
        builder.identifier = @"MyRegion";
        builder.proximityUUID = [[NSUUID alloc] initWithUUIDString:@"xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"];
        builder.major = [NSNumber numberWithInteger:1];
        builder.minor = [NSNumber numberWithInteger:1];
        builder.proximityZone = IMMEDIATE;
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

/**
 *  Add the new delegate
 *
 *  @param delegate LSMonitoringManagerDelegate
 */
- (void)addDelegate:(id<LSMonitoringManagerDelegate>)delegate;

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

/**
 *  Notify manager that application will enter background. In this case, regions with proximityZone will be in monitoring at least 3 minutes in background, otherwise only 10 seconds 
 */
- (void)applicationWillEnterBackground;

@end