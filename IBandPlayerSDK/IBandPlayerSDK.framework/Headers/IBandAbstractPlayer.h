//
//  IBandAbstractPlayer.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IBandPlayer;
@class IBandError;
@protocol IBandPlayerVariant;

typedef NS_ENUM(NSUInteger, IBandPlayerState) {
    /**
     * When the the player first created without any source
     */
    IBandPlayerStateUninitialize,
    
    /**
     * When player get a stream to play but is not ready to play yet.
     */
    IBandPlayerStateInitialize,
    
    /**
     * When the player is buffering
     */
    IBandPlayerStateBuffer,
    
    /**
     * When the player is ready to play or playing
     */
    IBandPlayerStateReady,
    
    /**
     * When the player got an error
     */
    IBandPlayerStateError,
};

@interface IBandAbstractPlayer : NSObject

/**
 * Get current state.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayerState) getState;

/**
 * Set the playWhenReady flag with the given value.
 * Make the player play or pause when the player is or will be on READY state.
 *
 * @link State
 * @noexcept This method do NOT throws exception on any case
 */
-(void) setPlayWhenReady:(BOOL) playWhenReady;

/**
 * Get the flag playWhenReady (default to true).
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) getPlayWhenReady;

/**
 * True if the player is playing right now.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) isPlaying;

/**
 * Seek to given position in seconds.
 * If the given position if bigger then the duration trigger
 * IPlayerReachEndListener.
 *
 * @throw IBandIllegalStateException if player state is not playable
 */
-(void) seekTo:(NSTimeInterval) position;

/**
 * Get the player current position in seconds, value between 0 to getDuration();
 * Default to 0, if state isn't playable.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSTimeInterval) getCurrentPosition;

/**
 * Get the player buffer position in seconds.
 * Default to 0, if state isn't playable.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSTimeInterval) getBufferPosition;

/**
 * Get the duration of the current stream in seconds.
 * Default to 0, if state isn't playable or duration is unknown.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSTimeInterval) getDuration;

/**
 * Change player mute state.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) setMute:(BOOL) mute;

/**
 * True if player is on mute (default to false).
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) isMuted;

/**
 * Get all variants for this source.
 *
 * @throw IBandIllegalStateExecption if player state is not playable
 */
-(NSArray<IBandPlayerVariant>*) getVariants;

/**
 * True only if player state is READY or BUFFER
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) isPlayable;

/**
 * Get current played variant.
 *
 * @throw IBandIllegalStateException if player state is not playable
 */
-(id<IBandPlayerVariant>) getCurrentVariant;

/**
 * Get current played variant index (zero based index).
 *
 * @throw IBandIllegalStateException if player state is not playable
 */
-(NSInteger) getCurrentVariantIndex;

/**
 * True if player switching variant mode is automatically.
 *
 * @throw IBandIllegalStateException if player state is not playable
 */
-(BOOL) isAutoVariant;

/**
 * Change player variant with the given index (0 based).
 *
 * @throw IBandIllegalStateException if player state is not playable
 * @throw IBandInvalidArgumentException if index is out of range
 */
-(void) setCurrentVariant:(NSInteger) variantIndex;

/**
 * Change player to auto variant switch mode.
 *
 * @throw IBandIllegalStateException if player state is not playable
 */
-(void) setAutoVariant;

/**
 * Release the player and all the resources of this player.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) releasePlayer;
@end
