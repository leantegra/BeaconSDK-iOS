//
//  LSBeaconURL.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 4/18/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LSBeaconURL : NSObject

+ (NSString*)decode:(NSData*)data;

+ (NSString*)decode:(const char*)bytes withLength:(NSInteger)length;

+ (NSData*)encode:(NSString*)url;

@end
