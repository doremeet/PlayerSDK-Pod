//
//  IBandAbstractPlayer+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandAbstractPlayer.h"
#import <CoreVideo/CoreVideo.h>

@class IBandSource;
@class AVPlayer;
@protocol IBandPlayerVariant;

@interface IBandAbstractPlayer (Internal)
#pragma mark - local methods
/**
 * Get the current bandwidth on the network in byte per seconds (bps)
 *
 * @throw IPlayerIllegalState if player state is not playable
 */
-(double) getBandwidth;

#pragma mark - protected methods
/**
 * Set the player sources.
 * Set player state to INITIALIZE and reset the player position.
 *
 * @link State
 */
-(void) setSources:(NSArray<IBandSource*>*) sources;

/**
 * Replace the player sources.
 * Set player state to INITIALIZE but save the current the player position.
 *
 * @link State
 */
-(void) replaceSources:(NSArray<IBandSource*>*) sources;

/**
 * Get player sources or NULL if not initialize.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSArray<IBandSource*>*) getSources;

/**
 * Get player active source or NULL if not initialize.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandSource*) getActiveSource;

/**
 * Event for any time the state changed.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onReadyStateChanged:(IBandPlayerReadyState) state oldState:(IBandPlayerReadyState) oldState;

/**
 * Event when the player isPlayable method change.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onPlayableChanged:(BOOL) isPlayable;

/**
 * Event when the player stop playing and position reach to it end.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onReachEnd;

/**
 * Event for any time the variants array changed
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onVariantsCreated:(NSArray<IBandPlayerVariant>*) variants;

/**
 * Event when the player change auto. variant automatically.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onCurrentVariantChanged:(NSUInteger)variantIndex oldVariantIndex:(NSUInteger) oldVariantIndex;

/**
 * Event when the player switch state to ERROR.
 *
 * @noexcept This method do NOT throws exception on any case
 */

/**
 * Event when the current position updated.
 * During playback this should fired every 15-250 milliseconds.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onCurrentPositionUpdate:(NSTimeInterval)currentPosition;

/**
 * Event when the buffer position updated.
 * During loading this should fired every 15-250 milliseconds.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onBufferPositionUpdate:(NSTimeInterval)bufferPosition;

/**
 * Event when the ready state changed to ERROR.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onError:(IBandError*) error;

-(void) setSource:(IBandSource*)source;

-(void)replaceSource:(IBandSource*)source;

-(void)createError:(NSError*)error force:(BOOL)force;

#pragma mark - player view
-(CVPixelBufferRef)retrievePixelBufferToDraw;

-(AVPlayer *)retrieveAVPlayer;

@end
