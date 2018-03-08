//
//  IBandDelegate.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 14/02/2018.
//  Copyright © 2018 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandDelegate.h"

@protocol IBandDelegatable <NSObject>
/*!
 * @discussion Add a given listener to this instance and call to `onListenerAttached`.
 *
 * @param delegate The given delegate
 */
-(void) addDelegate:(id<IBandDelegate>)delegate;

/*!
 * @discussion  Remove a given listener from the instance and call to `onListenerDetached`.
 *
 * @param delegate The given listener
 */
-(void) removeDelegate:(id<IBandDelegate>)delegate;
@end
