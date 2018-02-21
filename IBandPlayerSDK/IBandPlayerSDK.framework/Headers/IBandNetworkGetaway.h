//
//  IBandApi.h
//  Player test
//
//  Created by Yogev Barber on 16/07/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IBandNetworkGetaway : NSObject
-(void)postWithUrl:(NSString*)url params:(NSDictionary*)params headers:(NSDictionary*)headers completionHandler:(void (^)(NSData * data, NSURLResponse * response, NSError * error))completionHandler;
-(void)getWithUrl:(NSString*)url params:(NSDictionary*)params headers:(NSDictionary*)headers completionHandler:(void (^)(NSData * data, NSURLResponse * response, NSError * error))completionHandler;
-(void)cancelLastRequset;
@end
