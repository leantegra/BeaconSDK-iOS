//
//  LSFloor.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 12/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSFloor : NSObject

/**
 * Represents GeoJson data
 */
@property (readonly) NSDictionary *geojson;

/**
 * Represents image link
 */
@property (readonly) NSString *image;

/**
 * Represents UID
 */
@property (readonly) NSInteger uid;

/**
 * Represents center coordinates
 */
@property (readonly) NSArray<NSNumber*> *center;

/**
 * Represents coefficient
 */
@property (readonly) double coefficient;

/**
 * Represents name
 */
@property (readonly) NSString *name;

/**
 * Represents index
 */
@property (readonly) NSInteger index;

/**
 * Represents parent
 */
@property (readonly) NSInteger parent;

/**
 * Represents access
 */
@property (readonly) NSString *access;

/**
 *  Initialise object using NSDictionary from [LSCmsClient locations:fail:] response
 *
 *  @param dictionary NSDictionary
 *
 *  @return initialized object
 */
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;

///Must use initWithDictionary: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithDictionary: instead.")));

@end
