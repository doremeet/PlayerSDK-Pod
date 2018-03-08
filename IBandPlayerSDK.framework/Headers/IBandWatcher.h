//
//  IBandWatcher.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 06/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 * This class will be a on the sdk class and watch for any change on the watchlist entities.
 * If the watchlist is not empty, the watcher will open a socket and listen for changed for the
 * watched entities. If the watchlist got empty, the watcher will destroy the socket. If for any
 * reason the socket closed, the watcher should retry to open a new socket again after 10 seconds.
 *
 * The watcher should handle the case of multiple entities with the same entity id and watch
 * all of them correctly.
 * The watcher should send a PING message to the server each 25 seconds.
 */

@class IBandWatchable;
@class IBandSDK;

@interface IBandWatcher : NSObject
/*!
 * @discussion Create a new instance of socket watcher.
 * @param sdk IBandSDK
 */
-(instancetype)initWithSdk:(IBandSDK*)sdk;

/*!
 * @discussion Add an entity to the watch list
 * @param entity IBandWatchable
 * @noexcept This method do NOT throws exception on any case
 */
-(void) addEntity:(IBandWatchable*) entity;

/**
 * @discussion Remove an entity from the watch list.
 * @param entity IBandWatchable
 * @noexcept This method do NOT throws exception on any case
 */
-(void) removeEntity:(IBandWatchable*) entity;
@end
