//
//  LSWiBeat.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 12/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSLocationObjectProtocol.h"

@interface LSWiBeat : NSObject <LSLocationObject>

/**
 * Represents major
 */
@property (readonly) NSNumber *major;

/**
 * Represents minor
 */
@property (readonly) NSNumber *minor;

/**
 * Represents uuid
 */
@property (readonly) NSString *uuid;

/**
 * Represents MAC
 */
@property (readonly) NSString *mac;


///Must use initWithDictionary: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithDictionary: instead.")));

@end
