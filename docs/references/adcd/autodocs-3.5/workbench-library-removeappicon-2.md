---
title: workbench.library/RemoveAppIcon
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-removeappicon-2
functions: []
libraries: []
---

# workbench.library/RemoveAppIcon

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemoveAppIcon - remove an icon from Workbench's list            (V36)

                         of AppIcons.
   SYNOPSIS
	success = RemoveAppIcon(AppIcon)

         D0                      A0
	[BOOL](autodocs-3.5/include-exec-types-h.md) RemoveAppIcon(struct [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) *);

   FUNCTION
	Attempt to remove an [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) from Workbench's list of AppIcons.

   INPUTS
	[AppIcon](autodocs-3.5/include-workbench-workbench-h.md) - pointer to an [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) structure returned by AddAppIcon.

   RESULTS
	success - TRUE if the icon could be removed, FALSE otherwise.

   NOTES
	As with anything that deals with asynchronous operation, you will need
	to do a final check for messages on your [AppMessage](autodocs-3.5/include-workbench-workbench-h.md) port for messages
	that may have come in between the last time you checked and the
	call to remove the [AppIcon](autodocs-3.5/include-workbench-workbench-h.md).

   SEE ALSO
	[workbench.library/AddAppIconA](autodocs-3.5/workbench-library-addappicona-2.md)

