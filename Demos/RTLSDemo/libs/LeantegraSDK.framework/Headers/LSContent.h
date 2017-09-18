//
//  LSContent.h
//  LeantegraSDK
//
//  Created by Konstantin Efimenko on 8/12/16.
//  Copyright © 2016 Leantegra Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSCMSRule.h"

@interface LSContent : NSObject

/**
 Max number of push notification per day
 */
@property NSInteger maxImpressionsPerDay;

/**
 UTC offset in minutes
 */
@property NSInteger utcOffset;

/**
 List of LSCMSRule
 */
@property NSArray<LSCMSRule*> *rules;

@end
