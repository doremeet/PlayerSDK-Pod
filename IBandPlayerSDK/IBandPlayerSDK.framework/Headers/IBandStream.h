//
//  IBandStream.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 09/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandPublicEnums.h"

typedef NS_ENUM(NSUInteger, IBandStreamState) {
    /**
     * When the stream is initializing and loading data
     */
    IBandStreamStateInitialize,
    
    /**
     * When the stream state is open
     */
    IBandStreamStateOpen,
    
    /**
     * When the stream state is closed
     */
    IBandStreamStateClosed,
    
    /**
     * When the stream got error while initializing or refreshing stram data
     */
    IBandStreamStateError,
};

@class IBandStream;
@class IBandError;

@protocol IBandStreamDelegate <NSObject>
-(void) onStreamStateChanged:(IBandStream*)stream state:(IBandStreamState)state oldState:(IBandStreamState)oldState;
-(void) onStreamError:(IBandStream*)stream error:(IBandError*)error;
@end

@interface IBandStream : NSObject

@property (nonatomic, weak) id<IBandStreamDelegate> delegate;
@property (nonatomic, weak) id<IBandStreamDelegate> playerDelegate;

#pragma mark - public
/**
 * Get the stream id.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSString*) getId;

/**
 * Start watching for stream changes and update the stream accordingly.
 * The stream will watch for changes by default.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) watch;

/**
 * Stop watching for stream changes.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) unwatch;

/**
 * Get the stream state
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandStreamState) getState;

/**
 * Get the stream type
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandStreamType) getType;

/**
 * Get the stream structure
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandStreamStructure) getStructure;

/**
 * Get stream thumbnail url for the givn position in seconds.
 * Return NULL if the stream state is not OPEN or if there is no thumbnails support.
 *
 * @noexcept This method do NOT throws exception on any case
 */

-(NSString*) getThumbnail:(NSTimeInterval)position;

/**
 * Release the stream and all the resources of this stream.
 *
 * @noexcept This method do NOT throws exception on any case
 */
 -(void) releaseStream;



@end
