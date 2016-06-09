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
 *  If LSRegion is inside of CLRegion
 */
@property BOOL insideCLRegion;

/**
 *  Instantiates LSRegionWrapper object
 *
 *  @param region LSRegion
 *
 *  @return instancetype LSRegionWrapper
 */
- (instancetype)initWithRegion:(LSRegion*)region;

@end
