//
//  ViewController.m
//  PeerAssignment4
//
//  Created by Garrett Wang on 6/18/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "ViewController.h"
#import "AppDelegate.h"
#import "ThingMO+CoreDataClass.h"

@interface ViewController ()

@property (nonatomic) AppDelegate *delegate;
@property (weak, nonatomic) IBOutlet UITextField *thingTextField;
@property (weak, nonatomic) IBOutlet UILabel *countLabel;
@property (weak, nonatomic) IBOutlet UILabel *thingsListLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.delegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    [self updateList];
    // Do any additional setup after loading the view, typically from a nib.
}


- (IBAction)addTapped:(id)sender {
    ThingMO *thingMo = [self.delegate createThingMO];
    thingMo.thing = self.thingTextField.text;
    [self.delegate saveContext];
    [self updateList];
}

- (IBAction)deleteTapped:(id)sender {
    NSManagedObjectContext *moc = self.delegate.persistentContainer.viewContext;
    NSFetchRequest *fetchRequest = [NSFetchRequest fetchRequestWithEntityName:@"Thing"];
    
    NSError *error = nil;
    NSArray *thingRecords = [moc executeFetchRequest:fetchRequest error:&error];
    
    if(!thingRecords || error!=nil) {
        NSLog(@"Update list failed: %@", error);
        abort();
    }
    
    for(ThingMO *thingMo in thingRecords) {
        [moc deleteObject:thingMo];
    }
    
    [self.delegate saveContext];
    [self updateList];
}

- (void) updateList {
    NSArray* thingRecords = [self fetchThings];
    NSMutableString *buffer = [NSMutableString stringWithString:@""];
    for(ThingMO *thingMo in thingRecords) {
        [buffer appendFormat:@"%@\n", thingMo.thing, nil];
    }
    
    self.countLabel.text = [NSString stringWithFormat:@"Number of entries: %lu", (unsigned long)[thingRecords count]];
    self.thingsListLabel.text = buffer;
}

- (NSArray* )fetchThings {
    NSManagedObjectContext *moc = self.delegate.persistentContainer.viewContext;
    NSFetchRequest *fetchRequest = [NSFetchRequest fetchRequestWithEntityName:@"Thing"];
    
    NSError *error = nil;
    NSArray *thingRecords = [moc executeFetchRequest:fetchRequest error:&error];
    
    if(!thingRecords || error!=nil) {
        NSLog(@"Update list failed: %@", error);
        abort();
    }
    
    return thingRecords;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
