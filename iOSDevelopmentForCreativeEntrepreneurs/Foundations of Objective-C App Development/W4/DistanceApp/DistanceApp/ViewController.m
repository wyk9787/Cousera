//
//  ViewController.m
//  DistanceApp
//
//  Created by Garrett Wang on 11/13/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//

#import "ViewController.h"
#import "DistanceGetter/DGDistanceRequest.h"

@interface ViewController ()

@property (nonatomic) DGDistanceRequest *req;

@property (weak, nonatomic) IBOutlet UITextField *startLocation;

@property (weak, nonatomic) IBOutlet UITextField *endLocationA;
@property (weak, nonatomic) IBOutlet UILabel *distanceA;

@property (weak, nonatomic) IBOutlet UITextField *endLocationB;
@property (weak, nonatomic) IBOutlet UILabel *distanceB;

@property (weak, nonatomic) IBOutlet UITextField *endLocationC;
@property (weak, nonatomic) IBOutlet UILabel *distanceC;

@property (weak, nonatomic) IBOutlet UIButton *calculateButton;

@property (weak, nonatomic) IBOutlet UISegmentedControl *unitController;


@end

@implementation ViewController
- (IBAction)calculateButtonTapped:(id)sender {

    self.calculateButton.enabled = NO;
    
    self.req = [DGDistanceRequest alloc];
    NSString *start = self.startLocation.text;
    NSString *destA = self.endLocationA.text;
    NSString *destB = self.endLocationB.text;
    NSString *destC = self.endLocationC .text;
    NSArray *dests = @[destA, destB, destC];
    
    __weak ViewController *weakSelf = self;
    
    self.req = [self.req initWithLocationDescriptions:dests sourceDescription:start];
    self.req.callback =^void(NSArray *response){
        ViewController *strongSelf = weakSelf;
        if(!strongSelf) return;
       
        NSNull *badResult = [NSNull null];
        
        if(response[0] != badResult){
            if(strongSelf.unitController.selectedSegmentIndex == 0){
                double num = [response[0] floatValue];
                NSString *x = [NSString stringWithFormat:@"%.2f m", num];
                strongSelf.distanceA.text = x;
            }
            else if (strongSelf.unitController.selectedSegmentIndex == 1){
                double num = [response[0] floatValue]/1000.0;
                NSString *x = [NSString stringWithFormat:@"%.2f km", num];
                strongSelf.distanceA.text = x;
            }
            else{
                double num = [response[0] floatValue]/1600.0;
                NSString *x = [NSString stringWithFormat:@"%.2f miles", num];
                strongSelf.distanceA.text = x;
            }
            
        }
        else{
            strongSelf.distanceA.text = @"Error";
        }
        
        if(response[1] != badResult){
            if(strongSelf.unitController.selectedSegmentIndex == 0){
                double num = [response[1] floatValue]/1.0;
                NSString *x = [NSString stringWithFormat:@"%.2f m", num];
                strongSelf.distanceB.text = x;
            }
            else if (strongSelf.unitController.selectedSegmentIndex == 1){
                double num = [response[1] floatValue]/1000.0;
                NSString *x = [NSString stringWithFormat:@"%.2f km", num];
                strongSelf.distanceB.text = x;
            }
            else{
                double num = [response[1] floatValue]/1600.0;
                NSString *x = [NSString stringWithFormat:@"%.2f miles", num];
                strongSelf.distanceB.text = x;
            }
            
        }
        else{
            strongSelf.distanceB.text = @"Error";
        }
        
        if(response[2] != badResult){
            if(strongSelf.unitController.selectedSegmentIndex == 0){
                double num = [response[2] floatValue]/1.0;
                NSString *x = [NSString stringWithFormat:@"%.2f m", num];
                strongSelf.distanceC.text = x;
            }
            else if (strongSelf.unitController.selectedSegmentIndex == 1){
                double num = [response[2] floatValue]/1000.0;
                NSString *x = [NSString stringWithFormat:@"%.2f km", num];
                strongSelf.distanceC.text = x;
            }
            else{
                double num = [response[2] floatValue]/1600.0;
                NSString *x = [NSString stringWithFormat:@"%.2f miles", num];
                strongSelf.distanceC.text = x;
            }
            
        }
        else{
            strongSelf.distanceC.text = @"Error";
        }
        strongSelf.req = nil;
        strongSelf.calculateButton.enabled = YES;
    };
    
    [self.req start];
    
    
}

