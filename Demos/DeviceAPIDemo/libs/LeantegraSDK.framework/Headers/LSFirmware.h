//
//  LSFirmware.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 8/18/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LSFirmware : NSObject

/*
 * Represents the data contents of Firmware file
*/
@property (nonatomic, strong, readonly) NSData *firmwareFileData;

/*
 * Represents five digits separated by dots Firmware version string. For example: "1.3.0.0.32"
*/
@property (nonatomic, strong, readonly) NSString *firmwareVersion;

/*
 * Compares two Firmware version from WiBeat perspective.
*/
+ (NSComparisonResult)compareVersion:(NSString *)version1 withVersion:(NSString *)version2;

/*
 * Initializer for LSFirmware object.
*/
- (nullable instancetype)initWithFirmwareData:(NSData *)firmwareData;

NS_ASSUME_NONNULL_END

@end
