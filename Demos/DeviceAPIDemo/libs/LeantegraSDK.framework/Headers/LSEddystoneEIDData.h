//
//  LSEddystoneEIDData.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 11/25/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSEddystoneBaseData.h"

/**
 * Represents data from ADV slot data characteristic in SLOT_DATA_EID mode
 */
@interface LSEddystoneEIDData : LSEddystoneBaseData

/**
 * Exponent
 */
@property (readonly) NSInteger exponent;

/**
 * Clock
 */
@property (readonly) NSInteger clock;

/**
 * EID value
 */
@property (readonly) NSData *eid;

@end
