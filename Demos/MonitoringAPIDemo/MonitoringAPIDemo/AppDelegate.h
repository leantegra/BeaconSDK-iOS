//
//  AppDelegate.h
//  MonitoringAPIDemo
//
//  Created by Konstantin Efimenko on 6/3/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LeantegraSDK/LeantegraSDK.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, LSMonitoringManagerDelegate>

@property (strong, nonatomic) UIWindow *window;

@property LSMonitoringManager *monitoringManager;

@end

