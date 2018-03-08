//
//  IBandEvent+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 13/11/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandEvent.h"
@class IBandSDK;

@interface IBandEvent (Internal)
+ (IBandEventType)typeEnumFromString:(NSString*)string;
+ (NSString*)typeStringFromEnum:(IBandEventType)type;
/**
 * Create a new instance of IBandEvent.
 */
- (instancetype)initWithSDK:(IBandSDK*)sdk unparsedEventView:(id)unparsedEvent;

@end
