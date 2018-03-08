//
//  IBandApi.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IBandStreamStatusModel;
@class IBandError;
@class IBandEvent;
@class IBandSDK;

@interface IBandApi : NSObject
/**
 * Create a new instance of api gateway.
 * @param sdk IBandSDK The sdk instance to get token and session id
 */
- (instancetype)initWithSDK:(IBandSDK*)sdk;

/**
 * Get source format
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) getStream:(NSString*)streamId success:(void (^)(id unparsedStream))success failure:(void (^)(IBandError *error))failure;

/**
 * Get source format
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) getStreamStatusBulk:(NSString*)streamIds success:(void (^)(id streamStatuses))success failure:(void (^)(IBandError *error))failure;

/**
 * Post a player-event with the given params
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) postPlayerEvent:(NSString*) eventType info:(NSDictionary*)params success:(void (^)(void))success failure:(void (^)(IBandError *error))failure;

/**
 * Get stream from the API.
 * Get events by category from the API.
 * Using the API call: `GET /eventCategory/:categoryId/events`
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) getCategoryEvents:(NSString*) categoryId limit:(NSInteger)limit offset:(NSInteger)offset success:(void (^)(id unparsedEvents))success failure:(void (^)(IBandError *error))failure;

/**
 * Get event from the API.
 * Using the API call: `GET /event/:eventId`
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) getEvent:(NSString*)eventId success:(void (^)(id unparsedEvent))success failure:(void (^)(IBandError *error))failure;

/**
 * Get an event view properties.
 * Using the API call: `GET /event/:eventId/viewProperties`
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) getEventViewProperties:(NSString*) eventId success:(void (^)(id JSONObject))success failure:(void (^)(IBandError *error))failure;

/**
 * Post an event interaction.
 * Using the API call: `POST /event/:eventId/interaction`
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) postEventInteraction:(NSString*)eventId interaction:(NSDictionary*)interaction success:(void (^)(id data))success failure:(void (^)(IBandError *error))failure;


//TODO: remove this when moving to the AFNetworking
-(void) postVote:(NSNumber*)selection success:(void (^)(id data))success failure:(void (^)(IBandError *error))failure;
@end
