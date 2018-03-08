//
//  IEventPlayer.h
//  Player test
//
//  Created by Yogev Barber on 12/07/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <Foundation/Foundation.h>
@class IBandApi;
@protocol IBandPlayerVariant;

@protocol IEventPlayerDelegate <NSObject>
-(BOOL)isPlayable;
-(double)getBandwidth;
-(NSTimeInterval)getCurrentPosition;
@end

@interface IEvents : NSObject

- (instancetype)initWithClientApi:(IBandApi*)clientApi delegate:(id<IEventPlayerDelegate>)delegate;

/**
 * Reset "sessionId" and "bufferCount" and start `timeToStart` timers.
 *
 * @call: Every time IBandPlayer.setStream or IPlayer.replaceSource is called.
 */
-(void)resetSession:(NSString*)streamId;

/**
 * Start timer `timeToPlay` and `timeToFirstByte` for play event
 *
 * @call: After IBandPlayer.setStream or replaceSource,
 *     When streamState changed to AVIALABLE.
 */
-(void)gotStreamData:(NSString*)structure playbackUrl:(NSString*)playbackUrl;

/**
 * Stop timer for `timeToFirstByte` for play event
 *
 * @call: After IPlayer.setSource or replaceSource,
 *     When IPlayer.state changed to INITIALIZE.
 */
-(void)gotFirstByte;

/**
 * Stop `timeToPlay` and `timeToStart` timers,
 * Start `sessionDuration` timer and send "play" event
 *
 * @call: When the playerState change to READY on the first time since the last INITIALIZE state.
 */
-(void)sendPlay:(id<IBandPlayerVariant>) variant;

/**
 * Start timer `bufferTime`
 *
 * @call: When player state changed to BUFFERING and user not call seekTo or setCurrentVariantIndex.
 */
-(void)startBuffering;

/**
 * Stop timer `bufferTime` and send event "buffer".
 * Increment "bufferCount".
 *
 * @call: When player state changed from BUFFERING to READY and startBuffering called on last BUFFERING state.
 */
-(void)sendBuffer;

/**
 * Send "switchVariant" event
 *
 * @call: When player switch variant, by user (isForce = true) or automatically (isForce = false).
 */
-(void)sendSwitchVariant:(id<IBandPlayerVariant>) variant  isForce:(BOOL)isForce;

/**
 * Start timer "timeToPlay" and store "selectedQuality" for event "seek"
 *
 * @call: When the user change the quality or set it to Auto.
 */
-(void)changeQuality:(NSString*) selectedQuality;

/**
 * Stop timer "timeToPlay" and send event "changeQuality"
 *
 * @call: When player state changed from BUFFERING to READY after calling changeQuality().
 */
-(void)sendChangeQuality;

/**
 * Start timer "timeToPlay" and store "seekDifference" for event "seek"
 *
 * @call: When the user call IPlayer.setSeekPosition().
 */
-(void)beginSeek:(NSInteger) seekDifference;

/**
 * Stop timer "timeToPlay" and send event "seek"
 *
 * @call: When player state changed from BUFFERING to READY after calling beginSeek().
 */
-(void)sendSeek;

/**
 * Send "stop" event.
 *
 * @call: When player isPlayable changed to false
 *      or when the player released
 */
-(void)sendStop;

/**
 * Send "error" event.
 *
 * @call: When player state changed to ERROR.
 */
-(void)sendError:(NSString*)playbackErrorType playbackErrorMessage:(NSString*) playbackErrorMessage;
@end
