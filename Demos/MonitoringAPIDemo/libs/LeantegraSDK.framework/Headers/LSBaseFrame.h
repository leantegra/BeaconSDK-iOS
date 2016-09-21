//
//  LSBaseFrame.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/28/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "LSRangingEnums.h"

/**
 * Represents a basic advertising frame of WiBeat.
 * @see LSEddystoneUrlFrame
 * @see LSiBeaconFrame
 * @see LSTagFrame
 */
@interface LSBaseFrame : NSObject

/**
 * Represents peripheral device CBPeripheral.
 */
@property CBPeripheral *peripheral;

/**
 *  Represents peripheral device MAC address
 */
@property NSString *address;

/**
 *  Represents calculated distance in meters
 */
@property NSNumber *distance;

/**
 *  Represents RSSI level
 */
@property NSInteger rssi;

@property (readonly) LSFrameType frameType;

@end
