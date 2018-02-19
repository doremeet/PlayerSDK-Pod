//
//  IBandPlayer.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 09/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandAbstractPlayer.h"
#import "IBandDelegatable.h"

@class IBandPlayer;
@class IBandStream;
@class IBandPlayerView;
@protocol IBandPlayerVariant;

@protocol IBandPlayerDelegate <IBandDelegate>
/*!
 * @discussion Listen for any time the state changed.
 * @param player instance of the player
 * @param state the new state
 * @param oldState the old state
 */
-(void) onPlayerStateChanged:(IBandPlayer*) player state:(IBandPlayerReadyState)state oldState:(IBandPlayerReadyState)oldState;

/*!
 * @discussion Listen when the player stop playing and position reach to it end.
 * @param player instance of the player
 */
-(void) onPlayerReachEnd:(IBandPlayer*) player;

/*!
 * @discussion Listen when the player switch state to ERROR.
 * @param player instance of the player
 * @param error the error
 */
-(void) onPlayerError:(IBandPlayer*)player error:(IBandError*) error;

@optional
/*!
 * @discussion Listen when the player isPlayable method change.
 * @param player instance of the player
 * @param isPlayable indecate if the player is playable
 */
-(void) onPlayerPlayableChanged:(IBandPlayer*) player isPlayable:(BOOL) isPlayable;


/*!
 * @discussion Listen for any time the variants array changed
 * @param player instance of the player
 * @param variants array of the variant from the current source
 */
-(void) onPlayerVariantsCreated:(IBandPlayer*) player variants:(NSArray<IBandPlayerVariant>*) variants;

/*!
 * @discussion Listen for any time the variants array changed
 * @param player instance of the player
 * @param variantIndex the current variant index
 * @param oldVariantIndex the previous variant index
 */
-(void) onPlayerCurrentVariantChanged:(IBandPlayer*)player variantIndex:(NSUInteger)variantIndex oldVariantIndex:(NSUInteger)oldVariantIndex;

/*!
 * @discussion Listen when the current position updated.
 * During playback this should fired every 15-250 milliseconds.
 * @param player instance of the player
 * @param currentPosition the position of the player
 */
-(void) onPlayerCurrentPositionUpdate:(IBandPlayer*)player currentPosition:(NSTimeInterval) currentPosition;

/*!
 * @discussion Listen when the buffer position updated.
 * During loading this should fired every 15-250 milliseconds.
 * @param player instance of the player
 * @param bufferPosition the position of the buffer
 */
-(void) onPlayerBufferPositionUpdate:(IBandPlayer*)player bufferPosition:(NSTimeInterval) bufferPosition;
@end

@interface IBandPlayer : IBandAbstractPlayer <IBandDelegatable>

/*!
 * @discussion Add a delegate for the stream.
 * @param delegate id<IBandPlayerDelegate>
 * @noexcept This method do NOT throws exception on any case
 */
-(void) addDelegate:(id<IBandPlayerDelegate>)delegate;

/**
 * @discussion Remove a listener from the stream.
 * @param delegate id<IBandPlayerDelegate>
 * @noexcept This method do NOT throws exception on any case
 */
-(void) removeDelegate:(id<IBandPlayerDelegate>)delegate;

/*!
 * @discussion Set the current player stream.
 * Set player state to INITIALIZE and reset the player position.
 * Listen to the stream state, if the stream state is not open, the player will wait until
 * the stream state change to OPEN and then set the stream sources on the player.
 * If the stream state is ERROR or will change to ERROR, the player state will change to ERROR also.
 * @param stream IBandStream
 */
-(void) setStream:(IBandStream*) stream;

/*!
 * @discussion Replace the current player stream with the given stream.
 * Set player state to INITIALIZE but save the current the player position.
 * @param stream IBandStream
 */
-(void) replaceStream:(IBandStream*) stream;

/*!
 * @discussion Get the current player stream.
 * @return stream IBandStream
 */
-(IBandStream*) getStream;

/*!
 * @discussion Get the player view or NULL if not set yet.
 * @return view IBandPlayerView
 */
-(IBandPlayerView*) getView;


@end
