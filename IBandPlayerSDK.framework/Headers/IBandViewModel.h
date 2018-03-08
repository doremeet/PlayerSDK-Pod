//
//  IBandViewModel.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 20/12/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IBandViewModel : NSObject
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *bundleUrl;
+(IBandViewModel *)parseViewModel:(id)unparsedViewModel;
@end
