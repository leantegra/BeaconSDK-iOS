//
//  LSTrackablePerson.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 7/24/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSTrackable.h"

@interface LSTrackablePerson : LSTrackable

/**
 * Represents the email address string
 */
@property (nullable, nonatomic, strong, readonly) NSString *email;

/**
 * Represents the last name
 */
@property (nullable, nonatomic, strong, readonly) NSString *lastName;

/**
 * Represents the phone number string
 */
@property (nullable, nonatomic, strong, readonly) NSString *phone;

/**
 * Schedules the async loading of trackable persons from CVO portal
 * @param completion block that is called whe the loading is finished with optionally passed error as an argument
 */
+ (void)loadTrackablePersonsWithCompletion:(void (^_Nullable)(NSError *_Nullable))completion;

+ (void)loadTrackablePerson:(nonnull NSNumber *)personUID completion:(void (^_Nullable)(NSError *_Nullable))completion;

/**
 * Schedules the sync load of trackable persons from cache, if any.
 */
+ (nullable NSArray<LSTrackablePerson *> *)trackablePersons;

/**
 * Schedules the sync load of specific trackable person from cache, if any.
*/
+ (nullable LSTrackablePerson *)trackablePersonForUID:(nonnull NSNumber *)trackableUID;

@end
