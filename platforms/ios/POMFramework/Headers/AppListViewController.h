//
//  AppListViewController.h
//  MesDocuments
//
//  Created by vnext on 31/12/14.
//  Copyright (c) 2014 Aéroports de Paris. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppListViewController : UITableViewController<UITableViewDataSource, UITableViewDelegate>

- (void)RefreshAppInfo;

@end
