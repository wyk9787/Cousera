//
//  AppDelegate.m
//  CoreData
//
//  Created by Garrett Wang on 6/18/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "AppDelegate.h"
#import "ChoreMO+CoreDataClass.h"
#import "ChoreLogMO+CoreDataClass.h"
#import "personMO+CoreDataClass.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [self persistentContainer];
    NSManagedObjectContext *moc = self.persistentContainer.viewContext;
    NSAssert(moc!=nil, @"rd:didFinishLaunchingWithOptions: unable to create manage object");
    
    
    return YES;
}

#pragma mark - My Managed Object Code

- (ChoreMO *) createChoreMO {
    NSManagedObjectContext *moc = self.persistentContainer.viewContext;
    ChoreMO *choreMO = [NSEntityDescription insertNewObjectForEntityForName:@"Chore" inManagedObjectContext:moc];
    NSLog(@"rx:createChoreMO: retMe=%@", choreMO);
    return choreMO;
}

- (PersonMO *) createPersonMO {
    NSManagedObjectContext *moc = self.persistentContainer.viewContext;
    PersonMO *personMO = [NSEntityDescription insertNewObjectForEntityForName:@"Person" inManagedObjectContext:moc];
    NSLog(@"rx:createPersonMO: retMe=%@", personMO);
    return personMO;
}

- (ChoreLogMO *) createChoreLogMO {
    NSManagedObjectContext *moc = self.persistentContainer.viewContext;
    ChoreLogMO *choreLogMO = [NSEntityDescription insertNewObjectForEntityForName:@"ChoreLog" inManagedObjectContext:moc];
    NSLog(@"rx:createChoreLogMO: retMe=%@", choreLogMO);
    return choreLogMO;
}


#pragma mark - Core Data stack

@synthesize persistentContainer = _persistentContainer;

- (NSPersistentContainer *)persistentContainer {
    // The persistent container for the application. This implementation creates and returns a container, having loaded the store for the application to it.
    @synchronized (self) {
        if (_persistentContainer == nil) {
            _persistentContainer = [[NSPersistentContainer alloc] initWithName:@"CoreData"];
            [_persistentContainer loadPersistentStoresWithCompletionHandler:^(NSPersistentStoreDescription *storeDescription, NSError *error) {
                if (error != nil) {
                    // Replace this implementation with code to handle the error appropriately.
                    // abort() causes the application to generate a crash log and terminate. You should not use this function in a shipping application, although it may be useful during development.
                    
                    /*
                     Typical reasons for an error here include:
                     * The parent directory does not exist, cannot be created, or disallows writing.
                     * The persistent store is not accessible, due to permissions or data protection when the device is locked.
                     * The device is out of space.
                     * The store could not be migrated to the current model version.
                     Check the error message to determine what the actual problem was.
                    */
                    NSLog(@"Unresolved error %@, %@", error, error.userInfo);
                    abort();
                }
            }];
        }
    }
    
    return _persistentContainer;
}

#pragma mark - Core Data Saving support

- (void)saveContext {
    NSManagedObjectContext *context = self.persistentContainer.viewContext;
    NSError *error = nil;
    if ([context hasChanges] && ![context save:&error]) {
        // Replace this implementation with code to handle the error appropriately.
        // abort() causes the application to generate a crash log and terminate. You should not use this function in a shipping application, although it may be useful during development.
        NSLog(@"Unresolved error %@, %@", error, error.userInfo);
        abort();
    }
}

@end
