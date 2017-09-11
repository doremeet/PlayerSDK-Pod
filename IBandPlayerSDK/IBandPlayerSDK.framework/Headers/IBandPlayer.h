//
//  IBandPlayer.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 09/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandAbstractPlayer.h"

@class IBandPlayer;
@class IBandStream;
@class IBandPlayerView;
@protocol IBandPlayerVariant;

@protocol IBandPlayerDelegate <NSObject>
/**
 * Listen for any time the state changed.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onPlayerStateChanged:(IBandPlayer*) player state:(IBandPlayerState)state oldState:(IBandPlayerState)oldState;

/**
 * Listen when the player isPlayable method change.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onPlayerPlayableChanged:(IBandPlayer*) player isPlayable:(BOOL) isPlayable;

/**
 * Listen when the player stop playing and position reach to it end.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onPlayerReachEnd:(IBandPlayer*) player;

/**
 * Listen for any time the variants array changed
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onPlayerVariantsCreated:(IBandPlayer*) player variants:(NSArray<IBandPlayerVariant>*) variants;

/**
 * Listen when the player change auto. variant automatically.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onPlayerCurrentVariantChanged:(IBandPlayer*)player variantIndex:(NSUInteger)variantIndex oldVariantIndex:(NSUInteger)oldVariantIndex;

/**
 * Listen when the player switch state to ERROR.
 *
 * @noexcept This method do NOT throws exception on any case
 */

/**
 * Listen when the current position updated.
 * During playback this should fired every 15-250 milliseconds.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onPlayerCurrentPositionUpdate:(NSTimeInterval) currentPosition;

/**
 * Listen when the buffer position updated.
 * During loading this should fired every 15-250 milliseconds.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onPlayerBufferPositionUpdate:(NSTimeInterval) bufferPosition;

/**
 * Listen when the player switch state to ERROR.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onPlayerError:(IBandPlayer*) player error:(IBandError*) error;
@end

@interface IBandPlayer : IBandAbstractPlayer
@property (nonatomic, weak) id<IBandPlayerDelegate> delegate;

/**
 * Set the current player stream.
 * Set player state to INITIALIZE and reset the player position.
 * Listen to the stream state, if the stream state is not open, the player will wait until
 * the stream state change to OPEN and then set the stream sources on the player.
 * If the stream state is ERROR or will change to ERROR, the player state will change to ERROR also.
 *
 * @link State
 * @link IBandStream
 */
-(void) setStream:(IBandStream*) stream;

/**
 * Replace the current player stream with the given stream.
 * Set player state to INITIALIZE but save the current the player position.
 *
 * @link State
 * @link IBandStream
 */
-(void) replaceStream:(IBandStream*) stream;

/**
 * Get the current player stream.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandStream*) getStream;

/**
 * Set the player a view.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) setView:(IBandPlayerView*) view;

/**
 * Get the player view or NULL if not set yet.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayerView*) getView;

/**
 * Remove the current player view.
 * Does nothing if the player has no view.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) removeView;
@end
