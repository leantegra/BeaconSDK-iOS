//
//  LSPowerMoteConnection.h
//  Leantegra SDK
//
//  Created by Konstantin Efimenko on 4/5/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <LeantegraSDK/LeantegraSDK.h>
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <LeantegraSDK/LSPowerMoteEnums.h>
#import <LeantegraSDK/LSBeaconURL.h>
#import <LeantegraSDK/LSBaseDeviceInfo.h>
#import <LeantegraSDK/LSPowerMoteCharacteristic.h>
@class LSPowerMoteConnection;

#define LS_MAC_ADDRESS_WITH_COLONS_LENGTH 17

//General
/**Battery level characteristic type.*/
#define LS_BATTERY_LEVEL @"2B19"
/**TX power characteristic type.*/
#define LS_TX_POWER @"2BF7"
/**Temperature characteristic type.*/
#define LS_TEMPERATURE @"2B6E"
/**Advertising interval characteristic type.*/
#define LS_ADVERTISING_INTERVAL @"2B55"
/**Firmware version characteristic type.*/
#define LS_FIRMWARE_VERSION @"2A26"
/**Operation mode characteristic type.*/
#define LS_OPERATION_MODE @"2B99"
/**Vendor name characteristic type.*/
#define LS_VENDOR @"0"
/**Model name characteristic type.*/
#define LS_MODEL @"0"
/**Serial number characteristic type.*/
#define LS_SERIAL @"2A25"

//Eddystone URL
/**URL characteristic type.*/
#define LS_URL @"2084"

//iBeacon
/**Minor ID characteristic type.*/
#define LS_MINOR @"2BF8"
/**Major ID characteristic type.*/
#define LS_MAJOR @"2B9A"

#define LS_UUID @"0"
//Tag
/**Device ID characteristic type.*/
#define LS_DEVICE_ID @"2B76"
/**Network ID characteristic type.*/
#define LS_NETWORK_ID @"2BBB"

/**
 * Provides callbacks indicating whether connection state changed.
 * @see LSPowerMoteConnection
 */
@protocol LSPowerMoteConnectionDelegate <NSObject>

/**
 * Callback invoked when device established connection with PowerMote.
 * @param powerMoteConnection
 */
- (void)powerMoteConnectionDidConnect:(LSPowerMoteConnection*)powerMoteConnection;

/**
 * Callback invoked when device is disconnected from PowerMote.
 * @param powerMoteConnection
 */
- (void)powerMoteConnectionDidDisconnect:(LSPowerMoteConnection*)powerMoteConnection;

/** Calls when code can't process correctly any method
 * @param powerMoteConnection
 * @param powerMoteError Error code
 */
- (void)powerMoteConnection:(LSPowerMoteConnection*)powerMoteConnection didGetError:(LSPowerMoteError)powerMoteError;

@end


/**
 * Provides callbacks indicating whether characteristics are read
 * successfully or failed.
 */
@protocol LSPowerMoteReadCharacteristicDelegate <NSObject>

/**
 * Callback invoked when characteristic has been successfully read.
 * @param characteristic Characteristic value
 */
- (void)powerMoteReadCharacteristicSuccess:(LSPowerMoteCharacteristic*)characteristic;

/**
 * Callback invoked when characteristic reading has been failed.
 * @param error Error code
 */
- (void)powerMoteReadCharacteristic:(LSPowerMoteCharacteristic*)characteristic error:(LSPowerMoteError)error;

@end


/**
 * Provides callbacks indicating whether PowerMote info has been read
 * successfully or failed.
 */
@protocol LSPowerMoteReadDeviceInfoDelegate <NSObject>

/**
 * Callback invoked when device information reading has been completed successfully.
 * @param deviceInfo Device information
 * @see LSBaseDeviceInfo
 */
- (void)powerMoteReadDeviceInfoSuccess:(LSBaseDeviceInfo*)deviceInfo;

/**
 * Callback invoked when device information reading has been failed.
 * @param error Error reading device information. Can be one of
 * @see LSPowerMoteError
 */
- (void)powerMoteReadDeviceInfoError:(LSPowerMoteError)error;

@end


/**
 * Provides callbacks indicating whether characteristics are written
 * successfully or failed.
 */
