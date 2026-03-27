# amiga.lib/CxDebug



   NAME
	CxDebug -- create a commodity debug object. (V36)

   SYNOPSIS
	debugObj = CxDebug(id);

	[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *CxDebug(LONG);

   FUNCTION
	This function creates a Commodities debug object. The action of this
	object on receiving a Commodities message is to print out information
	about the Commodities message through the serial port (using the
	kprintf() routine). The value of 'id' will also be displayed.

	Note that this is a synchronous occurrence (the printing is done by
	the input device task). If screen or file output is desired, using a
	sender object instead of a debug object is necessary, since such
	output is best done by your application process.

	This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), defined
	in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html).

   INPUTS
	id - the id to assign to the debug object, this value is output
	     whenever the debug object sends data to the serial port.

   RESULTS
	debugObj - a pointer to the debug object, or NULL if it could
		   not be created.

   SEE ALSO
	[commodities.library/CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), [CxSender()](../Includes_and_Autodocs_3._guide/node0030.html), debug.lib/kprintf()

