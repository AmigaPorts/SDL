# printer.device/PRD_EDITPREFS



   NAME
	PRD_EDITPREFS - open the driver preferences window (V44)

   FUNCTION
	New drivers can have own preferences. This commands ask the driver
	to open a window to allow the user to change the prefs. Typically
	this is done with an [DoIO()](../Includes_and_Autodocs_3._guide/node0204.html) call.

	Every application should have a button "Driver Options..." (that
	calls PRD_EDITPREFS) in its printer dialog.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible.
	io_Command	PRD_EDITPREFS
	io_Flags	IOB_QUICK set if quick I/O is possible.
	io_TagList	a list of tags to specify more parameters

	The following tags are currently defined:

	PPRA_Window (struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *)	a pointer to a window. This prefs
		window will open on the same screen and lock the window from
		user input.
	PPRA_Screen (struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *)	a pointer to a screen. That can be
		used if no window is open.
	PPRA_PubScreen (STRPTR)	a name of a public screen that will be used
		to open the window. This can be NULL to use the default
		public screen.

