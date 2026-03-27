# workbench.library/CloseWorkbenchObjectAorkbench.library/CloseWorkbenchObjectA



   NAME
	CloseWorkbenchObjectA -- [Close](../Includes_and_Autodocs_3._guide/node0149.html) a drawer as if the user had clicked
	    on the window close gadget. (V44)

   SYNOPSIS
	success = CloseWorkbenchObjectA(name,tags)
	   D0                            A0   A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) CloseWorkbenchObjectA(STRPTR name,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tags);

	success = CloseWorkbenchObject(name,...);

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) CloseWorkbenchObject(STRPTR name,...);

   FUNCTION
	This routine attempts to close the named object as if the user
	had clicked on its drawer window close gadget.

   INPUTS
	name -- Name of the drawer to be closed.

	tags -- Additional options.

   TAGS
	No tags are defined yet (V44).

   RESULTS
	result -- FALSE if the object in question could not be closed,
	    TRUE otherwise. If FALSE is returned, you can query the error
	    code using [dos.library/IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).

   EXAMPLE
	/* [Close](../Includes_and_Autodocs_3._guide/node0149.html) the drawer "SYS:" */
	CloseWorkbenchObjectA("SYS:",NULL);

   NOTES
	The name of the drawer to be closed is interpreted relative
	to the current directory of the program to call
	CloseWorkbenchObjectA().

	For this function call to succeed, Workbench must be open. This
	means that the LoadWB command was executed and the Workbench
	screen has been opened.

	While the user is dragging icons, no on-screen rendering may
	take place. In this state Workbench may refuse to execute the
	CloseWorkbenchObject() call and return an error code instead
	(ERROR_OBJECT_IN_USE).

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[workbench.library/OpenWorkbenchObjectA](../Includes_and_Autodocs_3._guide/node05C1.html)

