//
//  LSEddystoneURLData.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 11/25/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSEddystoneBaseData.h"

/**
 * Represents data from ADV slot data characteristic in SLOT_DATA_URL mode
 */
@interface LSEddystoneURLData : LSEddystoneBaseData

/**
 * Advertisement TX power
 */
@property (readonly) NSInteger advTxPower;

/**
 * Represents advertised URL
 */
@property (readonly) NSString *url;

@end
