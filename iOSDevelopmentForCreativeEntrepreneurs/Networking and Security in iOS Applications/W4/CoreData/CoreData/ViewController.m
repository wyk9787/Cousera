//
//  ViewController.m
//  CoreData
//
//  Created by Garrett Wang on 6/18/17.
//  Copyright © 2017 Garrett Wang. All rights reserved.
//

#import "ViewController.h"
#import "AppDelegate.h"
#import "ChoreMO+CoreDataClass.h"

@interface ViewController ()

@property (nonatomic) AppDelegate *appDelegate;
@property (weak, nonatomic) IBOutlet UITextField *choreField;
@property (weak, nonatomic) IBOutlet UILabel *choreListLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self. appDelegate = (AppDelegate* )[[UIApplication sharedApplication] delegate];
    [self updateLogList];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)choreTapped:(id)sender {
    ChoreMO *c = [self.appDelegate createChoreMO];
    c.chore_name = self.choreField.text;
    [self.appDelegate saveContext];
    [self updateLogList];
    
}

- (IBAction)deleteTapped:(id)sender {
    NSManagedObjectContext *moc = self.appDelegate.persistentContainer.viewContext;
    NSFetchRequest *fetchRequest = [NSFetchRequest fetchRequestWithEntityName:@"Chore"];
    
    NSError *error = nil;
    NSArray *choreRecords = [moc executeFetchRequest:fetchRequest error:&error];
    if(!choreRecords || error != nil) {
        NSLog(@"rx:updateLogList: error fetching chores: %@", error);
        abort();
    }
    
    for(ChoreMO *chore in choreRecords) {
        [moc deleteObject:chore];
    }
    
    [self.appDelegate saveContext];
    [self updateLogList];
}


- (void) updateLogList{
    NSArray *choreRecords = [self fetchChores];
    NSMutableString *buffer = [NSMutableString stringWithString:@""];
    for(ChoreMO *chore in choreRecords) {
        [buffer appendFormat:@"\n%@", chore.chore_name, nil];
    }
    NSLog(@"%@", buffer);
    self.choreListLabel.text = buffer;
}

- (NSArray *) fetchChores {
    NSManagedObjectContext *moc = self.appDelegate.persistentContainer.viewContext;
    NSFetchRequest *fetchRequest = [NSFetchRequest fetchRequestWithEntityName:@"Chore"];
    
    NSError *error = nil;
    NSArray *choreRecords = [moc executeFetchRequest:fetchRequest error:&error];
    
    if(!choreRecords || error != nil) {
        NSLog(@"rx:updateLogList: error fetching chores: %@", error);
        abort();
    }
    
    NSLog(@"rx:fetchChores: fetched %lu records", (unsigned long)[choreRecords count]);
    return choreRecords;
}

@end
