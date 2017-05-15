//
//  LSRangingManager.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/28/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LeantegraSDK/LSBaseFrame.h>
#import "LSEddystoneUrlFrame.h"
#import "LSiBeaconFrame.h"
#import "LSTagFrame.h"
#import "LSWiBeatEnums.h"
#import "LSEddystoneUrlFrame.h"
#import "LSiBeaconFrame.h"
#import "LSTagFrame.h"
#import "LSTLMFrame.h"
#import "LSEIDFrame.h"
#import "LSUIDFrame.h"

@class LSRangingManager;

/**
 *  Provides callbacks returning frames or error
 */
@protocol LSRangingManagerDelegate <NSObject>

/**
 *  Returns callback when <b>activePeriod</b> over
 *
 *  @param manager LSRangingManager
 *  @param frames  NSArray<LSBaseFrame *> of all frames which were ranged during <b>activePeriod</b>
 */
- (void)rangingManager:(LSRangingManager*)manager didRangeBeacons:(NSArray<LSBaseFrame *> *)frames;

/**
 *  Returns callback when the new (during activePeriod) frame was found.
 *
 *  @param manager LSRangingManager
 *  @param frame   LSBaseFrame
 */
- (void)rangingManager:(LSRangingManager*)manager didRangeBeacon:(LSBaseFrame*)frame;

/**
 *  Returns callback if LSWiBeatError was generated
 *
 *  @param manager LSRangingManager
 *  @param error   LSWiBeatError
 */
- (void)rangingManager:(LSRangingManager*)manager didGetError:(LSWiBeatError)error;

@end


/**
 Provides scanning BLE devices and return their frames

 <b>Usage:</b>

    -(void)startRanging(){
        rangingManager = [[LSRangingManager alloc] init];
        [rangingManager addDelegate:self];
        rangingManager.activePeriod = 3;
        [rangingManager startRangingBeacons];
    }
 
    -(void)rangingManager:(LSRangingManager *)manager didRangeBeacon:(LSBaseFrame *)frame{
        //When new WiBeat will be found during active period
    }
  
    -(void)rangingManager:(LSRangingManager *)manager didRangeBeacons:(NSArray<LSBaseFrame *> *)newFrames{
        //When active period runs out - this collback returns all frames collected during active period
    }
  
    -(void)stopRanging{
        [rangingManager stopRangingBeacons];
    }
 */
@interface LSRangingManager : NSObject <CBCentralManagerDelegate>

/**
 *  Ranging period in seconds
 */
@property NSInteger activePeriod;

/**
 *  Length of pause between ranging in seconds
 */
@property NSInteger passivePeriod;

- (void)addDelegate:(id<LSRangingManagerDelegate>)delegate;

- (void)removeDelegate:(id<LSRangingManagerDelegate>)delegate;

/**
 Launches ranging
 */
- (void)startRangingBeacons;

/**
 *  Stops ranging
 */
- (void)stopRangingBeacons;

@end
