//
//  IBandDisposable.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 18/02/2018.
//  Copyright © 2018 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * "Living" instances with internal logic that keep them alive like WebSocket or timers require
 * a method to dispose the instance before the system can release it. This interface support this
 * behaviour.
 */
@protocol IBandDisposable <NSObject>
/*!
 * @discussion Dispose the instance and all the resources of this instance so the system can release it.
 *
 * @noexcept This method do NOT throws exception on any case
 */

-(void) dispose;
@end
