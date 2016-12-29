//
//  LSZone.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 12/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSZone : NSObject

/**
 * Represents GeoJson data
 */
@property (readonly) NSDictionary *geojson;

/**
 * Represents UID
 */
@property (readonly) NSInteger uid;

/**
 * Represents name
 */
@property (readonly) NSString *name;

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
