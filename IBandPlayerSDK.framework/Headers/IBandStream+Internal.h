//
//  IBandStream+Internal.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 09/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#import "IBandStream.h"
#import "IBandSource.h"
#import "IBandStreamStatus.h"
#import "IBandSDK.h"

@interface IBandStream (Internal)
- (instancetype)initWithStreamId:(NSString*)streamId sdk:(IBandSDK*)sdk;
/**
 * A none-public method for IBandPlayer to get stream sources.
 *
 * @throw IBandIllegalStateException if stream state is not OPEN
 */
-(NSArray<IBandSource*>*) getSources;

/**
 * A none-public method for IBandStreamWatcher to get the stream.status model.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(IBandStreamStatus*) getStatus;

/**
 * A none-public method for IBandStreamWatcher to update the stream.status model when no-update needed.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void)setStatus:(IBandStreamStatus*) status;

/**
 * A none-public method for IBandStreamWatcher to update the stream model when needed.
 *
 * @noexcept This method do NOT throws exception on any case
 */
-(void) update;


-(NSString*) getLastUpdate;
+(NSArray<IBandSource*>*) parseSources:(id)unparsedSources;
+(IBandStreamStructure)structureEnumFromString:(NSString*)string;
+(NSString*)structureStringFromEnum:(IBandStreamStructure)type;
@end
