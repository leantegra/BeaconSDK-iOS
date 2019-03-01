//
//  LSBeaconKey.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 7/7/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class for efficient identifying the WiBeat instance trough the following:
 * 1) CVO Portal <devices> call,
 * 2) CVO Portal <content> call,
 * 3) CoreLocation CLBeacon
 * The only way to identify WiBeat/iBeacon trough all mentioned areas - is a key with major and minor values.
*/
@interface LSBeaconKey : NSObject <NSCopying>

@property (readonly, strong) NSNumber *major;
@property (readonly, strong) NSNumber *minor;

- (instancetype)initWithMajor:(NSNumber *)major minor:(NSNumber *)minor uuid:(NSString*)uuid;

+ (LSBeaconKey *)keyWithMajor:(NSNumber *)major minor:(NSNumber *)minor uuid:(NSString*)uuid;

NS_ASSUME_NONNULL_END

@end
