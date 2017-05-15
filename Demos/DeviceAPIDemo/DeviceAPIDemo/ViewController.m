//
//  ViewController.m
//  DeviceAPIDemo
//
//  Created by Artem Drozd on 06/01/16.
//  Copyright © 2016 Leantegra. All rights reserved.
//

#import "ViewController.h"

@interface ViewController (){
    
    __weak IBOutlet UITextField *addressTextField;
    __weak IBOutlet UIActivityIndicatorView *indicator;
    __weak IBOutlet UITableView *characteristicsTableView;
    __weak IBOutlet UIButton *connectButton;
    LSWiBeatConnection*connection;
    LSBaseDeviceInfo*wiBeatDeviceInfo;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Actions

- (IBAction)connectButtonClick:(id)sender {
    if(!connection.isConnected){
        connection=[[LSWiBeatConnection alloc] initWithDeviceMACAddress:addressTextField.text.lowercaseString delegate:self];
        [connection connect];
    }else{
        [connection disconnect];
    }
    [indicator startAnimating];
    [characteristicsTableView setHidden:true];
    [connectButton setEnabled:false];
    [addressTextField setEnabled:false];
}

#pragma mark - UITableViewDelegate

-(BOOL)tableView:(UITableView *)tableView shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath{
    switch (indexPath.row) {
        case 3:
            return false;
            
        case 4:
            return false;
            
        default:
            return true;
    }
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    switch (indexPath.row) {
        case 0:{
            [self showOperationModeDialog];
        }
            break;
            
        case 1:{
            [self showNumberDialogWithTitle:@"Advertising interval"
                                    message:@"Enter new value(100-10000)"
                                  initValue:wiBeatDeviceInfo.advertisingInterval
                                    handler:^(int value) {
                                        if(value>=100 && value<=10000){
                                            [self writeAdvertisingInterval:value];
                                        }
                                    }];
        }
            break;
            
        case 2:{
            [self showTXPowerDialog];
        }
            break;
            
            
        default:{
            
        }
            break;
    }
    [tableView deselectRowAtIndexPath:indexPath animated:true];
}


#pragma mark - UITableViewDataSource{

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return (connection.isConnected)?5:0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    //
    NSString*title;
    NSString*subTitle;
    switch (indexPath.row) {
        case 0:
            title=@"Operation mode";
            subTitle=[self operationModeToString:wiBeatDeviceInfo.operationMode];
            break;
            
        case 1:
            title=@"Advertising interval";
            subTitle=[NSString stringWithFormat:@"%ldms",(long)wiBeatDeviceInfo.advertisingInterval];
            break;
            
        case 2:
            title=@"Tx power";
            subTitle=[NSString stringWithFormat:@"%lddBm",(long)wiBeatDeviceInfo.txPowerLevel];
            break;
            
        case 3:
            title=@"Firmware version";
            subTitle=wiBeatDeviceInfo.firmwareVersion;
            break;
            
        default:
            break;
    }
    cell.textLabel.text=title;
    cell.detailTextLabel.text=subTitle;
    
    return cell;
}

#pragma mark - LSWiBeatConnectionDelegate

-(void)wiBeatConnectionDidConnect:(LSWiBeatConnection *)wiBeatConnection{
    [connection readDeviceInfo:self];
}

-(void)wiBeatConnectionDidDisconnect:(LSWiBeatConnection *)wiBeatConnection{
    [indicator stopAnimating];
    [characteristicsTableView setHidden:true];
    [connectButton setEnabled:true];
    [addressTextField setEnabled:true];
    connection=NULL;
    [connectButton setTitle:@"Connect" forState:UIControlStateNormal];
}

-(void)wiBeatConnection:(LSWiBeatConnection *)wiBeatConnection didGetError:(LSWiBeatError)powerMoteError{
    [self onDisconnect];
    //handle error
}

- (void)wiBeatConnectionDidDisconnect:(LSWiBeatConnection *)wiBeatConnection error:(NSError *)error{
    [self onDisconnect];
}

- (void)onDisconnect{
    [indicator stopAnimating];
    [characteristicsTableView setHidden:true];
    [connectButton setEnabled:true];
    [addressTextField setEnabled:true];
    connection=NULL;
    [connectButton setTitle:@"Connect" forState:UIControlStateNormal];
}

#pragma mark- LSReadDeviceInfoDelegate

-(void)wiBeatReadDeviceInfoSuccess:(LSBaseDeviceInfo *)deviceInfo{
    wiBeatDeviceInfo=deviceInfo;
    [indicator stopAnimating];
    [characteristicsTableView setHidden:false];
    [connectButton setEnabled:true];
    [addressTextField setEnabled:true];
    [connectButton setTitle:@"Disconnect" forState:UIControlStateNormal];
    [characteristicsTableView reloadData];
}

-(void)wiBeatReadDeviceInfoError:(LSWiBeatError)error{
    //handle error
}

#pragma marl- LSWiBeatWriteCharacteristicDelegate

-(void)wiBeatWriteCharacteristicSuccess:(LSCharacteristicType)characteristicType{
    [connection readDeviceInfo:self];
    
}

-(void)wiBeatWriteCharacteristic:(LSCharacteristicType)characteristicType error:(LSWiBeatError)error{
    [indicator stopAnimating];
    [characteristicsTableView setHidden:false];
    [connectButton setEnabled:true];
    [addressTextField setEnabled:true];
    //handle error
}

