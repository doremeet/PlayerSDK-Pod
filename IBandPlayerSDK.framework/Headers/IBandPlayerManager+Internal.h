//
//  IBandPlayerManager+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 28/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandPlayerManager.h"

@class IBandSDK;
@class IBandEvent;

@interface IBandPlayerManager (Internal)
/**
 * Create a new instance of IBandPlayerManager.
 * The initial state of the manager will be INITIALIZING or INITIALIZED depending on the streams
 * states.
 */
- (instancetype)initWithSDK:(IBandSDK*)sdk;
@end
