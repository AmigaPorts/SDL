# expansion.library/ReleaseConfigBinding



   NAME
	ReleaseConfigBinding - allow others to bind to drivers

   SYNOPSIS
	ReleaseConfigBinding()


   FUNCTION
	This call should be used when you are done binding drivers
	to [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) entries.  It releases the SignalSemaphore; this
	allows others to bind their drivers to [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structures.

   SEE ALSO
	[ObtainConfigBinding()](../Includes_and_Autodocs_3._guide/node0267.html)

