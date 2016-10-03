//
//  ViewController.m
//  HelloWorld
//
//  Created by Garrett Wang on 16/7/20.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UILabel *testLabel;

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

- (IBAction)testButtonTapped:(id)sender {
    int height_feet = 5;
    int height_inches = 11;
    double height_cm = (height_feet*12+height_inches) * 2.54;
//    self.testLabel.text= [NSString stringWithFormat: @"%f", height_cm];
    if(height_cm > 200)
        self.testLabel.text = @"You are over 2 meters tall!";
    else
        self.testLabel.text = @"You are under 2 meters tall!";
}


@end
