//
//  YBPlayerView.h
//  Player test
//
//  Created by Yogev Barber on 02/07/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

/*!
 * @typedef IBandPlayerViewVideoScale
 * @brief A list of video scales.
 * @constant IBandPlayerViewVideoScaleStretch When the Video Scale is stretch
 * @constant IBandPlayerViewVideoScaleCrop When the Video Scale is crop
 * @constant IBandPlayerViewVideoScaleFit When the Video Scale is fit
 */
typedef NS_ENUM(NSUInteger, IBandPlayerViewVideoScale) {
    IBandPlayerViewVideoScaleStretch,
    IBandPlayerViewVideoScaleCrop,
    IBandPlayerViewVideoScaleFit,
};

@protocol IBandPlayerViewDelegate;


@interface IBandPlayerView : UIViewController

/*!
 * @discussion indecate if the view in VR mode
 * @return True if VR mode is ON
 */
-(BOOL) getVRMode;

/*!
 * @discussion Change the VR mode
 * @param vrMode BOOL
 */
-(void) setVRMode:(BOOL)vrMode;

/*!
 * @discussion Reset the position of the display
 */
-(void) resetDisplayPosition;

/*!
 * @discussion Get the current position angle of the panorama display on the Z axis (radiands).
 * @return Return `0` if the current display is not panorama.
 */
-(double) getPanoramaPositionAngle;

/*!
 * @discussion Get the current position matrix of the panorama display (4x4 matrix).
 * @return Return identity matrix if the current display is not panorama.
 */
-(GLKMatrix4) getPanoramaPositionMatrix;

/*!
 * @discussion Set video scale
 * @param videoScale IBandPlayerViewVideoScale
 */
-(void) setVideoScale:(IBandPlayerViewVideoScale) videoScale;

/*!
 * @discussion Get current video scale (default to FIT)
 * @return  videoScale IBandPlayerViewVideoScale
 */
-(IBandPlayerViewVideoScale)getVideoScale;
@end
