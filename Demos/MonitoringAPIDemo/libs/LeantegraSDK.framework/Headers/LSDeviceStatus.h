//
//  LSDeviceStatus.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 11/15/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSWiBeatEnums.h"

@interface LSDeviceStatus : NSObject

/**Represents operation mode:
 *<br>HYBRID, I_BEACON, EDDYSTONE_URL, TAG
 * @see LSOperationMode
 */
@property (readonly) LSOperationMode operationMode;

/**
 * Get button block state.
 * @return Button block state of WiBeat
 */
@property (readonly) BOOL buttonLock;

/**
 * Get battery level.
 * @return Battery level
 */
@property (readonly) NSInteger batteryLevel;

/**
 * Get led test state.
 * @return Led test state of WiBeat
 */
@property (readonly) BOOL ledTest;


- (instancetype)initWithOperationMode:(LSOperationMode)operationMode buttonLock:(BOOL)buttonLock batteryLevel:(NSInteger)batteryLevel ledTest:(BOOL)ledTest;

///Must use initWithOperationMode:buttonLock:batteryLevel:ledTest instead.
- (instancetype)init __attribute__((unavailable("Must use initWithOperationMode:buttonLock:batteryLevel:ledTest instead.")));

@end
