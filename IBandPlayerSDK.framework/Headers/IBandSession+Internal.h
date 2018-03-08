//
//  IBandSession+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 11/01/2018.
//  Copyright © 2018 IBand. All rights reserved.
//

#import "IBandSession.h"

@interface IBandSession (Internal)
/**
 * Get the session token.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(NSString*) getToken;
@end
