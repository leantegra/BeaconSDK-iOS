//
//  LeantegraSDKErrors.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 7/7/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

extern NSString *_Nonnull const kLeantegraSDKErrorDomain;

extern NSString *_Nonnull const kLeantegraSDKErrorDescription;

typedef NS_ENUM(NSUInteger, LSLeantegraSDKErrorCodeType) {
    /**Unknown error.*/
    kLSUnknownErrorCode = -1000,

    // Venue plan, RTLS, Routing errors
    kLSNoFloorsStoredDataVenuePlanErrorCode = -2000,
    kLSRoutingNotSupportedForFloorErrorCode = -2001,
    kLSRTLSTimeoutErrorCode = -2002,

    // Possible errors for interactions with WiBeat.
    /**No connection to the remote device.*/
    kLSWiBeatNotConnectedErrorCode = -3000,
    /**Requested characteristic is unavailable in WiBeat.*/
    kLSCharacteristicNotFoundErrorCode = -3001,
    /**Wrong characteristic*/
    kLSCharacteristicValueErrorCode = -3002,
    /**Read operation failed.*/
    kLSReadFailedErrorCode = -3003,
    /**Write operation failed.*/
    kLSWriteFailedErrorCode = -3004,
    /**Bluetooth not enabled or unavailable in this device.*/
    kLSBluetoothNotFoundErrorCode = -3005,
    /**Bluetooth is off on device.*/
    kLSBluetoothOffErrorCode = -3006,
    /**Connecting to WiBeat failed.*/
    kLSConnectionFailedErrorCode = -3007,
    /**Prmission not provided.*/
    kLSPermissionsNotProvidedErrorCode = -3008,
    /**Connection to WiBeat closed during read/write operation.*/
    kLSConnectionClosedErrorCode = -3009,
    /**WiBeat services discovery has been failed.*/
    kLSConnectionScanFailedErrorCode = -3010,
    /**Incorrect MAC address.*/
    kLSConnectionInvalidMACErrorCode = -3011,
    /**Can't find device with this MAC address.*/
    kLSConnectionDeviceNotFoundErrorCode = -3012,
    /**Unlock operation failed.*/
    kLSConnectionUnlockErrorCode = -3013,

    // WiBeat FW updating errors.
    kLSFirmwareNotFoundErrorCode = -7001,
    kLSFirmwareVerificationErrorCode = -7002,
    kLSFimwareUpdateInvalidDeviceErrorCode = -7003,
    kLSLowBatteryLevelErrorCode = -7004,
    kLSNotEnoughFreeSpaceErrorCode = -7005,
    kLSFirmwareWriteProblemErrorCode = -7006,
    kLSDeviceUnresponsiveErrorCode = -7007,
    kLSFirmwareSignNotValidErrorCode = -7008,
  
    // Content loading errors
    kLSNoVenueIDErrorCode = -4000,
    
    // Storage errors
    /**Throwed when NSPersistentStoreOpenError occurs.*/
    kLSPersistentStoreOpenError = -5000,

    // Other
    kLSInvalidParameters = -6000,
    kLSOperationCancelledByUser = -6001
};
