//
//  IBandPlayerVariantInterface.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IBandPlayerVariant <NSObject>
/**
 * Get variant width (0 if unknown)
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSUInteger) getWidth;

/**
 * Get variant height (0 if unknown)
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSUInteger) getHeight;

/**
 * Get variant bitrate in bps (0 if unknown)
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSUInteger) getBitrate;
@end
