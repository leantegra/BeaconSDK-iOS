//
//  LSVenuePlanView.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 4/6/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

@class LSFloor, LSPassage, LSZone, LSRouteRequest, LSRoute, LSVenuePlanView;

typedef NS_ENUM(NSUInteger, LSVenuePlanSourceType) {
    LSVenuePlanSourceDefault,
    LSVenuePlanSourceGeoJSON,
    LSVenuePlanSourceOSM,
    LSVenuePlanSourceMixed
};

typedef NS_OPTIONS(NSUInteger, LSVenuePlanPaintingLayerOptions) {
    LSVenuePlanFloorImageLayer = (1 << 0),
    LSVenuePlanFloorShapeLayer = (1 << 1),
    LSVenuePlanZoneShapeLayer = (1 << 2),
    LSVenuePlanPassageShapeLayer = (1 << 3),
    LSVenuePlanOffersShapeLayer = (1 << 4)
};

NS_ASSUME_NONNULL_BEGIN

@protocol LSVenuePlanViewDelegate <MKMapViewDelegate>

/**
 * Specifies the layers, that should be displayed on the Venue Plan.
 * Look for <code>LSVenuePlanPaintingLayerOptions</code> for supported options.
 */
- (LSVenuePlanPaintingLayerOptions)displayingOptionsForVenuePlanView:(LSVenuePlanView *)venuePlanView;

@optional

/**
 * Get called, when there are several floors candidate to be displayed.
 * For example: when calling -[LSVenuePlanView setOffers:], if passed offer's connected wiBeats are located on several floors,
 * delegate should decide, which floor should be displayed.
 * @return - Should return one of the passed floorUIDs as the result.
 */
- (NSNumber *)venuePlanViewShouldSelectFloorWithinCandidates:(NSSet <NSNumber *> *)floorUIDs;

/**
 * Informs delegate about the completed route request.
 * This method is required, if -[LSVenuePlanView performRouteRequest] is used!
 */
- (void)venuePlanView:(LSVenuePlanView *)venuePlanView didPerformRouteRequest:(LSRouteRequest *)routeRequest result:(nullable LSRoute *)route error:(nullable NSError *)error;

/**
 * Indicates, when Venue Plan did finish load from it's cache or is updated from CVO Portal.
 * Select the floor to display here.
 * You should rely on this callback instead of MKMapViewDelegate methods:
 * -[id<MKMapViewDelegate> mapViewWillStartLoadingMap:]
 * -[id<MKMapViewDelegate> mapViewDidFinishLoadingMap:]
 * -[id<MKMapViewDelegate> mapViewDidFailLoadingMap:withError:]
 * -[id<MKMapViewDelegate> mapViewDidFinishRenderingMap:fullyRendered:]
 */
- (void)didUpdateVenuePlanView:(LSVenuePlanView *)venuePlanView error:(nullable NSError *)error;

/**
 * When userLocation == YES, this will be called on user location update (normally, once per 1 sec.).
 * You should rely on this callback instead of MKMapViewDelegate methods:
 * -[id<MKMapViewDelegate> mapView:didUpdateUserLocation:]
 * -[id<MKMapViewDelegate> mapView:didFailToLocateUserWithError:]
 * @param location CLLocation object with user's longitude and altitude
 * @param floor UID of floor, that user is located on. Determined by the shortest average distance to wiBeats on particular floor.
 * @param error Any error during the locating of user
 */
- (void)didUpdateUserLocation:(nullable CLLocation *)location floor:(nullable LSFloor *)floor error:(nullable NSError *)error;

// Offer image
- (UIImage *)imageForOfferID:(NSNumber *)offerID;

// User image
- (UIImage *)imageForUser;

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

@interface LSVenuePlanView : MKMapView

@property (nullable, nonatomic, weak) id<LSVenuePlanViewDelegate> delegate;

/**
 * By default LSVenuePlanSourceGeoJSON will be used.
 * For LSVenuePlanSourceGeoOSM, make sure that OSMData has valid OSM XML data.
 */
@property (nonatomic, assign) LSVenuePlanSourceType sourceType;

/**
 * NSUTF8StringEncoding XML data of OSM venue representation.
 */
@property (nonatomic, strong) NSData *OSMData;

/**
 * Returns current floor for venue. To change the floor, use <code>-[LSVenuePlanView setFloor:]</code> and then call
 * -[LSVenuePlanView redisplayVenuePlanAnimated:] or -[LSVenuePlanView reloadData]
 */
@property (nullable, nonatomic, readonly) LSFloor *currentFloor;

/**
 * Returns the list of venue's floors sorted by it's index.
 */
@property (nullable, nonatomic, readonly) NSArray <LSFloor *> *floors;

/**
 * Indicates, if route request is scheduled.
 */
@property (nonatomic, assign, readonly) BOOL isRouteRequested;

/**
 * Set to YES to add the user location annotation to the venue plan and start updating its location. Location updates are performed by using Multilateration algorithm on visible WiBeats.
 * If not enough WiBeats are visible for locating the user, error code -2003 will be passed to -[id<LSVenuePlanViewDelegate> didUpdateUserLocation:error:] delegate callback and value of this property becomes NO
**/
@property (nonatomic) BOOL showsUserLocation;

/**
 * The annotation representing the user's location
**/
@property (nonatomic, readonly) MKUserLocation *userLocation;

/**
 * Listed layers will be selected as base values to calculate "sticky" map region, that should be displayed as default region.
 * When change this property, call -[LSVenuePlanView redisplayVenuePlanAnimated:resetCamera:] with resetCamera parameter set to YES to take effect
 * @remark
 * The following default values will be applied
 * 1. If delegate has LSVenuePlanFloorImageLayer as suboption returned by -[id<LSVenuePlanViewDelegate> displayingOptionsForVenuePlanView:] method, LSVenuePlanFloorImageLayer will be selected by default. Will not be applied, if rule #2 is true.
 * 2. If delegate has LSVenuePlanFloorShapeLayer as suboption returned by -[id<LSVenuePlanViewDelegate> displayingOptionsForVenuePlanView:] method, LSVenuePlanFloorShapeLayer will be selected by default. Rule #1 will be ignored.
 **/
 @property (nonatomic, assign) LSVenuePlanPaintingLayerOptions boundingRegionLayers;

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
 * @param animated If YES, animates redisplaying by changing the opacity
 * @param resetCamera If YES, changes the visible region of the map to fit the whole floor or offers rect, that were selected via -[LSVenuePlanView setOffers:] method. Also sets the max and min camera altitude. You should pass YES as the argument at the initial venue plan setup. If NO, no camera updates will be occured.
 */
- (void)redisplayVenuePlanAnimated:(BOOL)animated resetCamera:(BOOL)resetCamera;

/**
 * Indicates, if venue is cached.
 */
- (BOOL)hasCachedVenuePlan;

/**
 * Schedules a route request in background.
 * When complete, calls the -[id<LSVenuePlanViewDelegate> venuePlanView:didPerformRouteRequest:result:error:]
 */
- (void)performRouteRequest:(LSRouteRequest *)routeRequest;

/**
 * Declines the scheduled route request.
 */
- (void)cancelRouteRequest;

/**
 * Determines, if given floor supports Indoor Routing functionality.
 * If OSM representation exists for given floor, YES will be returned.
 */
- (BOOL)supportsRoutingForFloor:(LSFloor *)floor;

/**
 * Indicates, if venue contains OSM data.
 */
- (BOOL)hasOSMVenuePlan;

NS_ASSUME_NONNULL_END

@end
