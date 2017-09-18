//
//  LSCloudEnums.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 6/8/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Local notification name in case of rules was changed
#define LSCMSRulesCacheContentWasChanged @"LSCMSRulesCacheContentWasChanged"

// String constants for content/view call
#define LSViewChannelTypeOfferList @"offer-list"
#define LSViewChannelTypeNotification @"notification"

#define LSGenderStringArray @[@"Any",@"Male",@"Female"]
#define LSDaysOfWeekStringArray @[@"Sun", @"Mon", @"Tue", @"Wed", @"Thu", @"Fri", @"Sat"]

/**
 *  Represents type of rule content
 */
typedef NS_ENUM(NSInteger, LSRuleContentType) {
    /**
     *  Image
     */
    LS_RULE_CONTENT_TYPE_IMAGE,
    /**
     *  URL
     */
    LS_RULE_CONTENT_TYPE_URL,
    /**
     *  Video
     */
    LS_RULE_CONTENT_TYPE_VIDEO
};

/**
 *  Represents frequency of notification
 */
typedef NS_ENUM(NSInteger, LSRuleFrequency) {
    /**
     *  Always
     */
    LS_RULE_FREQUENCY_ALWAYS,
    /**
     *  Only once
     */
    LS_RULE_FREQUENCY_ONLY_ONCE,
    /**
     *  Once every period (Period represents by LSEventOnceEveryPeriod enum)
     */
    LS_RULE_FREQUENCY_ONCE_EVERY
};

/**
 *  Represents event type
 */
typedef NS_ENUM(NSInteger, LSEventType) {
    /**
     *  On enter
     */
    LS_EVENT_TYPE_ENTER,
    /**
     *  On exit
     */
    LS_EVENT_TYPE_EXIT,
    /**
     *  Dwell time inside of region
     */
    LS_EVENT_TYPE_DWELL
};

/**
 Represents display mode
 */
typedef NS_ENUM(NSInteger, LSDisplayMode) {
    /**
     *  Event info will showed in offer list and in notification
     */
    LS_DISPLAY_MODE_EVERYWHERE,
    /**
     *  Event info will showed in offer list
     */
    LS_DISPLAY_MODE_IN_OFFER_LIST,
    /**
     *  Event info will showed in notification
     */
    LS_DISPLAY_MODE_AS_PUSH_NOTIFICATION
};

/**
 *  Represents gender
 */
typedef NS_ENUM(NSInteger, LSGender) {
    /**
     *  Any
     */
    LS_GENDER_ANY,
    /**
     *  Male
     */
    LS_GENDER_MALE,
    /**
     *  Female
     */
    LS_GENDER_FEMALE
};
