//
//  LSTagDeviceInfo.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseDeviceInfo.h"

/**
 * Represents all Bluetooth GATT characteristics of WiBeat in the location tag mode.
 * @see LSBaseDeviceInfo
 * @see LSOperationMode#TAG
 */
@interface LSTagDeviceInfo : LSBaseDeviceInfo

/// Represents device ID
@property NSInteger deviceID;

/// Represents network ID
@property NSInteger networkID;

@end
