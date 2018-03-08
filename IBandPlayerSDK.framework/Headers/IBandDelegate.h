//
//  IBandTransmitterDelegate.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 14/02/2018.
//  Copyright © 2018 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IBandDelegate <NSObject>
@optional
/*!
 * @discussion Called after the delegate added to the transmitter.
 *
 * @param delegate The current delegate
 */
-(void) onDelegateAdded:(id)delegate;

/*!
 * @discussion Called after the delegate removed from the transmitter.
 *
 * @param delegate The current delegate
 */
-(void) onDelegateRemoved:(id)delegate;
@end
