//
//  LSCMSRule.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 6/8/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSCloudEnums.h"

/**
 * Immutable representation of the event info stored in Leantegra CMS.
 *
 * @see [LSCmsClient allCMSRulesSuccess:fail:]
 * @see [LSCmsClient CMSRules:major:minor:proximityZone:address:success:fail:]
 */
@interface LSCMSRule : NSObject

/**
 *  Represents content type - image, URL or video
 *
 * @see LSEventContentType
 */
@property (readonly) LSRuleContentType contentType;

/**
 *  Represents event content URL
 */
@property (readonly) NSString *url;

/**
 *  Represents text in notification
 */
@property (readonly) NSString *notification;

/**
 *  Represents long notification text
 */
@property (readonly) NSString *notificationLong;

/**
 *  Represents barcode
 */
@property (readonly) NSString *barcode;

/**
 *  Represents Item Number
 */
@property (readonly) NSString *itemNumber;

/**
 *  Represents sticker
 */
@property (readonly) NSString *sticker;

/**
 *  Represents price
 */
@property (readonly) NSString *price;

/**
 *  Represents rule ID
 */
@property (readonly) NSInteger ruleId;

/**
 *  Represents period of event in seconds
 *
 */
@property (readonly) NSInteger onceEveryPeriod;

/**
 *  Represents event frequency
 *
 * @see LSRuleFrequency
 */
@property (readonly) LSRuleFrequency ruleFrequency;

/**
 *  Represents event type (enter, exit, dwell)
 *
 * @see LSEventType
 */
@property (readonly) LSEventType eventType;

/**
 Represents dwell time
 */
@property (readonly) NSInteger dwellTime;

/**
 Represents coupon ID
 */
@property (readonly) NSString *couponId;

/**
 Represents display mode
 */
@property (readonly) LSDisplayMode displayMode;

/**
 Represents gender
 */
@property (readonly) LSGender gender;

/**
 Represents minimal age
 */
@property (readonly) NSInteger minAge;

/**
 Represents maximal age
 */
@property (readonly) NSInteger maxAge;

/**
 Represents matrix of active/nonactive days
 */
@property (readonly) NSData *scheduleDays;

/**
 Represents schedule start time
 */
@property (readonly) NSInteger scheduleTimeStart;

/**
 Represents schedule end time
 */
@property (readonly) NSInteger scheduleTimeEnd;

/**
 If rule can be disposable
 */
@property (readonly) BOOL disposable;

/**
 If rule was already used
 */
@property (readonly) BOOL used;

/**
 Array of categories UIDs
 */
@property (readonly) NSArray *categoriesUIDs;

/**
 *  Initialise object using NSDictionary from [LSCmsClient allCMSRulesSuccess:fail:] or [LSCmsClient CMSRules:major:minor:proximityZone:address:success:fail:] response
 *
 *  @param dictionary NSDictionary
 *
 *  @return initialized object
 */
- (instancetype)initWithDictionary:(NSDictionary*)dictionary;

///Must use initWithDictionary: instead.
- (instancetype)init __attribute__((unavailable("Must use initWithDictionary: instead.")));

///Save object state into NSDictonary
-(NSDictionary*)convertToDictonary;

///Restore object from NSDictonary. Used for UILocalNotification to restore event info from userInfo.
- (instancetype)initWithNotificationDictionary:(NSDictionary*)dictionary;
@end
