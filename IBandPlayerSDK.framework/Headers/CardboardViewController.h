//
//  CardboardViewController.h
//  SlateVideo360
//
//  Created by linyize on 16/2/26.
//  Copyright © 2016年 islate. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "CBDViewController.h"
#import "IBandPlayerViewDelegate.h"

@interface CardboardViewController : CBDViewController

@property (weak, nonatomic) id<IBandPlayerViewDelegate> videoPlayerController;

@end
