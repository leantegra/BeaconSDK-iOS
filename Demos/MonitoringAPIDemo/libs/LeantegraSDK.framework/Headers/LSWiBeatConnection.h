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

@class LSWiBeatConnection;

//Common service characteristics
/**Status*/
#define LS_STATUS @"2C00"
/**Firmware version characteristic type.*/
#define LS_FIRMWARE_VERSION @"2A26"
/**Serial number characteristic type.*/
#define LS_SERIAL @"2A25"

//iBeacon service characteristics
/**Proximity UUID.*/
#define LS_UUID @"2B98"
/**Major ID characteristic type.*/
#define LS_MAJOR @"2B9A"
/**Minor ID characteristic type.*/
#define LS_MINOR @"2BF8"

//Eddystone service characteristics
/**Capabilities*/
#define LS_CAPABILITIES @"A3C87501-8ED3-4BDF-8A39-A01BEBEDE295"
/**Active slot*/
#define LS_ACTIVE_SLOT @"A3C87502-8ED3-4BDF-8A39-A01BEBEDE295"
/**Advertising interval characteristic type.*/
#define LS_ADVERTISING_INTERVAL @"A3C87503-8ED3-4BDF-8A39-A01BEBEDE295"//@"2B55"
/**Radio TX power characteristic type.*/
#define LS_RADIO_TX_POWER @"A3C87504-8ED3-4BDF-8A39-A01BEBEDE295"
/**Advertised Tx Power*/
#define LS_ADVERTISED_TX_POWER @"A3C87505-8ED3-4BDF-8A39-A01BEBEDE295"
/**Lock state*/
#define LS_LOCK_STATE @"A3C87506-8ED3-4BDF-8A39-A01BEBEDE295"
/**EID identity key*/
#define LS_EID_IDENTITY_KEY @"A3C87509-8ED3-4BDF-8A39-A01BEBEDE295"
/**ADV slot data*/
#define LS_ADV_SLOT_DATA @"A3C8750A-8ED3-4BDF-8A39-A01BEBEDE295"
/**Factory reset*/
#define LS_FACTORY_RESET @"A3C8750B-8ED3-4BDF-8A39-A01BEBEDE295"
/**Remain connectable*/
#define LS_REMAIN_CONNECTABLE @"A3C8750C-8ED3-4BDF-8A39-A01BEBEDE295"

/**Temperature characteristic type.*/
#define LS_TEMPERATURE @"2B6E"


/**Vendor name characteristic type.*/
#define LS_VENDOR @"0"
/**Model name characteristic type.*/
#define LS_MODEL @"0"


/**URL characteristic type.*/
#define LS_URL @"2084"


//Tag
/**Adv data (Device ID, Network ID)*/
#define LS_ADV_DATA @"2B00"


/**
 * Provides callbacks indicating whether connection state changed.
 * @see LSWiBeatConnection
 */
@protocol LSWiBeatConnectionDelegate <NSObject>

/**
 * Callback invoked when device established connection with WiBeat.
 * @param wiBeatConnection current connection
 */
- (void)wiBeatConnectionDidConnect:(LSWiBeatConnection*)wiBeatConnection;

/**
 * Callback invoked when device is disconnected from WiBeat.
 * @param wiBeatConnection current connection
 * @param error occured error
 */
- (void)wiBeatConnectionDidDisconnect:(LSWiBeatConnection*)wiBeatConnection error:(NSError*)error;

/** Calls when code can't process correctly any method
 * @param wiBeatConnection current connection
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
 * @param characteristicType current characteristic
 */
- (void)wiBeatWriteCharacteristicSuccess:(LSCharacteristicType)characteristicType;

/**
 * Callback invoked when characteristic writing has been failed.
 * @param characteristicType current characteristic
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
        [pmConnection readDeviceStatus:self];
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

/**
 * Connection status
 */
- (BOOL)isConnected;

/**
 * Lock WiBeat with the same key
 */
- (void)lock:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 * Lock WiBeat with new key
 */
- (void)lockWithNewKey:(CBUUID*)newKey oldKey:(CBUUID*)oldKey delegate:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 *  Disable automatic relocking
 */
- (void)disableAutomaticRelocking:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 *  Unlock WiBeat
 */
- (void)unlockWithLockCode:(NSUUID*)lockCode delegate:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

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
 * Reads Radio TX power characteristic.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readRadioTxPower:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

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
 * Reads device capabilities characteristic from the associated WiBeat.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 * @since 1.3.0
 */
- (void)readCapabilities:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads active slot characteristic from the associated WiBeat.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 * @since 1.3.0
 */
- (void)readActiveSlot:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

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
 * Reads device status characteristic from the associated WiBeat.
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readDeviceStatus:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads advertised TX power characteristic from the associated WiBeat.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 * @since 1.3.0
 */
