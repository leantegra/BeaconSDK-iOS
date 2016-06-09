//
//  LSBaseDeviceInfo.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/18/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSPowerMoteEnums.h"

/**
 * Represents all basic Bluetooth GATT characteristics of PowerMote.
 * @see LSTagDeviceInfo
 * @see LSiBeaconeDeviceInfo
 * @see LSHybrideDeviceInfo
 * @see LSEddystoneURLDeviceInfo
 */
@interface LSBaseDeviceInfo : NSObject

///Represents vendor
@property NSString *vendor;

///Represents device model
@property NSString *model;

///Represents device name
@property NSString *name;

///Represents device serial number
@property NSString *serial;

///Represents device MAC address
@property NSString *macAddress;

/**Represents operation mode:
 *<br>HYBRIDE, I_BEACON, EDDYSTONE_URL, TAG
 * @see LSOperationMode
 */
@property LSOperationMode operationMode;

///Represents TX power
@property NSInteger txPowerLevel;

///Represents advertising interval in miliseconds
@property NSInteger advertisingInterval;

///Represents firmvare version
@property NSString *firmwareVersion;

///Represents temperature
@property NSInteger temperature;

///Represents battery level in persent
@property NSInteger batteryLevel;

@end
