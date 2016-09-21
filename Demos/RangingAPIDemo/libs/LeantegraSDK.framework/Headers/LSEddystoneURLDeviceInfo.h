//
//  LSEddistoneURLDeviceInfo.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/19/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import "LSBaseDeviceInfo.h"

/**
 * Represents all Bluetooth GATT characteristics of WiBeat in Eddystone(URL) mode.
 * @see LSBaseDeviceInfo
 * @see LSOperationMode#EDDYSTONE_URL
 */
@interface LSEddystoneURLDeviceInfo : LSBaseDeviceInfo

///Represents advertise URL.
@property NSString* url;

@end
