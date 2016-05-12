//
//  UoMetierViewController.h
//  POMFramework
//
//  Created by Essam Dahab on 07/05/2015.
//  Copyright (c) 2015 Aéroports de Paris. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DeviceInfo.h"


@class  UoMetierView;

@interface UoMetierView : UIView<UITableViewDataSource,UITableViewDelegate,UIPickerViewDataSource,UIPickerViewDelegate>{
    
    NSMutableArray *UoList;
    NSMutableArray *MetiersList;
    NSMutableArray *CouplesUOMetiersList;
}

@property (weak, nonatomic) IBOutlet UIButton *AddButton;
@property (strong, nonatomic) NSMutableArray  *UoFromServer;
@property (strong, nonatomic) NSMutableArray  *MetiersFromServer;
@property (strong, nonatomic) DeviceInfo  *deviceInfo;
@property (weak, nonatomic) IBOutlet UIPickerView *MetierPickerView;
@property (weak, nonatomic) IBOutlet UIButton *ReturnButton;
@property (weak, nonatomic) IBOutlet UITableView *CouplesUOMetierTableView;
-(IBAction)RetourButtonClick:(id)sender;
- (IBAction)addButtonClicked:(id)sender;
+(id) UoMetierView;

// -(IBAction)addButtonClick:(id)sender;

@end
