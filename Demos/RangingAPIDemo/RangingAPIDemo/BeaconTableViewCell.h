//
//  BeaconTableViewCell.h
//  SDK test
//
//  Created by Artem Drozd on 05/26/16.
//  Copyright © 2016 Artem Drozd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LeantegraSDK/LSBaseFrame.h>

@interface BeaconTableViewCell : UITableViewCell

@property (nonatomic,readonly) LSBaseFrame*frame;

@property (weak, nonatomic) IBOutlet UILabel*addressLable;
@property (weak, nonatomic) IBOutlet UILabel*typeLabel;
@property (weak, nonatomic) IBOutlet UILabel*zoneLabel;
@property (weak, nonatomic) IBOutlet UILabel*distanceLabel;
@property (weak, nonatomic) IBOutlet UILabel*infoLabel;

-(void)setContentFrame:(LSBaseFrame*)frame;

@end
