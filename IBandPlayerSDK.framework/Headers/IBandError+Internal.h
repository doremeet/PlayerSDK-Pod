//
//  IBandError+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandError.h"

@interface IBandError (Internal)
- (instancetype)initWithError:(NSError*)error;
- (instancetype)initWithError:(NSError *)error type:(IBandErrorType)type message:(NSString*)message;
+ (NSString*)getErrorTypeStringFromEnum:(IBandErrorType)type;
+ (IBandErrorType)typeEnumFromString:(NSString*)string;
@end
