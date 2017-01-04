//
//  AppDelegate.h
//  CoreData
//
//  Created by Garrett Wang on 1/3/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

