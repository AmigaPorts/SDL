---
title: workbench.library/OpenWorkbenchObjectA
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-openworkbenchobjecta
functions: [IoErr]
libraries: [dos.library]
---

# workbench.library/OpenWorkbenchObjectA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OpenWorkbenchObjectA -- [Open](autodocs-3.5/dos-library-open-2.md) a drawer or launch a program as if
	    the user had double-clicked on an icon. (V44)

   SYNOPSIS
	success = OpenWorkbenchObjectA(name,tags)
	   D0                           A0   A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) OpenWorkbenchObjectA(STRPTR name,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	success = OpenWorkbenchObject(name,...);

	[BOOL](autodocs-3.5/include-exec-types-h.md) OpenWorkbenchObject(STRPTR name,...);

   FUNCTION
	This routine attempts to open the named object as if the user
	had double-clicked on its icon. This allows you to open drawers
	under program control or to have Workbench launch your programs.

   INPUTS
	name -- Name of the object to be opened; this can be a drawer
	    name, a tool name or a project name.

	tags -- Additional options.

   TAGS
	WBOPENA_ArgLock (BPTR) -- Corresponds to the WBArg->wa_Lock
	    entry of a [WBStartup](autodocs-3.5/include-workbench-startup-h.md) message, to be sent to a program
	    to be launched. The lock you provide will be duplicated
	    when it is put into a [WBArg](autodocs-3.5/include-workbench-startup-h.md) list.

	    The WBOPENA_ArgLock determines the lock parameters
	    to be associated with all following WBOPENA_ArgName tags.

	    This tag defaults to NULL.

	WBOPENA_ArgName (STRPTR) -- Corresponds to the WBArg->wa_Name
	    entry of a [WBStartup](autodocs-3.5/include-workbench-startup-h.md) message to be sent to a program
	    to be launched. This tag can be used to construct a list
	    of parameters to pass to the tool/project to be launched.
	    It works in conjunction with the WBOPENA_ArgLock tag.
	    The name you provide will be duplicated when it is put
	    into a [WBArg](autodocs-3.5/include-workbench-startup-h.md) list.

   RESULTS
	result -- FALSE if the object in question could not be opened,
	    TRUE otherwise. Note that TRUE may be returned even if
	    the program the object represents could not be launched;
	    this is due to limitations in the current (V44) Workbench
	    design. If FALSE is returned, you can query the error
	    code using [dos.library/IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

   EXAMPLE
	/* Launch Multiview with S:Startup-Sequence as its parameter. */
	OpenWorkbenchObject("MultiView",
	    WBOPENA_ArgLock, Lock("S:",SHARED_LOCK),
	    WBOPENA_ArgName, "Startup-Sequence",
	TAG_DONE);

	/* Launch the application "Paint" with the project files "Image1"
	 * and "Image2", which are both found in the drawer "Paint:Pictures".
	 */
	OpenWorkbenchObject("Paint",
	    WBOPENA_ArgLock, Lock("Paint:Pictures",SHARED_LOCK),
	    WBOPENA_ArgName, "Image1",
	    WBOPENA_ArgName, "Image2",
	TAG_DONE);

	/* Launch the application "Paint" with the project files "Image1"
	 * and "Anim1", which are both found in the drawers "Paint:Pictures"
	 * and "Paint:Animations", respectively.
	 */
	OpenWorkbenchObject("Paint",
	    WBOPENA_ArgLock, Lock("Paint:Pictures",SHARED_LOCK),
	    WBOPENA_ArgName, "Image1",
	    WBOPENA_ArgLock, Lock("Paint:Animations",SHARED_LOCK),
	    WBOPENA_ArgName, "Anim1",
	TAG_DONE);

   NOTES
	You need not specify fully qualified path names for programs to
	be launched. Workbench will look for files without fully
	qualified path names along its default Shell search path.
	In any case, Workbench will look for the tool to be launched
	in the current directory of the program that called
	OpenWorkbenchObjectA(). The same holds true for drawers.

	When launching a program, Workbench will automatically figure
	out which tool to use if the object in question is actually a
	project file with a project icon. Note that if the project
	icon's default tool cannot be found, you will not see any
	error message.

	Workbench transparently supports launching of Shell programs,
	but this is not recommended. You should always launch Shell
	programs from your own process.

	When you open a drawer, all WBOPENA_Arg[..] parameters you may
	have provided will be ignored.

	For this function call to succeed, Workbench must be open. This
	means that the LoadWB command was executed and the Workbench
	screen has been opened.

	While the user is dragging icons, no on-screen rendering may
	take place. In this state Workbench may refuse to execute the
	OpenWorkbenchObject() call and return an error code instead
	(ERROR_OBJECT_IN_USE).

   SEE ALSO
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[workbench.library/CloseWorkbenchObjectA](autodocs-3.5/workbench-library-closeworkbenchobjectaorkbench-library.md)
	[<workbench/startup.h>](autodocs-3.5/include-workbench-startup-h.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
