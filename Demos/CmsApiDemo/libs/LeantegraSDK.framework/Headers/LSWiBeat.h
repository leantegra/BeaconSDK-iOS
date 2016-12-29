//
//  LSWiBeat.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 12/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSWiBeat : NSObject

/**
 * Represents GeoJson data
 */
@property (readonly) NSDictionary *geojson;

/**
 * Represents name
 */
@property (readonly) NSString *name;

/**
 * Represents parent
 */
@property (readonly) NSInteger parent;

/**
 * Represents uid
 */
@property (readonly) NSInteger uid;

/**
 * Represents major
 */
@property (readonly) NSInteger major;

/**
 * Represents minor
 */
@property (readonly) NSInteger minor;

/**
 * Represents uuid
 */
@property (readonly) NSString *uuid;

/**
 * Represents MAC
 */
@property (readonly) NSString *mac;

/**
 *  Initialise object using NSDictionary from [LSCmsClient devices:fail:] response
 *
 *  @param dictionary NSDictionary
 *
 *  @return initialized object
 */
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;

///Must use initWithDictionary: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithDictionary: instead.")));

@end
