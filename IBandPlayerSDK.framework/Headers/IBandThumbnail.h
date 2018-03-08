//
//  ThumbnailModel.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 10/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSUInteger, IBandThumbnailType) {
    IBandThumbnailTypeUnknown,
    IBandThumbnailTypeRefresh,
    IBandThumbnailTypeCounter,
};

@interface IBandThumbnail : NSObject
@property (nonatomic, assign) IBandThumbnailType type;
@property (nonatomic, strong) NSString *urlPattern;
@property (nonatomic, assign) NSTimeInterval interval;
@property (nonatomic, strong) NSString *counterFormat;
+(IBandThumbnail*)parseThumbnails:(id)unparsedThumbnails;
@end
