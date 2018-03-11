//
//  IBandSDK.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SDK_VERSION @"0.3.10"
#define SDK_BUILD_NUMBER @"4"

@class IBandPlayer;
@class IBandStream;
@class IBandEvent;
@class IBandError;
@class IBandSession;
@class IBandPlayerManager;

@interface IBandSDK : NSObject

/*!
 @discussion Create a new SDK instance with session and the API key on the dictionary value
 * "IBandSDK.apiKey".
 * @param session IBandSession
 * @return instancetype
 */
- (instancetype)initWithSession:(IBandSession*)session;

/*!
 * @discussion Create a new SDK instance with session and the given API key.
 * @param session IBandSession
 * @param apiKey NSString
 * @throws IBandInvalidArgumentException if the apiKey is on invalid format.
 */
-(instancetype) initWithSession:(IBandSession*)session apiKey:(NSString*)apiKey;


/*!
 * @discussion Get the current sdk session
 * @return IBandSession
 */
-(IBandSession*) getSession;

/*!
 * @discussion Get the current API key.
 * @return NSString
 * @noexcept This method do NOT throws exception on any case
 */
-(NSString*) getApiKey;

/*!
 * Create a new event manager from given event.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayerManager*) createPlayerManager;


/*!
 * @discussion Create a new player instance.
 *
 * @return player IBandPlayer
 */
-(IBandPlayer*) createPlayer;

/*!
 * @discussion Create a new stream instance for given `streamId`.
 @throws IBandInvalidArgumentException if the stream id is on invalid format.
 @param streamId NSString
 @return stream IBandStream
 */
-(IBandStream*) createStream:(NSString*)streamId;

/*!
 * @discussion Get a new event instance for given `eventId`.
 * @param eventId NSString
 * @param success block return event
 * @param failure block return error
 * @throws IBandInvalidArgumentException if the event id is not on invalid format.
 */
-(void) getEvent:(NSString*)eventId success:(void (^)(IBandEvent *event))success failure:(void (^)(IBandError *error))failure;

/*!
 * @discussion Get an array of event instances in the given `categoryId`.
 * @param categoryId NSString
 * @throws IBandInvalidArgumentException if the category id is not on invalid format.
 */
-(void) getEventsByCategory:(NSString*) categoryId success:(void (^)(NSArray<IBandEvent*>* events))success failure:(void (^)(IBandError *error))failure;

/*!
 * @discussion Get an array of event instances in the given `categoryId`.
 * @param categoryId NSString
 * @param limit int
 * @throws IBandInvalidArgumentException if the category id is not on invalid format.
 */
-(void) getEventsByCategory:(NSString*) categoryId limit:(NSInteger)limit success:(void (^)(NSArray<IBandEvent*>* events))success failure:(void (^)(IBandError *error))failure;

/*!
 * @discussion Get an array of event instances in the given `categoryId`.
 * @param categoryId NSString
 * @param limit int
 * @param offset int
 * @throws IBandInvalidArgumentException if the category id is not on invalid format.
 */
-(void) getEventsByCategory:(NSString*) categoryId limit:(NSInteger)limit offset:(NSInteger)offset success:(void (^)(NSArray<IBandEvent*>* events))success failure:(void (^)(IBandError *error))failure;

/*!
 * @discussion Get the current background mode of the SDK (Default to `false`).
 * @return backgroundMode BOOL
 */
-(BOOL) getBackgroundMode;

/*!
 * @discussion Change the background mode of the SDK.
 * Toggle the background mode to `True` will enable the SDK to run on background (ie. Keep
 * sockets opens and play streams on background).
 * @param backgroundMode BOOL
 */
-(void)setBackgroundMode:(BOOL)backgroundMode;
@end
