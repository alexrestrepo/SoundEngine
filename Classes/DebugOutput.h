/************************************************************************
 * DebugOutput.h
 *
 * Definitions for DebugOutput class
 * John Muchow
 * http://iphonedevelopertips.com/cocoa/filename-and-line-number-with-nslog-part-ii.html
 ************************************************************************/

// Show full path of filename?
#define DEBUG_SHOW_FULLPATH NO

// Enable debug (NSLog) wrapper code?
#define DEBUG 1

//Use NSLog or CFShow
#define USE_NSLOG 0

#if DEBUG
  #define debug(format,...) [[DebugOutput sharedDebug] output:__FILE__ lineNumber:__LINE__ input:(format), ##__VA_ARGS__]
#else
  #define debug(format,...) 
#endif
  
@interface DebugOutput : NSObject
{
}
+ (DebugOutput *) sharedDebug;
-(void)output:(char*)fileName lineNumber:(int)lineNumber input:(NSString*)input, ...;
@end
