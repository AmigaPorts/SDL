---
title: workbench.library/RemoveAppMenuItem
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-removeappmenuitem-2
functions: []
libraries: []
---

# workbench.library/RemoveAppMenuItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemoveAppMenuItem - remove a menu item from Workbench's list     (V36)
	                    of AppMenuItems.

   SYNOPSIS
	success = RemoveAppMenuItem(AppMenuItem)

         D0                            A0
	[BOOL](autodocs-3.5/include-exec-types-h.md) RemoveAppMenuItem(struct AppMenuItem *);

   FUNCTION
	Attempt to remove an AppMenuItem from Workbench's list
	of AppMenuItems.

   INPUTS
	AppMenuItem - pointer to an AppMenuItem structure returned by
	              AddAppMenuItem.

   RESULTS
	success - TRUE if the menu could be removed, FALSE otherwise.

   NOTES
	As with anything that deals with asynchronous operation, you will need
	to do a final check for messages on your [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) port for messages
	that may have come in between the last time you checked and the
	call to removed the AppMenuItem.

   SEE ALSO
	[workbench.library/AddAppMenuItemA](autodocs-3.5/workbench-library-addappmenuitema-2.md)

