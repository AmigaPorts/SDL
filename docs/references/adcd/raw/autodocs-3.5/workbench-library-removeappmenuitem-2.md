# workbench.library/RemoveAppMenuItem



   NAME
	RemoveAppMenuItem - remove a menu item from Workbench's list     (V36)
	                    of AppMenuItems.

   SYNOPSIS
	success = RemoveAppMenuItem(AppMenuItem)

         D0                            A0
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) RemoveAppMenuItem(struct AppMenuItem *);

   FUNCTION
	Attempt to remove an AppMenuItem from Workbench's list
	of AppMenuItems.

   INPUTS
	AppMenuItem - pointer to an AppMenuItem structure returned by
	              AddAppMenuItem.

   RESULTS
	success - TRUE if the menu could be removed, FALSE otherwise.

   NOTES
	As with anything that deals with asynchronous operation, you will need
	to do a final check for messages on your [AppMessage](../Includes_and_Autodocs_3._guide/node05D6.html#line115) port for messages
	that may have come in between the last time you checked and the
	call to removed the AppMenuItem.

   SEE ALSO
	[workbench.library/AddAppMenuItemA](../Includes_and_Autodocs_3._guide/node05BB.html)

