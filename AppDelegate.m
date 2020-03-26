//
//  AppDelegate.m
//  AdSDK Demo
//
//  Created by Eros Garcia Ponte on 25.03.20.
//  Copyright © 2020 Can Soykarafakili. All rights reserved.
//

#import "AppDelegate.h"
#import "AdSdkDemoSettings.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [HyBid initWithAppToken:[AdSdkDemoSettings sharedInstance].appToken withPartnerKeyword: [AdSdkDemoSettings sharedInstance].partnerKeyword completion:^(BOOL success) {
        if (success) {
            [HyBidLogger setLogLevel:HyBidLogLevelDebug];
            NSLog(@"HyBid initialisation completed");
        }
    }];
    HyBidTargetingModel *targetingModel = [[HyBidTargetingModel alloc] init];
    targetingModel.age = [NSNumber numberWithInt:29];
    targetingModel.gender = @"m";
    [HyBid setTargeting: targetingModel];
    return YES;
}


#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
