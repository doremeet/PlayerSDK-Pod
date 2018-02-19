//
//  IBandAbstractPlayer.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandDisposable.h"

@class IBandPlayer;
@class IBandError;
@protocol IBandPlayerVariant;

/*!
 * @typedef IBandPlayerReadyState
 * @brief A list of player ready state.
 * @constant IBandPlayerStateUninitialize When the the player first created without any source.
 * @constant IBandPlayerStateInitialize When player get a stream to play but is not ready to play yet.
 * @constant IBandPlayerStateBuffer When the player is buffering
 * @constant IBandPlayerStateReady When the player is ready to play or playing
 * @constant IBandPlayerStateError When the player got an error
 */
typedef NS_ENUM(NSUInteger, IBandPlayerReadyState) {
    IBandPlayerStateUninitialized,
    IBandPlayerStateInitialized,
    IBandPlayerStateBuffering,
    IBandPlayerStateReady,
    IBandPlayerStateError,
};

@interface IBandAbstractPlayer : NSObject <IBandDisposable>

/*!
 * @discussion Get current state.
 * @return IBandPlayerState
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayerReadyState) getReadyState;

/*!
 * @discussion Set the playWhenReady flag with the given value.
 * Make the player play or pause when the player is or will be on READY state.
 * @param playWhenReady BOOL
 * @link State
 * @noexcept This method do NOT throws exception on any case
 */
-(void) setPlayWhenReady:(BOOL) playWhenReady;

/*!
 * @discussion Get the flag playWhenReady (default to true).
 * @return BOOL
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) getPlayWhenReady;

/*!
 * @discussion True if the player is playing right now.
 * @return BOOL
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) isPlaying;

/*!
 * @discussion Seek to given position in seconds.
 * If the given position if bigger then the duration trigger
 * IPlayerReachEndListener.
 * @param position NSTimeInterval
 * @throw IBandIllegalStateException if player state is not playable
 */
-(void) seekTo:(NSTimeInterval) position;

/*!
 * @discussion Get the player current position in seconds, value between 0 to getDuration();
 * Default to 0, if state isn't playable.
 * @return NSTimeInterval
 * @noexcept This method do NOT throws exception on any case
 */
-(NSTimeInterval) getCurrentPosition;

/*!
 * @discussion Get the player buffer position in seconds.
 * Default to 0, if state isn't playable.
 * @return NSTimeInterval
 * @noexcept This method do NOT throws exception on any case
 */
-(NSTimeInterval) getBufferPosition;

/*!
 * @discussion Get the duration of the current stream in seconds.
 * Default to 0, if state isn't playable or duration is unknown.
 * @return NSTimeInterval
 * @noexcept This method do NOT throws exception on any case
 */
-(NSTimeInterval) getDuration;

/*!
 * @discussion Change player mute state.
 * @param mute BOOL
 * @noexcept This method do NOT throws exception on any case
 */
-(void) setMute:(BOOL) mute;

/*!
 * @discussion True if player is on mute (default to false).
 * @return BOOL
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) isMuted;

/*!
 * @discussion Get all variants for this source.
 * @return NSArray<IBandPlayerVariant>*
 * @throw IBandIllegalStateExecption if player state is not playable
 */
-(NSArray<IBandPlayerVariant>*) getVariants;

/*!
 * @discussion True only if player state is READY or BUFFER
 * @return BOOL
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) isPlayable;

/*!
 * @discussion Get current played variant.
 * @return id<IBandPlayerVariant>
 * @throw IBandIllegalStateException if player state is not playable
 */
-(id<IBandPlayerVariant>) getCurrentVariant;

/*!
 * @discussion Get current played variant index (zero based index).
 * @return NSInteger
 * @throw IBandIllegalStateException if player state is not playable
 */
-(NSInteger) getCurrentVariantIndex;

/*!
 * @discussion True if player switching variant mode is automatically.
 * @return BOOL
 * @throw IBandIllegalStateException if player state is not playable
 */
-(BOOL) isAutoVariant;

/*!
 * @discussion Change player variant with the given index (0 based).
 * @param variantIndex NSInteger
 * @throw IBandIllegalStateException if player state is not playable
 * @throw IBandInvalidArgumentException if index is out of range
 */
-(void) setCurrentVariant:(NSInteger) variantIndex;

/*!
 * @discussion Change player to auto variant switch mode.
 * @throw IBandIllegalStateException if player state is not playable
 */
-(void) setAutoVariant;

/*!
 * @discussion Reset the ready state to UNINITIALIZED and clear any source that currently playing.
 * @noexcept This method do NOT throws exception on any case
 */
-(void) reset;
@end
