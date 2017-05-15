//
//  BeaconTableViewCell.m
//  SDK test
//
//  Created by Artem Drozd on 05/26/16.
//  Copyright © 2016 Artem Drozd. All rights reserved.
//

#import "BeaconTableViewCell.h"
#import <LeantegraSDK/LSFrameProximable.h>
#import <LeantegraSDK/LSiBeaconFrame.h>
#import <LeantegraSDK/LSEddystoneUrlFrame.h>
#import <LeantegraSDK/LSTagFrame.h>

@implementation BeaconTableViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    
    // Configure the view for the selected state
}

-(void)setContentFrame:(LSBaseFrame*)frame{
    _frame=frame;
    //
    self.addressLable.text=_frame.address.uppercaseString;
    self.distanceLabel.text =[NSString stringWithFormat:@"%.2fm",_frame.distance.floatValue];
    switch (_frame.frameType) {
        case FRAME_TYPE_I_BEACON:{
            LSiBeaconFrame*iBeaconFrame=(LSiBeaconFrame*)_frame;
            self.typeLabel.text=@"iBeacon";
            self.backgroundColor=[self colorWith:iBeaconFrame.proximityZone];
            self.zoneLabel.text=[self proximityZoneToString:iBeaconFrame.proximityZone];
            self.infoLabel.text =[NSString stringWithFormat:@"Major id:%ld Minor id:%ld",(long)iBeaconFrame.major,(long)iBeaconFrame.minor];
        }
            break;
            
        case FRAME_TYPE_EDDYSTONE_URL:{
            LSEddystoneUrlFrame*eddystoneFrame=(LSEddystoneUrlFrame*)_frame;
            self.typeLabel.text=@"Eddystone";
            self.backgroundColor=[self colorWith:eddystoneFrame.proximityZone];
            self.zoneLabel.text=[self proximityZoneToString:eddystoneFrame.proximityZone];
            self.infoLabel.text =[NSString stringWithFormat:@"Url:%@",eddystoneFrame.url];
        }
            break;
            
        case FRAME_TYPE_TAG:{
            LSTagFrame*tagFrame=(LSTagFrame*)_frame;
            self.typeLabel.text=@"Tag";
            self.backgroundColor=[self colorWith:UNKNOWN];
            self.zoneLabel.text=[self proximityZoneToString:UNKNOWN];
            self.infoLabel.text =[NSString stringWithFormat:@"Network id:%ld Device id:%ld",(long)tagFrame.networkId,(long)tagFrame.deviceId];
        }
            break;
            
        default:{
            self.typeLabel.text=@"Unknown";
            self.backgroundColor=[self colorWith:UNKNOWN];
            self.zoneLabel.text=[self proximityZoneToString:UNKNOWN];
            self.infoLabel.text =nil;
        }
            break;
    }
}


-(UIColor*)colorWith:(LSProximityZone)proximityZone{
    switch (proximityZone) {
        case IMMEDIATE:
            return [UIColor colorWithRed:0 green:1 blue:0 alpha:0.1];
            break;
            
        case NEAR:
            return [UIColor colorWithRed:1 green:1 blue:0 alpha:0.1];
            break;
            
        case FAR:
            return [UIColor colorWithRed:1 green:0 blue:0 alpha:0.1];
            break;
            
        default:
            return [UIColor whiteColor];
            break;
    }
}

-(NSString*)proximityZoneToString:(LSProximityZone)proximityZone{
    switch (proximityZone) {
        case IMMEDIATE:
            return @"IMMEDIATE";
            break;
            
        case NEAR:
            return @"NEAR";
            break;
            
        case FAR:
            return @"FAR";
            break;
            
        default:
            return @"UNKNOWN";
            break;
    }
}


@end
