---
title: workbench.library/AddAppWindowDropZoneAorkbench.library/AddAppWindowDropZoneA
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-addappwindowdropzoneaorkbench-library
functions: []
libraries: []
---

# workbench.library/AddAppWindowDropZoneAorkbench.library/AddAppWindowDropZoneA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddAppWindowDropZoneA -- Designate an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) area as suitable for
	    dropping icons on. (V44)

   SYNOPSIS
	dropZone = AddAppWindowDropZoneA(appWindow,id,userData,tags)
	   D0                               A0    D0    D1     A1

	struct AppWindowDropZone * AddAppWindowDropZoneA(struct [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) *aw,
	                           ULONG id,ULONG userData,
	                           struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * tags);

	dropZone = AddAppWindowDropZone(appWindow,id,userData,zone,...)

	struct AppWindowDropZone * AddAppWindowDropZone(struct [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) *aw,
	                           ULONG id,ULONG userData,...);

   FUNCTION
	Once it is created, Workbench will allow the user to drop an
	icon anywhere inside an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md), regardless of whether the
	icon was dropped on an area designated for dropping icons on
	or not. With AddAppWindowDropZoneA() you can tell Workbench
	which [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) areas are suitable for dropping icons on.

   INPUTS
	aw -- An [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) data structure, as returned by
	    [workbench.library/AddAppWindowA](autodocs-3.5/workbench-library-addappwindowa-2.md).
	id -- This variable is strictly for your own use and is ignored by
	    Workbench. Typical uses in C are in switch and case statements,
	    and in assembly language table lookup. Later, when an icon is
	    dropped on the designated area, the [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) sent to your
	    port will have the am_ID member set to this value.
	userData -- this variable is strictly for your own use and is ignored
	    by Workbench. Later, when an icon is dropped on the designated area,
	    the [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) sent to your port will have the am_UserData member
	    set to this value.
	tags -- [List](autodocs-3.5/include-exec-lists-h.md) of attributes to control the position and size
	    of the drop zone.

   TAGS
	WBDZA_Left (WORD) -- Left edge of the drop zone; a value of
	    0 would create a zone located at the left corner of the
	    window.

	WBDZA_RelRight (WORD) -- Left edge of the drop zone, relative
	    to the window width; a value of -10 would create a zone located
	    10 pixels left of the window right edge.

	WBDZA_Top (WORD) -- Top edge of the drop zone; a value of
	    0 would create a zone located at the top corner of the
	    window.

	WBDZA_RelBottom (WORD) -- Top edge of the drop zone, relative
	    to the window height; a value of -10 would create a zone located
	    10 pixels above the window bottom edge.

	WBDZA_Width (WORD) -- Width of the drop zone.

	WBDZA_RelWidth (WORD) -- Width of the drop zone, relative to the
	    width of the window; a value of -20 would create a zone that
	    is by 20 pixels narrower than the window.

	WBDZA_Height (WORD) -- Height of the drop zone.

	WBDZA_RelHeight (WORD) -- Height of the drop zone, relative to the
	    height of the window; a value of -20 would create a zone that
	    is by 20 pixels smaller than the window.

	WBDZA_Box (struct [IBox](autodocs-3.5/include-intuition-intuition-h.md) *) -- Position and size of the drop zone.

	WBDZA_Hook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) -- Pointer to a hook that will be
	    invoked whenever the mouse enters or leaves your drop zone
	    area. Your hook will be called with the following parameters:

	    result = hookFunc(hook,reserved,arm)
	      D0               A0     A2     A1

	    [LONG](autodocs-3.5/include-exec-types-h.md) hookFunc(struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *hook,[APTR](autodocs-3.5/include-exec-types-h.md) reserved,
	                  struct [AppWindowDropZoneMsg](autodocs-3.5/include-workbench-workbench-h.md) *adzm);

	    The reserved parameter will be set to NULL (V44).
	    For future enhancement, make sure that your hook
	    function always returns NULL (V44).

	    The drop zone message contents are as follows:

	        adzm_RastPort
	            A pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to render into.
	            Typically, this is the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) of the window
	            the drop zone is attached to.

	        adzm_DropZoneBox
	            This member describes the position and size
	            of the drop zone. The zone is guaranteed to
	            be a valid area, i.e. the Width and Height
	            will both be greater than 0 and the Left/Top
	            will be well within the bounds of the window
	            containing the drop zone.

	        adzm_ID
	        adzm_UserData
	            These two come straight from the values you passed
	            as the id and userData parameters to
	            AddAppWindowDropZoneA().

	        adzm_Action
	            Depending upon whether the mouse has just entered
	            or left the drop zone area, this variable will be
	            set to ADZMACTION_Enter or to ADZMACTION_Leave.
	            Any other values for adzm_Action should be ignored.

	            When the mouse enters the drop zone, do your drop
	            zone area highlighting. When the mouse leaves the
	            drop zone, remove any highlighting done in the
	            previous ADZMACTION_Enter pass.

	            Note that the mouse leaving your drop zone box
	            does not imply that no icons will be dropped on it.
	            You may still receive a notification lateron, telling
	            you that your drop zone had icons dropped on it.
	            The hook function is solely for highlighting and
	            unhighlighting the drop zone area.

	    A final word of warning: when your hook code is called, you
	    must limit your rendering to simple drawing operations
	    from graphics.library; if you do anything complex that
	    involves Intuition locking and unlocking the display,
	    such as refreshing gadgets or locking [IntuitionBase](autodocs-3.5/include-intuition-intuitionbase-h.md),
	    you will deadlock the operating system. You have been
	    warned!

   RESULT
	dropZone -- A newly created drop zone identifier, or NULL if
	    it could not be created; use [dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md) to find out
	    what caused it to fail.

   NOTES
	Once an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) has a drop zone installed, Workbench will send
	a new type of [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) to your port if icons are dropped on
	a drop zone. Instead of AMTYPE_APPWINDOW type messages you
	will receive AMTYPE_APPWINDOWZONE messages. In fact, you will
	no longer hear any AMTYPE_APPWINDOW type messages since Workbench
	will allow users to drop icons only on drop zones. Be prepared
	to handle this.

	Adding a drop zone to an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) does not guarantee that only
	AMTYPE_APPWINDOWZONE type messages will arrive at your message
	port. In fact, the user may be able to drop an icon on the window
	before the first drop zone is installed. Be prepared to handle
	this.

	Workbench checks drop zones in the order in which they were added
	to the [AppWindow](autodocs-3.5/include-workbench-workbench-h.md). Thus, if two zones overlap, the zone that was
	added first will be reported as hit.

	An [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) starts out with its entire area available for dropping
	icons on. Thus, you may receive AppMessages for icons dropped upon
	your [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) before you have added the first drop zone to it.
	Be prepared to handle this.

	Drop zones must be created with a position and a size. If you omit
	either one, this routine will fail.

	When an icon is dropped on a drop zone, the [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) am_MouseX and
	am_MouseY members will be relative to the window top left corner;
	they WILL NOT be relative to the left/top edge of the drop zone.

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[workbench.library/AddAppWindowA](autodocs-3.5/workbench-library-addappwindowa-2.md)

