//
//  AudioSampleAppDelegate.h
//  AudioSample
//
//  Created by Alex Restrepo on 9/14/09.
//  Copyright Brainchild 2009. All rights reserved.
//

@interface AudioSampleAppDelegate : NSObject <UIApplicationDelegate> {
    
    UIWindow *window;
    UINavigationController *navigationController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet UINavigationController *navigationController;

@end

