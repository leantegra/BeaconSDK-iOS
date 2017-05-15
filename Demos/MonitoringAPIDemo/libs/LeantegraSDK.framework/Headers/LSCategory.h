//
//  LSCategory.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 4/26/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSCategory : NSObject

/**
 * Represents UID
 */
@property (readonly) NSInteger uid;

/**
 * Represents name
 */
@property (readonly) NSString *name;

/**
 * Represents the date of category creation
 */
@property (readonly) NSDate *creationDate;

/**
 * Represents the date of category modifying
 */
@property (readonly) NSDate *modifiedDate;

/**
 *  Initialise object using NSDictionary from [LSCmsClient categories:fail:] response
 *
 *  @param dictionary NSDictionary
 *
 *  @return initialized object
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

///Must use initWithDictionary: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithDictionary: instead.")));

+ (LSCategory *)categoryForCategoryUID:(NSInteger)uid;

@end
