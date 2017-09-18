//
//  LSVenue.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 7/10/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LSVenue : NSObject

/**
 * Represents UID
 */
@property (readonly, assign) NSInteger uid;

/**
 * Represents rotation angle for venue about the North-South line
 */
@property (readonly, assign) float rotation;

/**
 * Represents venue name
 */
@property (readonly, strong) NSString *name;

/**
 * Represents path to OSM map on the server
 */
@property (nullable, readonly, strong) NSString *OSMMapPath;

/**
 * Returns all stored venue
 */
+ (nullable NSArray<LSVenue *> *)venues;

+ (void)loadVenuesWithCompletion:(void (^_Nullable)(NSError *_Nullable))completion;

/**
 *  Initialise object using NSDictionary from with @"uid" key and NSNumber value
 *
 *  @param dictionary NSDictionary
 *
 *  @return initialized object
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/// Must use initWithDictionary: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithDictionary: instead.")));

/// Save object state into NSDictonary
- (NSDictionary *)convertToDictonary;

NS_ASSUME_NONNULL_END

@end
