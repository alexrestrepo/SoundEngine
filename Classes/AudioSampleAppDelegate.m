//
//  AudioSampleAppDelegate.m
//  AudioSample
//
//  Created by Alex Restrepo on 9/14/09.
//  Copyright Brainchild 2009. All rights reserved.
//

#import "AudioSampleAppDelegate.h"
#import "RootViewController.h"


@implementation AudioSampleAppDelegate

@synthesize window;
@synthesize navigationController;


#pragma mark -
#pragma mark Application lifecycle

- (void)applicationDidFinishLaunching:(UIApplication *)application {    
    
    // Override point for customization after app launch    
	
	[window addSubview:[navigationController view]];
    [window makeKeyAndVisible];
}


- (void)applicationWillTerminate:(UIApplication *)application {
	// Save data if appropriate
}


#pragma mark -
#pragma mark Memory management

- (void)dealloc {
	[navigationController release];
	[window release];
	[super dealloc];
}


@end

