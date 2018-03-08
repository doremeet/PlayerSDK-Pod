//
//  IBandUtils.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 27/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
@class IBandSDK;

@interface IBandUtils : NSObject

+(NSDictionary*)getHeaders:(IBandSDK*)sdk;
@end
