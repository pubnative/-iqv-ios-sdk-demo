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
#import "IQVContentInfoView.h"

@class IQVMRAIDView;
@protocol IQVMRAIDServiceDelegate;

// A delegate for MRAIDView to listen for notification on ad ready or expand related events.
@protocol IQVMRAIDViewDelegate <NSObject>

@optional

// These callbacks are for basic banner ad functionality.
- (void)mraidViewAdReady:(IQVMRAIDView *)mraidView;
- (void)mraidViewAdFailed:(IQVMRAIDView *)mraidView;
- (void)mraidViewWillExpand:(IQVMRAIDView *)mraidView;
- (void)mraidViewDidClose:(IQVMRAIDView *)mraidView;
- (void)mraidViewNavigate:(IQVMRAIDView *)mraidView withURL:(NSURL *)url;

// This callback is to ask permission to resize an ad.
- (BOOL)mraidViewShouldResize:(IQVMRAIDView *)mraidView toPosition:(CGRect)position allowOffscreen:(BOOL)allowOffscreen;

@end

@interface IQVMRAIDView : UIView

@property (nonatomic, strong) id<IQVMRAIDViewDelegate> delegate;
@property (nonatomic, strong) id<IQVMRAIDServiceDelegate> serviceDelegate;
@property (nonatomic, weak, setter = setRootViewController:) UIViewController *rootViewController;
@property (nonatomic, assign, getter = isViewable, setter = setIsViewable:) BOOL isViewable;

// IMPORTANT: This is the only valid initializer for an MRAIDView; -init and -initWithFrame: will throw exceptions
- (id)initWithFrame:(CGRect)frame
       withHtmlData:(NSString*)htmlData
        withBaseURL:(NSURL*)bsURL
  supportedFeatures:(NSArray *)features
      isInterstital:(BOOL)isInterstitial
           delegate:(id<IQVMRAIDViewDelegate>)delegate
    serviceDelegate:(id<IQVMRAIDServiceDelegate>)serviceDelegate
 rootViewController:(UIViewController *)rootViewController
        contentInfo:(IQVContentInfoView *)contentInfo
         skipOffset:(NSInteger)skipOffset;

- (void)cancel;

/// Helper method that presents the interstitial ad modally from the current view controller.
- (void)showAsInterstitial;

/**
* Helper method that presents the interstitial ad modally from the specified view controller.
*
* @param viewController The view controller that should be used to present the interstitial ad.
*/
- (void)showAsInterstitialFromViewController:(UIViewController *)viewController;
- (void)hide;
- (void)stopAdSession;
- (void)startAdSession;
@end
