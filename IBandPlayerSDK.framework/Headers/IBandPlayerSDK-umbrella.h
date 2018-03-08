#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "IBandSDK.h"
#import "IBandPlayer.h"
#import "IBandError.h"
#import "IBandStream.h"
#import "IBandPlayerVariant.h"
#import "IBandPlayerView.h"
#import "IBandEvent.h"
#import "IBandWatchable.h"
#import "IBandPlayerManager.h"
#import "IBandSession.h"
#import "IBandInteraction.h"
#import "IBandInteraction+Protected.h"
#import "IBandInteractionView.h"
#import "IBandDelegate.h"
#import "IBandDelegatable.h"
#import "IBandDisposable.h"
#import "IBandNetworkGetaway.h"
#import "DelegatesArray.h"

FOUNDATION_EXPORT double IBandPlayerSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char IBandPlayerSDKVersionString[];

