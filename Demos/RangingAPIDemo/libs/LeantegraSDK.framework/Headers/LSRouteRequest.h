//
//  LSRouteRequest.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 6/29/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LSRoutePoint;

NS_ASSUME_NONNULL_BEGIN

@interface LSRouteRequest : NSObject

/**
 * Start point of Route request.
 */
@property (nonatomic, strong, readonly) LSRoutePoint *startPoint;

/**
 * End point of Route request.
 */
@property (nonatomic, strong, readonly) LSRoutePoint *endPoint;

/**
 * Returns LSRouteRequest object with specified startPoint and endPoint.
 */
+ (LSRouteRequest *)routeRequestWithStartRoutePoint:(LSRoutePoint *)startPoint endRoutePoint:(LSRoutePoint *)endPoint;

/**
 * Unavailable. Use the -[initWithStartRoutePoint:endRoutePoint:] Designated Initializer
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Designated Initializer
 * Initializes the LSRouteRequest object with specified startPoint and endPoint.
 */
- (instancetype)initWithStartRoutePoint:(LSRoutePoint *)startPoint endRoutePoint:(LSRoutePoint *)endPoint NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