- (void)readAdvertisedTxPower:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads lock state.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 * @since 1.3.0
 */
- (void)readLockState:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads EID identity key.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 * @since 1.3.0
 */
- (void)readEIDIdentityKey:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Reads ADV slot data.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadDeviceInfoDelegate wiBeatReadDeviceInfoSuccess:deviceInfo] callback.
 * If error occurred, the [LSWiBeatReadDeviceInfoDelegate wiBeatReadDeviceInfoError:error:] callback is triggered.
 * @param delegate LSWiBeatReadDeviceInfoDelegate The read delegate
 * @see LSWiBeatReadDeviceInfoDelegate
 */
- (void)readActiveAdvSlotData:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

/**
 * Remain Connectable. >0 - non-connectable capability supported; 0 - not supported.
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadDeviceInfoDelegate wiBeatReadDeviceInfoSuccess:deviceInfo] callback.
 * If error occurred, the [LSWiBeatReadDeviceInfoDelegate wiBeatReadDeviceInfoError:error:] callback is triggered.
 * @param delegate LSWiBeatReadDeviceInfoDelegate The read delegate
 * @see LSWiBeatReadDeviceInfoDelegate
 */
- (void)readRemainConnectable:(id<LSWiBeatReadCharacteristicDelegate>) delegate;


#pragma mark - Read Tag

/**
 * Reads TAG adv data (Network and device ID).
 * <p>
 * This is an asynchronous operation. The result of the read operation is reported by the
 * [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristicSuccess:] callback.
 * If error occurred, the [LSWiBeatReadCharacteristicDelegate wiBeatReadCharacteristic:error:] callback is triggered.
 * @param delegate LSWiBeatReadCharacteristicDelegate The read delegate
 * @see LSWiBeatReadCharacteristicDelegate
 * @see LSWiBeatCharacteristic
 */
- (void)readAdvData:(id<LSWiBeatReadCharacteristicDelegate>) delegate;

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
 * Write Radio TX power characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New Radio TX power value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 */
- (void)writeRadioTxPower:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

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

/**
 * Write button lock characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param  value New button lock value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)writeButtonLock:(BOOL)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

/**
 * Write led test characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New led test value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)writeLedTest:(BOOL)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>) delegate;

/**
 * Write device status characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param mode New operation mode value
 * @param buttonLock New operation mode value
 * @param ledTest New operation mode value
 * @param newDelegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @see OperationMode#I_BEACON I_BEACON
 * @see OperationMode#EDDYSTONE_URL EDDYSTONE_URL
 * @see OperationMode#HYBRID HYBRID
 * @see OperationMode#TAG TAG
 * @since 1.3.0
 */
- (void)writeDeviceStatusWithMode:(LSOperationMode)mode buttonLock:(LSSettingCapabilities)buttonLock ledTest:(LSSettingCapabilities)ledTest delegate:(id<LSWiBeatWriteCharacteristicDelegate>)newDelegate;
/**
 * Write active slot characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New active slot value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)writeActiveSlot:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 * Write advertised TX power characteristic.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New advertised TX power value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)writeAdvertisedTxPower:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 * Write TLM frame in advertised slot data
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)writeTLMinActiveAdvSlotWithDelegate:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 * Write UID frame in advertised slot data
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param nid nid data for advertisement frames
 * @param bid bid data for advertisement frames
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)writeUIDinActiveAdvSlotWithNid:(NSInteger)nid bid:(NSInteger)bid delegate:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 * Write URL frame in advertised slot data
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param url url for advertisement frames
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)writeURLinActiveAdvSlotWithURL:(NSString*)url delegate:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 * Write EID frame in advertised slot data
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param identityKey key 16-byte encrypted Identify key array
 * @param exponent exponent
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)writeEIDinActiveAdvSlotWithIdentityKey:(NSData*)identityKey exponent:(NSInteger)exponent delegate:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 * Set all WiBeat's characteristics to factory values, except Serial Number, GATT Lock Code, Identification mode
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)factoryReset:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

/**
 * Write Remain connectable characteristic.  >0 - remain in connectable mode until 0 will be written.
 * <p>
 * This is an asynchronous operation.
 * Once the write operation has been completed successfully, the
 * [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristicSuccess:] callback is invoked,
 * otherwise [LSWiBeatWriteCharacteristicDelegate wiBeatWriteCharacteristic:error:] callback is triggered.
 * @param value New connectable value
 * @param delegate Write delegate
 * @see LSWiBeatWriteCharacteristicDelegate
 * @since 1.3.0
 */
- (void)writeRemainConnectable:(NSInteger)value delegate:(id<LSWiBeatWriteCharacteristicDelegate>)delegate;

@end





