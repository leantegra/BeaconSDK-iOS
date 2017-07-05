//
//  LSLocationObjectProtocol.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 4/7/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LSVenueObjectType) {
    LSVenueObjectTypeUndefined = 0,
    LSVenueObjectTypeWiBeat,
    LSVenueObjectTypeFloor,
    LSVenueObjectTypeZone,
    LSVenueObjectTypePassage,
    LSVenueObjectTypeStairs,
    LSVenueObjectTypeElevator,
    LSVenueObjectTypeDoor
};

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
@property (readonly) NSArray <NSNumber *> *parents;

/**
 * Represents parent
 */
@property (readonly) NSDictionary *dictionaryRepresentation;

/**
 * Type of Venue object
 */
@property (nonatomic, assign) LSVenueObjectType type;

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
