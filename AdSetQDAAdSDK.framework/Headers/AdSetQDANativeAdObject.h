//
//  AdSetQDANativeAdObject.h
//  AdSetQDAAdSDK
//
//  Created by admin on 2024/1/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdSetQDAAdSDK/AdSetQDANativeAdData.h>
#import <AdSetQDAAdSDK/AdSetQDANativeAdRelatedView.h>


NS_ASSUME_NONNULL_BEGIN

@interface AdSetQDANativeAdObject : NSObject

/// 广告数据
@property (nonatomic, strong, readonly) AdSetQDANativeAdData *adData;
/// 视频relatedView
@property (nonatomic, strong, readonly)AdSetQDANativeAdRelatedView *relatedView;


/// 开屏自渲染注册容器和可点击视图
/// @param containerView 容器视图
/// @param clickableViews 可点击视图数组
- (void)setSplashContainer:(UIView *)containerView clickableViews:(NSArray<UIView *> *)clickableViews;

/// 其他广告位置注册容器和可点击视图
/// @param containerView 容器视图
/// @param clickableViews 可点击视图数组
- (void)setContainer:(UIView *)containerView clickableViews:(NSArray<UIView *> *)clickableViews;


@end

NS_ASSUME_NONNULL_END
