//
//  AdSetQDANativeExpressAd.h
//  AdSetQDAAdSDK
//
//  Created by admin on 2021/1/16.
//

#import <Foundation/Foundation.h>
#import "AdSetQDANativeExpressAd.h"
#import <AdSetQDAAdSDK/AdSetQDABidReason.h>
@class AdSetQDANativeExpressAdManager;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    AdSetQDANativeExpressAdTypeDraw,  // draw视频信息流
    AdSetQDANativeExpressAdTypeSelfRender, // 自渲染
    AdSetQDANativeExpressAdTypeFeed,  // 普通模板信息流
    AdSetQDANativeExpressAdTypeSelfRenderSplash // 自渲染开屏
} AdSetQDANativeExpressAdType;


@protocol AdSetQDANativeExpressAdDelegate <NSObject>
@optional;

/// 原生模版广告获取成功
/// @param manager 广告管理类
/// @param ads 广告数组 一般只会有一条广告数据 使用数组预留扩展
- (void)adsetQDA_nativeExpressAdSuccessToLoad:(AdSetQDANativeExpressAdManager *)manager ads:(NSArray<__kindof AdSetQDANativeExpressAd *> *)ads;

/// 原生模版广告获取失败
/// @param manager 广告管理类
/// @param error 错误信息
- (void)adsetQDA_nativeExpressAdFailToLoad:(AdSetQDANativeExpressAdManager *)manager error:(NSError *_Nullable)error;

/// 原生模版渲染成功
/// @param nativeExpressAd 渲染成功的模板广告
- (void)adsetQDA_nativeExpressAdRenderSuccess:(AdSetQDANativeExpressAd *)nativeExpressAd;

/// 原生模版渲染失败
/// @param nativeExpressAd 渲染失败的模板广告
/// @param error 渲染过程中的错误
- (void)adsetQDA_nativeExpressAdRenderFail:(AdSetQDANativeExpressAd *)nativeExpressAd error:(NSError *_Nullable)error;

/// 原生模板将要显示
/// @param nativeExpressAd 要显示的模板广告
- (void)adsetQDA_nativeExpressAdWillShow:(AdSetQDANativeExpressAd *)nativeExpressAd;

/// 广告显示失败
/// @param nativeExpressAd 要显示的广告
- (void)adsetQDA_nativeExpressAdShowFail:(AdSetQDANativeExpressAd *)nativeExpressAd error:(NSError *_Nullable)error;

/// 原生模板将被点击了
/// @param nativeExpressAd  被点击的模板广告
- (void)adsetQDA_nativeExpressAdDidClick:(AdSetQDANativeExpressAd *)nativeExpressAd;

///  原生模板广告被关闭了
/// @param nativeExpressAd 要关闭的模板广告
- (void)adsetQDA_nativeExpressAdViewClosed:(AdSetQDANativeExpressAd *)nativeExpressAd;

/// 原生模板广告将要展示详情页
/// @param nativeExpressAd  广告
- (void)adsetQDA_nativeExpressAdWillPresentScreen:(AdSetQDANativeExpressAd *)nativeExpressAd;

/// 原生模板广告将要关闭详情页
/// @param nativeExpressAd 广告
- (void)adsetQDA_nativeExpressAdVDidCloseOtherController:(AdSetQDANativeExpressAd *)nativeExpressAd;

@end

@interface AdSetQDANativeExpressAdManager : NSObject

@property(nonatomic,weak)id<AdSetQDANativeExpressAdDelegate> delegate;

@property(nonatomic,weak)UIViewController *currentViewController;

@property(nonatomic,assign,readonly)AdSetQDANativeExpressAdType type;

/// 最新的一条广告的ecpm
@property(nonatomic,assign,readonly)NSInteger ecpm;

/// 广告底价，单位分，不会返回低于此底价的广告，底价过高可能会没有广告，兜底返回错误提示：广告价格低于底价！
@property(nonatomic,assign)NSInteger basePrice;


/// 禁止使用此方法来初始化
+ (instancetype)new NS_UNAVAILABLE;

/// 禁止使用此方法来初始化
- (instancetype)init NS_UNAVAILABLE;

/// 初始化方法
/// @param placementId 广告id
/// @param type 广告type
/// @param adSize 广告尺寸,AdSetQDANativeExpressAdTypeFeed 类型根据宽度自适应，可将高度直接设置为0 AdSetQDANativeExpressAdTypeDraw类型传入屏幕的宽高
- (instancetype)initWithPlacementId:(nonnull NSString *)placementId type:(AdSetQDANativeExpressAdType)type adSize:(CGSize)adSize NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)loadAd;

/// 通知广告平台的广告竞胜
///  @param costPrice 竞胜价格
///  @param secondPrice 二价
- (void)notifyBidWin:(double)costPrice secondPrice:(double)secondPrice;
/// 通知广告平台的广告竞败
/// @param bidLossReason 竞败原因
- (void)notifyBidLoss:(AdSetQDABidReason *)bidLossReason;

@end

NS_ASSUME_NONNULL_END
