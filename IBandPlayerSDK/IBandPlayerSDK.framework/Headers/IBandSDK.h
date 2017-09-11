//
//  IBandSDK.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SDK_VERSION @"0.1.0"
#define SDK_BUILD_NUMBER @"1"

@class IBandPlayer;
@class IBandStream;

@interface IBandSDK : NSObject

/**
 * Create a new SDK instance with the token on the dictonery value "IBandSDK.token".
 *
 */
- (instancetype)init;

/**
 * Create a new SDK instance with the given token.
 *
 */

- (instancetype)initWithToken:(NSString*)token;
/**
 * Create a new player instance.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandPlayer*) createPlayer;

/**
 * Create a new stream instance.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandStream*) createStream:(NSString*)streamId;
@end
