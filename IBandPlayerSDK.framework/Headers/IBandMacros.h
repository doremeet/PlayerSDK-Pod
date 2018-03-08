//
//  IbandMacros.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 02/08/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#ifndef IbandMacros_h
#define IbandMacros_h

#ifndef NDEBUG
#define debugLogs(x, ...) //NSLog(@"debug logs: %s %d: " x, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define debugLogs(x, ...)
#endif

#define STRING_TO_TIME @"yyyy-MM-dd'T'HH:mm:ss.SSSZ"

#define BASE_URL @"api.iband.io/v1"
#define HTTP_BASE_URL [NSString stringWithFormat:@"https://%@", BASE_URL]

#endif