NSInteger segmentIndexNow;

- (IBAction)unitControllerTapped:(id)sender {
    NSString *destA = self.distanceA.text;
    NSString *destB = self.distanceB.text;
    NSString *destC = self.distanceC .text;
    if(self.unitController.selectedSegmentIndex == 0){
        if(segmentIndexNow == 1){
            double num = [destA floatValue]*1000.0;
            NSString *x = [NSString stringWithFormat:@"%.2f m", num];
            self.distanceA.text = x;
            
            double num1 = [destB floatValue]*1000.0;
            NSString *y = [NSString stringWithFormat:@"%.2f m", num1];
            self.distanceB.text = y;
            
            double num2 = [destC floatValue]*1000.0;
            NSString *z = [NSString stringWithFormat:@"%.2f m", num2];
            self.distanceC.text = z;
        }
        else if(segmentIndexNow == 2){
            double num = [destA floatValue]*1600.0;
            NSString *x = [NSString stringWithFormat:@"%.2f m", num];
            self.distanceA.text = x;
            
            double num1 = [destB floatValue]*1600.0;
            NSString *y = [NSString stringWithFormat:@"%.2f m", num1];
            self.distanceB.text = y;
            
            double num2 = [destC floatValue]*1600.0;
            NSString *z = [NSString stringWithFormat:@"%.2f m", num2];
            self.distanceC.text = z;
        }
    }
    else if (self.unitController.selectedSegmentIndex == 1){
        if(segmentIndexNow == 0){
            double num = [destA floatValue]/1000.0;
            NSString *x = [NSString stringWithFormat:@"%.2f km", num];
            self.distanceA.text = x;
            
            double num1 = [destB floatValue]/1000.0;
            NSString *y = [NSString stringWithFormat:@"%.2f km", num1];
            self.distanceB.text = y;
            
            double num2 = [destC floatValue]/1000.0;
            NSString *z = [NSString stringWithFormat:@"%.2f km", num2];
            self.distanceC.text = z;
        }
        else if(segmentIndexNow == 2){
            double num = [destA floatValue]*1.6;
            NSString *x = [NSString stringWithFormat:@"%.2f km", num];
            self.distanceA.text = x;
            
            double num1 = [destB floatValue]*1.6;
            NSString *y = [NSString stringWithFormat:@"%.2f km", num1];
            self.distanceB.text = y;
            
            double num2 = [destC floatValue]*1.6;
            NSString *z = [NSString stringWithFormat:@"%.2f km", num2];
            self.distanceC.text = z;
        }
    }
    else{
        if(segmentIndexNow == 0){
            double num = [destA floatValue]/1600.0;
            NSString *x = [NSString stringWithFormat:@"%.2f miles", num];
            self.distanceA.text = x;
            
            double num1 = [destB floatValue]/1600.0;
            NSString *y = [NSString stringWithFormat:@"%.2f miles", num1];
            self.distanceB.text = y;
            
            double num2 = [destC floatValue]/1600.0;
            NSString *z = [NSString stringWithFormat:@"%.2f miles", num2];
            self.distanceC.text = z;
        }
        else if(segmentIndexNow == 1){
            double num = [destA floatValue]/1.6;
            NSString *x = [NSString stringWithFormat:@"%.2f miles", num];
            self.distanceA.text = x;
            
            double num1 = [destB floatValue]/1.6;
            NSString *y = [NSString stringWithFormat:@"%.2f miles", num1];
            self.distanceB.text = y;
            
            double num2 = [destC floatValue]/1.6;
            NSString *z = [NSString stringWithFormat:@"%.2f miles", num2];
            self.distanceC.text = z;
        }
    }
    segmentIndexNow = self.unitController.selectedSegmentIndex;
}




@end
