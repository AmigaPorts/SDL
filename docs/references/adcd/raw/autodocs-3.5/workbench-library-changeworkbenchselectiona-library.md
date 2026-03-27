# workbench.library/ChangeWorkbenchSelectionA.library/ChangeWorkbenchSelectionA



   NAME
	ChangeWorkbenchSelectionA -- Change the selection states of icons
	    displayed by Workbench. (V44)

   SYNOPSIS
	success = ChangeWorkbenchSelectionA(name,hook,tags)
	   D0                                A0   A1   A2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ChangeWorkbenchSelectionA(STRPTR name,struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *hook,
	                               struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tags);

	success = ChangeWorkbenchSelection(name,hook,...);

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ChangeWorkbenchSelection(STRPTR name,struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *hook,...);

   FUNCTION
	The icons displayed inside each Workbench window can be in selected
	or in unselected state. This routine allows you to change this state
	for every icon found in a particular window.

   INPUTS
	name -- Name of the drawer whose icons should be submitted to the
	    callback hook for testing; pass NULL as the name to have the
	    icons in the Workbench backdrop (where disks and AppIcons live)
	    passed through the hook. Note that the drawer whose icons you
	    want to change must be open before you can make any changes.

	hook -- [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) to be invoked for each icon in the window.

	    The hook code will be invoked with the following parameters

	    action = hookFunc(hook,reserved,ism)
	       D0                A0     A2    A1

	    ULONG hookFunc(struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *hook,[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) reserved,
	                   struct [IconSelectMsg](../Includes_and_Autodocs_3._guide/node05D6.html#line398) *ism);

	    The reserved parameter will be set to NULL (V44).

	    The [IconSelectMsg](../Includes_and_Autodocs_3._guide/node05D6.html#line398) contents are as follows:

	        ism_Length
	            Size of the [IconSelectMsg](../Includes_and_Autodocs_3._guide/node05D6.html#line398) data structure (in bytes).
	            Since this message may need to grow in the future,
	            always compare this value against the message size
	            you expect. For V44, ism_Length is guaranteed to
	            contain a value of 36. Expect this value to become
	            larger in the future.

	        ism_Drawer
	            A lock on the drawer the object in question resides
	            in. This may be NULL for the Workbench backdrop (where
	            disks and AppIcons live).

	        ism_Name
	            Name of the object in question; please note that for
	            disk icons the name does not end with a colon character
	            (":").

	        ism_Type
	            This is one of WBDISK, WBDRAWER, WBTOOL, WBPROJECT,
	            WBGARBAGE, WBDEVICE, WBKICK or WBAPPICON.

	        ism_Selected
	            TRUE if the object in question is currently selected,
	            FALSE otherwise.

	        ism_Tags
	            The list of tag items passed to ChangeWorkbenchSelectionA().

	        ism_DrawerWindow
	            If the object in question is a drawer or disk and its
	            associated window is currently open, then you will find
	            a pointer to it here.

	        ism_ParentWindow
	            This is a pointer to the window the object resides in.

	        ism_Left
	        ism_Top
	        ism_Width
	        ism_Height
	            These denote the position and size of the object in
	            question, relative to the top left edge of the window
	            it resides in.

	    With the exception of the ism_Left and ism_Top members, the
	    [IconSelectMsg](../Includes_and_Autodocs_3._guide/node05D6.html#line398) is read-only. The ism_Left/ism_Top members can
	    be used to change the position of the icon.

	    You hook code must return one of the following values:

	        ISMACTION_Unselect
	            Unselect the icon

	        ISMACTION_Select
	            Select the icon

	        ISMACTION_Ignore
	            Do not change the selection state of the icon.

	        ISMACTION_Stop
	            Do not change the selection state of the icon. Do not
	            invoke the hook function again.

	tags -- Additional options.

   TAGS
	No tags are defined yet (V44).

   RESULTS
	result -- FALSE if the drawer in question could not be found,
	    TRUE otherwise. If FALSE is returned, you can query the error
	    code using [dos.library/IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).

   EXAMPLE
	/* Select the icon labeled "Prefs" in the drawer "SYS:". */
	struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) hook;

	/* This hook code is responsible for selecting the icon. */
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73)
	SelectPrefs(struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *hook,[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) reserved,struct [IconSelectMsg](../Includes_and_Autodocs_3._guide/node05D6.html#line398) *ism)
	{
	    /* [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) the old icon select status; if the icon name
	     * does not match "Prefs", this is what we will return,
	     * not changing anything.
	     */
	    [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) selected = ism->ism_Selected;

	    /* If the name matches, select it. Otherwise, leave its
	     * select state alone.
	     */
	    if(Stricmp(ism->ism_Name,"Prefs") == 0)
	        selected = TRUE;

	    return(selected);
	}

	.
	.
	.

	/* Set up the hook data structure. */
	hook.h_Entry = HookEntry;
	hook.h_SubEntry = (HOOKFUNC)SelectPrefs;

	/* And finally change the selection. */
	ChangeWorkbenchSelection("SYS:",&hook,TAG_END);

   NOTES
	The name of the drawer to work on is interpreted relative
	to the current directory of the program to call
	ChangeWorkbenchSelectionA().

	For this function call to succeed, Workbench must be open. This
	means that the LoadWB command was executed and the Workbench
	screen has been opened.

	While the user is dragging icons, no on-screen rendering may
	take place. In this state Workbench may refuse to execute the
	ChangeWorkbenchSelection() call and return an error code instead
	(ERROR_OBJECT_IN_USE).

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)

