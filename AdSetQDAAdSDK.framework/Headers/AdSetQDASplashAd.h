//
//  AdSetQDASplashAd.h
//  AdSetQDAAdSDK
//
//  Created by admin on 2021/1/13.
//

#import <UIKit/UIKit.h>
#import <AdSetQDAAdSDK/AdSetQDASourceAdType.h>
#import <AdSetQDAAdSDK/AdSetQDABidReason.h>
#import <AdSetQDAAdSDK/AdSetQDAAdMaterial.h>
@class AdSetQDASplashAd;

NS_ASSUME_NONNULL_BEGIN

@protocol AdSetQDASplashAdDelegate <NSObject>
@optional
/// 开屏加载成功
- (void)adsetQDA_splashAdDidLoad:(AdSetQDASplashAd *)splashAd;

/// 开屏加载失败
- (void)adsetQDA_splashAd:(AdSetQDASplashAd *)splashAd didFailWithError:(NSError * _Nullable)error;

/// 开屏素材加载成功
- (void)adsetQDA_splashAdMaterialDidLoad:(AdSetQDASplashAd *)splashAd;

/// 开屏素材加载失败
- (void)adsetQDA_splashAdMaterial:(AdSetQDASplashAd *)splashAd didFailWithError:(NSError * _Nullable)error;

/// 开屏广告被点击了
- (void)adsetQDA_splashAdDidClick:(AdSetQDASplashAd *)splashAd;

/// 开屏广告关闭了
- (void)adsetQDA_splashAdDidClose:(AdSetQDASplashAd *)splashAd;

/// 开屏广告详情页关闭 落地页关闭
- (void)adsetQDA_splashAdDetailDidClose:(AdSetQDASplashAd *)splashAd;
 
/// 开屏广告详情页展示
- (void)adsetQDA_splashAdDetailShow:(AdSetQDASplashAd *)splashAd;

///  开屏广告将要展示
- (void)adsetQDA_splashAdWillVisible:(AdSetQDASplashAd *)splashAd;

///  开屏广告展示失败
- (void)adsetQDA_splashAdVisibleError:(AdSetQDASplashAd *)splashAd error:(NSError * _Nullable)error;

@end

@interface AdSetQDASplashAd : NSObject

/// buttomView  底部视图 可为空
@property(nonatomic,strong)UIView *bottomView;

/// Fancy 支持跳过时间配置 默认5s  最小值为3s 最大值为15s
@property(nonatomic,assign)NSInteger skipTime;

/// 是否隐藏跳过按钮 默认NO
@property(nonatomic,assign)BOOL hideSkipButton;

/// 根控制器 广告加载的根控制器 需要传入当前的栈顶可见的控制器
@property(nonatomic, weak)UIViewController *rootViewController;

/// 广告id
@property(nonatomic,copy,readonly)NSString *placementId;

/// 开屏广告代理
@property(nonatomic,weak)id<AdSetQDASplashAdDelegate> delegate;

/// 消耗方类型
@property(nonatomic,assign)AdSetQDAAdSourceType sourceType;

/// 广告素材 可能为空
@property(nullable,nonatomic,strong)AdSetQDAAdMaterial *adMaterial;

/// 广告是否有效（展示前请务必判断）
/// 如不严格按照此方法对接，将导致因曝光延迟时间造成的双方消耗gap过大，请开发人员谨慎对接
@property(nonatomic,assign,readonly)BOOL isReady;

///  素材是否加载成功
@property(nonatomic,assign,readonly)BOOL isMaterialLoaded;

/// 广告ecpm 单位分
@property(nonatomic,assign,readonly)NSInteger ecpm;

/// 广告底价，单位分，不会返回低于此底价的广告，底价过高可能会没有广告，兜底返回错误提示：广告价格低于底价！
@property(nonatomic,assign)NSInteger basePrice;

/// 禁止使用此方法来初始化
+ (instancetype)new NS_UNAVAILABLE;

/// 禁止使用此方法来初始化
- (instancetype)init NS_UNAVAILABLE;

///  初始化
/// @param placementId 广告id
- (instancetype)initWithPlacementId:(nonnull NSString *)placementId NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)loadAd;

/// 展示广告
- (void)showAdWithViewController:(UIViewController *)viewController;

/// 展示广告并传入bottomview  传入的bottomiview 会覆盖 bottomView 属性的值
- (void)showAdWithViewController:(UIViewController *)viewController bottomView:(UIView *)bottomView;

/// 销毁广告
- (void)destory;

/// 通知广告平台的广告竞胜
///  @param costPrice 竞胜价格
///  @param secondPrice 二价
- (void)notifyBidWin:(double)costPrice secondPrice:(double)secondPrice;
/// 通知广告平台的广告竞败
/// @param bidLossReason 竞败原因
- (void)notifyBidLoss:(AdSetQDABidReason *)bidLossReason;

@end

NS_ASSUME_NONNULL_END
