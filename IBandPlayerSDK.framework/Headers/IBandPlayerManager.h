//
//  IBandPlayerManager.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 28/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandDelegatable.h"
#import "IBandDisposable.h"

@class IBandPlayerManager;
@class IBandPlayer;
@class IBandPlayerView;
@class IBandEvent;
@class IBandStream;
@class IBandError;

/*!
 * @typedef IBandPlayerManagerDisplayState
 * @brief A list of manager display state.
 * @constant IBandPlayerManagerDisplayStateUninitilized When the manager created.
 * @constant IBandPlayerManagerDisplayStateInitializing When the event streams are loading.
 * @constant IBandPlayerManagerDisplayStateInitialized When there is no streams or when all streams loaded and the player is not playable
 * @constant IBandPlayerManagerDisplayStatePlayable When display state initialized and the player is on playable state.
 * @constant IBandPlayerManagerDisplayStateError When there is a fatal error on the player or on the streams.
 */

typedef NS_ENUM(NSUInteger, IBandPlayerManagerDisplayState) {
    IBandPlayerManagerDisplayStateUninitilized,
    IBandPlayerManagerDisplayStateInitializing,
    IBandPlayerManagerDisplayStateInitialized,
    IBandPlayerManagerDisplayStatePlayable,
    IBandPlayerManagerDisplayStateError,
};

/*!
 * @typedef IBandPlayerManagerReadyState
 * @brief A list of manager ready state.
 * @constant IBandPlayerManagerReadyStateReady When there is not more loading on the manager components.
 * @constant IBandPlayerManagerReadyStateLoading When the player or the streams are loading.
 */

typedef NS_ENUM(NSUInteger, IBandPlayerManagerReadyState) {
    IBandPlayerManagerReadyStateReady,
    IBandPlayerManagerReadyStateLoading,
};



@protocol IBandPlayerManagerDelegate <IBandDelegate>

/*!
 * @discussion Listen for any time the display state changed.
 * @param manager IBandPlayerManager
 * @param state IBandPlayerManagerDisplayState
 * @param oldState IBandPlayerManagerDisplayState
 * @noexcept This method do NOT throws exception on any case
 */
-(void)onManagerDisplayStateChanged:(IBandPlayerManager*)manager state:(IBandPlayerManagerDisplayState)state oldState:(IBandPlayerManagerDisplayState)oldState;

/*!
 * @discussion Listen for any time the ready state changed.
 * @param manager IBandPlayerManager
 * @param state IBandPlayerManagerReadyState
 * @param oldState IBandPlayerManagerReadyState
 * @noexcept This method do NOT throws exception on any case
 */
-(void)onManagerReadyStateChanged:(IBandPlayerManager*)manager state:(IBandPlayerManagerReadyState)state oldState:(IBandPlayerManagerReadyState)oldState;

/*!
 * Listen for the player event "onPlayerCurrentPositionUpdate".
 * @param manager IBandPlayerManager
 * @param currentPosition NSTimeInterval
 * @noexcept This method do NOT throws exception on any case
 */
-(void)onManagerPlayerCurrentPositionUpdate:(IBandPlayerManager*)manager currentPosition:(NSTimeInterval)currentPosition;

/*!
 * Listen for the player event "onPlayerBufferPositionUpdate".
 * @param manager IBandPlayerManager
 * @param bufferPosition NSTimeInterval
 * @noexcept This method do NOT throws exception on any case
 */
-(void)onManagerPlayerBufferPositionUpdate:(IBandPlayerManager*)manager bufferPosition:(NSTimeInterval)bufferPosition;

/**
 * Listen for the player event "onPlayerReachEnd".
 * @param manager IBandPlayerManager
 * @noexcept This method do NOT throws exception on any case
 */
-(void)onManagerPlayerReachEnd:(IBandPlayerManager*)manager;

/*!
 * Listen for the player event "onPlayerCurrentVariantChanged".
 * @param manager IBandPlayerManager
 * @param variantIndex NSInteger
 * @param oldVariantIndex NSInteger
 * @noexcept This method do NOT throws exception on any case
 */
-(void)onManagerPlayerCurrentVariantChanged:(IBandPlayerManager*)manager variantIndex:(NSInteger)variantIndex oldVariantIndex:(NSInteger)oldVariantIndex;



/*!
 * Listen when there is a fatal error on the manager (ie. state changed to `ERROR`).
 * @param manager IBandPlayerManager
 * @noexcept This method do NOT throws exception on any case
 */
-(void)onManagerError:(IBandPlayerManager*)manager error:(IBandError*)error;
@end

/*!
 * An player manager that manage player streams and display states.
 */
@interface IBandPlayerManager : NSObject <IBandDelegatable, IBandDisposable>

/*!
 * @discussion Remove a listener from the stream.
 * @param delegate id<IBandPlayerManagerDelegate>
 * @noexcept This method do NOT throws exception on any case
 */
-(void) addDelegate:(id<IBandPlayerManagerDelegate>) delegate;

/**
 * Remove a delegate from the manager.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) removeDelegate:(id<IBandPlayerManagerDelegate>) delegate ;


/*!
 * @discussion Get current display state.
 * @return IBandPlayerManagerDisplayState
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayerManagerDisplayState) getDisplayState;

/*!
 * @discussion Get current ready state.
 * @return IBandPlayerManagerReadyState
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayerManagerReadyState) getReadyState;


/*!
 * @discussion Get current stream open.
 * If the event has no streams, return `false`.
 * @return BOOL
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) isStreamOpen;

/*!
 * @discussion Get the current player instance of the event manager.
 * @return IBandPlayer
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayer*) getPlayer;

/*!
 * @discussion Get the player view of the manager.
 * @return IBandPlayerView
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayerView*) getPlayerView;

/*!
 * @discussion Replace the current streams with the given streams and set the state to
 * INITIALIZING or INITIALIZED (trigger a change event as well).
 * It's the user responsibility to release the previous streams.
 * @param streams NSArray<IBandStream*>
 * @noexcept This method do NOT throws exception on any case
 */
-(void) setStreams:(NSArray<IBandStream*>*)streams;

/*!
 * @discussion Get the total number of streams on this manager.
 * @return NSInteger
 * @noexcept This method do NOT throws exception on any case
 */
-(NSInteger) getStreamCount;

/**
 * @discussion Get the selected stream index (default to `0`).
 * If the manager has no streams, return `0`.
 * @return NSInteger
 * @noexcept This method do NOT throws exception on any case
 */
-(NSInteger) getSelectedStreamIndex;

/*!
 * @discussion Set the selected stream index.
 * @param index NSNumber
 * @throws IBandInvalidArgumentException If the index is greater or equal to `streamsCount` or
 *   if index is lower then `0`.
 */
-(void) setSelectedStreamIndex:(NSInteger)index;

/*!
 * @discussion Get the selected stream or NULL if the event has no streams.
 * @return IBandStream
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandStream*) getSelectedStream;

/*!
 * @discussion Get all streams on the event.
 * @return NSArray<IBandStream*>*
 * @noexcept This method do NOT throws exception on any case
 */
-(NSArray<IBandStream*>*) getStreams;
@end
