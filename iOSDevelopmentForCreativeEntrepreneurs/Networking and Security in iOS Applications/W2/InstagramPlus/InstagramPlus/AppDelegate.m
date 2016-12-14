//
//  AppDelegate.m
//  InstagramPlus
//
//  Created by Garrett Wang on 12/12/16.
//  Copyright © 2016 Garrett Wang. All rights reserved.
//

#import "AppDelegate.h"
#import "NXOAuth2.h"

@interface AppDelegate ()

@property (atomic) NSString *outgoingRedirect;
@property (atomic) NSString *incomingRedirect;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.outgoingRedirect = @"http://djp3.westmont.edu/classes/2015-coursera-live/redirect.php/myscheme/thing.com";
    self.incomingRedirect = @"myscheme://thing.com";
    [[NXOAuth2AccountStore sharedStore] setClientID:@"3381b75adea44250aa29dacc59746448"
                                             secret:@"59d9d93028dc44d7a1304ca30002ec40"
                                   authorizationURL:[NSURL URLWithString:@"https://api.instagram.com/oauth/authorize/"]
                                           tokenURL:[NSURL URLWithString:@"https://api.instagram.com/oauth/access_token/"]
                                        redirectURL:[NSURL URLWithString:self.outgoingRedirect]
                                     forAccountType:@"Instagram"];
    return YES;
}

- (BOOL) application:(UIApplication *)app oepnURL:(NSURL *)url options:(NSDictionary<NSString *,id> *)options{
    NSLog(@"Succeed!");
    if([self.incomingRedirect containsString:[url scheme]] && [self.incomingRedirect containsString:[url host]]){
        NSURL *constructed = [NSURL URLWithString:[NSString stringWithFormat:@"%@?%@", self.outgoingRedirect, [url query]]];
        return [[NXOAuth2AccountStore sharedStore] handleRedirectURL:constructed];
    }
    else{
        return [[NXOAuth2AccountStore sharedStore] handleRedirectURL:url];
    }
    
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}



- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
