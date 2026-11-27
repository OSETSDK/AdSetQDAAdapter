Pod::Spec.new do |s|
  s.name             = 'AdSetQDAAdapter'
  s.version          = '2.0.2.2'
  s.summary          = 'AdSetQDA 渠道适配器'
  s.description      = 'AdSetQDA 渠道适配器'
  s.homepage         = 'https://github.com/OSETSDK/AdSetQDAAdapter'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'shenshi' => 'yaohaofei@shenshiads.com' }

  # source 指**分发仓**而非 monorepo：CocoaPods 用 :git + :tag 会 clone 整个仓，
  # 指到 monorepo 的话客户装一个适配器就要拉下全部适配器的所有历史二进制。
  # 分发仓各背各的，客户只拉 3M 左右。release_adapter.sh 负责同步产物过去。
  s.source           = { :git => 'https://github.com/OSETSDK/AdSetQDAAdapter.git', :tag => s.version.to_s }

  s.platform         = :ios, '12.0'
  s.swift_versions   = '5.0'

  # 相对路径在 monorepo（channel/<id>/）和分发仓（仓根）里一致，同一份 podspec 两边通用。
  s.vendored_frameworks = 'AdSetQDAAdapter.xcframework'
  s.frameworks          = 'Foundation', 'UIKit'

  # 适配器是静态库，自身不含这两个 SDK 的代码，靠宿主链接它们来解析符号。
  #
  # ⚠️ 基座只能是 OSETCoreAd。依赖 OSETCoreSDK 或任何空壳 pod 都会成环：
  #      OSETCoreSDK(空壳) → AdSetQDAAdapter → OSETCoreSDK
  #    这个环正是当年退回「适配器内置」方案的原因。check_deps.sh 会拦。
  s.dependency 'OSETCoreAd'
  s.dependency 'AdSetQDAAdSDK', '= 3.0.22'

  # 映射由 core 集中管理；适配器类仅通过 NSClassFromString 引用。
  # 必须用 -ObjC 把静态库里的 Objective-C 类链接进宿主，否则运行时找不到类。
  s.user_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
end
