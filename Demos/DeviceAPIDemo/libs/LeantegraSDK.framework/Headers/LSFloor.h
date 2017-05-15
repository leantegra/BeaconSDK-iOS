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

///Must use initWithDictionary: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithDictionary: instead.")));

@end
