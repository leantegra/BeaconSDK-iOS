//
//  LSiBeaconDeviceInfo.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseDeviceInfo.h"

/**
 * Represents all Bluetooth GATT characteristics of PowerMote in iBeacone mode.
 * @see LSBaseDeviceInfo
 * @see OperationMode#I_BEACON I_BEACON
 */
@interface LSiBeaconDeviceInfo : LSBaseDeviceInfo

/// Represents major ID
@property NSInteger major;

/// Represents minor ID
@property NSInteger minor;

/// Represents UUID
@property NSString *uuid;

@end
