//
//  LSEddystoneUIDData.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 11/25/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSEddystoneBaseData.h"

/**
 * Represents data from ADV slot data characteristic in SLOT_DATA_UID mode
 */
@interface LSEddystoneUIDData : LSEddystoneBaseData

/**
 * Advertisement TX power.
 */
@property (readonly) NSInteger advTxPower;

/**
 * Namespace
 */
@property (readonly) NSInteger nid;

/**
 * Instance
 */
@property (readonly) NSInteger bid;

@end
