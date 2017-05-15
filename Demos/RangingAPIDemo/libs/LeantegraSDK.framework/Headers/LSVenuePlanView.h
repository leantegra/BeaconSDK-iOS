//
//  LSVenuePlanView.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 4/6/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LSFloor.h"
#import "LSZone.h"
#import "LSPassage.h"

@class LSVenuePlanView;

extern NSInteger const kLSNoFloorsDataVenuePlanError;

typedef NS_OPTIONS(NSUInteger, LSVenuePlanPaintingLayerOptions) {
    LSVenuePlanFloorImageLayer = (1 << 0), // Not Implemented yet
    LSVenuePlanFloorShapeLayer = (1 << 1),
    LSVenuePlanZoneShapeLayer = (1 << 2),
    LSVenuePlanPassageShapeLayer = (1 << 3),
    LSVenuePlanOffersShapeLayer = (1 << 4)
};

NS_ASSUME_NONNULL_BEGIN

@protocol LSVenuePlanViewDelegate <NSObject>

/**
 * Specifies the layers, that should be displayed on the Venue Plan.
 * Look for <code>LSVenuePlanPaintingLayerOptions</code> for supported options.
 */
- (LSVenuePlanPaintingLayerOptions)displayingOptionsForVenuePlanView:(LSVenuePlanView *)venuePlanView;

@optional

/**
 * Indicates, when Venue Plan did finish load from it's cache or is updated from CVO Portal.
 * Select the floor to display here.
 */
- (void)didUpdateVenuePlanView:(LSVenuePlanView *)venuePlanView error:(nullable NSError *)error;

// Offer image
- (UIImage *)imageForOfferID:(NSNumber *)offerID;

// Venue objects colors
- (UIColor *)fillColorForFloor:(LSFloor *)floor;
- (UIColor *)strokeColorForFloor:(LSFloor *)floor;
- (UIColor *)fillColorForZone:(LSZone *)zone;
- (UIColor *)strokeColorForZone:(LSZone *)zone;
- (UIColor *)fillColorForPassage:(LSPassage *)passage;
- (UIColor *)strokeColorForPassage:(LSPassage *)passage;
- (UIColor *)backgroundColorForVenuePlan;

// Venue objects sizes. Return CGFloat wrapped in NSNumber
- (NSNumber *)strokeWidthForFloor:(LSFloor *)floor;
- (NSNumber *)strokeWidthForZone:(LSZone *)zone;
- (NSNumber *)strokeWidthForPassage:(LSPassage *)passage;

@end

@interface LSVenuePlanView : UIView

@property (nullable, nonatomic, weak) id<LSVenuePlanViewDelegate> delegate;

/**
 * A Boolean indicating whether the map displays a compass control.
 * Use this property to show or hide the control that lets users change the heading orientation of the map.
 * The default value of this property is NO.
  */
@property (nonatomic, assign) BOOL showsCompass;

/**
 * A Boolean indicating whether the map shows scale information.
 * The default value of this property is NO.
 */
@property (nonatomic, assign) BOOL showsScale;

/**
 * Returns current floor for venue. To change the floor, use <code>-[LSVenuePlanView setFloor:animatable:]</code>
 */
@property (nullable, nonatomic, readonly) LSFloor *currentFloor;

/**
 * Returns the list of venue's floors sorted by it's index.
 */
@property (nullable, nonatomic, readonly) NSArray <LSFloor *> *floors;

/**
 * Use this method for setting the floor to display
 * Floor that will be used to display
 * Should be a member of -[LSVenuePlanView floors]
 */
- (void)setFloor:(nullable LSFloor *)floor;

/**
 * Use this method for setting the offers IDs array to display.
 * LSVenuePlanOffersShapeLayer should be returned via -[id<LSVenuePlanViewDelegate> displayingOptionsForVenuePlanView:]
 * Set nil to display all offers on the floor.
 * Set empty array to indicate that no offers should be displayed
 */
- (void)setOffers:(nullable NSArray <NSNumber *> *)offers;

/**
 * Causes the force reloading of venue data from CVO Portal and redisplays the Venue Plan.
 * When finish, -[didUpdateVenuePlanView: error:] delegate method is called
 */
- (void)reloadData;

/**
 * Causes the loading of current venue data from cache and redisplays the Venue Plan.
 * When finish, -[didUpdateVenuePlanView: error:] delegate method is called
 */
- (void)redisplayVenuePlanAnimated:(BOOL)animated;

/**
 * Indicates, if venue is cached.
 */
- (BOOL)hasCachedVenuePlan;

NS_ASSUME_NONNULL_END

@end
