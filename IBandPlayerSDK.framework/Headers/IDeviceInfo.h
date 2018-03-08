//
//  IDeviceInfo.h
//  Player test
//
//  Created by Yogev Barber on 12/07/2017.
//  Copyright © 2017 iBand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>
#import <MediaPlayer/MediaPlayer.h>
#import <sys/utsname.h>


@interface IDeviceInfo : NSObject
+ (IDeviceInfo *)sharedInstance;
+(NSString *) fetchOSSystem;
+(NSString *) fetchDeviceModel;
+(NSString *) fetchDeviceVersion;
+(NSString *) fetchAppVersion;
+(NSString *) fetchAppBuild;
+(NSString *) fetchCarrierName;
+(NSString *) fetchConnectionType;

@end
