//
//  IBandWatchable+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 06/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandWatchable.h"
@class IBandMessage;
@class IBandWatcher;

@interface IBandWatchable (Internal)

-(instancetype)initWithWatcher:(IBandWatcher*)watcher id:(NSString*)id;

/**
 * Notify the entity that it out of sync and should sync. itself manually.
 * This method should be called by the watcher, when the watcher reconnect to the server after
 * it lost sync. (like on internet disconnect, background mode, etc.)
 *
 */
-(void) watcherSync;

/**
 * A local method for the watcher to send message to the entity and update it.
 * The entity should ignore unknown message types.
 *
 * @throws IBandInvalidArgument If the message entity id is not equals to `getId()`.
 */
-(void) watcherUpdate:(IBandMessage*) message;
@end
