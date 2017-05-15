//
//  AppDelegate.h
//  CmsApiDemo
//
//  Created by Konstantin Efimenko on 6/17/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LeantegraSDK/LeantegraSDK.h>
#import <LeantegraSDK/LSAdvertisingNotificationManager.h>
#import <UserNotifications/UserNotifications.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, LSAdvertisingNotificationManagerDelegate, UNUserNotificationCenterDelegate>

@property (strong, nonatomic) UIWindow *window;

@end

