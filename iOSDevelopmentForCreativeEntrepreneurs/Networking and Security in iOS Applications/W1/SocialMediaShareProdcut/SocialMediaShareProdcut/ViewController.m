//
//  ViewController.m
//  SocialMediaShareProdcut
//
//  Created by Garrett Wang on 12/10/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//

#import "ViewController.h"
#import "Social/Social.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextView *textView1;
@property (weak, nonatomic) IBOutlet UITextView *textView2;
@property (weak, nonatomic) IBOutlet UITextView *textView3;
- (void) configureTextView;
- (void) showAlertMessage:(NSString *) myMess;

@end

@implementation ViewController

- (void)showAlertMessage:(NSString *)myString{
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"SocialMediaShare" message:myString preferredStyle:UIAlertControllerStyleAlert];
    [alertController addAction:[UIAlertAction actionWithTitle:@"Okay" style:UIAlertActionStyleDefault handler:nil]];
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self configureTextView];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)shareAction1:(id)sender {
    if ([self.textView1 isFirstResponder]){
        [self.textView1 resignFirstResponder];
    }
    if([SLComposeViewController isAvailableForServiceType:SLServiceTypeTwitter]){
        SLComposeViewController *twitterVC = [SLComposeViewController composeViewControllerForServiceType:SLServiceTypeTwitter];
        if([self.textView1.text length] < 140){
            [twitterVC setInitialText:self.textView1.text];
        }
        else{
            [twitterVC setInitialText:[self.textView1.text substringToIndex:140]];
        }
        [self presentViewController:twitterVC animated:YES completion:nil];
    }
    else{
        [self showAlertMessage:@"Please sign in your twitter account."];
    }
    
}
- (IBAction)shareAction2:(id)sender {
    if ([self.textView2 isFirstResponder]){
        [self.textView2 resignFirstResponder];
    }
    if([SLComposeViewController isAvailableForServiceType:SLServiceTypeFacebook]){
        SLComposeViewController *facebookVC = [SLComposeViewController composeViewControllerForServiceType:SLServiceTypeFacebook];
        [facebookVC setInitialText:self.textView2.text];
        [self presentViewController:facebookVC animated:YES completion:nil];
    }
    else{
        [self showAlertMessage:@"Please sign in your facebook account."];
    }

}
- (IBAction)shareAction3:(id)sender {
    if ([self.textView3 isFirstResponder]){
        [self.textView3 resignFirstResponder];
    }
    UIActivityViewController *moreVC = [[UIActivityViewController alloc] initWithActivityItems:@[self.textView3.text] applicationActivities:nil];
    [self presentViewController:moreVC animated:YES completion:nil];
}
- (IBAction)shareAction4:(id)sender {
    UIAlertController *nothing = [UIAlertController alertControllerWithTitle:@"SocialMediaShare" message:@"This doesn't do anything" preferredStyle:UIAlertControllerStyleAlert];
    [nothing addAction:[UIAlertAction actionWithTitle:@"Okay" style:UIAlertActionStyleDefault handler:nil]];
    [self presentViewController:nothing animated:YES completion:nil];
}

- (void) configureTextView{
    self.textView1.layer.backgroundColor = [UIColor colorWithRed:0.7 green:0.3 blue:0.3 alpha:0.8].CGColor;
    self.textView1.layer.cornerRadius = 10.0;
    self.textView1.layer.borderColor = [UIColor colorWithWhite:0 alpha:0.3].CGColor;
    self.textView1.layer.borderWidth = 2.0;
    
    self.textView2.layer.backgroundColor = [UIColor colorWithRed:0.3 green:0.7 blue:0.3 alpha:0.8].CGColor;
    self.textView2.layer.cornerRadius = 10.0;
    self.textView2.layer.borderColor = [UIColor colorWithWhite:0 alpha:0.3].CGColor;
    self.textView2.layer.borderWidth = 2.0;
    
    self.textView3.layer.backgroundColor = [UIColor colorWithRed:0.3 green:0.3 blue:0.7 alpha:0.8].CGColor;
    self.textView3.layer.cornerRadius = 10.0;
    self.textView3.layer.borderColor = [UIColor colorWithWhite:0 alpha:0.3].CGColor;
    self.textView3.layer.borderWidth = 2.0;
    
}

@end
