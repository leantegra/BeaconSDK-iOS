//
//  LSFirmwareUpdater.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 8/17/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LSFirmwareUpdater;
@class LSWiBeatConnection;
@class LSFirmware;
@class CBUUID;

NS_ASSUME_NONNULL_BEGIN

@protocol LSFirmwareUpdaterDelegate <NSObject>

/*
 * Called when LSFirmwareUpdater getting the unlock challenge.
 * Return nil to interrupt the firmware updating process.
*/
- (nullable CBUUID *)unlockCodeForFirmwareUpdater:(LSFirmwareUpdater *)firmwareUpdater;

/*
 * Called when -[LSFirmwareUpdater loadFirmware] successfully completes. From now you can start Firmware Update
*/
- (void)firmwareUpdater:(LSFirmwareUpdater *)firmwareUpdater didLoadFirmware:(LSFirmware *)firmware;

/*
 * Called when LSFirmwareUpdater gets the error
*/
- (void)firmwareUpdater:(LSFirmwareUpdater *)firmwareUpdater didOccuredError:(NSError *)error;

/*
 * Called when LSFirmwareUpdater finishes the Firmware Update.
*/
- (void)firmwareUpdater:(LSFirmwareUpdater *)firmwareUpdater didUpdateFirmware:(LSFirmware *)firmware;

/*
 * Called right before LSFirmwareUpdater will delete old Firmware.
*/
- (void)firmwareUpdaterWillEraseFirmware:(LSFirmwareUpdater *)firmwareUpdater;

/*
 * Called right before LSFirmwareUpdater will send the first frame of new Firmware.
*/
- (void)firmwareUpdaterWillSendFirmware:(LSFirmwareUpdater *)firmwareUpdater;

/*
 * Called before each frame of Firmware image sending during the Firmware update.
*/
- (void)firmwareUpdater:(LSFirmwareUpdater *)firmwareUpdater willSendFrame:(NSInteger)frameNumber ofTotal:(NSInteger)totalFramesCount;

@end

@interface LSFirmwareUpdater : NSObject

/*
 * Delegate that receives LSFirmwareUpdaterDelegate protocol callbacks.
*/
@property (nullable, nonatomic, weak) id<LSFirmwareUpdaterDelegate> delegate;

/*
 * MAC address of device to be updated.
*/
@property (nonatomic, strong, readonly) NSString *MACAddress;

/*
 * LSFirmware object that represents the Firmware to be send on the WiBeat.
*/
@property (nullable, nonatomic, strong) LSFirmware *firmware;

/*
 * If MAC address is not valid, LSFirmwareUpdater will not initialized.
*/
- (nullable instancetype)initWithMACAddress:(NSString *)address;

/*
 * After setting the firmware, calling this will cause the verification procedures of loaded LSFirmware. 
 * After successfull completion, -[id<LSFirmwareUpdaterDelegate> firmwareUpdater: didLoadFirmware:]. 
 * If error occured, -[id<LSFirmwareUpdaterDelegate> firmwareUpdater: didOccuredError:]
*/
- (void)loadFirmware;

/*
 * Starts the Firmware Update procedure. You responsible to have no active connections to the WiBeat before calling this and during the update process! 
 * If error occured, -[id<LSFirmwareUpdaterDelegate> firmwareUpdater: didOccuredError:]
*/
- (void)startFirmwareUpdate;

@end

NS_ASSUME_NONNULL_END
