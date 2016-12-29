//
//  LSADVSlotData.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 11/25/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSWiBeatEnums.h"

/**
 * Represents data in ADV slot data characteristic
 */
 @interface LSEddystoneBaseData : NSObject

/**
 * Represents Eddystone frame type
 * @see LSADVSlotDataType
 */
@property (readonly) LSADVSlotDataType frameType;

- (instancetype)initWithData:(NSData*)data;

///Must use initWithData: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithData: instead.")));

@end
