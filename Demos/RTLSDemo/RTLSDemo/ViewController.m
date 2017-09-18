//
//  ViewController.m
//  RTLSDemo
//
//  Created by Anton Voitsekhivskyi on 9/14/17.
//  Copyright © 2017 Leantegra Llc. All rights reserved.
//

#import "ViewController.h"
#import <LeantegraSDK/LeantegraSDK.h>

@interface ViewController () <LSVenuePlanViewDelegate>

@property (weak, nonatomic) IBOutlet LSVenuePlanView *venuePlanView;
@property (strong, nonatomic) LSFloor *currentFloor;
@property (assign, nonatomic) BOOL shouldRedisplay;
@property (weak, nonatomic) IBOutlet UILabel *determiningLocationLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.shouldRedisplay = YES;
    self.venuePlanView.showsUserLocation = YES;
    self.venuePlanView.sourceType = LSVenuePlanSourceMixed;
    self.venuePlanView.delegate = self;
    [self.venuePlanView reloadData];
}

#pragma mark - LSVenuePlanViewDelegate

- (LSVenuePlanPaintingLayerOptions)displayingOptionsForVenuePlanView:(LSVenuePlanView *)venuePlanView {
    return LSVenuePlanFloorImageLayer | LSVenuePlanFloorShapeLayer | LSVenuePlanZoneShapeLayer | LSVenuePlanPassageShapeLayer;
}

- (void)didUpdateUserLocation:(CLLocation *)location floor:(LSFloor *)floor error:(NSError *)error {
    self.venuePlanView.hidden = NO;
    self.determiningLocationLabel.hidden = YES;

    NSLog(@"user located on floor: %@ error: %@", @(floor.uid), error);
    if (nil != error) {
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Error" message:@"Unable to determine your position" preferredStyle:UIAlertControllerStyleAlert];
        [alertController addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:nil]];
        [self presentViewController:alertController animated:YES completion:nil];
    }
    else if (self.currentFloor.uid != floor.uid) {
        self.currentFloor = floor;
        [self.venuePlanView setFloor:self.currentFloor];
        [self.venuePlanView redisplayVenuePlanAnimated:YES resetCamera:YES];
    }
}

- (void)didUpdateVenuePlanView:(LSVenuePlanView *)venuePlanView error:(nullable NSError *)error {
    if (self.shouldRedisplay) {
        self.shouldRedisplay = NO;
        [self.venuePlanView redisplayVenuePlanAnimated:YES resetCamera:YES];
    }
}

// Map apperiance can be configured with methods:

- (UIColor *)fillColorForFloor:(LSFloor *)floor {
    return [UIColor colorWithRed:0 green:0 blue:0 alpha:0.0];
}

- (UIColor *)strokeColorForFloor:(LSFloor *)floor {
    return [UIColor colorWithRed:220.0/255.0 green:220.0/255.0 blue:220.0/255.0 alpha:0.5];
}

- (UIColor *)fillColorForZone:(LSZone *)zone {
    return [UIColor colorWithRed:215.0/255.0 green:227.0/255.0 blue:225.0/255.0 alpha:0.3];
}

- (UIColor *)strokeColorForZone:(LSZone *)zone {
    return [UIColor colorWithRed:164.0/255.0 green:208.0/255.0 blue:202.0/255.0 alpha:1.0];
}

- (UIColor *)fillColorForPassage:(LSPassage *)passage {
    return [UIColor colorWithRed:203.0/255.0 green:203.0/255.0 blue:203.0/255.0 alpha:0.3];
}

- (UIColor *)strokeColorForPassage:(LSPassage *)passage {
    return [UIColor colorWithRed:150.0/255.0 green:150.0/255.0 blue:150.0/255.0 alpha:1.0];
}

@end