@protocol LSPowerMoteWriteCharacteristicDelegate <NSObject>

/**
 * Callback invoked when characteristic has been successfully written.
 * @param characteristicType
 */
- (void)powerMoteWriteCharacteristicSuccess:(LSCharacteristicType)characteristicType;

/**
 * Callback invoked when characteristic writing has been failed.
 * @param characteristic
 * @param error Error code
 */
- (void)powerMoteWriteCharacteristic:(LSCharacteristicType)characteristicType error:(LSPowerMoteError)error;

@end


/**
 Provides basic functionality for communication with the remote device.
 Used for reading and writing device GATT characteristics.
 
 All read and write operations perform synchronously, so no need to wait for finishing the previous
 operation.
 
 <b>Note:</b> Application should call  disconnect as early as possible after executing job
 with the device.
 
 <b>Usage:</b>
 
    -(void)connect {
        pmConnection = [[LSPowerMoteConnection alloc] initWithDeviceMACAddress:@"xx:xx:xx:xx:xx:xx" delegate:self];
        if (pmConnection) {
            [pmConnection connect];
        }
    }
 
    -(void)powerMoteConnectionDidConnect:(LSPowerMoteConnection *)powerMoteConnection {
        //After connection we can write or read GATT characteristic's values
        [pmConnection readBatteryLevel:self];
        [pmConnection writeAdvertisingInterval:200 delegate:self];
    }
 
    -(void)powerMoteReadCharacteristicSuccess:(LSPowerMoteCharacteristic *)characteristic {
        //After value of characteristic was read
    }
 
    -(void)powerMoteWriteCharacteristicSuccess:(LSCharacteristicType)characteristicType {
        //After new value of characteristic was written
    }
 
    -(void)disconnect {
        [pmConnection disconnect];
    }
 
    -(void)powerMoteConnectionDidDisconnect:(LSPowerMoteConnection *)powerMoteConnection {
        //After application was disconnected from PowerMote
    }
 */
@interface LSPowerMoteConnection : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate>

/** Time in seconds - maximum time of scanning */
@property NSNumber *scanInterval;

/** MAC address of peripheral*/
@property NSString *deviceMACAddress;

/** Bounded peripheral*/
@property CBPeripheral *peripheral;

/**
 Construct new connection to PowerMote
 @param newDeviceMACAddress should be in format XX:XX:XX:XX:XX:XX in any register
 */
- (id)initWithDeviceMACAddress:(NSString*)newDeviceMACAddress delegate:(id<LSPowerMoteConnectionDelegate>)newDelegate;

/**
 Connect to the remote device.
 */
- (void)connect;

/**
 Disconnect an established connection, or cancel connection that is currently in progress.
 */
- (void)disconnect;

/**
 * Returns a list of GATT characteristics from the remote device.
 */
- (NSArray*)characteristics;

- (BOOL)isConnected;

#pragma mark - Read

/**
 * Reads the requested characteristic from the remote device.
 * <p>
 * This is an asynchronous operation.
 * <p>
 * The successful result of the read operation is returned by the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * <p>
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param characteristic CBCharacteristic to read from the remote device
 * @param newReadDelegate The read delegate
 * @see CBCharacteristic
 */
- (void)readCharacteristic:(CBCharacteristic*)characteristic delegate:(id<LSPowerMoteReadCharacteristicDelegate>)newReadDelegate;

/**
 * Reads battery level characteristic.
 *
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readBatteryLevel:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads TX power characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readTxPower:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads firmware version characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readFirmwareVersion:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads temperature characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readTemperature:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads URL characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readURL:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads advertising interval characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readAdvertisingInterval:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads major ID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readMajor:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads minor ID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readMinor:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads device ID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readDeviceID:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads network ID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readNetworkID:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads operation mode characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readOperationMode:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads serial characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readSerial:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads vendor characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readVendor:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads model characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readModel:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads UUID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSPowerMoteReadCharacteristicDelegate powerMoteReadCharacteristic:error:] callback is triggered.
 * @param delegate LSPowerMoteReadCharacteristicDelegate The read delegate
 * @see LSPowerMoteReadCharacteristicDelegate
 * @see LSPowerMoteCharacteristic
 */
