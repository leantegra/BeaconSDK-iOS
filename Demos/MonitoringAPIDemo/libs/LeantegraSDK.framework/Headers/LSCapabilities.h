//
//  LSCapabilities.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 11/17/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSCapabilities : NSObject

/**
 * Get the version of this spec.
 * @return the version of this spec
 */
@property (readonly) NSInteger version;

/**
 * Get the maximum number of slots this beacon is capable of broadcasting concurrently,
 * inclusive of EID slots. This is the total number of advertisement frames the beacon is
 * capable of broadcasting concurrently.
 * @return the maximum number of slots
 */
@property (readonly) NSInteger maxSupportedTotalSlots;

/**
 * Get the maximum number of independent EID slots this beacon is capable of broadcasting.
 * @return the maximum number of independent EID slots
 */
@property (readonly) NSInteger maxSupportedEidSlots;

/**
 * Get the field encoding the following properties:
 * <br>
 * - LSCapabilitiesVariableSupported.IS_VARIABLE_ADV_SUPPORTED. Set if the beacon supports individual per-slot
 * advertising intervals. Not set if the beacon supports only a global advertising interval.
 * <br>
 * - LSCapabilitiesVariableSupported.IS_VARIABLE_TX_POWER_SUPPORTED. Set if the beacon supports individual per-slot Tx powers.
 * Not set if the beacon supports only a single global Tx power.
 * @return the value encoding variable values.
 */
@property (readonly) NSInteger variableSupported;

/**
 * Get the field encoding the supported frame types:
 * - LSCapabilitiesFrameType.UID
 * - LSCapabilitiesFrameType.URL
 * - LSCapabilitiesFrameType.TLM
 * - LSCapabilitiesFrameType.EID
 *
 * @return the value encoding the supported frame types
 */
@property (readonly) NSInteger supportedFrameTypes;

/**
 * Returns a variable length array of the supported radio Tx power absolute (dBm) values.
 * @return NSData with array of the supported radio Tx power values.
 */
@property (readonly) NSData *supportedRadioTxPower;

- (instancetype)initWithVersion:(NSInteger)version maxSupportedTotalSlots:(NSInteger)maxSupportedTotalSlots maxSupportedEidSlots:(NSInteger)maxSupportedEidSlots variableSupported:(NSInteger)variableSupported supportedFrameTypes:(NSInteger)supportedFrameTypes supportedRadioTxPower:(NSData*)supportedRadioTxPower;

///Must use initWithVersion:maxSupportedTotalSlots:maxSupportedEidSlots:variableSupported:supportedFrameTypes:supportedRadioTxPower: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithVersion:maxSupportedTotalSlots:maxSupportedEidSlots:variableSupported:supportedFrameTypes:supportedRadioTxPower: instead.")));

@end
