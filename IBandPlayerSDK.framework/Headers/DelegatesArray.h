//
//  DelegatesArray.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 14/02/2018.
//  Copyright © 2018 IBand. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IBandDelegatable.h"

@interface DelegatesArray : NSObject <NSFastEnumeration, IBandDelegatable>
@property (nonatomic, assign, readonly) NSUInteger count;
-(id<IBandDelegate>)delegateAtIndex:(NSUInteger)index;
-(void)removeAll;
@end