#pragma mark - Other


-(void)writeOperationMode:(LSOperationMode)mode{
    [connection writeOperationMode:mode delegate:self];
    [indicator startAnimating];
    [characteristicsTableView setHidden:true];
    [connectButton setEnabled:false];
    [addressTextField setEnabled:false];
}

-(void)writeAdvertisingInterval:(int)advertisingInterval{
    [connection writeAdvertisingInterval:advertisingInterval delegate:self];
    [indicator startAnimating];
    [characteristicsTableView setHidden:true];
    [connectButton setEnabled:false];
    [addressTextField setEnabled:false];
}

-(void)writeTXPower:(int)txPower{
    [connection writeRadioTxPower:txPower delegate:self];
    [indicator startAnimating];
    [characteristicsTableView setHidden:true];
    [connectButton setEnabled:false];
    [addressTextField setEnabled:false];
}

-(NSString*)operationModeToString:(LSOperationMode)mode{
    switch (mode) {
        case EDDYSTONE_URL:
            return @"Eddystone";
            break;
            
        case TAG:
            return @"Tag";
            break;
            
        case HYBRID:
            return @"Hybrid";
            break;
            
        case I_BEACON:
            return @"iBeacon";
            break;
            
        default:
            return @"Unknown";
            break;
    }
}

- (void)showOperationModeDialog{
    UIAlertController * actionView=   [UIAlertController
                                       alertControllerWithTitle:@"Operation mode"
                                       message:@"Select operation mode"
                                       preferredStyle:UIAlertControllerStyleActionSheet];
    [actionView addAction:[UIAlertAction actionWithTitle:@"Cancel"
                                                   style:UIAlertActionStyleCancel
                                                 handler:^(UIAlertAction *action) {
                                                     [actionView dismissViewControllerAnimated:YES completion:nil];
                                                 }]];
    int modes[]={I_BEACON,EDDYSTONE_URL,HYBRID,TAG};
    
    for(int i=0;i<4;i++){
        NSNumber*mode=[NSNumber numberWithInt:modes[i]];
        [actionView addAction:[UIAlertAction
                               actionWithTitle:[self operationModeToString:modes[i]]
                               style:UIAlertActionStyleDefault
                               handler:^(UIAlertAction * action)
                               {
                                   [actionView dismissViewControllerAnimated:YES completion:nil];
                                   [self writeOperationMode:[mode intValue]];
                               }]
         ];
    }
    actionView.popoverPresentationController.sourceView = [characteristicsTableView.visibleCells objectAtIndex:0];
    actionView.popoverPresentationController.sourceRect = [characteristicsTableView.visibleCells objectAtIndex:0].bounds;
    [self presentViewController:actionView animated:YES completion:nil];
}

- (void)showTXPowerDialog{
    UIAlertController * actionView=   [UIAlertController
                                       alertControllerWithTitle:@"TX power"
                                       message:@"Select TX power"
                                       preferredStyle:UIAlertControllerStyleActionSheet];
    [actionView addAction:[UIAlertAction actionWithTitle:@"Cancel"
                                                   style:UIAlertActionStyleCancel
                                                 handler:^(UIAlertAction *action) {
                                                     [actionView dismissViewControllerAnimated:YES completion:nil];
                                                 }]];
    int values[]={8,5,1,-2,-5,-8,-12,-15};
    
    for(int i=0;i<8;i++){
        NSNumber*tx=[NSNumber numberWithInt:values[i]];
        [actionView addAction:[UIAlertAction
                               actionWithTitle:[NSString stringWithFormat:@"%d",values[i]]
                               style:UIAlertActionStyleDefault
                               handler:^(UIAlertAction * action)
                               {
                                   [actionView dismissViewControllerAnimated:YES completion:nil];
                                   [self writeTXPower:[tx intValue]];
                               }]
         ];
    }
    actionView.popoverPresentationController.sourceView = [characteristicsTableView.visibleCells objectAtIndex:0];
    actionView.popoverPresentationController.sourceRect = [characteristicsTableView.visibleCells objectAtIndex:0].bounds;
    [self presentViewController:actionView animated:YES completion:nil];
}

-(void)showNumberDialogWithTitle:(NSString*)title message:(NSString*)message initValue:(NSInteger)initValue handler:(void (^)(int value))handler{
    UIAlertController *actionView = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    [actionView addAction:[UIAlertAction actionWithTitle:@"Ok"
                                                   style:UIAlertActionStyleDefault
                                                 handler:^(UIAlertAction * _Nonnull action) {
                                                     int value=[actionView.textFields.firstObject.text intValue];
                                                     handler(value);
                                                     [actionView dismissViewControllerAnimated:YES completion:nil];
                                                 }]];
    [actionView addAction:[UIAlertAction actionWithTitle:@"Cancel"
                                                   style:UIAlertActionStyleCancel
                                                 handler:^(UIAlertAction *action) {
                                                     [actionView dismissViewControllerAnimated:YES completion:nil];
                                                 }]];
    [actionView addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        textField.text=[NSString stringWithFormat:@"%ld",(long)initValue];
        [textField setKeyboardType:UIKeyboardTypeNumbersAndPunctuation];
    }];
    [self presentViewController:actionView animated:YES completion:nil];
}

@end
