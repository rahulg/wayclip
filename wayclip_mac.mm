#include <iostream>
#import <Cocoa/Cocoa.h>

void returnFocus() {
	NSRunningApplication *old = [[NSWorkspace sharedWorkspace] frontmostApplication];
	[old activateWithOptions:NSApplicationActivateIgnoringOtherApps];
}
