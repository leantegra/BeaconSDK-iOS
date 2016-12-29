//
//  LSEddystoneTLMData.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 11/25/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSEddystoneBaseData.h"

/**
 * Represents data from ADV slot data characteristic in SLOT_DATA_TLM mode
 */
@interface LSEddystoneTLMData : LSEddystoneBaseData

/**
 * TLM version
 */
@property (readonly) NSInteger tlmVersion;

/**
 * Battery voltage
 */
@property (readonly) NSInteger batteryVoltage;

/**
 * Temperature
 */
@property (readonly) float temperature;

/**
 * Advertisement counter from last WiBeat rebooting
 */
@property (readonly) NSInteger advertisementCounter;

/**
 * Seconds counter from last WiBeat rebooting
 */
@property (readonly) NSInteger secondCounter;


@end
