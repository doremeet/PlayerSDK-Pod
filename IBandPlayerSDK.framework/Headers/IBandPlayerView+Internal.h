//
//  IBandPlayerView+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 08/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandPlayerView.h"
#import "IBandStream.h"

@interface IBandPlayerView (Internal)
- (instancetype)initIntenral;
#pragma mark - local methods
-(void) reloadPlayerView;
-(void) setStructure:(IBandStreamStructure)state;
-(IBandStreamStructure) getStructure;
-(void) removeViews;
-(void)setDelegate:(id<IBandPlayerViewDelegate>)delegate;
@end
