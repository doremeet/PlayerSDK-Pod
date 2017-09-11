Pod::Spec.new do |s|
  s.name         = "IBandPlayerSDK"
  s.version      = "0.0.1"
  s.summary      = "iOS library to play streams from IBand"
  s.homepage     = "http://www.iband.io"
  s.author       = { "Yogev Barber" => "yogev@iband.io" }
  s.platform     = :ios
  s.source       = { :git => "https://github.com/doremeet/PlayerSDK-Pod.git", :tag => "#{s.version}" }
  s.public_header_files = 'IBandPlayerSDK/IBandPlayerSDK.framework/Headers/*.h'
  s.vendored_frameworks = 'IBandPlayerSDK/IBandPlayerSDK.framework'
  s.ios.deployment_target = '8.0'
  s.frameworks = 'UIKit', 'SystemConfiguration', 'coreMedia', 'coreGraphics', 'coreMotion', 'GLKit', 'AudioToolbox', 'AVFoundation', 'OpenGLES'
  s.library   = "c++"
  s.requires_arc = true
  # s.xcconfig  =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/IBandPlayerSDK"',
  #                  'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/Headers/IBandPlayerSDK"' }
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2017 IBand, Inc. All rights reserved.
      LICENSE
  }
end
