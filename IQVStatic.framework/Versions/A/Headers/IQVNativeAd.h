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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IQVAd.h"
#import "IQVNativeAdRenderer.h"
#import "IQVContentInfoView.h"
#import "IQVSkAdNetworkModel.h"

@class IQVNativeAd;

@protocol IQVNativeAdDelegate <NSObject>

- (void)nativeAd:(IQVNativeAd *)nativeAd impressionConfirmedWithView:(UIView *)view;
- (void)nativeAdDidClick:(IQVNativeAd *)nativeAd;

@end

@protocol IQVNativeAdFetchDelegate <NSObject>

- (void)nativeAdDidFinishFetching:(IQVNativeAd *)nativeAd;
- (void)nativeAd:(IQVNativeAd *)nativeAd didFailFetchingWithError:(NSError *)error;

@end

@interface IQVNativeAd : NSObject

@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) NSString *body;
@property (nonatomic, readonly) NSString *callToActionTitle;
@property (nonatomic, readonly) NSString *iconUrl;
@property (nonatomic, readonly) NSString *bannerUrl;
@property (nonatomic, readonly) NSString *clickUrl;
@property (nonatomic, readonly) NSNumber *rating;
@property (nonatomic, readonly) UIView *banner;
@property (nonatomic, readonly) UIImage *bannerImage;
@property (nonatomic, readonly) UIImage *icon;
@property (nonatomic, strong) IQVAd *ad;
@property (nonatomic, readonly) IQVContentInfoView *contentInfo;

- (instancetype)initWithAd:(IQVAd *)ad;
- (void)renderAd:(IQVNativeAdRenderer *)renderer;
- (void)fetchNativeAdAssetsWithDelegate:(NSObject<IQVNativeAdFetchDelegate> *)delegate;
- (void)startTrackingView:(UIView *)view withDelegate:(NSObject<IQVNativeAdDelegate> *)delegate;
- (void)stopTracking;

@end
