//
//  LSWiBeatConnection.h
//  Leantegra SDK
//
//  Created by Konstantin Efimenko on 4/5/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <LeantegraSDK/LeantegraSDK.h>
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <LeantegraSDK/LSWiBeatEnums.h>
#import <LeantegraSDK/LSBeaconURL.h>
#import <LeantegraSDK/LSBaseDeviceInfo.h>
#import <LeantegraSDK/LSWiBeatCharacteristic.h>
@class LSWiBeatConnection;

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
 * @see LSWiBeatConnection
 */
@protocol LSWiBeatConnectionDelegate <NSObject>

/**
 * Callback invoked when device established connection with WiBeat.
 * @param wiBeatConnection
 */
- (void)wiBeatConnectionDidConnect:(LSWiBeatConnection*)wiBeatConnection;

/**
 * Callback invoked when device is disconnected from WiBeat.
 * @param wiBeatConnection
 */
- (void)wiBeatConnectionDidDisconnect:(LSWiBeatConnection*)wiBeatConnection;

/** Calls when code can't process correctly any method
 * @param wiBeatConnection
 * @param wiBeatError Error code
 */
- (void)wiBeatConnection:(LSWiBeatConnection*)wiBeatConnection didGetError:(LSWiBeatError)wiBeatError;

@end


/**
 * Provides callbacks indicating whether characteristics are read
 * successfully or failed.
 */
@protocol LSWiBeatReadCharacteristicDelegate <NSObject>

/**
 * Callback invoked when characteristic has been successfully read.
 * @param characteristic Characteristic value
 */
- (void)wiBeatReadCharacteristicSuccess:(LSWiBeatCharacteristic*)characteristic;

/**
 * Callback invoked when characteristic reading has been failed.
 * @param error Error code
 */
- (void)wiBeatReadCharacteristic:(LSWiBeatCharacteristic*)characteristic error:(LSWiBeatError)error;

@end


/**
 * Provides callbacks indicating whether WiBeat info has been read
 * successfully or failed.
 */
@protocol LSWiBeatReadDeviceInfoDelegate <NSObject>

/**
 * Callback invoked when device information reading has been completed successfully.
 * @param deviceInfo Device information
 * @see LSBaseDeviceInfo
 */
- (void)wiBeatReadDeviceInfoSuccess:(LSBaseDeviceInfo*)deviceInfo;

/**
 * Callback invoked when device information reading has been failed.
 * @param error Error reading device information. Can be one of
 * @see LSWiBeatError
 */
- (void)wiBeatReadDeviceInfoError:(LSWiBeatError)error;

@end


/**
 * Provides callbacks indicating whether characteristics are written
 * successfully or failed.
 */
@protocol LSWiBeatWriteCharacteristicDelegate <NSObject>

/**
 * Callback invoked when characteristic has been successfully written.
 * @param characteristicType
 */
- (void)wiBeatWriteCharacteristicSuccess:(LSCharacteristicType)characteristicType;

/**
 * Callback invoked when characteristic writing has been failed.
 * @param characteristic
 * @param error Error code
 */
- (void)wiBeatWriteCharacteristic:(LSCharacteristicType)characteristicType error:(LSWiBeatError)error;

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
        pmConnection = [[LSWiBeatConnection alloc] initWithDeviceMACAddress:@"xx:xx:xx:xx:xx:xx" delegate:self];
        if (pmConnection) {
            [pmConnection connect];
        }
    }
 
    -(void)wiBeatConnectionDidConnect:(LSWiBeatConnection *)wiBeatConnection {
        //After connection we can write or read GATT characteristic's values
        [pmConnection readBatteryLevel:self];
        [pmConnection writeAdvertisingInterval:200 delegate:self];
    }
 
    -(void)wiBeatReadCharacteristicSuccess:(LSWiBeatCharacteristic *)characteristic {
        //After value of characteristic was read
    }
 
    -(void)wiBeatWriteCharacteristicSuccess:(LSCharacteristicType)characteristicType {
        //After new value of characteristic was written
    }
 
    -(void)disconnect {
        [pmConnection disconnect];
    }
 
    -(void)wiBeatConnectionDidDisconnect:(LSWiBeatConnection *)wiBeatConnection {
        //After application was disconnected from WiBeat
    }
 */
@interface LSWiBeatConnection : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate>

/** Time in seconds - maximum time of scanning */
@property NSNumber *scanInterval;

/** MAC address of peripheral*/
@property NSString *deviceMACAddress;

/** Bounded peripheral*/
@property CBPeripheral *peripheral;

/**
 Construct new connection to WiBeat
 @param newDeviceMACAddress should be in format XX:XX:XX:XX:XX:XX in any register
 */
- (id)initWithDeviceMACAddress:(NSString*)newDeviceMACAddress delegate:(id<LSWiBeatConnectionDelegate>)newDelegate;

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
 * The successful result of the read operation is returned by the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * <p>
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param characteristic CBCharacteristic to read from the remote device
 * @param newReadDelegate The read delegate
 * @see CBCharacteristic
 */
- (void)readCharacteristic:(CBCharacteristic*)characteristic delegate:(id<LSWiBeatReadCharacteristicDelegate>)newReadDelegate;

/**
 * Reads battery level characteristic.
 *
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readBatteryLevel:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads TX power characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readTxPower:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads firmware version characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readFirmwareVersion:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads temperature characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readTemperature:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads URL characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readURL:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads advertising interval characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readAdvertisingInterval:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads major ID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readMajor:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads minor ID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readMinor:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads device ID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readDeviceID:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads network ID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readNetworkID:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads operation mode characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readOperationMode:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads serial characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readSerial:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads vendor characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readVendor:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads model characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readModel:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads UUID characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readUUID:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads all available characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadDeviceInfoDelegate wiBeatReadDeviceInfoSuccess:deviceInfo] callback.
 * If error occurred, the [LSWiBeatReadDeviceInfoDelegate wiBeatReadDeviceInfoError:error:] callback is triggered.
 * @param delegate LSWiBeatReadDeviceInfoDelegate The read delegate
 * @see LSWiBeatReadDeviceInfoDelegate
 */
- (void)readDeviceInfo:(id<LSWiBeatReadDeviceInfoDelegate>) delegate;

#pragma mark - Write

/**
 * Write a given characteristics to the remote device.
 * <p>
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is triggered,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:]  callback is triggered.
 * @param characteristic Characteristic to write
 * @param dataValue New characteristic value
 * @param newWriteDelegate The write delegate
 * @see CBCharacteristic
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeCharacteristic:(CBCharacteristic*)characteristic dataValue:(NSData*)dataValue delegate:(id<LSWiBeatWriteCharacteristicDelegate>)newWriteDelegate;

/**
 * Write TX power characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New TX power value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeTxPower:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

/**
 * Write URL characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New URL value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeURL:(NSString*)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

/**
 * Write advertising interval characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New advertising interval value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeAdvertisingInterval:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

/**
 * Write major ID characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New major ID value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeMajor:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

/**
 * Write minor ID characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New minor ID value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeMinor:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

/**
 * Write device ID characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New device ID value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeDeviceID:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

/**
 * Write network ID characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New network ID value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeNetworkID:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

/**
 * Write operation mode characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New operation mode value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeOperationMode:(LSOperationMode)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

@end





