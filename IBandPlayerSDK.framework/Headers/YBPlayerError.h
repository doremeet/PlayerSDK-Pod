//
//  YBPlayerError.h
//  Player test
//
//  Created by Yogev Barber on 27/06/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface YBPlayerError : NSObject
@property (nonatomic, strong) NSError *error;
@property (nonatomic, strong) NSArray<AVPlayerItemErrorLogEvent*> *playerItemErrorLogEvent;
@property (nonatomic, strong) NSData *extendedLogData;
@property (nonatomic, assign) UInt64 extendedLogDataStringEncoding;
@end
