//
//  IBandM3U8Parser.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 28/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IBandM3U8Parser : NSObject
@property (nonatomic, strong) NSString *parsedContent;
@property (nonatomic, strong) NSString *base64EncodeUrl;
- (instancetype)initWithContent:(NSString*)content url:(NSURL *)URL;
@end
