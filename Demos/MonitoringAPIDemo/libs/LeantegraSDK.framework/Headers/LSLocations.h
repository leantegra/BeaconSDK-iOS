//
//  LSLocations.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 12/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSFloor.h"
#import "LSPassage.h"
#import "LSZone.h"

@interface LSLocations : NSObject

/**
 * List of LSFloor
 */
@property (readonly) NSArray<LSFloor*>* floors;

/**
 * List of LSPassage
 */
@property (readonly) NSArray<LSPassage*>*passages;

/**
 * List of LSZone
 */
@property (readonly) NSArray<LSZone*>*zones;

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
