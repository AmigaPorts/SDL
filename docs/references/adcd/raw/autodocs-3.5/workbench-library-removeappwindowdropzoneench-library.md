# workbench.library/RemoveAppWindowDropZoneench.library/RemoveAppWindowDropZone



   NAME
	RemoveAppWindowDropZone -- [Remove](../Includes_and_Autodocs_3._guide/node022F.html) a drop zone from an [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160).

   SYNOPSIS
	success = RemoveAppWindowDropZone(appWindow,dropZone)
	  D0                                 A0        A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) RemoveAppWindowDropZone(struct [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) *,
	                             struct AppWindowDropZone *);

   FUNCTION
	Attempt to remove a drop zone from an [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160).

   INPUTS
	appWindow -- pointer to an [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160) structure returned by
	    [workbench.library/AddAppWindowA](../Includes_and_Autodocs_3._guide/node05BC.html). A value of NULL will be
	    ignored.
	dropZone -- pointer to an AppWindowDropZone returned by
	    [workbench.library/AddAppWindowDropZoneA](../Includes_and_Autodocs_3._guide/node05BD.html). A value of NULL will
	    be ignored.

   RESULTS
	success - TRUE if the drop zone could be removed, FALSE otherwise.
	    The reason for the failure can be obtained using
	    [dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html). This routine may fail if the specified drop
	    zone is not registered with the [AppWindow](../Includes_and_Autodocs_3._guide/node05D6.html#line160).

   NOTES
	Due to the asynchronous nature of Workbench/user interaction, you
	may receive [AppIcon](../Includes_and_Autodocs_3._guide/node05D6.html#line162) drop zone messages for zones that you have
	just removed. These messages may arrive in the time between your
	code calling RemoveAppWindowDropZone() and Workbench responding
	to the drop zone removal request. Be prepared to handle this. Once
	a drop zone is removed, it will generate no new AppMessages.

   SEE ALSO
	[workbench.library/AddAppWindowDropZoneA](../Includes_and_Autodocs_3._guide/node05BD.html)

