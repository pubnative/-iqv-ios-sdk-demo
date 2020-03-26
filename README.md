# IQV IOS SDK Integration and Configuration

## Requirements
- You will be provided with a parameter set by your account manager. This consists of two string values for appToken and partnerKeyword.
##  Install HyBid SDK
1. Select HyBid.framework in this example application project and and simply drag and drop the HyBid.framework file to Embedded Binaries section on your projection configuration page.

2. Select your target and navigate to the Build Phases. Then, add a Run Script step to your build steps.
3. Put it after your step to Embed Frameworks, set it to use /bin/sh and enter the following script:

APP_PATH="${TARGET_BUILD_DIR}/${WRAPPER_NAME}"

find "$APP_PATH" -name 'HyBid.framework' -type d | while read -r FRAMEWORK
do
    FRAMEWORK_EXECUTABLE_NAME=$(defaults read "$FRAMEWORK/Info.plist" CFBundleExecutable)
    FRAMEWORK_EXECUTABLE_PATH="$FRAMEWORK/$FRAMEWORK_EXECUTABLE_NAME"
    echo "Executable is $FRAMEWORK_EXECUTABLE_PATH"

    EXTRACTED_ARCHS=()

    for ARCH in $ARCHS
    do
        echo "Extracting $ARCH from $FRAMEWORK_EXECUTABLE_NAME"
        lipo -extract "$ARCH" "$FRAMEWORK_EXECUTABLE_PATH" -o "$FRAMEWORK_EXECUTABLE_PATH-$ARCH"
        EXTRACTED_ARCHS+=("$FRAMEWORK_EXECUTABLE_PATH-$ARCH")
    done

    echo "Merging extracted architectures: ${ARCHS}"
    lipo -o "$FRAMEWORK_EXECUTABLE_PATH-merged" -create "${EXTRACTED_ARCHS[@]}"
    rm "${EXTRACTED_ARCHS[@]}"

    echo "Replacing original executable with thinned version"
    rm "$FRAMEWORK_EXECUTABLE_PATH"
    mv "$FRAMEWORK_EXECUTABLE_PATH-merged" "$FRAMEWORK_EXECUTABLE_PATH"

done


## Initialise SDK
Add the HyBid.framework to your code.

### Swift:

import HyBid
### Objective-C:

#import <HyBid/HyBid.h>

In order to initialize a request, you must call init() before requesting for ads.

### Swift:

HyBid.initWithAppToken("<YOUR_APP_TOKEN_HERE>", "<YOUR_PARTNER_KEYWORD_HERE>") { (success) in
            if (success) {
                print("HyBid Successfully Initialized")
            }
        }

### Objective-C:

 [HyBid initWithAppToken:@"<YOUR_APP_TOKEN_HERE>" withPartnerKeyword:@"<YOUR_PARTNER_KEYWORD_HERE>" completion:^(BOOL success) {
        if (success) {
            NSLog(@"HyBid initialisation completed");
        }
    }];
    
## Advanced Configurations
There are certain parameters that should be configured in the SDK before doing any type of interaction with it. Ensure to configure these parameters only 1 per session.

### If your app is COPPA compliant:
Swift:

HyBid.setCoppa(Bool)
Objective-C:

[HyBid setCoppa:BOOL];
### Test Mode
In development, you should set Test Mode as true for our SDK and disable it in the release. It allows not to track impressions and tracks on the server side of development application:

Swift:

HyBid.setTestMode(Bool)
Objective-C:

[HyBid setTestMode:BOOL];
### Targeting
If you want to improve targeting, first configure the HyBidTargetingModel object that you want to pass on and then invoke the following method:

Swift:

var targeting = HyBidTargetingModel()
targeting.age = <AGE>
targeting.interests = <ARRAY_OF_THE_INTERESTS>
targeting.gender = "<GENDER>"     // "f" for female, "m" for male
HyBid.setTargeting(targeting)
Objective-C:

HyBidTargetingModel *targeting = [[HyBidTargetingModel alloc] init];
targeting.age = <AGE>;
targeting.interests = <ARRAY_OF_THE_INTERESTS>;
targeting.gender = "<GENDER>";     // "f" for female, "m" for male
[HyBid setTargeting:targeting];
### Logging
You can control the level of log that you want to see in your console. As default HyBidLogger is set to HyBidLogLevelDebug. There are 5 HyBidLogLevels;

HyBidLogLevelNone
HyBidLogLevelError
HyBidLogLevelWarning
HyBidLogLevelInfo
HyBidLogLevelDebug
If you want to set a different HyBidLogLevel in your app, the best place is to do it in the HyBid initialization part.

Swift:

HyBid.initWithAppToken("<YOUR_APP_TOKEN_HERE>") { (success) in
            if (success) {
                HyBidLogger.setLogLevel(HyBidLogLevelDebug)
                print("HyBid Successfully Initialized")
            }
        }
Objective-C:

 [HyBid initWithAppToken:@"<YOUR_APP_TOKEN_HERE>" completion:^(BOOL success) {
        if (success) {
            [HyBidLogger setLogLevel:HyBidLogLevelDebug];
            NSLog(@"HyBid initialisation completed");
        }
    }];

## HyBid Banner and MRECT Ads

Banner Ads will be rendered using the HyBid SDK.

Please see the enclosed example app for details on how to use this feature.

## Intersititials and full screen video

This feature will be available in an upcoming version of this SDK.
