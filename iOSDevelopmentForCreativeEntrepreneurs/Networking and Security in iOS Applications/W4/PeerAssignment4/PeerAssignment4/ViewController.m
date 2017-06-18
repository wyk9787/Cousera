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

@property (nonatomic) AppDelegate* delegate;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.delegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    // Do any additional setup after loading the view, typically from a nib.
}


- (IBAction)addTapped:(id)sender {
    
}

- (void) updateList {
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
