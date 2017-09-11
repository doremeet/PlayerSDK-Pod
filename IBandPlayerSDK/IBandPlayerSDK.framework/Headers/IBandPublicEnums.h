//
//  IBandPublicEnums.h
//  IBandPlayerSDK
//
//  Created by Yogev Barber on 13/08/2017.
//  Copyright © 2017 IBand. All rights reserved.
//

#ifndef IBandPublicEnums_h
#define IBandPublicEnums_h

typedef NS_ENUM(NSUInteger, IBandStreamType) {
    /**
     * When the stream state is INITIALIZE
     */
    IBandStreamTypeUndefined,
    
    /**
     * When the stream type is "live"
     */
    IBandStreamTypeLive,
    
    /**
     * When the stream type is "vod"
     */
    IBandStreamTypeVod,
};

typedef NS_ENUM(NSUInteger, IBandStreamStructure) {
    IBandStreamStructureUndefined,
    IBandStreamStructurePlain,
    IBandStreamStructureEquirectangular,
};

#endif /* IBandPublicEnums_h */
