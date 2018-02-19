//
//  IBandWatchable.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 06/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IBandWatchable : NSObject

/*!
 * @discussion Start watching for changes for this instance.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) watch;

/*!
 * @discussion Stop watching for changes for this instance.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) unwatch;

/*!
 * @discussion Get the entity id.
 * @return NSString the entity id
 * @noexcept This method do NOT throws exception on any case
 */
-(NSString*) getId;
@end
