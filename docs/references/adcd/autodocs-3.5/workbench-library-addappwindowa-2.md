---
title: workbench.library/AddAppWindowA
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-addappwindowa-2
functions: []
libraries: []
---

# workbench.library/AddAppWindowA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddAppWindowA - add a window to Workbench's list of AppWindows.  (V36)

   SYNOPSIS
	[AppWindow](autodocs-3.5/include-workbench-workbench-h.md) = AddAppWindowA(id, userdata, window, msgport, taglist)
	D0                        D0     D1       A0      A1       A2

	struct [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) *AddAppWindowA(ULONG, ULONG, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
	                                struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	Alternate, varargs version:
	struct [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) *AddAppWindow(ULONG, ULONG, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
	                               struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *
	                               tag1, data1,
	                               tag2, data2,
	                               ...
	                               TAG_END );

   FUNCTION
	Attempt to add the window to Workbench's list of AppWindows.
	Normally non-Workbench windows (those not opened by Workbench)
	cannot have icons dropped in them.  This call is provided to
	allow applications to be notified when an icon or icons get
	dropped inside a window that they have registered with Workbench.
	The notification consists of an [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) (found in workbench.h/i)
	of type 'MTYPE_APPWINDOW' arriving at the message port you specified.
	What you do with the list of icons (pointed to by am_ArgList) is
	up to you, but generally you would want to call [GetDiskObjectNew](autodocs-3.5/icon-library-getdiskobjectnew-2.md) on
	them.

   INPUTS
	id - this variable is strictly for your own use and is ignored by
	     Workbench.  Typical uses in C are in switch and case statements,
	     and in assembly language table lookup.
	userdata - this variable is strictly for your own use and is ignored
	           by Workbench.
	window - pointer to window to add.
	msgport - pointer to message port Workbench will use to send you an
	          [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) message of type 'MTYPE_APPWINDOW' when your
	          window gets an icon or icons dropped in it.
	taglist - ptr to a list of tag items.  Must be NULL for V2.0.

   RESULTS
	[AppWindow](autodocs-3.5/include-workbench-workbench-h.md) - a pointer to an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) structure which you pass to
	            [RemoveAppWindow](autodocs-3.5/workbench-library-removeappwindow-2.md) when you want to remove the window
	            from Workbench's list of AppWindows.  NULL
	            if Workbench was unable to add your window; typically
	            happens when Workbench is not running or under low
	            memory conditions.

   SEE ALSO
	[workbench.library/AddAppWindowDropZoneA](autodocs-3.5/workbench-library-addappwindowdropzoneaorkbench-library.md)
	[workbench.library/RemoveAppWindow](autodocs-3.5/workbench-library-removeappwindow-2.md)

   NOTES
	The V2.0 icon editor is an example of an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md).  Note that app
	window applications generally want to call [GetDiskObjectNew](autodocs-3.5/icon-library-getdiskobjectnew-2.md)
	(as opposed to GetDiskObject) to get the disk object for the icon
	dropped in the window.

	For this function call to succeed, Workbench must be open. This
	means that the LoadWB command was executed and the Workbench
	screen has been opened.

	When removing an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md), all its drop zones will be automatically
	removed.

