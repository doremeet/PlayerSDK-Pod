//
//  IBandSource.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, IBandSourceFormat) {
    IBandSourceFormatUnknown,
    IBandSourceFormatHLSv1,
};

@interface IBandSource : NSObject
/**
 * Get source format
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandSourceFormat) getFormat;

/**
 * Get source url
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSString*) getUrl;

@end
