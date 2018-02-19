//
//  IBandPlayerVariantInterface.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IBandPlayerVariant <NSObject>
/*!
 Get variant width (0 if unknown)

 @return width NSUInteger
 */
-(NSUInteger) getWidth;

/*!
 Get variant height (0 if unknown)
 
 @return height NSUInteger
 */
-(NSUInteger) getHeight;


/*!
 Get variant bitrate in bps (0 if unknown)

 @return bitrate NSUInteger
 */
-(NSUInteger) getBitrate;
@end
