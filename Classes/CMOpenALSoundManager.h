//
//  CMOpenALSoundManager.h
//
//  Created by Alex Restrepo on 5/19/09.
//  Copyright 2009 Colombiamug. All rights reserved.
//
//	Portions of this code are adapted from Apple's oalTouch example and
//	http://www.gehacktes.net/2009/03/iphone-programming-part-6-multiple-sounds-with-openal/
//
//  This code is released under the creative commons attribution-share alike licence, meaning:
//
//	Attribution - You must attribute the work in the manner specified by the author or licensor 
//	(but not in any way that suggests that they endorse you or your use of the work).
//	In this case, simple credit somewhere in your app or documentation will suffice.
//
//	Share Alike - If you alter, transform, or build upon this work, you may distribute the resulting
//	work only under the same, similar or a compatible license.
//	Simply put, if you improve upon it, share!
//
//	http://creativecommons.org/licenses/by-sa/3.0/us/

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import <OpenAL/al.h>
#import <OpenAL/alc.h>

#define USE_AS_SINGLETON 0	//Set this to 0 if you want to use this class as a regular class instead of as a singleton.

@class CMOpenALSound;

@interface CMOpenALSoundManager : NSObject 
{	
	AVAudioPlayer		*backgroundAudio;	// background music
	
	NSMutableDictionary	*soundDictionary;	// stores our soundkeys
	NSArray				*soundFileNames;	// array that holds the filenames for the sounds, they will be referenced by index
	
	BOOL				isiPodAudioPlaying;	// ipod playing music? 

	float				backgroundMusicVolume;
	float				soundEffectsVolume;
	
	BOOL				interrupted;
	NSString			*currentBackgroundAudioFile;
}

@property (nonatomic, retain) NSArray *soundFileNames;
@property (nonatomic, readonly) BOOL isiPodAudioPlaying;
@property (nonatomic) float backgroundMusicVolume;
@property (nonatomic) float soundEffectsVolume;

#if USE_AS_SINGLETON
+ (CMOpenALSoundManager *) sharedCMOpenALSoundManager;
#endif

- (void) purgeSounds;		// purges all sounds from memory, in case of a memory warning...
- (void) beginInterruption;	// handle os sound interruptions
- (void) endInterruption;

- (void) playBackgroundMusic:(NSString *)file;	//file is the filename to play (from your main bundle)
- (void) playBackgroundMusic:(NSString *)file forcePlay:(BOOL)forcePlay; //if forcePlay is YES, iPod audio will be stopped.
- (void) stopBackgroundMusic;
- (void) pauseBackgroundMusic;
- (void) resumeBackgroundMusic;

- (void) playSoundWithID:(NSUInteger)soundID;	//id is the index in the sound filename array
- (void) stopSoundWithID:(NSUInteger)soundID;
- (void) pauseSoundWithID:(NSUInteger)soundID;
- (void) rewindSoundWithID:(NSUInteger)soundID;

- (BOOL) isPlayingSoundWithID:(NSUInteger)soundID;
- (BOOL) isBackGroundMusicPlaying;
@end
