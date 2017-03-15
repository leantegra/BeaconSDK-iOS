//
//  LSTLMFrame.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 12/21/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseFrame.h"

@interface LSTLMFrame : LSBaseFrame

/**
 * TLM version
 */
@property (readonly) NSInteger tlmVersion;

/**
 * Battery voltage
 */
@property (readonly) NSInteger batteryVoltage;

/**
 * Battery level
 */
@property (readonly, nonatomic) float batteryLevel;

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

- (instancetype)initWithData:(NSData*)data;

///Must use initWithData: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithData: instead.")));

@end
