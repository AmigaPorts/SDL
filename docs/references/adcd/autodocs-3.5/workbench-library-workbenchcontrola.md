---
title: workbench.library/WorkbenchControlA
manual: autodocs-3.5
chapter: autodocs-3.5
section: workbench-library-workbenchcontrola
functions: [IoErr]
libraries: [dos.library]
---

# workbench.library/WorkbenchControlA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	WorkbenchControlA -- Query or modify Workbench and icon
	    options. (V44)

   SYNOPSIS
	success = WorkbenchControlA(name,tags)
	   D0                       A0   A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) WorkbenchControlA(STRPTR name,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	success = WorkbenchControl(name,...);

	[BOOL](autodocs-3.5/include-exec-types-h.md) WorkbenchControl(STRPTR name,...);

   FUNCTION
	With this function you can query or modify global Workbench
	parameters or local icon options.

   INPUTS
	name -- Name of an object to query or modify.

	tags -- Additional options.

   TAGS
	WBCTRLA_IsOpen (LONG *) -- Check if the named object is
	    currently open. In this case, the function "name"
	    parameter refers to the drawer that should be
	    tested; the result value will be set to TRUE if
	    the named drawer is currently open, FALSE otherwise.

	WBCTRLA_DuplicateSearchPath (BPTR *) -- This is a safe way
	    to obtain a copy of the Workbench search path list.
	    You will receive a [BPTR](autodocs-3.5/include-dos-dos-h.md) to a path list, such as can
	    be stored in the cli_CommandDir pointer of a
	    [CommandLineInterface](autodocs-3.5/include-dos-dosextens-h.md) structure. Note that this is really
	    a copy of the Workbench search path list and not a reference
	    to the data associated with the Workbench process. Thus,
	    it can be freed by FreeDosObject(DOS_CLI,..), if part of
	    a [CommandLineInterface](autodocs-3.5/include-dos-dosextens-h.md) structure.

	WBCTRLA_FreeSearchPath (BPTR) -- If you did not attach the
	    data returned by the WBCTRLA_DuplicateSearchPath
	    to a CLI, to be freed automatically later, you can
	    pass it back to WorkbenchControlA() to be released.

	WBCTRLA_GetDefaultStackSize (ULONG *) -- Get the default stack
	    size used by Workbench when launching Shell programs
	    or programs without a valid stack size number.

	    The default stack size is 4096 bytes.

	WBCTRLA_SetDefaultStackSize (ULONG) -- Set the default stack
	    size used by Workbench when launching Shell programs
	    or programs without a valid stack size number. You cannot
	    set a stack size number smaller than 4096 bytes

	WBCTRLA_RedrawAppIcon (struct [AppIcon](autodocs-3.5/include-workbench-workbench-h.md) *) -- This tag will cause
	    Workbench to redraw an [AppIcon](autodocs-3.5/include-workbench-workbench-h.md). Note that due to which state
	    the Workbench is currently in, it may refuse to redraw the
	    icon.

	WBCTRLA_GetProgramList (struct [List](autodocs-3.5/include-exec-lists-h.md) **) -- You can obtain a list
	    of currently running Workbench programs; every entry of this
	    list will have the complete path to the program and the
	    program name in its Node->ln_Name. When you no longer need
	    the list, don't forget to free it again using the tag
	    WBCTRLA_FreeProgramList.

	    Note that the list you will receive may be empty. Be
	    prepared to handle this.

	WBCTRLA_FreeProgramList (struct [List](autodocs-3.5/include-exec-lists-h.md) *) -- With this tag you can
	    free the list allocated by the WBCTRLA_GetProgramList tag.

	WBCTRLA_GetSelectedIconList (struct [List](autodocs-3.5/include-exec-lists-h.md) **) -- You can obtain a
	    list of currently selected icons; every entry of this
	    list will have the complete path to the icon and the
	    icon name in its Node->ln_Name. Some icons do not enter the
	    list, such as AppIcons. When you no longer need the list,
	    don't forget to free it again using the tag
	    WBCTRLA_FreeSelectedIconList.

	    Note that the list you will receive may be empty. Be
	    prepared to handle this.

	WBCTRLA_FreeSelectedIconList (struct [List](autodocs-3.5/include-exec-lists-h.md) *) -- With this tag
	    you can free the list allocated by the
	    WBCTRLA_GetSelectedIconList tag.

	WBCTRLA_GetOpenDrawerList (struct [List](autodocs-3.5/include-exec-lists-h.md) **) -- You can obtain a
	    list of currently open drawers and volumes; every entry of this
	    list will have the complete drawer path name in its Node->ln_Name.
	    When you no longer need the list, don't forget to free it
	    again using the tag WBCTRLA_FreeOpenDrawerList.

	    Note that the list you will receive may be empty. Be
	    prepared to handle this.

	WBCTRLA_FreeOpenDrawerList (struct [List](autodocs-3.5/include-exec-lists-h.md) *) -- With this tag
	    you can free the list allocated by the
	    WBCTRLA_GetOpenDrawerList tag.

	WBCTRLA_AddHiddenDeviceName (STRPTR) -- Name of a device which
	    Workbench should not display a disk or device icon for.
	    Any such device will be effectively hidden from the Workbench
	    backdrop. The name must include a terminating colon character,
	    such as in "DF0:".

	    Note that adding new entries to this list may not immediately
	    take effect.

	WBCTRLA_RemoveHiddenDeviceName (STRPTR) -- Name of a device on
	    the list of devices to be hidden which should be removed.
	    The name must include a terminating colon character,
	    such as in "DF0:". Trying to remove an entry from the list
	    that is not on it will have no effect.

	    Note that removing entries from this list may not immediately
	    take effect.

	WBCTRLA_GetHiddenDeviceList (struct [List](autodocs-3.5/include-exec-lists-h.md) **) -- This will obtain
	    the list of devices whose contents which Workbench will not
	    display.

	    Note that the list you will receive may be empty. Be
	    prepared to handle this.

	WBCTRLA_FreeHiddenDeviceList (struct [List](autodocs-3.5/include-exec-lists-h.md) *) -- With this tag
	    you can free the list allocated by the
	    WBCTRLA_GetHiddenDeviceList tag.

	WBCTRLA_GetTypeRestartTime (ULONG *) -- Get the number of seconds
	    that have to pass before typing the next character in a drawer
	    window will restart with a new file name.

	WBCTRLA_SetTypeRestartTime (ULONG) -- Set the number of seconds
	    that have to pass before typing the next character in a drawer
	    window will restart with a new file name. You must specify a
	    number greater than 0. Default type restart time is 3 seconds.

   RESULTS
	result -- FALSE if the requested action could not be performed,
	    TRUE otherwise. If FALSE is returned, you can query the error
	    code using [dos.library/IoErr()](autodocs-3.5/dos-library-ioerr-2.md).

   NOTES
	If this function returns FALSE, the expected result is undefined.
	For example, if you tried to obtain the list of currently running
	programs via the WBCTRLA_GetProgramList tag and WorkbenchControl()
	failed with an error code, do not expect the [List](autodocs-3.5/include-exec-lists-h.md) pointer you
	passed in to be initialized.

	This function may only be called by a [Process](autodocs-3.5/include-dos-dosextens-h.md).

	This function may not process all tags if the Workbench is not
	currently open. For V44, the following tags are support if
	Workbench is closed:

	    WBCTRLA_SetDefaultStackSize
	    WBCTRLA_GetDefaultStackSize
	    WBCTRLA_FreeHiddenDeviceList
	    WBCTRLA_GetHiddenDeviceList
	    WBCTRLA_AddHiddenDeviceName
	    WBCTRLA_RemoveHiddenDeviceName
	    WBCTRLA_SetTypeRestartTime
	    WBCTRLA_GetTypeRestartTime

   EXAMPLE
	/* Obtain a copy of the Workbench search path list, then
	 * release it again.
	 */
	[BPTR](autodocs-3.5/include-dos-dos-h.md) pathList;

	if(WorkbenchControl(NULL,
	    WBCTRLA_DuplicateSearchPath,&pathList,
	TAG_DONE))
	{
	    WorkbenchControl(NULL,
	        WBCTRLA_FreeSearchPath,pathList,
	    TAG_DONE);
	}

	/* Check if the drawer "SYS:" is open. */
	[LONG](autodocs-3.5/include-exec-types-h.md) isOpen;

	if(WorkbenchControl("SYS:",
	    WBCTRLA_IsOpen,&isOpen,
	TAG_DONE))
	{
	    Printf("Drawer "SYS:" is %s.n",
	        isOpen ? "open" : "closed");
	}

	/* Print the list of all currently running
	 * Workbench programs, then free the list again.
	 */
	struct [List](autodocs-3.5/include-exec-lists-h.md) * list;

	if(WorkbenchControl(NULL,
	    WBCTRLA_GetProgramList,&list,
	TAG_DONE))
	{
	    struct [Node](autodocs-3.5/include-exec-nodes-h.md) * node;

	    for(node = list->lh_Head ;
	        node->ln_Succ != NULL ;
	        node = node->ln_Succ)
	    {
	        Printf("%sn",node->ln_Name);
	    }

	    WorkbenchControl(NULL,
	        WBCTRLA_FreeProgramList,list,
	    TAG_DONE);
	}

   SEE ALSO
	[dos.library/FreeDosObject](autodocs-3.5/dos-library-freedosobject-2.md)
	[dos.library/IoErr](autodocs-3.5/dos-library-ioerr-2.md)
	[<dos/dosextens.h>](autodocs-3.5/include-dos-dosextens-h.md)

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
