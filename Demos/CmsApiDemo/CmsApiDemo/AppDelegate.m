//
//  AppDelegate.m
//  CmsApiDemo
//
//  Created by Konstantin Efimenko on 6/17/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate
{
    LSAdvertisingNotificationManager *manager;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [LeantegraSDK setClientId:@"demo_mobile"];
    [LeantegraSDK setClientSecret:@"d0177393-f9a7-4417-9930-9465ee4e59ee"];

    [UNUserNotificationCenter currentNotificationCenter].delegate = self;
    LSLocalNotification *notification = [LSLocalNotification new];
    notification.title = @"CMSAPIDemo";
    [notification setSoundName:LSLocalNotificationDefaultSoundName];
    manager = [[LSAdvertisingNotificationManager alloc] initWithNotification:notification];
    [manager setDelegate:self];
    [manager startScan];
    return YES;
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
    if(notification) {
        LSCMSRule*cmsRule=[[LSCMSRule alloc] initWithNotificationDictionary:notification.userInfo];
        [manager sendViewCMSRules:@[cmsRule] channel:LSViewChannelTypeNotification];
    }
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler {
    LSCMSRule *cmsRule=[[LSCMSRule alloc] initWithNotificationDictionary:notification.request.content.userInfo];
    [manager sendViewCMSRules:@[cmsRule] channel:LSViewChannelTypeNotification];

    completionHandler(UNAuthorizationOptionSound | UNAuthorizationOptionAlert |UNAuthorizationOptionBadge);
}


- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)())completionHandler {
    completionHandler();
}

#pragma mark - LSAdvertisingNotificationManagerDelegate
- (void)monitoringDidGetError:(LSWiBeatError)error {
    NSLog(@"Monitoring did get error");
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
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

@end
