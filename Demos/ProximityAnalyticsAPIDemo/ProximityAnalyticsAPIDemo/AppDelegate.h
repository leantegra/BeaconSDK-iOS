//
//  AppDelegate.h
//  ProximityAnalyticsAPIDemo
//
//  Created by Anton Voitsekhivskyi on 5/10/17.
//  Copyright © 2017 Leantegra Llc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LeantegraSDK/LeantegraSDK.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, LSProximityAnalyticsManagerDelegate>

@property (strong, nonatomic) UIWindow *window;

@end

