//
//  Varinat.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 09/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBandPlayerVariant.h"
@interface Varinat : NSObject <IBandPlayerVariant>
/**
 * variant width (0 if unknown)
 */
@property (nonatomic, assign) NSUInteger width;

/**
 * variant height (0 if unknown)
 */
@property (nonatomic, assign) NSUInteger height;

/**
 * variant bitrate in bps (0 if unknown)
 */
@property (nonatomic, assign) NSUInteger bitrate;

@property (nonatomic, strong) NSURL *url;

- (instancetype)initWithWidth:(NSInteger)width height:(NSInteger)height bitrate:(NSInteger)bitrate;
@end
