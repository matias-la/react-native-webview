/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <React/RCTView.h>
#import <React/RCTDefines.h>
#import <WebKit/WebKit.h>

typedef enum RNCWebViewPermissionGrantType : NSUInteger {
  RNCWebViewPermissionGrantType_GrantIfSameHost_ElsePrompt,
  RNCWebViewPermissionGrantType_GrantIfSameHost_ElseDeny,
  RNCWebViewPermissionGrantType_Deny,
  RNCWebViewPermissionGrantType_Grant,
  RNCWebViewPermissionGrantType_Prompt
} RNCWebViewPermissionGrantType;

@class RNCWebView;

@protocol RNCWebViewDelegate <NSObject>

- (BOOL)webView:(RNCWebView *_Nonnull)webView
shouldStartLoadForRequest:(NSMutableDictionary<NSString *, id> *_Nonnull)request
   withCallback:(RCTDirectEventBlock _Nonnull)callback;

@end

@interface RNCWeakScriptMessageDelegate : NSObject<WKScriptMessageHandler>

@property (nonatomic, weak, nullable) id<WKScriptMessageHandler> scriptDelegate;

- (nullable instancetype)initWithDelegate:(id<WKScriptMessageHandler> _Nullable)scriptDelegate;

@end

@interface RNCWebView : RCTView

@property (nonatomic, weak) id<RNCWebViewDelegate> _Nullable delegate;
@property (nonatomic, copy) NSDictionary * _Nullable source;
@property (nonatomic, assign) BOOL messagingEnabled;
@property (nonatomic, copy) NSString * _Nullable injectedJavaScript;
@property (nonatomic, copy) NSString * _Nullable injectedJavaScriptBeforeContentLoaded;
@property (nonatomic, assign) BOOL injectedJavaScriptForMainFrameOnly;
@property (nonatomic, assign) BOOL injectedJavaScriptBeforeContentLoadedForMainFrameOnly;
@property (nonatomic, assign) BOOL scrollEnabled;
@property (nonatomic, assign) BOOL sharedCookiesEnabled;
@property (nonatomic, assign) BOOL autoManageStatusBarEnabled;
@property (nonatomic, assign) BOOL pagingEnabled;
@property (nonatomic, assign) CGFloat decelerationRate;
@property (nonatomic, assign) BOOL allowsInlineMediaPlayback;
@property (nonatomic, assign) BOOL allowsAirPlayForMediaPlayback;
@property (nonatomic, assign) BOOL bounces;
@property (nonatomic, assign) BOOL mediaPlaybackRequiresUserAction;
#if WEBKIT_IOS_10_APIS_AVAILABLE
@property (nonatomic, assign) WKDataDetectorTypes dataDetectorTypes;
#endif
@property (nonatomic, assign) UIEdgeInsets contentInset;
@property (nonatomic, assign) BOOL automaticallyAdjustContentInsets;
@property (nonatomic, assign) BOOL keyboardDisplayRequiresUserAction;
@property (nonatomic, assign) BOOL hideKeyboardAccessoryView;
@property (nonatomic, assign) BOOL allowsBackForwardNavigationGestures;
@property (nonatomic, assign) BOOL incognito;
@property (nonatomic, assign) BOOL useSharedProcessPool;
@property (nonatomic, copy) NSString * _Nullable userAgent;
@property (nonatomic, copy) NSString * _Nullable applicationNameForUserAgent;
@property (nonatomic, assign) BOOL cacheEnabled;
@property (nonatomic, assign) BOOL javaScriptEnabled;
@property (nonatomic, assign) BOOL allowFileAccessFromFileURLs;
@property (nonatomic, assign) BOOL allowUniversalAccessFromFileURLs;
@property (nonatomic, assign) BOOL allowsLinkPreview;
@property (nonatomic, assign) BOOL showsHorizontalScrollIndicator;
@property (nonatomic, assign) BOOL showsVerticalScrollIndicator;
@property (nonatomic, assign) BOOL directionalLockEnabled;
@property (nonatomic, assign) BOOL ignoreSilentHardwareSwitch;
@property (nonatomic, copy) NSString * _Nullable allowingReadAccessToURL;
@property (nonatomic, copy) NSDictionary * _Nullable basicAuthCredential;
@property (nonatomic, assign) BOOL pullToRefreshEnabled;
@property (nonatomic, assign) BOOL enableApplePay;
@property (nonatomic, copy) NSArray<NSDictionary *> * _Nullable menuItems;
@property (nonatomic, copy) RCTDirectEventBlock onCustomMenuSelection;
#if !TARGET_OS_OSX
@property (nonatomic, weak) UIRefreshControl * _Nullable refreshControl;
#endif

#if defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED >= 130000 /* iOS 13 */
@property (nonatomic, assign) WKContentMode contentMode;
#endif

#if defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED >= 140000 /* iOS 14 */
@property (nonatomic, assign) BOOL limitsNavigationsToAppBoundDomains;
#endif

#if defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED >= 140500 /* iOS 14.5 */
@property (nonatomic, assign) BOOL textInteractionEnabled;
#endif

#if defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED >= 150000 /* iOS 15 */
@property (nonatomic, assign) RNCWebViewPermissionGrantType mediaCapturePermissionGrantType;
#endif

+ (void)setClientAuthenticationCredential:(nullable NSURLCredential*)credential;
+ (void)setCustomCertificatesForHost:(nullable NSDictionary *)certificates;
- (void)postMessage:(NSString *_Nullable)message;
- (void)injectJavaScript:(NSString *_Nullable)script;
- (void)goForward;
- (void)goBack;
- (void)reload;
- (void)stopLoading;
- (void)requestFocus;
#if !TARGET_OS_OSX
- (void)addPullToRefreshControl;
- (void)pullToRefresh:(UIRefreshControl *_Nonnull)refreshControl;
#endif

@end
