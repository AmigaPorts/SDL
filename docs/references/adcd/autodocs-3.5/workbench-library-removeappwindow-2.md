---
title: workbench.library/RemoveAppWindow
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-removeappwindow-2
functions: []
libraries: []
---

# workbench.library/RemoveAppWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemoveAppWindow - remove a window from Workbench's list         (V36)

                          of AppWindows.
   SYNOPSIS
	success = RemoveAppWindow(AppWindow)

         D0                        A0
	[BOOL](autodocs-3.5/include-exec-types-h.md) RemoveAppWindow(struct [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) *);

   FUNCTION
	Attempt to remove an appwindow from Workbench's list of AppWindows.

   INPUTS
	[AppWindow](autodocs-3.5/include-workbench-workbench-h.md) - pointer to an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) structure returned by
	            AddAppWindow.

   RESULTS
	success - TRUE if the window could be removed, FALSE otherwise.

   NOTES
	As with anything that deals with asynchronous operation, you will need
	to do a final check for messages on your [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) port for messages
	that may have come in between the last time you checked and the
	call to removed the [AppWindow](autodocs-3.5/include-workbench-workbench-h.md).

	Before the [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) is removed, all its drop zones will be removed
	first. There is no need for you to call [RemoveAppWindowDropZone()](autodocs-3.5/workbench-library-removeappwindowdropzoneench-library.md)
	for every single one.

   SEE ALSO
	[workbench.library/AddAppWindowA](autodocs-3.5/workbench-library-addappwindowa-2.md)
	[workbench.library/RemoveAppWindowDropZone](autodocs-3.5/workbench-library-removeappwindowdropzoneench-library.md)

