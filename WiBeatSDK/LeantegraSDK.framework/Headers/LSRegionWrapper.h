//
//  LSRegionWrapper.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 5/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "LSRegion.h"

@class LSBaseFrame;

/**
 *  Keeps monitoring state of region
 */
@interface LSRegionWrapper : NSObject

/**
 *  Represents LSRegion
 */
@property LSRegion *region;

/**
 *  What last callback was send to delegates
 */
@property CLRegionState notifiedRegion;

/**
 *  Last time any of frames of this region had been visible
 */
@property NSTimeInterval lastTimeWasVisible;

/**
 *  First frame received in this region
 */
@property LSBaseFrame*enterFrame;

/**
 *  Instantiates LSRegionWrapper object
 *
 *  @param region LSRegion
 *
 *  @return instancetype LSRegionWrapper
 */
- (instancetype)initWithRegion:(LSRegion*)region;

@end
