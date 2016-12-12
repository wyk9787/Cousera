//
//  ViewController.m
//  TwitterShareProduct
//
//  Created by Garrett Wang on 11/21/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//

#import "ViewController.h"
#import "Social/Social.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextView *tweetTextView;

- (void) configureTweetTextView;
- (void) showAlertMessages:(NSString *) myMess;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self configureTweetTextView];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) showAlertMessages:(NSString *) myMessage{
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Social Share" message:myMessage preferredStyle:UIAlertControllerStyleAlert];
    [alertController addAction:[UIAlertAction actionWithTitle:@"Okay" style:UIAlertActionStyleDefault handler:nil]];
    [self presentViewController:alertController animated:YES completion:nil];
}
- (IBAction)showShareAction:(id)sender {
    if ([self.tweetTextView isFirstResponder])
        [self.tweetTextView resignFirstResponder];
    
    UIActivityViewController *moreVC = [[UIActivityViewController alloc]initWithActivityItems:@[self.tweetTextView.text] applicationActivities:nil];
    [self presentViewController:moreVC animated:YES completion:nil];
    
    UIAlertController *actionController = [UIAlertController alertControllerWithTitle:@"Share" message:@ "" preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleDefault handler:nil];
    
    UIAlertAction *tweetAction = [UIAlertAction actionWithTitle:@"Tweet" style:UIAlertActionStyleDefault handler:
                                  ^(UIAlertAction *action){
                                      if([SLComposeViewController isAvailableForServiceType:SLServiceTypeTwitter]){
                                          SLComposeViewController *twitterVC  = [SLComposeViewController composeViewControllerForServiceType:SLServiceTypeTwitter];
                                          if([self.tweetTextView.text length] < 140){
                                              [twitterVC setInitialText:self.tweetTextView.text];
                                          }
                                          else{
                                              NSString *shortText = [self.tweetTextView.text substringToIndex:140];
                                              [twitterVC setInitialText:shortText];
                                          }
                                          [self presentViewController:twitterVC animated:YES completion:nil];
                                      }
                                      else{
                                          [self showAlertMessages: @"Please sign in tweeter before you tweet"];
                                      }
                                  }];
    UIAlertAction *facebookAction = [UIAlertAction actionWithTitle:@"Facebook" style:UIAlertActionStyleDefault handler:
                                  ^(UIAlertAction *action){
                                      if([SLComposeViewController isAvailableForServiceType:SLServiceTypeFacebook]){
                                          SLComposeViewController *facebookVC  = [SLComposeViewController composeViewControllerForServiceType:SLServiceTypeFacebook];
                                          [facebookVC setInitialText:self.tweetTextView.text];
                                          [self presentViewController:facebookVC animated:YES completion:nil];
                                      }
                                      else{
                                          [self showAlertMessages: @"Please sign in facebook before you tweet"];
                                      }
                                  }];
    
    UIAlertAction *moreAction = [UIAlertAction actionWithTitle:@"More" style:UIAlertActionStyleDefault handler:
                                 ^(UIAlertAction *action){
                                     UIActivityViewController *moreVC = [[UIActivityViewController alloc]initWithActivityItems:@[self.tweetTextView.text] applicationActivities:nil];
                                     [self presentViewController:moreVC animated:YES completion:nil];
                                 }];
    
    [actionController addAction:tweetAction];
    [actionController addAction:facebookAction];
    [actionController addAction:moreAction];
    [actionController addAction:cancelAction];
    
//    [self presentViewController:actionController animated:YES completion:Nil];
}

- (void) configureTweetTextView{
    self.tweetTextView.layer.backgroundColor = [UIColor colorWithRed:1.0 green:1.0 blue:0.9 alpha:1.0].CGColor;
    self.tweetTextView.layer.cornerRadius = 10.0;
    self.tweetTextView.layer.borderColor = [UIColor colorWithWhite:0 alpha:0.5].CGColor;
    self.tweetTextView.layer.borderWidth = 2.0;
}

@end
