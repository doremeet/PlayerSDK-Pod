//
//  IBandInteraction+Protected.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 11/02/2018.
//  Copyright © 2018 IBand. All rights reserved.
//

#import "IBandInteraction.h"

@interface IBandInteraction (Protected)
/*!
 * @discussion Change the ready state to `READY` when the interaction is ready to display and interact.
 *
 * @throws IBandIllegalStateException If the current state is not equals to INITIALIZING
 */
-(void) setReadyStateReady;

/*!
 * @discussion Change the ready state error with the given error.
 *
 * @param error The given error
 * @throws IBandIllegalStateException If the ready state is not equals to INITIALIZING or READY
 */
-(void) setReadyStateError:(NSError*)error;

/*!
 * @discussion Change the `isActive` property of the interactions.
 *
 * @param isActive The new is active value
 * @throws IBandIllegalStateException If the ready state is not equals to READY
 */
-(void) setActive:(BOOL)isActive;

/*!
 * @discussion Handle ready state change to initializing.
 */
-(void)handleInitializing;

/*!
 * @discussion Handle a message received from the attached event.
 *
 * @param data The given message data
 */
-(void) handleEventMessage:(id)data;

/*!
 * @discussion Handle a reconnection on the event watcher.
 */
-(void)handleEventReconnect;
@end
