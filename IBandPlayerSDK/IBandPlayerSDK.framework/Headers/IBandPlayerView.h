//
//  YBPlayerView.h
//  Player test
//
//  Created by Yogev Barber on 02/07/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

typedef NS_ENUM(NSUInteger, IBandPlayerViewVideoScale) {
    IBandPlayerViewVideoScaleStretch,
    IBandPlayerViewVideoScaleCrop,
    IBandPlayerViewVideoScaleFit,
};

@protocol IBandPlayerViewDelegate;


@interface IBandPlayerView : UIViewController
@property (nonatomic, weak) id<IBandPlayerViewDelegate> delegate;

/**
 * True if VR mode is ON
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) getVRMode;

/**
 * Change the VR mode
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) setVRMode:(BOOL)vrMode;

/**
 * Reset the position of the display
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) resetDisplayPosition;

/**
 * Get the current position angle of the panorama display on the Z axis (radiands).
 * Return `0` if the current display is not panorama.
 *
 */
-(double) getPanoramaPositionAngle;

/**
 * Get the current position matrix of the panorama display (4x4 matrix).
 * Return identity matrix if the current display is not panorama.
 *
 */
-(GLKMatrix4) getPanoramaPositionMatrix;

/**
 * Set video scale
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) setVideoScale:(IBandPlayerViewVideoScale) videoScale;

/**
 * Get current video scale (default to FIT)
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayerViewVideoScale)getVideoScale;
@end
