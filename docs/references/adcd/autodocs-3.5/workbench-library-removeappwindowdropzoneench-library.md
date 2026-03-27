---
title: workbench.library/RemoveAppWindowDropZoneench.library/RemoveAppWindowDropZone
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-removeappwindowdropzoneench-library
functions: []
libraries: []
---

# workbench.library/RemoveAppWindowDropZoneench.library/RemoveAppWindowDropZone

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemoveAppWindowDropZone -- [Remove](autodocs-3.5/exec-library-remove-2.md) a drop zone from an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md).

   SYNOPSIS
	success = RemoveAppWindowDropZone(appWindow,dropZone)
	  D0                                 A0        A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) RemoveAppWindowDropZone(struct [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) *,
	                             struct AppWindowDropZone *);

   FUNCTION
	Attempt to remove a drop zone from an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md).

   INPUTS
	appWindow -- pointer to an [AppWindow](autodocs-3.5/include-workbench-workbench-h.md) structure returned by
	    [workbench.library/AddAppWindowA](autodocs-3.5/workbench-library-addappwindowa-2.md). A value of NULL will be
	    ignored.
	dropZone -- pointer to an AppWindowDropZone returned by
	    [workbench.library/AddAppWindowDropZoneA](autodocs-3.5/workbench-library-addappwindowdropzoneaorkbench-library.md). A value of NULL will
	    be ignored.

   RESULTS
	success - TRUE if the drop zone could be removed, FALSE otherwise.
	    The reason for the failure can be obtained using
	    [dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md). This routine may fail if the specified drop
	    zone is not registered with the [AppWindow](autodocs-3.5/include-workbench-workbench-h.md).

   NOTES
	Due to the asynchronous nature of Workbench/user interaction, you
	may receive [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) drop zone messages for zones that you have
	just removed. These messages may arrive in the time between your
	code calling RemoveAppWindowDropZone() and Workbench responding
	to the drop zone removal request. Be prepared to handle this. Once
	a drop zone is removed, it will generate no new AppMessages.

   SEE ALSO
	[workbench.library/AddAppWindowDropZoneA](autodocs-3.5/workbench-library-addappwindowdropzoneaorkbench-library.md)

