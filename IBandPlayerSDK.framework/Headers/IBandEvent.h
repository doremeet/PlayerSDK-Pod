//
//  IBandEvent.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 12/11/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandWatchable.h"
#import "IBandDelegatable.h"
#import "IBandDisposable.h"

/*!
 * @typedef IBandEventType
 * @brief A list of event types.
 * @constant IBandEventTypeLive live.
 * @constant IBandEventTypeVod void
 */
typedef NS_ENUM(NSUInteger, IBandEventType) {
    IBandEventTypeLive,
    IBandEventTypeVod,
};

@class IBandStream;

@protocol IBandEventDelegate <IBandDelegate>
/*!
 * @discussion Listener when the event receive message from the watcher.
 * @param event IBandEvent
 * @param data id
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onEventWatcherMessage:(IBandEvent*)event data:(id)data;

/*!
 * @discussion Listener after the event lose and regain connection on the watcher.
 * @param event IBandEvent
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onEventWatcherReconnect:(IBandEvent*)event;
@end

@interface IBandEvent : IBandWatchable <IBandDelegatable, IBandDisposable>

/*!
 * @discussion Get the event id.
 * @return id NSString
 */
-(NSString*) getId;

/*!
 * @discussion Get the event type.
 * @return type IBandEventType
 */
-(IBandEventType) getType;

/*!
 * @discussion Get the event title.
 * @return title NSString
 */
-(NSString*) getTitle;

/*!
 * @discussion Get the event subtitle.
 * @return subtitle NSString - return NULL if the event has no subtitle .
 */
-(NSString*) getSubtitle;

/*!
 * @discussion Get the event content.
 * @return content NSString - Return NULL if the event has no content.
 */
-(NSString*) getContent;

/*!
 * @discussion Get the live event start date.
 * @return startAt NSDate - Return NULL if the event type is not LIVE.
 */

-(NSDate*) getStartAt;

/*!
 * @discussion Get the live event end date.
 * @return endAt NSDate - Return NULL if the event type is not LIVE or ending date is unknown yet.
 */
-(NSDate*) getEndAt;

/*!
 * @discussion Checks if the live event is now.
 * @return Returns true if the event type is LIVE and it's happening right now (ie. start time is on the past and end time is unknown or in the future).
 */
-(BOOL) isHappeningNow;

/*!
 * @discussion Checks if the event is open to view.
 * @return Return true if the event type is not LIVE or if `isHappeningNow` is true.
 */
-(BOOL) isViewable;

/*!
 * @discussion Get event medium artwork url (maximum 512px).
 * @return mediumArtwork NSString - Return NULL if the event has no artworks.
 */
-(NSString*) getMediumArtwork;

/*!
 * @discussion Get event large artwork url (maximum 1920px).
 * @return largeArtwork NSString - Return NULL if the event has no artworks.
 */

-(NSString*) getLargeArtwork;

/*!
 * Get event player artwork url (maximum 1920px).
 * Return NULL if the event has no player artwork.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSString*) getPlayerArtwork;

/*!
 * @discussion Get the event streams ids.
 * @return streamIds NSArray<NSString*>
 */
-(NSArray<NSString*>*) getStreamsIds;

/*!
 * @discussion Create new streams for this event.
 * @return NSArray<IBandStream*>*
 * @noexcept This method do NOT throws exception on any case
 */
-(NSArray<IBandStream*>*)createStreams;

/*!
 * @discussion Start watching for event changes and update the event accordingly.
 * @noexcept This method do NOT throws exception on any case
 */
-(void) watch;

/*!
 * @discussion Stop watching for event changes.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void)unwatch;

/*!
 * Add a delegate for the event.
 * @param delegate id<IBandEventDelegate>
 * @noexcept This method do NOT throws exception on any case
 */
-(void) addDelegate:(id<IBandEventDelegate>)delegate;

/**
 * Remove a delegate from the event.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) removeDelegate:(id<IBandEventDelegate>)delegate;
@end
