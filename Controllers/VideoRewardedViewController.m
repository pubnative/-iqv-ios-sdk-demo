//
//  VideoRewardedViewController.m
//  iqv demo
//
//  Created by Orkhan Alizada on 17.06.21.
//  Copyright © 2021 PubNative. All rights reserved.
//

#import "VideoRewardedViewController.h"
#import <IQVStatic/IQVStatic.h>

@interface VideoRewardedViewController () <IQVRewardedAdDelegate>

@property (nonatomic, strong) IQVRewardedAd *rewardedAd;
@property (weak, nonatomic) IBOutlet UIButton *loadAdButton;
@property (weak, nonatomic) IBOutlet UIButton *showAdButton;

@end

@implementation VideoRewardedViewController

- (void)dealloc {
    self.rewardedAd = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.showAdButton.hidden = YES;
}

- (IBAction)requestRewardedTouchUpInside:(id)sender {
    [self requestAd];
}

- (IBAction)showRewardedTouchUpInside:(UIButton *)sender {
    if (self.rewardedAd.isReady) {
        [self.rewardedAd show];
    }
}

- (void)requestAd {
    self.rewardedAd = [[IQVRewardedAd alloc] initWithZoneID:@"15" andWithDelegate:self];
    [self.rewardedAd load];
}

- (void)showAlertControllerWithMessage:(NSString *)message {
    UIAlertController *alertController = [UIAlertController
                                          alertControllerWithTitle:@"I have a bad feeling about this... 🙄"
                                          message:message
                                          preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction * dismissAction = [UIAlertAction actionWithTitle:@"Dismiss" style:UIAlertActionStyleCancel handler:nil];
    UIAlertAction *retryAction = [UIAlertAction actionWithTitle:@"Retry" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self requestAd];
    }];
    [alertController addAction:dismissAction];
    [alertController addAction:retryAction];
    [self presentViewController:alertController animated:YES completion:nil];
}

#pragma mark - IQVRewardedAdDelegate

- (void)onReward {
    NSLog(@"On Reward.");
}

- (void)rewardedDidDismiss {
    NSLog(@"Rewarded did dismiss.");
    self.showAdButton.hidden = YES;
}

- (void)rewardedDidFailWithError:(NSError *)error {
    NSLog(@"Rewarded did fail with error: %@", error.localizedDescription);
}

- (void)rewardedDidLoad {
    self.showAdButton.hidden = NO;
}

- (void)rewardedDidTrackClick {
    NSLog(@"Rewarded did track click.");
}

- (void)rewardedDidTrackImpression {
    NSLog(@"Rewarded did track impression.");
}

@end
