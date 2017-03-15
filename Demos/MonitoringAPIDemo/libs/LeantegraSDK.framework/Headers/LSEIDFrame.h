//
//  LSEIDFrame.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 12/21/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseFrame.h"

@interface LSEIDFrame : LSBaseFrame

/**
 * Exponent
 */
@property (readonly) NSInteger exponent;

/**
 * Clock
 */
@property (readonly) NSInteger clock;

/**
 * EID value
 */
@property (readonly) NSData *eid;

- (instancetype)initWithData:(NSData*)data;

///Must use initWithData: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithData: instead.")));

@end
