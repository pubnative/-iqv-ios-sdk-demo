//
//  AdSdkDemoSettings.h
//  AdSDK Demo
//
//  Created by Eros Garcia Ponte on 25.03.20.
//  Copyright © 2020 Can Soykarafakili. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HyBidStatic/HyBidStatic.h>

@interface AdSdkDemoSettings : NSObject

@property (nonatomic, strong) NSString *appToken;

+ (AdSdkDemoSettings *)sharedInstance;

@end
