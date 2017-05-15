//
//  AppDelegate.m
//  MonitoringAPIDemo
//
//  Created by Konstantin Efimenko on 6/3/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    return YES;
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //register notification
    if (floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_9_x_Max) {
        UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
        center.delegate = self;
        [center requestAuthorizationWithOptions:(UNAuthorizationOptionBadge | UNAuthorizationOptionSound | UNAuthorizationOptionAlert)
        completionHandler:^(BOOL granted, NSError * _Nullable error) {
            if (!error) {
                NSLog(@"request authorization succeeded!");
            }
        }];
    }
    else if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)]) {
        UIUserNotificationSettings *notificationSettings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:notificationSettings];
        [[UIApplication sharedApplication] registerForRemoteNotifications];
    } else {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
        [[UIApplication sharedApplication] registerForRemoteNotificationTypes: (UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert)];
#pragma GCC diagnostic pop
    }
    NSUUID *uuid = [[NSUUID alloc] initWithUUIDString:@"85a99e33-bbbe-4763-a66b-4d3a3edec09b"];
    LSRegionBuilder *builder = [[LSRegionBuilder alloc] initWithIdentifier:@"DemoRegion"];
    builder.proximityZone = IMMEDIATE;
    [builder addBeaconByUUID:uuid major:nil minor:nil];
    LSRegion *region = [builder build];
    
    self.monitoringManager = [LSMonitoringManager sharedMonitoringManager];
    [self.monitoringManager addDelegate:self];
    [self.monitoringManager startMonitoringForRegion:region];
    
    return YES;
}

- (void)showNotification:(NSString *)message {
    if (floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_9_x_Max) {
        [[UNUserNotificationCenter currentNotificationCenter] getDeliveredNotificationsWithCompletionHandler:^(NSArray<UNNotification*>*notifications){
            UNMutableNotificationContent *content = [[UNMutableNotificationContent alloc] init];
            content.body = message;
            content.sound = [UNNotificationSound defaultSound];
            content.title = @"MonitoringAPIDemo";
            content.userInfo = @{@"message" : message};
            UNTimeIntervalNotificationTrigger *trigger = [UNTimeIntervalNotificationTrigger triggerWithTimeInterval:1 repeats:NO];
            
            UNNotificationRequest *request = [UNNotificationRequest requestWithIdentifier:message content:content trigger:trigger];
            UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
            [center addNotificationRequest:request withCompletionHandler:^(NSError * _Nullable error) {
                if (!error) {
                    NSLog(@"add NotificationRequest succeeded!");
                }
            }];
        }];
    }
    else {
        UILocalNotification *notification = [[UILocalNotification alloc] init];
        notification.alertBody = message;
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler {
    completionHandler(UNAuthorizationOptionSound | UNAuthorizationOptionAlert |UNAuthorizationOptionBadge);
}


- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)())completionHandler {
    completionHandler();
}


#pragma mark - LSMonitoringManagerDelegate

- (void)monitoringManager:(LSMonitoringManager *)manager didEnterRegion:(LSRegion *)region frame:(LSBaseFrame *)frame {
    [self showNotification:[NSString stringWithFormat:@"Enter region %@",region.identifier]];
}

- (void)monitoringManager:(LSMonitoringManager *)manager didExitRegion:(LSRegion *)region frame:(LSBaseFrame *)frame {
    [self showNotification:[NSString stringWithFormat:@"Exit region %@",region.identifier]];
}

- (void)monitoringManager:(LSMonitoringManager *)manager didGetError:(LSWiBeatError)error {

}

- (void)monitoringManager:(LSMonitoringManager *)manager timeForRangingBeaconsWasExpiredInRegions:(NSSet<LSRegionWrapper *> *)regions {
    [self showNotification: @"Time for ranging in backround expired"];
}

@end
