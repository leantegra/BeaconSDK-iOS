//
//  LSWiBeatCharacteristic.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/20/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSWiBeatEnums.h"
#import <CoreBluetooth/CoreBluetooth.h>

/**
 Represents a wrapper around Bluetooth GATT Characteristic of WiBeat.
 
 Contains a value and type of characteristic.
 @see LSWiBeatReadCharacteristicDelegate
 */
@interface LSWiBeatCharacteristic : NSObject

@property (weak) CBCharacteristic *cbCharacteristic;

/**
 Return string value represented by characteristic.

 Use for:<br>
 LS_CHARACTERISTIC_TYPE_VENDOR,<br>
 LS_CHARACTERISTIC_TYPE_MODEL,<br>
 LS_CHARACTERISTIC_TYPE_SERIAL,<br>
 LS_CHARACTERISTIC_TYPE_FIRMWARE_VERSION,<br>
 LS_CHARACTERISTIC_TYPE_NAME,<br>
 LS_CHARACTERISTIC_TYPE_UUID,<br>
 LS_CHARACTERISTIC_TYPE_URL<br>
 types of characteristics.
 @return NSString value represented by characteristic.
 @see LSCharacteristicType
 */
@property NSString *stringValue;

/**
 Return integer value represented by characteristic.
 
 Use for:<br>
 LS_CHARACTERISTIC_TYPE_ADVERTISING_INTERVAL,<br>
 LS_CHARACTERISTIC_TYPE_TEMPERATURE,<br>
 LS_CHARACTERISTIC_TYPE_MAJOR,<br>
 LS_CHARACTERISTIC_TYPE_MINOR,<br>
 LS_CHARACTERISTIC_TYPE_NETWORK_ID,<br>
 LS_CHARACTERISTIC_TYPE_TX_POWER,<br>
 LS_CHARACTERISTIC_TYPE_DEVICE_ID,<br>
 LS_CHARACTERISTIC_TYPE_BATTERY_LEVEL<br>
 types of characteristics.
 @return NSInteger representation of characteristic.
 @see LSCharacteristicType
 */
@property NSInteger intValue;

/**
 Return the operation mode represented by characteristic.

 Use for LS_CHARACTERISTIC_TYPE_OPERATION_MODE  type of characteristics.
 @return Operation mode represented by characteristic.
 @see LSCharacteristicType
 */
@property LSOperationMode operationMode;

@end
