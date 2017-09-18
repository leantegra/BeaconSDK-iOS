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

/**
 * Curve option for LSRouteRequest
 * If YES - generated route will have curved stroke
 */
extern NSString *const kLSRouteRequestCurveRoute;

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
 * Options for route request. See available keys on top.
 */
@property (nonatomic, strong, readonly) NSDictionary *options;

/**
 * Returns LSRouteRequest object with specified startPoint and endPoint.
 */
+ (LSRouteRequest *)routeRequestWithStartRoutePoint:(LSRoutePoint *)startPoint endRoutePoint:(LSRoutePoint *)endPoint options:(nullable NSDictionary *)options;

/**
 * Unavailable. Use the -[initWithStartRoutePoint:endRoutePoint:] Designated Initializer
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Designated Initializer
 * Initializes the LSRouteRequest object with specified startPoint and endPoint.
 */
- (instancetype)initWithStartRoutePoint:(LSRoutePoint *)startPoint endRoutePoint:(LSRoutePoint *)endPoint options:(nullable NSDictionary *)options NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
