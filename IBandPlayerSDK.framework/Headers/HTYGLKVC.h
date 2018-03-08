//
//  HTYGLKVC.h
//  HTY360Player
//
//  Created by  on 11/8/15.
//  Copyright © 2015 Hanton. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "IBandPlayerViewDelegate.h"

@interface HTYGLKVC : GLKViewController <UIGestureRecognizerDelegate>

@property (nonatomic, strong) GLKView *view;
@property (weak, nonatomic, readwrite) id<IBandPlayerViewDelegate> videoPlayerController;
@property (assign, nonatomic, readonly) BOOL isUsingMotion;
- (instancetype)initWithSupportedInterfaceOrientations:(UIInterfaceOrientationMask)supportedInterfaceOrientations;
- (void)startDeviceMotion;
- (void)stopDeviceMotion;
- (void)resetDisplayPosition;
- (double)getPanoramaPositionAngle;
- (GLKMatrix4)getPanoramaPositionMatrix;
@end
