# workbench.library/RemoveAppIcon



   NAME
	RemoveAppIcon - remove an icon from Workbench's list            (V36)

                         of AppIcons.
   SYNOPSIS
	success = RemoveAppIcon(AppIcon)

         D0                      A0
	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) RemoveAppIcon(struct [AppIcon](../Includes_and_Autodocs_3._guide/node05D6.html#line162) *);

   FUNCTION
	Attempt to remove an [AppIcon](../Includes_and_Autodocs_3._guide/node05D6.html#line162) from Workbench's list of AppIcons.

   INPUTS
	[AppIcon](../Includes_and_Autodocs_3._guide/node05D6.html#line162) - pointer to an [AppIcon](../Includes_and_Autodocs_3._guide/node05D6.html#line162) structure returned by AddAppIcon.

   RESULTS
	success - TRUE if the icon could be removed, FALSE otherwise.

   NOTES
	As with anything that deals with asynchronous operation, you will need
	to do a final check for messages on your [AppMessage](../Includes_and_Autodocs_3._guide/node05D6.html#line115) port for messages
	that may have come in between the last time you checked and the
	call to remove the [AppIcon](../Includes_and_Autodocs_3._guide/node05D6.html#line162).

   SEE ALSO
	[workbench.library/AddAppIconA](../Includes_and_Autodocs_3._guide/node05BA.html)

