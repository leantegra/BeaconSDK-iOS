//
//  ViewController.h
//  DeviceAPIDemo
//
//  Created by Artem Drozd on 06/01/16.
//  Copyright © 2016 Leantegra. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LeantegraSDK/LSWiBeatConnection.h>

@interface ViewController : UIViewController<UITableViewDelegate,UITableViewDataSource,LSWiBeatConnectionDelegate,LSWiBeatReadDeviceInfoDelegate,LSWiBeatWriteCharacteristicDelegate>


@end

