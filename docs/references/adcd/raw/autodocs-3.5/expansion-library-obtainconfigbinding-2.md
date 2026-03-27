# expansion.library/ObtainConfigBinding



   NAME
	ObtainConfigBinding - try to get permission to bind drivers

   SYNOPSIS
	ObtainConfigBinding()


   FUNCTION
	ObtainConfigBinding gives permission to bind drivers to
	[ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structures.  It exists so two drivers at once
	do not try and own the same [ConfigDev](../Includes_and_Autodocs_3._guide/node05F1.html#line31) structure.  This
	call will block until it is safe proceed.

	It is crucially important that people lock out others
	before loading new drivers.  Much of the data that is used
	to configure things is statically kept, and others need
	to be kept from using it.

	This call is built directly on Exec [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) code
	(e.g. ObtainSemaphore).

   INPUTS

   RESULTS

   EXCEPTIONS

   SEE ALSO
	[ReleaseConfigBinding()](../Includes_and_Autodocs_3._guide/node026A.html)

   BUGS

