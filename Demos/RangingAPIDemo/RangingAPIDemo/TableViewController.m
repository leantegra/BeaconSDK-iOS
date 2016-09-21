//
//  ViewController.m
//  RangingAPIDemo
//
//  Created by Artem Drozd on 06/02/16.
//  Copyright © 2016 Leantegra. All rights reserved.
//

#import "TableViewController.h"
#import "BeaconTableViewCell.h"

@interface TableViewController (){
    
    LSRangingManager *rangingManager;
    NSMutableArray*beacons;
}

@end

@implementation TableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    beacons=[NSMutableArray new];
    rangingManager=[LSRangingManager new];
    rangingManager.activePeriod=2;
    rangingManager.passivePeriod=0;
    [rangingManager addDelegate:self];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)viewWillAppear:(BOOL)animated{
    [rangingManager startRangingBeacons];
}

-(void)viewDidDisappear:(BOOL)animated{
    [rangingManager stopRangingBeacons];
}

#pragma mark - UITableViewDataSource

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return beacons.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    BeaconTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"BeaconCell"];
    
    [cell setContentFrame:[beacons objectAtIndex:indexPath.row]];
    
    return cell;
}

#pragma mark - LSRangingManagerDelegate

-(void)rangingManager:(LSRangingManager *)manager didGetError:(LSWiBeatError)error{
}

-(void)rangingManager:(LSRangingManager *)manager didRangeBeacon:(LSBaseFrame *)frame{
    if(frame){
        [self addBeacon:frame];
    }
}

-(void)rangingManager:(LSRangingManager *)manager didRangeBeacons:(NSArray<LSBaseFrame *> *)frames{
}

#pragma mark - Other

-(void)addBeacon:(LSBaseFrame *)beacon{
    NSInteger index=[self indexOfBeacon:beacon];
    if(index!=NSNotFound){
        [beacons replaceObjectAtIndex:index withObject:beacon];
    }else{
        [beacons addObject:beacon];
    }
    [beacons sortUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
        LSBaseFrame*frame1=(LSBaseFrame*)obj1;
        LSBaseFrame*frame2=(LSBaseFrame*)obj2;
        return [frame1.distance compare:frame2.distance];
    }];
    [self.tableView reloadData];
}

-(NSInteger)indexOfBeacon:(LSBaseFrame *)beacon{
    for(int i=0;i<beacons.count;i++){
        if([beacon.address isEqualToString:((LSBaseFrame*)[beacons objectAtIndex:i]).address]){
            return i;
        }
    }
    return NSNotFound;
}

@end
