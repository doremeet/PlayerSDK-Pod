//
//  StreamStatusModel.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 10/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IBandStreamStatus : NSObject
@property (nonatomic, strong) NSString* state;
@property (nonatomic, assign) NSUInteger refreshInterval;
@property (nonatomic, strong) NSString *lastUpdate;
+(IBandStreamStatus*)parseStatus:(id)unparsedStatus;
@end
