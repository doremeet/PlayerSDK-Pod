//
//  IBandError.h
//  Player test
//
//  Created by Yogev Barber on 04/07/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    IBandErrorTypeUnknown,
    IBandErrorTypeBadRequest,
    IBandErrorTypeUnauthorized,
    IBandErrorTypeForbidden,
    IBandErrorTypeServerError,
    IBandErrorTypeNotFound,
    IBandErrorTypeInvalidStream,
    IBandErrorTypeNoNetwork,    
} IBandErrorType;

@interface IBandError : NSError
-(IBandErrorType) getErrorType;
-(NSString*) getErrorMessage;
@end
