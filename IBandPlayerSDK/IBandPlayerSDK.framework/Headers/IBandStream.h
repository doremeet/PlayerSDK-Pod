//
//  IBandStream.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 09/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandWatchable.h"
#import "IBandDelegatable.h"
#import "IBandDisposable.h"

/*!
 * @typedef IBandStreamStructure
 * @brief A list of stream structutes.
 * @constant IBandStreamStructureUndefined When the stream state is INITIALIZE
 * @constant IBandStreamStructurePlain When the stream structure is "plain"
 * @constant IBandStreamStructureEquirectangular When the stream structure is "equirectangular"
 */
typedef NS_ENUM(NSUInteger, IBandStreamStructure) {
    IBandStreamStructureUndefined,
    IBandStreamStructurePlain,
    IBandStreamStructureEquirectangular,
};

/*!
 * @typedef IBandStreamState
 * @brief A list of stream state.
 * @constant IBandStreamStateInitialize When the stream is initializing and loading data.
 * @constant IBandStreamStateOpen When the stream state is open
 * @constant IBandStreamStateClosed When the stream state is closed
 * @constant IBandStreamStateError When the stream got error while initializing or refreshing stram data
 */

typedef NS_ENUM(NSUInteger, IBandStreamState) {
    IBandStreamStateInitialize,
    IBandStreamStateOpen,
    IBandStreamStateClosed,
    IBandStreamStateError,
};


@class IBandStream;
@class IBandError;

@protocol IBandStreamDelegate <IBandDelegate>
-(void) onStreamStateChanged:(IBandStream*)stream state:(IBandStreamState)state oldState:(IBandStreamState)oldState;
-(void) onStreamError:(IBandStream*)stream error:(IBandError*)error;
@end


@interface IBandStream : IBandWatchable <IBandDelegatable, IBandDisposable>

#pragma mark - public

/*!
 * @discussion Add a delegate for the stream.
 * @param delegate id<IBandStreamDelegate>
 * @noexcept This method do NOT throws exception on any case
 */
-(void) addDelegate:(id<IBandStreamDelegate>)delegate;

/*!
 * @discussion Remove a listener from the stream.
 * @param delegate id<IBandStreamDelegate>
 * @noexcept This method do NOT throws exception on any case
 */
-(void) removeDelegate:(id<IBandStreamDelegate>)delegate;


/*!
 * @discussion Get the stream state
 */
-(IBandStreamState) getState;

/**
 * Get the stream structure
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandStreamStructure) getStructure;

/**
 * Get stream thumbnail url for the givn position in miliseconds.
 * Return NULL if the stream state is not OPEN or if there is no thumbnails support.
 *
 * @noexcept This method do NOT throws exception on any case
 */

-(NSString*) getThumbnail:(NSTimeInterval)position;

/*!
 * Start watching for changes for this stream.
 * In addition, call `watcherSync` if state is `OPEN` or `CLOSED`.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) watch;
@end
