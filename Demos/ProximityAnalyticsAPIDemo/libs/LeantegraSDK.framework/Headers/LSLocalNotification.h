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

@interface LSLocalNotification : NSObject

/**
 Returns YES in callback if notifications for this rule haven't fired yet, or from last showing to user this rule
 */
- (void)showWithCMSRule:(LSCMSRule*)cmsRule callback:(void (^)(BOOL))callback;

@property NSString* soundName;

@property NSString* title;

//Only for versions iOS older 10
+ (void)removeNotificationForRuleId:(NSInteger)ruleId;

@end
