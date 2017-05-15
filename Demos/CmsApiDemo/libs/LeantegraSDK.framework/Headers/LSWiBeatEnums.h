//
//  LSWiBeatEnums.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/15/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Error enum describes all possible errors for interactions with WiBeat.
 */
typedef NS_ENUM(NSInteger, LSWiBeatError) {
    /**No connection to the remote device.*/
    ERROR_NOT_CONNECTED,
    /**Requested characteristic is unavailable in WiBeat.*/
    ERROR_CHARACTERISTIC_NOT_FOUND,
    /**Wrong characteristic*/
    ERROR_CHARACTERISTIC_VALUE,
    /**Read operation failed.*/
    ERROR_READ,
    /**Write operation failed.*/
    ERROR_WRITE,
    /**Bluetooth not enabled or unavailable in this device.*/
    ERROR_BLUETOOTH_NOT_FOUND,
    /**Bluetooth is off on device.*/
    ERROR_BLUETOOTH_OFF,
    /**Connecting to WiBeat failed.*/
    ERROR_CONNECTION_FAILED,
    /**Prmission not provided.*/
    ERROR_PERMISSION_NOT_PROVIDED,
    /**Connection to WiBeat closed during read/write operation.*/
    ERROR_CONNECTION_CLOSED,
    /**WiBeat services discovery has been failed.*/
    ERROR_CONNECTION_SCAN_FAILED,
    /**Incorrect MAC address.*/
    ERROR_CONNECTION_WRONG_MAC_ADDRESS,
    /**Can't find device with this MAC address.*/
    ERROR_CONNECTION_DEVICE_NOT_FOUND,
    /**Unknown error.*/
    ERROR
};

/**
 * Operation mode enum describes all possible broadcasting schemes of the WiBeat.
 */
typedef NS_ENUM(NSInteger, LSOperationMode) {
    /*!Undefined WiBeat operation mode.*/
    UNDEFINED = -1,
    /*!WiBeat broadcasts iBeacon and Eddystone(URL) advertising frames.*/
    HYBRID,
    /*!WiBeat broadcasts iBeacon advertising frame.*/
    I_BEACON,
    /*!WiBeat broadcasts Eddystone(URL) advertising frame.*/
    EDDYSTONE_URL,
    /*!WiBeat broadcasts advertising frame with location tag.*/
    TAG
};

typedef NS_ENUM(NSInteger, LSCharacteristicType){
    LS_CHARACTERISTIC_TYPE_UNKNOWN,
    LS_CHARACTERISTIC_TYPE_STATUS,
    LS_CHARACTERISTIC_TYPE_TX_POWER,
    LS_CHARACTERISTIC_TYPE_TEMPERATURE,
    LS_CHARACTERISTIC_TYPE_ADVERTISING_INTERVAL,
    LS_CHARACTERISTIC_TYPE_FIRMWARE_VERSION,
    LS_CHARACTERISTIC_TYPE_OPERATION_MODE,
    LS_CHARACTERISTIC_TYPE_LS_VENDOR,
    LS_CHARACTERISTIC_TYPE_LS_MODEL,
    LS_CHARACTERISTIC_TYPE_SERIAL,
    LS_CHARACTERISTIC_TYPE_URL,
    LS_CHARACTERISTIC_TYPE_MINOR,
    LS_CHARACTERISTIC_TYPE_MAJOR,
    LS_CHARACTERISTIC_TYPE_UUID,
    LS_CHARACTERISTIC_TYPE_NETWORK_ID,
    LS_CHARACTERISTIC_TYPE_DEVICE_ID,
    LS_CHARACTERISTIC_TYPE_UNLOCK,
    LS_CHARACTERISTIC_TYPE_ADV_SLOT_DATA
};

typedef NS_ENUM(NSInteger, LSCapabilitiesVariableSupported){
    IS_VARIABLE_ADV_SUPPORTED = 0x01,
    IS_VARIABLE_TX_POWER_SUPPORTED = 0x02
};

typedef NS_ENUM(NSInteger, LSSettingCapabilities){
    LSSettingCapabilitiesUndefined = -1,
    LSSettingCapabilitiesDisabled,
    LSSettingCapabilitiesEnabled
};

typedef NS_ENUM(NSInteger, LSCapabilitiesFrameType){
    UID = 0x0001,
    URL = 0x0002,
    TLM = 0x0004,
    EID = 0x0008
};

typedef NS_ENUM(NSInteger, LSLockState){
    LS_LOCKED,
    LS_UNLOCKED,
    LS_UNLOCKED_AND_AUTOMATIC_RELOCK_DISABLED
};

/**Eddystone frame type for ADV slot data characterystic*/
typedef NS_ENUM(NSInteger, LSADVSlotDataType){
    /**Eddystone UID frame*/
    SLOT_DATA_UID = 0x00,
    /**Eddystone URL frame*/
    SLOT_DATA_URL = 0x10,
    /**Eddystone TLM frame*/
    SLOT_DATA_TLM = 0x20,
    /**Eddystone EID frame*/
    SLOT_DATA_EID = 0x30
};
