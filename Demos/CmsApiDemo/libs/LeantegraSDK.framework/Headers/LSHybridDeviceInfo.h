//
//  LSHybrideDeviceInfo.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseDeviceInfo.h"

/**
 * Represents all Bluetooth GATT characteristics of WiBeat in the hybrid mode.
 * @see LSBaseDeviceInfo
 * @see LSOperationMode#HYBRID
 */
@interface LSHybridDeviceInfo : LSBaseDeviceInfo

/// Represents major ID
@property NSInteger major;

/// Represents minor ID
@property NSInteger minor;

/// Represents advertise URL
@property NSString *url;

@end
