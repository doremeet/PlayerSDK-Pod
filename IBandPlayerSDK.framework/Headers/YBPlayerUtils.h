//
//  YBPlayerUtils.h
//  Player test
//
//  Created by Yogev Barber on 27/06/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    YBPlayerMediaFormatUnknown,
    YBPlayerMediaFormatMpeg4,
    YBPlayerMediaFormatM3u8,
    YBPlayerMediaFormatMov,
    YBPlayerMediaFormatM4v,
    YBPlayerMediaFormatError
} YBPlayerMediaFormat;

@interface YBPlayerUtils : NSObject
+(NSBundle*) playerBundle;
+(NSString*) fileResource:(NSString*)fileName fileType:(NSString*)fileType;
+(UIImage*) imageResource:(NSString*)imageName fileType:(NSString*)fileType;
+(YBPlayerMediaFormat)decoderVideoFormat:(NSURL*)url;
@end
