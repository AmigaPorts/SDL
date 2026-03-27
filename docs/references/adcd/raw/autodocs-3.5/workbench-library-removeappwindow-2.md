# workbench.library/RemoveAppWindow



   NAME
	RemoveAppWindow - remove a window from Workbench's list         (V36)

                          of AppWindows.
   SYNOPSIS
	success = RemoveAppWindow(AppWindow)

         D0                        A0
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) RemoveAppWindow(struct [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) *);

   FUNCTION
	Attempt to remove an appwindow from Workbench's list of AppWindows.

   INPUTS
	[AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) - pointer to an [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) structure returned by
	            AddAppWindow.

   RESULTS
	success - TRUE if the window could be removed, FALSE otherwise.

   NOTES
	As with anything that deals with asynchronous operation, you will need
	to do a final check for messages on your [AppMessage](../Includes_and_Autodocs_3._guide/node05D6.html#line115) port for messages
	that may have come in between the last time you checked and the
	call to removed the [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160).

	Before the [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) is removed, all its drop zones will be removed
	first. There is no need for you to call [RemoveAppWindowDropZone()](../Includes_and_Autodocs_3._guide/node05C5.html)
	for every single one.

   SEE ALSO
	[workbench.library/AddAppWindowA](../Includes_and_Autodocs_3._guide/node05BC.html)
	[workbench.library/RemoveAppWindowDropZone](../Includes_and_Autodocs_3._guide/node05C5.html)

