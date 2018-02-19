//
//  IBandInteraction.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 04/02/2018.
//  Copyright © 2018 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandDelegatable.h"
#import "IBandDisposable.h"

/*!
 * @typedef IBandInteractionReadyState
 * @brief A list of ready states.
 * @constant IBandInteractionReadyStateUninitialzed - When the interaction is not initialize with event.
 * @constant IBandInteractionReadyStateInitializing - When the interaction is in loading.
 * @constant IBandInteractionReadyStateReady        - When the interaction is ready to display and interact.
 * @constant IBandInteractionReadyStateError        - When there is a fatal error while loading or interacting.
 */

typedef NS_ENUM(NSUInteger, IBandInteractionReadyState) {
    IBandInteractionReadyStateUninitialzed,
    IBandInteractionReadyStateInitializing,
    IBandInteractionReadyStateReady,
    IBandInteractionReadyStateError,
};

@class IBandInteraction;
@class IBandError;
@class IBandEvent;

@protocol IBandInteractionDelegate <IBandDelegate>
/*!
 * @discussion Listen for any time the ready state changed.
 *
 * @param interaction The current class
 * @param state The current ready state
 * @param oldState The previous ready state
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onInteractionReadyStateChanged:(IBandInteraction*) interaction state:(IBandInteractionReadyState)state oldState:(IBandInteractionReadyState)oldState;

/*!
 * @discussion Listener when the `isActive` changed.
 *
 * @param interaction The current class
 * @param isActive The latest `isActive` value
 * @noexcept This method do NOT throws exception on any case
 */
-(void)onInteractionActiveChanged:(IBandInteraction*)interaction isActive:(BOOL)isActive;

/*!
 * @discussion Listener when there is a fatal error.
 *
 * @param interaction The current class
 * @param error The fatal error
 * @noexcept This method do NOT throws exception on any case
 */
-(void)onInteractionError:(IBandInteraction*)interaction error:(IBandError*)error;
@end

@interface IBandInteraction : NSObject <IBandDelegatable, IBandDisposable>

/*!
 * @discussion Add the given interactions delegate for this class.
 *
 * @param delegate The given delegate
 * @noexcept This method do NOT throws exception on any case
 */
-(void)addDelegate:(id<IBandInteractionDelegate>)delegate;

/*!
 * @discussion Remove the given interactions delegate from this class.
 *
 * @param delegate The given delegate
 * @noexcept This method do NOT throws exception on any case
 */
-(void)removeDelegate:(id<IBandInteractionDelegate>)delegate;


/*!
 * @discussion Initialize and set the interaction an event.
 * This method will `watch` for any event changes and `unwatch` the previous event.
 * The `isActive` property should also be reset to `false`.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void)setEvent:(IBandEvent*)event;

/*!
 * @discussion Get the current initialized event.
 * @return IBandEvent
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandEvent*)getEvent;

/*!
 * @discussion Reset the interaction state.
 * Uninitialized the interaction, `unwatch` the previous event and set `isActive` to false.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) reset;

/*!
 * @discussion Get current ready state (Default to `UNINITIALIZED`).
 * @return IBandInteractionReadyState
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandInteractionReadyState) getReadyState;

/*!
 * @discussion Check if one of the interactions are currently active (Default to `false`).
 * Changed to `false` if the ready state is not READY.
 * @return BOOL
 * @noexcept This method do NOT throws exception on any case
 */
-(BOOL) isActive;
@end
