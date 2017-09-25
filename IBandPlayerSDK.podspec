Pod::Spec.new do |s|
  s.name                  = "IBandPlayerSDK"
  s.version               = "0.1.0"
  s.summary               = "iOS library to play streams from IBand"
  s.homepage              = "http://www.iband.io"
  s.author                = { "Yogev Barber" => "yogev@iband.io" }
  s.platform              = :ios
  s.source                = { :http => "https://iband-io.s3.amazonaws.com/IBandPlayerPod/v0.1.0/IBandPlayerSDK.zip" }  
  s.vendored_frameworks   = 'IBandPlayerSDK/IBandPlayerSDK.framework'
  s.resource              = "IBandPlayerSDK/Resources/Shader.{fsh,vsh}"
  s.ios.deployment_target = '8.0'
  s.frameworks            = 'SystemConfiguration', 'coreMedia', 'coreGraphics', 'coreMotion', 'GLKit', 'AudioToolbox', 'AVFoundation', 'OpenGLES'
  s.library               = "c++"
  s.requires_arc          = true
  s.license               = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2017 IBand, Inc. All rights reserved.
      LICENSE
  }
end
