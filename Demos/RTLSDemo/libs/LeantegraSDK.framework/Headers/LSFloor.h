//
//  LSFloor.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 12/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSLocationObjectProtocol.h"

@interface LSFloor : NSObject <LSAccessibleLocationObject>

/**
 * Represents image link
 */
@property (readonly) NSString *image;

/**
 * Represents center coordinates
 */
@property (readonly) NSArray<NSNumber*> *center;

/**
 * Represents coefficient
 */
@property (readonly) double coefficient;

/**
 * Represents index
 */
@property (readonly) NSString *index;

/**
 * Represents coordinates of image. First pair - Left Top coords.
 * Second pair - Right Bottom coords.
 */
@property (readonly) NSArray <NSNumber *> *imageExtent;

///Must use initWithDictionary: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithDictionary: instead.")));

/**
 * Loads LSFloor object for a specific uid, if any
 */
+ (LSFloor *)floorForUID:(NSNumber *)uid;

@end
