//
//  IBandEvent.h
//  Pods
//
//  Created by Yogev Barber on 25/07/2017.
//
//

#import <Foundation/Foundation.h>
#import "IEvents.h"

@class IBandError;
@class IBandApi;
@protocol IBandPlayerVariant;
@protocol IEventPlayerDelegate;

@interface IBandPlayerEvent : NSObject
- (instancetype)initWithClientApi:(IBandApi*)clientApi delegate:(id<IEventPlayerDelegate>)delegate;

-(void) playerSetSourceWithStreamId:(NSString*)streamId structure:(NSString*)structure url:(NSString*)url;
-(void) playerReplaceSourceWithStreamId:(NSString*)streamId structure:(NSString*)structure url:(NSString*)url;
-(void) playerSetStream:(NSString*)streamId;
-(void) playerReplaceStream:(NSString*)streamId;
-(void) playerStateReadyWithVariant:(id<IBandPlayerVariant>)variant;
-(void) playerVariantCreated;
-(void) playerStartBuffering;
-(void) playerSwitchVariant:(id<IBandPlayerVariant>)variant isForce:(BOOL)isForce;
-(void) playerChangeQuality:(id<IBandPlayerVariant>)variant;
-(void) playerBeginSeek:(NSTimeInterval)position oldPosition:(NSTimeInterval)oldPosition;
-(void) playerSetError:(IBandError*)error;
-(void) playerStop;
-(void) playerPlayableChange:(BOOL)isPlayable;
-(void) playerSetAuto;
-(void) playerRelease;
-(void) playerReset;
@end
