//
//  IBandError.h
//  Player test
//
//  Created by Yogev Barber on 04/07/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * @typedef IBandErrorType
 * @brief A list of error types.
 * @constant IBandErrorTypeUnknown
 * @constant IBandErrorTypeBadRequest
 * @constant IBandErrorTypeUnauthorized
 * @constant IBandErrorTypeForbidden
 * @constant IBandErrorTypeServerError
 * @constant IBandErrorTypeNotFound
 * @constant IBandErrorTypeInvalidStream
 * @constant IBandErrorTypeNoNetwork
 */
typedef NS_ENUM(NSUInteger, IBandErrorType) {
    IBandErrorTypeUnknown,
    IBandErrorTypeBadRequest,
    IBandErrorTypeUnauthorized,
    IBandErrorTypeForbidden,
    IBandErrorTypeServerError,
    IBandErrorTypeNotFound,
    IBandErrorTypeInvalidStream,
    IBandErrorTypeNoNetwork,
};

@interface IBandError : NSError

/*!
 Get the error type

 @return error IBandErrorType
 */
-(IBandErrorType) getErrorType;


/*!
 Get the error message
 
 @return error NSString
 */
-(NSString*) getErrorMessage;
@end
