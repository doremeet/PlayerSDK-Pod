Pod::Spec.new do |s|
  s.name                  = "IBandPlayerSDK"
  s.version               = "0.3.9"
  s.summary               = "iOS library to play streams from IBand"
  s.homepage              = "http://www.iband.io"
  s.author                = { "Yogev Barber" => "yogev@iband.io" }
  s.platform              = :ios
  s.source                = { :http => "https://raw.githubusercontent.com/doremeet/PlayerSDK-Pod/v#{s.version}/IBandPlayerSDK.zip" }  
  s.vendored_frameworks   = 'IBandPlayerSDK.framework'
  s.resource              = "IBandPlayerSDK.framework/Shader.{fsh,vsh}"
  s.ios.deployment_target = '8.2'
  s.frameworks            = 'SystemConfiguration', 'coreMedia', 'coreGraphics', 'coreMotion', 'GLKit', 'AudioToolbox', 'AVFoundation', 'OpenGLES'
  s.library               = "c++"
  s.requires_arc          = true
  s.license               = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2017 IBand, Inc. All rights reserved.
      LICENSE
  }
  s.dependency 'AFNetworking', '~> 3.0'
  s.dependency 'SocketRocket', '~> 0.5.1'
end
