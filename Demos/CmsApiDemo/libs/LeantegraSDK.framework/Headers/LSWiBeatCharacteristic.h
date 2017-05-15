//
//  LSWiBeatCharacteristic.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/20/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSWiBeatEnums.h"
#import "LSDeviceStatus.h"
#import "LSCapabilities.h"
#import "LSEddystoneBaseData.h"
#import <CoreBluetooth/CoreBluetooth.h>

struct LSAdvDataStruct
{
    NSInteger networkId;
    NSInteger deviceId;
};

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

 Use for:<br> 
 LS_CHARACTERISTIC_TYPE_OPERATION_MODE<br>  
 type of characteristics.
 @return Operation mode represented by characteristic.
 @see LSCharacteristicType
 */
@property (readonly) LSOperationMode operationMode;


@property NSData *data;

/**
 * Return the device status represented by characteristic.
 * <p>
 * Use for LS_STATUS type of characteristics.
 * @return Device status represented by characteristic.
 * @since 1.3.0
 */
@property (readonly) LSDeviceStatus *deviceStatus;

/**
 * Return the device capabilities represented by characteristic.
 * <p>
 * Use for
 * LS_CAPABILITIES type of characteristics.
 * @return Device capabilities represented by characteristic.
 * @since 1.3.0
 */
@property (readonly) LSCapabilities *capabilities;

/**
 * Returns Eddystone ADV slot data
 * <p>
 * Use for
 * LS_ADV_SLOT_DATA type of characteristics.
 * @return ADV slot data represented by characteristic.
 * @since 1.3.0
 */
@property LSEddystoneBaseData *advSlotData;

@property struct LSAdvDataStruct *advDataStruct;

@end
