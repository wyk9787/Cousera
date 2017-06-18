//
//  AppDelegate.h
//  CoreData
//
//  Created by Garrett Wang on 6/18/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
#import "ChoreMO+CoreDataClass.h"
#import "ChoreLogMO+CoreDataClass.h"
#import "PersonMO+CoreDataClass.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;

- (ChoreMO *) createChoreMO;

- (PersonMO *) createPersonMO;

- (ChoreLogMO *) createChoreLogMO;

@end

