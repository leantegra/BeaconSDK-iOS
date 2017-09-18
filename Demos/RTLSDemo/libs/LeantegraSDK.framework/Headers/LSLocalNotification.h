//
//  LSLocalNotification.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 10/5/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSCMSRule.h"

#define kLSNotificationsList @"LSNotificationsList"
#define LSLocalNotificationDefaultSoundName @"LSLocalNotificationDefaultSoundName"

NS_ASSUME_NONNULL_BEGIN

@interface LSLocalNotification : NSObject

/**
    Schedules notification showing with UNUserNotificationCenter / UILocalNotification system API
    @param cmsRule Rule to show
    @param callback Passing YES as success argument in callback if notifications for this rule haven't fired yet, or from last showing to user this rule. If notification not successfully scheduled, NO as success argument with optional error argument (if any) will be passed to the callback.
*/
- (void)showWithCMSRule:(LSCMSRule *)cmsRule callback:(void (^)(BOOL success, NSError *error))callback;

@property (nullable) NSString *soundName;

@property (nullable) NSString *title;

//Only for versions iOS older 10
+ (void)removeNotificationForRuleId:(NSInteger)ruleId;

NS_ASSUME_NONNULL_END

@end
