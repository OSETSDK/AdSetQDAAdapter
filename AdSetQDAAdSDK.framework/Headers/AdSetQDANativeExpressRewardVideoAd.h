//
//  AdSetQDANativeExpressRewardVideoAd.h
//  lottie-ios_Oc
//
//  Created by admin on 2021/1/26.
//

#import <UIKit/UIkit.h>
#import <AdSetQDAAdSDK/AdSetQDASourceAdType.h>
#import <AdSetQDAAdSDK/AdSetQDABidReason.h>
#import <AdSetQDAAdSDK/AdSetQDAAdMaterial.h>
#import <AdSetQDAAdSDK/AdSetQDARewardedVideoModel.h>
@class AdSetQDANativeExpressRewardVideoAd;

NS_ASSUME_NONNULL_BEGIN

@protocol AdSetQDARewardVideoDelegate <NSObject>
@optional
/// 激励广告加载成功
- (void)adsetQDA_rewardVideoAdDidLoad:(AdSetQDANativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告失败 加载失败 播放失败 渲染失败
- (void)adsetQDA_rewardVideoAd:(AdSetQDANativeExpressRewardVideoAd *)rewardVideoAd didFailWithError:(NSError *)error;

/// 激励广告将要展示
- (void)adsetQDA_rewardVideoAdWillVisible:(AdSetQDANativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告曝光
- (void)adsetQDA_rewardVideoAdDidExposed:(AdSetQDANativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告曝光失败
- (void)adsetQDA_rewardVideoAdExposedFail:(AdSetQDANativeExpressRewardVideoAd *)rewardVideoAd error:(NSError *)error;;

/// 激励广告关闭
- (void)adsetQDA_rewardVideoAdDidClose:(AdSetQDANativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告被点击
- (void)adsetQDA_rewardVideoAdDidClicked:(AdSetQDANativeExpressRewardVideoAd *)rewardVideoAd;

/// 激励广告播放完成
- (void)adsetQDA_rewardVideoAdDidPlayFinish:(AdSetQDANativeExpressRewardVideoAd *)rewardVideoAd;

/// 达到激励条件
- (void)adsetQDA_rewardVideoAdDidRewardEffective:(AdSetQDANativeExpressRewardVideoAd *)rewardedVideoAd isVerify:(BOOL)isVerify;

@end

@interface AdSetQDANativeExpressRewardVideoAd : NSObject

/// 广告id
@property(nonatomic,copy,readonly)NSString *placementId;

/// 激励广告代理
@property(nonatomic,weak)id<AdSetQDARewardVideoDelegate> delegate;

/// 消耗方类型
@property(nonatomic,assign)AdSetQDAAdSourceType sourceType;

/// 广告ecpm 单位分
@property(nonatomic,assign,readonly)NSInteger ecpm;

@property(nonatomic,assign,readonly)BOOL isReady;

@property(nonatomic,strong,readonly)AdSetQDARewardedVideoModel *rewardedVideoModel;

/// 广告素材 可能为空
@property(nullable,nonatomic,strong)AdSetQDAAdMaterial *adMaterial;

/// 广告底价，单位分，不会返回低于此底价的广告，底价过高可能会没有广告，兜底返回错误提示：广告价格低于底价！
@property(nonatomic,assign)NSInteger basePrice;

/// 禁止使用此方法来初始化
+ (instancetype)new NS_UNAVAILABLE;

/// 禁止使用此方法来初始化
- (instancetype)init NS_UNAVAILABLE;


///  初始化 
/// @param placementId 广告id
/// @param model rewarded video model. 可传空 
- (instancetype)initWithPlacementId:(nonnull NSString *)placementId rewardedVideoModel:(nullable AdSetQDARewardedVideoModel *)model NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)loadAd;

/// 展示激励广告
/// @param controller 控制器 一般为当前控制器 或者栈顶控制器
- (void)showAdFromRootViewController:(UIViewController *)controller;

/// 通知广告平台的广告竞胜
///  @param costPrice 竞胜价格
///  @param secondPrice 二价
- (void)notifyBidWin:(double)costPrice secondPrice:(double)secondPrice;
/// 通知广告平台的广告竞败
/// @param bidLossReason 竞败原因
- (void)notifyBidLoss:(AdSetQDABidReason *)bidLossReason;

@end

NS_ASSUME_NONNULL_END
