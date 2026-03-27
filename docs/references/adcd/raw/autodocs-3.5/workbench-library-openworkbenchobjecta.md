# workbench.library/OpenWorkbenchObjectA



   NAME
	OpenWorkbenchObjectA -- [Open](../Includes_and_Autodocs_3._guide/node0196.html) a drawer or launch a program as if
	    the user had double-clicked on an icon. (V44)

   SYNOPSIS
	success = OpenWorkbenchObjectA(name,tags)
	   D0                           A0   A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) OpenWorkbenchObjectA(STRPTR name,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tags);

	success = OpenWorkbenchObject(name,...);

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) OpenWorkbenchObject(STRPTR name,...);

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
	    entry of a [WBStartup](../Includes_and_Autodocs_3._guide/node0650.html#line24) message, to be sent to a program
	    to be launched. The lock you provide will be duplicated
	    when it is put into a [WBArg](../Includes_and_Autodocs_3._guide/node0650.html#line33) list.

	    The WBOPENA_ArgLock determines the lock parameters
	    to be associated with all following WBOPENA_ArgName tags.

	    This tag defaults to NULL.

	WBOPENA_ArgName (STRPTR) -- Corresponds to the WBArg->wa_Name
	    entry of a [WBStartup](../Includes_and_Autodocs_3._guide/node0650.html#line24) message to be sent to a program
	    to be launched. This tag can be used to construct a list
	    of parameters to pass to the tool/project to be launched.
	    It works in conjunction with the WBOPENA_ArgLock tag.
	    The name you provide will be duplicated when it is put
	    into a [WBArg](../Includes_and_Autodocs_3._guide/node0650.html#line33) list.

   RESULTS
	result -- FALSE if the object in question could not be opened,
	    TRUE otherwise. Note that TRUE may be returned even if
	    the program the object represents could not be launched;
	    this is due to limitations in the current (V44) Workbench
	    design. If FALSE is returned, you can query the error
	    code using [dos.library/IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).

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
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[workbench.library/CloseWorkbenchObjectA](../Includes_and_Autodocs_3._guide/node05BF.html)
	[<workbench/startup.h>](../Includes_and_Autodocs_3._guide/node0650.html)

