//
//  POMUoMetiersViewControler.h
//  POMFramework
//
//  Created by Pupponi Jacques - Société VNEXT on 20/05/2016.
//  Copyright © 2016 Aéroports de Paris. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DeviceInfo.h"

@interface POMUoMetiersViewControler : UIViewController<UITableViewDataSource,UITableViewDelegate,UIPickerViewDataSource,UIPickerViewDelegate> {
    
    NSMutableArray *UoList;
    NSMutableArray *MetiersList;
    NSMutableArray *CouplesUOMetiersList;
    
    
    
}

@property (strong, nonatomic) NSMutableArray    *UoFromServer;
@property (strong, nonatomic) NSMutableArray    *MetiersFromServer;
@property (strong, nonatomic) DeviceInfo        *deviceInfo;

@property (weak, nonatomic) IBOutlet UIButton       *AddButton;
@property (weak, nonatomic) IBOutlet UIPickerView   *MetierPickerView;
@property (weak, nonatomic) IBOutlet UIButton       *ReturnButton;
@property (weak, nonatomic) IBOutlet UITableView    *CouplesUOMetierTableView;


-(IBAction)RetourButtonClick:(id)sender;
- (IBAction)addButtonClicked:(id)sender;


@end
