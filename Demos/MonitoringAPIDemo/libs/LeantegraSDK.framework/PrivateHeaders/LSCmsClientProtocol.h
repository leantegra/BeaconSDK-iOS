//
//  LSCmsClientProtocol.h
//  LeantegraSDK
//
//  Created by Anton Voitsekhivskyi on 10/20/17.
//  Copyright © 2017 Leantegra Inc. All rights reserved.
//

@class LSCampaignEvent;

@protocol LSCmsClientProtocol <NSObject>

- (void)sendCSVCampaignAnalytics:(nonnull NSData *)campaignEvents attemptsCount:(NSUInteger)attemptsCount channel:(NSString*_Nullable)channel  success:(void (^_Nonnull)(void))successfulCallback fail:(void (^_Nonnull)(NSError *_Nullable))failCallback;

@end
