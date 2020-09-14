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
    
    // GDPR countries: The publisher's CMP is expected to write a TCF2 compliant iab consent string to standardUserDefaults with key "IABConsent_ConsentString"
    //[[NSUserDefaults standardUserDefaults] setObject:gdpr_consent forKey:@"IABConsent_ConsentString"];
    
    // CCPA countries: The publisher's CMP is expected to write a US privacy string to standardUserDefaults with key "IABUSPrivacy_String"
    //[[NSUserDefaults standardUserDefaults] setObject:usprivacy forKey:@"IABUSPrivacy_String"];
    
    [IQV initWithAppToken:[AdSdkDemoSettings sharedInstance].appToken completion:^(BOOL success) {
        if (success) {
            [IQVLogger setLogLevel:IQVLogLevelDebug];
            NSLog(@"IQV initialisation completed");
        }
    }];
    IQVTargetingModel *targetingModel = [[IQVTargetingModel alloc] init];
    targetingModel.age = [NSNumber numberWithInt:29];
    targetingModel.gender = @"m";
    [IQV setTargeting: targetingModel];
    
    
     /*
      If you have to reconfigure the AdSDK at runtime you can call reconfigure with new parameters. These will be used from the next ad requests onwards
     
     [IQV reconfigure:<#(NSString *)#> completion:<#^(BOOL)completion#>];
      */
     
    
    return YES;
}


#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options  API_AVAILABLE(ios(13.0)){
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions  API_AVAILABLE(ios(13.0)){
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
