//
//  ViewController.m
//  UnitConverter
//
//  Created by Garrett Wang on 16/7/25.
//  Copyright © 2016年 Garrett Wang. All rights reserved.
//

#import "ViewController.h"

double convertUnitOneToUnitTwo(double unitOneVale){
    double unitTwoValue;
    unitTwoValue = 1.609 * unitOneVale;
    return unitTwoValue;
}

double convertUnitOneToUnitThree(double unitOneVale){
    double unitThreeValue;
    unitThreeValue = 5280 * unitOneVale;
    return unitThreeValue;
}

double convertUnitOneToUnitFour(double unitOneVale){
    double unitFourValue;
    unitFourValue = 63360 * unitOneVale;
    return unitFourValue;
}


@interface ViewController ()

@property (weak, nonatomic) IBOutlet UITextField *inputField;

@property (weak, nonatomic) IBOutlet UISegmentedControl *segementController;

@property (weak, nonatomic) IBOutlet UILabel *outputField;

@end

@implementation ViewController

- (IBAction)updateButton:(id)sender {
    NSMutableString *buf = [NSMutableString new];
    
    double userInput = [self.inputField.text doubleValue];
    
    if(self.segementController.selectedSegmentIndex == 0){
        double unitTwoValue = convertUnitOneToUnitTwo(userInput);
        [buf appendString: [@(unitTwoValue) stringValue]];
    }
    else if(self.segementController.selectedSegmentIndex == 1){
        double unitThreeValue = convertUnitOneToUnitThree(userInput);
        [buf appendString: [@(unitThreeValue) stringValue]];
    }
    else{
        double unitFourValue = convertUnitOneToUnitFour(userInput);
        [buf appendString: [@(unitFourValue) stringValue]];
    }

    self.outputField.text = buf;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
