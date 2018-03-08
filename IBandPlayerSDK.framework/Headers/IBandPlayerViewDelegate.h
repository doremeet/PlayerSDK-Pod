//
//  DRM360PlayerDelegate.h
//  DoReMeet
//
//  Created by Yogev Barber on 28/12/2016.
//  Copyright © 2016 DanyL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandDelegatable.h"

@class AVPlayer;

@protocol IBandPlayerViewDelegate <IBandDelegate>
- (CVPixelBufferRef)retrievePixelBufferToDraw;
- (AVPlayer*)retrieveAVPlayer;
@optional

@end
