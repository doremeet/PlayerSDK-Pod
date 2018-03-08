//
//  IBandSocket.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 06/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandDelegatable.h"
#import "IBandDisposable.h"

/*!
 * @typedef IBandSocketReadyState
 * @brief A list of socket status type.
 * @constant IBandSocketReadyStateConnecting - When the connection is not yet open.
 * @constant IBandSocketReadyStateOpen - When the connection is open and ready to communicate.
 * @constant IBandSocketReadyStateClosing - When the connection is in the process of closing.
 * @constant IBandSocketReadyStateClosed - When the connection is closed or couldn't be opened.
 */

typedef NS_ENUM(NSUInteger, IBandSocketReadyState) {
    IBandSocketReadyStateConnecting,
    IBandSocketReadyStateOpen,
    IBandSocketReadyStateClosing,
    IBandSocketReadyStateClosed,
};

@class IBandSocket;
@class IBandMessage;
@class IBandError;
@class IBandSDK;

@protocol IBandSocketDelegate <IBandDelegate>
/*!
 * @discussion Listen when the ready state changed to OPEN.
 * @param socket IBandSocket
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onSocketOpen:(IBandSocket*)socket;

/*!
 * @discussion Listen when a message is received from the server.
 * @param socket IBandSocket
 * @param message IBandMessage
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onSocketMessage:(IBandSocket*)socket message:(IBandMessage*)message;

/*!
 * @discussion Listene when the ready state changed to CLOSED.
 * @param socket IBandSocket
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onSocketClosed:(IBandSocket*)socket;

/*!
 * @discussion Listene when there is an fatal error on the socket.
 * @param socket IBandSocket
 * @noexcept This method do NOT throws exception on any case
 */
-(void) onSocketError:(IBandSocket*)socket error:(IBandError*)error;
@end

/*!
 * @discussion Creates a WebSocket to IBand.io servers.
 * The socket will send and receive messages from the servers.
 * If the socket receives a PING message, the socket should reply with a PONG message with the same
 * message data as the PING message.
 */
@interface IBandSocket : NSObject <IBandDelegatable, IBandDisposable>

/*!
 * @discussion Add a given listener to this instance and call to `onListenerAttached`.
 *
 * @param delegate The given delegate
 */
-(void) addDelegate:(id<IBandSocketDelegate>)delegate;

/*!
 * @discussion  Remove a given listener from the instance and call to `onListenerDetached`.
 *
 * @param delegate The given listener
 */
-(void) removeDelegate:(id<IBandSocketDelegate>)delegate;

/*!
 * @discussion Create a new instance of socket and connect to the server.
 * Initialize the ready state to CONNECTING.
 *
 * @param sdk IBandSDK - sdkToken The token to use with the socket connection
 * @param path String - The socket relative url to open (ie. "/watcher")
 */
-(instancetype)initWithSdk:(IBandSDK*)sdk path:(NSString*)path;

/*!
 * @discussion Get the socket ready state
 * @return readyState IBandSocketReadyState
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandSocketReadyState) getReadyState;

/*!
 * @discussion Send a message to the server.
 * @param message - IBandMessage
 * @throws IBandIllegalStateException if the state is not OPEN.
 */
-(void) sendMessage:(IBandMessage*) message;

/*!
 * @discussion Close this socket.
 */
-(void) close;

@end
