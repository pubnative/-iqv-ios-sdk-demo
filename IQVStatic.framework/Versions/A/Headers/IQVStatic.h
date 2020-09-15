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

//! Project version number for IQV.
FOUNDATION_EXPORT double IQVVersionNumber;

//! Project version string for IQV.
FOUNDATION_EXPORT const unsigned char IQVVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <IQV/PublicHeader.h>

#import <IQVStatic/IQVRequestParameter.h>
#import <IQVStatic/IQVTargetingModel.h>
#import <IQVStatic/IQVAdRequest.h>
#import <IQVStatic/IQVMRAIDServiceProvider.h>
#import <IQVStatic/IQVMRAIDView.h>
#import <IQVStatic/IQVMRAIDServiceDelegate.h>
#import <IQVStatic/IQVLeaderboardAdRequest.h>
#import <IQVStatic/IQVBannerAdRequest.h>
#import <IQVStatic/IQVMRectAdRequest.h>
#import <IQVStatic/IQVInterstitialAdRequest.h>
#import <IQVStatic/IQVAdPresenter.h>
#import <IQVStatic/IQVInterstitialPresenter.h>
#import <IQVStatic/IQVNativeAdLoader.h>
#import <IQVStatic/IQVAdPresenterFactory.h>
#import <IQVStatic/IQVLeaderboardPresenterFactory.h>
#import <IQVStatic/IQVBannerPresenterFactory.h>
#import <IQVStatic/IQVMRectPresenterFactory.h>
#import <IQVStatic/IQVInterstitialPresenterFactory.h>
#import <IQVStatic/IQVAdCache.h>
#import <IQVStatic/IQVHeaderBiddingUtils.h>
#import <IQVStatic/IQVPrebidUtils.h>
#import <IQVStatic/IQVContentInfoView.h>
#import <IQVStatic/IQVUserDataManager.h>
#import <IQVStatic/IQVBaseModel.h>
#import <IQVStatic/IQVAdModel.h>
#import <IQVStatic/IQVDataModel.h>
#import <IQVStatic/IQVAd.h>
#import <IQVStatic/IQVNativeAd.h>
#import <IQVStatic/IQVAdView.h>
#import <IQVStatic/IQVLeaderboardAdView.h>
#import <IQVStatic/IQVBannerAdView.h>
#import <IQVStatic/IQVMRectAdView.h>
#import <IQVStatic/IQVInterstitialAd.h>
#import <IQVStatic/IQVSettings.h>
#import <IQVStatic/IQVStarRatingView.h>
#import <IQVStatic/IQVNativeAdRenderer.h>
#import <IQVStatic/IQVViewabilityManager.h>
#import <IQVStatic/IQVLogger.h>
#import <IQVStatic/IQVIntegrationType.h>
#import <IQVStatic/IQVAdSize.h>

typedef void (^IQVCompletionBlock)(BOOL);

@interface IQV : NSObject

+ (void)setCoppa:(BOOL)enabled;
+ (void)setTargeting:(IQVTargetingModel *)targeting;
+ (void)setTestMode:(BOOL)enabled;
+ (void)initWithAppToken:(NSString *)appToken completion:(IQVCompletionBlock)completion;
+ (void)setLocationUpdates:(BOOL)enabled;

@end
