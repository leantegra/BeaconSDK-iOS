//
//  LSCampaignEvent.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 10/18/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LSCampaignEventType) {
    LSCampaignEventTypeUnknown = 0,
    LSCampaignEventTypeViewed = 1,
    LSCampaignEventTypeUsed = 2,
    LSCampaignEventTypeDelivered = 3
};

NS_ASSUME_NONNULL_BEGIN

@interface LSCampaignEvent : NSObject

/**
 * Campaign event type.
 * @see LSCampaignEventType
 */
@property (nonatomic, assign) LSCampaignEventType eventType;

/**
 * Campaign event channel string. Specify the channel of incomed event (i.e. "Offer list, "Notification")
 */
@property (nonatomic, strong) NSString *channel;

/**
 * Rule ID, that corresponds to campaign event.
 */
@property (nonatomic, strong) NSNumber *ruleID;

/**
 * Time of occured event.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 * Initializes new object of LSCampaignEvent. Timestamp will be the time of calling this method.
 * @param eventType - campaign event type
 * @param ruleID - rule ID, that corresponds to campaign event.
 * @param channel - campaign event channel string
 */
- (instancetype)initWithType:(LSCampaignEventType)eventType ruleID:(NSNumber *)ruleID channel:(NSString *)channel;

/**
 * Initializes new object of LSCampaignEvent. Timestamp will be the time of calling this method. Designated initializer.
 * @param eventType - campaign event type
 * @param ruleID - rule ID, that corresponds to campaign event.
 * @param channel - campaign event channel string
 * @param timestamp - time of occured event.
 */
- (instancetype)initWithType:(LSCampaignEventType)eventType ruleID:(NSNumber *)ruleID channel:(NSString *)channel timestamp:(nullable NSDate *)timestamp;

@end

NS_ASSUME_NONNULL_END
