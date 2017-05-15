//
//  LSLocationObjectProtocol.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 4/7/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LSLocationObject <NSObject>

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
 *  Initialise object using NSDictionary from [LSCmsClient locations:fail:] response
 *
 *  @param dictionary NSDictionary
 *
 *  @return initialized object
 */
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;

@end

@protocol LSAccessibleLocationObject <LSLocationObject>

/**
 * Represents access
 */
@property (readonly) NSString *access;

@end
