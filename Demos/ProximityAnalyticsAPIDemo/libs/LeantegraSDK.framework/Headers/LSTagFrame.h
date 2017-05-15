//
//  LSTagFrame.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/28/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseFrame.h"

/**
 * Represents Location Tag advertising frame of WiBeat.
 * @see LSBaseFrame
 */
@interface LSTagFrame : LSBaseFrame

/**
 *  Represents network ID
 */
@property NSInteger networkId;

/**
 *  Represents device ID
 */
@property NSInteger deviceId;

@end
