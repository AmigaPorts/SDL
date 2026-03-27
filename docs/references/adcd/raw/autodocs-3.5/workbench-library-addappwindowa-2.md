# workbench.library/AddAppWindowA



   NAME
	AddAppWindowA - add a window to Workbench's list of AppWindows.  (V36)

   SYNOPSIS
	[AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) = AddAppWindowA(id, userdata, window, msgport, taglist)
	D0                        D0     D1       A0      A1       A2

	struct [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) *AddAppWindowA(ULONG, ULONG, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
	                                struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	Alternate, varargs version:
	struct [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) *AddAppWindow(ULONG, ULONG, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
	                               struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *
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
	The notification consists of an [AppMessage](../Includes_and_Autodocs_3._guide/node05D6.html#line115) (found in workbench.h/i)
	of type 'MTYPE_APPWINDOW' arriving at the message port you specified.
	What you do with the list of icons (pointed to by am_ArgList) is
	up to you, but generally you would want to call [GetDiskObjectNew](../Includes_and_Autodocs_3._guide/node034E.html) on
	them.

   INPUTS
	id - this variable is strictly for your own use and is ignored by
	     Workbench.  Typical uses in C are in switch and case statements,
	     and in assembly language table lookup.
	userdata - this variable is strictly for your own use and is ignored
	           by Workbench.
	window - pointer to window to add.
	msgport - pointer to message port Workbench will use to send you an
	          [AppMessage](../Includes_and_Autodocs_3._guide/node05D6.html#line115) message of type 'MTYPE_APPWINDOW' when your
	          window gets an icon or icons dropped in it.
	taglist - ptr to a list of tag items.  Must be NULL for V2.0.

   RESULTS
	[AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) - a pointer to an [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) structure which you pass to
	            [RemoveAppWindow](../Includes_and_Autodocs_3._guide/node05C4.html) when you want to remove the window
	            from Workbench's list of AppWindows.  NULL
	            if Workbench was unable to add your window; typically
	            happens when Workbench is not running or under low
	            memory conditions.

   SEE ALSO
	[workbench.library/AddAppWindowDropZoneA](../Includes_and_Autodocs_3._guide/node05BD.html)
	[workbench.library/RemoveAppWindow](../Includes_and_Autodocs_3._guide/node05C4.html)

   NOTES
	The V2.0 icon editor is an example of an [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160).  Note that app
	window applications generally want to call [GetDiskObjectNew](../Includes_and_Autodocs_3._guide/node034E.html)
	(as opposed to GetDiskObject) to get the disk object for the icon
	dropped in the window.

	For this function call to succeed, Workbench must be open. This
	means that the LoadWB command was executed and the Workbench
	screen has been opened.

	When removing an [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160), all its drop zones will be automatically
	removed.

