//
//  IBandSession.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 24/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IBandSession : NSObject
/*!
 * @discussion Restore a session from a serialized session string.
 * @param serializedSession NSData
 */
+(IBandSession*) deserialize:(NSData*)serializedSession;

/*!
 * Get the unique session id.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSString*) getId;

/*!
 * @discussion Serialize the session object.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSData*) serialize;

@end
