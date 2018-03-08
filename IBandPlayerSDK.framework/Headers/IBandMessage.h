//
//  IBandMessage.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 06/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, IBandMessageType) {
    IBandMessageTypePing = 0x01,
    IBandMessageTypePong = 0x02,
    
    IBandMessageTypeEntitySubscribe = 0x10,
    IBandMessageTypeEntityUnsubscribe = 0x11,
    
    IBandMessageTypeStreamStatusChanged = 0x20,
    
    IBandMessageTypeEventSendMessage = 0x30,
};

@interface IBandMessage : NSObject
/*!
 * @discussion Create a new message from a JSON string.
 *
 * @throws IBandInvalidArgumentException If the JSON has invalid message format
 */
+(IBandMessage*)fromJson:(NSString*)stringData;

/*!
 * @discussion Creates a new message
 * @param type MessageType enum
 */
-(instancetype)initWithType:(IBandMessageType)type;

/*!
 * @discussion Creates a new message
 * @param type MessageType enum
 * @param entityId String
 */
-(instancetype)initWithType:(IBandMessageType)type entityId:(NSString*)entityId;

/*!
 * @discussion Creates a new message
 * @param type MessageType enum
 * @param entityId String
 * @param data id - json from the native json parser
 */
-(instancetype)initWithType:(IBandMessageType)type entityId:(NSString*)entityId data:(id)data;

/*!
 * @discussion Get the message type
 * @return type IBandMessageType
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandMessageType) getType;

/*!
 * @discussion Get the message entity id or NULL if unspecified.
 * @return entityId String
 * @noexcept This method do NOT throws exception on any case
 */
-(NSString*) getEntityId;

/*!
 * @discussion Get the message data or NULL if unspecified.
 * @return data id - json
 * @noexcept This method do NOT throws exception on any case
 */
-(id) getData;

/*!
 * @discussion Serialize the message to a JSON to send over a socket.
 * @return json string
 * @noexcept This method do NOT throws exception on any case
 */
-(NSString*)toJSON;
@end
