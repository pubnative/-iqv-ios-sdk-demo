//
//  Copyright © 2018 PubNative. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <UIKit/UIKit.h>
#import "IQVAd.h"
#import "IQVAdRequest.h"
#import "IQVAdPresenter.h"
#import "IQVSignalDataProcessor.h"

@class IQVAdView;

@protocol IQVAdViewDelegate<NSObject>

- (void)adViewDidLoad:(IQVAdView *)adView;
- (void)adView:(IQVAdView *)adView didFailWithError:(NSError *)error;
- (void)adViewDidTrackImpression:(IQVAdView *)adView;
- (void)adViewDidTrackClick:(IQVAdView *)adView;

@end

@interface IQVAdView : UIView <IQVAdRequestDelegate, IQVAdPresenterDelegate, IQVSignalDataProcessorDelegate>

@property (nonatomic, strong) IQVAdRequest *adRequest;
@property (nonatomic, strong) IQVAd *ad;
@property (nonatomic, weak) NSObject <IQVAdViewDelegate> *delegate;
@property (nonatomic, assign) BOOL isMediation;
@property (nonatomic, strong) IQVAdSize *adSize;
@property (nonatomic, assign) BOOL autoShowOnLoad;

- (instancetype)initWithSize:(IQVAdSize *)adSize NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
//- (instancetype)init NS_UNAVAILABLE;
- (void)loadWithZoneID:(NSString *)zoneID andWithDelegate:(NSObject<IQVAdViewDelegate> *)delegate;
- (void)setupAdView:(UIView *)adView;
- (void)renderAd;
- (void)renderAdWithContent:(NSString *)adContent withDelegate:(NSObject<IQVAdViewDelegate> *)delegate;
- (void)startTracking;
- (void)stopTracking;
- (void)show;
- (IQVAdPresenter *)createAdPresenter;

@end
