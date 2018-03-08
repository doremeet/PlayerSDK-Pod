//
//  IBandSource+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandSource.h"

@interface IBandSource (Internal)
+(IBandSource*)parseSource:(id)unparsedSource;

+ (IBandSourceFormat)typeEnumFromString:(NSString*)string;

+ (NSString*)typeStringFromEnum:(IBandSourceFormat)type;
@end
