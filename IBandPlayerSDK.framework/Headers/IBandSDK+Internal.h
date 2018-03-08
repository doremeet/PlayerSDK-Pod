//
//  IBandSDK+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandSDK.h"

@class IBandWatcher;
@class IBandApi;
@class IBandSession;

@interface IBandSDK (Internal)
#pragma mark - local methods

/**
 * A none-public method for IBandStream to get the stream watcher instance.
 *
 */
-(IBandWatcher*) getWatcher;

/**
 * A none-public method for IBandEvents and IBandStream to get the api instance.
 *
 */
-(IBandApi*) getApi;

/**
 * Get the user agent header for all api requests.
 * The user agent should be on the following format:
 * "IBandPlayerSDK/{VERSION} ({PLATFORM_NAME} {PLATFORM_IDENTIFIER})"
 */
-(NSString*) getUserAgent;
@end