- (void)readUUID:(id<LSPowerMoteReadCharacteristicDelegate>) delegate;

/**
 * Reads all available characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSPowerMoteReadDeviceInfoDelegate powerMoteReadDeviceInfoSuccess:deviceInfo] callback.
 * If error occurred, the [LSPowerMoteReadDeviceInfoDelegate powerMoteReadDeviceInfoError:error:] callback is triggered.
 * @param delegate LSPowerMoteReadDeviceInfoDelegate The read delegate
 * @see LSPowerMoteReadDeviceInfoDelegate
 */
- (void)readDeviceInfo:(id<LSPowerMoteReadDeviceInfoDelegate>) delegate;

#pragma mark - Write

/**
 * Write a given characteristics to the remote device.
 * <p>
 * Once the write operation has been completed successfully, the
 * [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristicSuccess:] callback is triggered,
 * otherwise [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristic:error:]  callback is triggered.
 * @param characteristic Characteristic to write
 * @param dataValue New characteristic value
 * @param newWriteDelegate The write delegate
 * @see CBCharacteristic
 * @see LSPowerMoteWriteCharacteristicDelegate
 */
- (void)writeCharacteristic:(CBCharacteristic*)characteristic dataValue:(NSData*)dataValue delegate:(id<LSPowerMoteWriteCharacteristicDelegate>)newWriteDelegate;

/**
 * Write TX power characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristic:error:] callback is triggered.
 * @param value New TX power value
 * @param delegate Write delegate
 * @see LSPowerMoteWriteCharacteristicDelegate
 */
- (void)writeTxPower:(NSInteger)value delegate:(id<LSPowerMoteWriteCharacteristicDelegate>) delegate;

/**
 * Write URL characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristic:error:] callback is triggered.
 * @param value New URL value
 * @param delegate Write delegate
 * @see LSPowerMoteWriteCharacteristicDelegate
 */
- (void)writeURL:(NSString*)value delegate:(id<LSPowerMoteWriteCharacteristicDelegate>) delegate;

/**
 * Write advertising interval characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristic:error:] callback is triggered.
 * @param value New advertising interval value
 * @param delegate Write delegate
 * @see LSPowerMoteWriteCharacteristicDelegate
 */
- (void)writeAdvertisingInterval:(NSInteger)value delegate:(id<LSPowerMoteWriteCharacteristicDelegate>) delegate;

/**
 * Write major ID characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristic:error:] callback is triggered.
 * @param value New major ID value
 * @param delegate Write delegate
 * @see LSPowerMoteWriteCharacteristicDelegate
 */
- (void)writeMajor:(NSInteger)value delegate:(id<LSPowerMoteWriteCharacteristicDelegate>) delegate;

/**
 * Write minor ID characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristic:error:] callback is triggered.
 * @param value New minor ID value
 * @param delegate Write delegate
 * @see LSPowerMoteWriteCharacteristicDelegate
 */
- (void)writeMinor:(NSInteger)value delegate:(id<LSPowerMoteWriteCharacteristicDelegate>) delegate;

/**
 * Write device ID characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristic:error:] callback is triggered.
 * @param value New device ID value
 * @param delegate Write delegate
 * @see LSPowerMoteWriteCharacteristicDelegate
 */
- (void)writeDeviceID:(NSInteger)value delegate:(id<LSPowerMoteWriteCharacteristicDelegate>) delegate;

/**
 * Write network ID characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristic:error:] callback is triggered.
 * @param value New network ID value
 * @param delegate Write delegate
 * @see LSPowerMoteWriteCharacteristicDelegate
 */
- (void)writeNetworkID:(NSInteger)value delegate:(id<LSPowerMoteWriteCharacteristicDelegate>) delegate;

/**
 * Write operation mode characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSPowerMoteWriteCharacteristicDelegate powerMoteWriteCharacteristic:error:] callback is triggered.
 * @param value New operation mode value
 * @param delegate Write delegate
 * @see LSPowerMoteWriteCharacteristicDelegate
 */
- (void)writeOperationMode:(LSOperationMode)value delegate:(id<LSPowerMoteWriteCharacteristicDelegate>) delegate;

@end





