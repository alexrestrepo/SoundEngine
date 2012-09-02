/************************************************************************
* DebugOutput.m
*
* Singleton class for wrapping NSLog messages, adding functionality
* for displaying filename and line numbers. Also includes configuration
* options to "turn off" all debug (NSLog) messages
************************************************************************/
#import "DebugOutput.h"

@implementation DebugOutput

static DebugOutput *sharedDebugInstance = nil;

/*---------------------------------------------------------------------*/
+ (DebugOutput *) sharedDebug
{
  @synchronized(self)
  {
    if (sharedDebugInstance == nil)
    {
      [[self alloc] init];
    }  
  }
  return sharedDebugInstance;
}

/*---------------------------------------------------------------------*/
+ (id) allocWithZone:(NSZone *) zone
{
  @synchronized(self)
  {
    if (sharedDebugInstance == nil)
    {
      sharedDebugInstance = [super allocWithZone:zone];
      return sharedDebugInstance;
    }
  }
  return nil;
}

/*---------------------------------------------------------------------*/
- (id)copyWithZone:(NSZone *)zone
{
  return self;
}

/*---------------------------------------------------------------------*/
- (id)retain
{  
  return self;
}

/*---------------------------------------------------------------------*/
- (oneway void)release
{
  // No action required...
}

/*---------------------------------------------------------------------*/
- (unsigned)retainCount
{
  return UINT_MAX;  // An object that cannot be released
}

/*---------------------------------------------------------------------*/
- (id)autorelease
{ 
  return self;
}

/*---------------------------------------------------------------------*/
-(void)output:(char*)fileName lineNumber:(int)lineNumber input:(NSString*)input, ...
{
  va_list argList;
  NSString *filePath, *formatStr;
  
  // Build the path string
  filePath = [[NSString alloc] initWithBytes:fileName length:strlen(fileName) encoding:NSUTF8StringEncoding];
  
  // Process arguments, resulting in a format string
  va_start(argList, input);
  formatStr = [[NSString alloc] initWithFormat:input arguments:argList];
  va_end(argList);
  
	
  // Call NSLog, prepending the filename and line number
#if USE_NSLOG
  NSLog(@"%s[%d]: %@",[((DEBUG_SHOW_FULLPATH) ? filePath : [filePath lastPathComponent]) UTF8String], lineNumber, formatStr);
#else
  CFShow([NSString stringWithFormat: @"%s[%d]: %@",[((DEBUG_SHOW_FULLPATH) ? filePath : [filePath lastPathComponent]) UTF8String], lineNumber, formatStr]);
#endif
  
  [filePath release];
  [formatStr release];
}

@end