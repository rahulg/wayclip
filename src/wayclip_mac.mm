#import <Cocoa/Cocoa.h>
#include <iostream>

void returnFocus() {
	NSRunningApplication* old =
	  [[NSWorkspace sharedWorkspace] frontmostApplication];
	[old activateWithOptions:NSApplicationActivateIgnoringOtherApps];
}
