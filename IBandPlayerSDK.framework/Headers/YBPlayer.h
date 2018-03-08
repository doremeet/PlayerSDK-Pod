//
//  YBPlayer.h
//  Player test
//
//  Created by Yogev Barber on 27/06/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "YBPlayerError.h"
#import "YBPlayerUtils.h"
/// play state
///
/// - none: none
/// - playing: playing
/// - paused: pause
/// - playFinished: finished
/// - error: play failed
typedef enum : NSUInteger {
    YBPlayerStateNone,
    YBPlayerStateBuffer,
    YBPlayerStateReadyToPlay,
//    YBPlayerStatePlaying,
//    YBPlayerStatePaused,
    YBPlayerStatePlayFinished,
    YBPlayerStateError
} YBPlayerState;

/// buffer state
///
/// - none: none
/// - readyToPlay: ready To Play
/// - buffering: buffered
/// - stop : buffer error stop
/// - bufferFinished: finished
//typedef enum : NSUInteger {
//    YBPlayerBufferStateNone,           // default
//    YBPlayerBufferStateReadyToPlay,
//    YBPlayerBufferStateBuffering,
//    YBPlayerBufferStateStop,
//    YBPlayerBufferStateBufferFinished,
//} YBPlayerBufferState;

/// play background mode
///
/// - suspend: suspend
/// - autoPlayAndPaused: auto play and Paused
/// - proceed: continue
typedef enum : NSUInteger {
    YBPlayerBackgroundModeSuspend,
    YBPlayerBackgroundModeAutoPlayAndPause,
    YBPlayerBackgroundModeProceed,
} YBPlayerBackgroundMode;

@class YBPlayer;


@protocol YBPlayerDelegate <NSObject>
@optional
// play state
-(void)ybPlayerStateDidChange:(YBPlayer*)player state:(YBPlayerState)state;

//buffer state
-(void)ybPlayerFailed:(YBPlayer*)player error:(YBPlayerError*)error;

-(void)playerLayerReady;

-(void)ybPlayerSwitchBitrate:(YBPlayer*)player uri:(NSString*)uri oldBitrate:(float)oldBitrate newBitrate:(float)newBitrate serverAddress:(NSString*)serverAddress sessionId:(NSString*)sessionId bandWidth:(float)bandwidth;

-(void)ybPlayerCurrentPositionUpdate:(NSTimeInterval)currentPosition;

-(void)ybPlayerBufferPositionUpdate:(NSTimeInterval)bufferPosition;
@end

@interface YBPlayer : NSObject <AVAudioPlayerDelegate>
@property (nonatomic, weak) id<YBPlayerDelegate> delegate;
@property (nonatomic, strong) AVPlayer *player;
@property (nonatomic, strong) YBPlayerError *error;
@property (nonatomic, assign) BOOL needToPlay;

-(void)replaceVideoUrl:(NSURL*)URL withCurrentTime:(BOOL)currentTime;
-(void)reloadPlayer;
-(void)cleanPlayer;
-(void)play;
-(void)pause;
-(void)seekTime:(NSTimeInterval)time;
-(void)seekTime:(NSTimeInterval)time complitionHandler:(void (^)(BOOL))complition;
-(BOOL)isPlaying;
-(NSTimeInterval)getCurrentPosition;
-(NSTimeInterval)getCurrentBuffer;
-(NSTimeInterval)getTotalDuration;
-(void)setMuted:(BOOL)muted;
-(float)getRate;
-(CVPixelBufferRef)retrievePixelBufferToDraw;
-(AVPlayerLayer *)retrieveAVPlayerLayer;
-(YBPlayerMediaFormat)getMediaFormat;
-(void)saveLastTime;
@end
