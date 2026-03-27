# printer.device/PWrite



   NAME
	PWrite -- internal write to printer port

   SYNOPSIS
	error = (*PrinterData->pd_PWrite)(buffer, length);
	D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) PWrite(UBYTE *, ULONG);

   FUNCTION
	PWrite writes 'length' bytes directly to the printer.  This
	function is generally called by printer drivers to send
	their buffer(s) to the printer.

	This function is accessed by referencing off the [PrinterData](../Includes_and_Autodocs_3._guide/node05FC.html#line103) (PD)
	structure.  Below is a code fragment to show how to do get access
	to a pointer to the [PrinterData](../Includes_and_Autodocs_3._guide/node05FC.html#line103) (PD) structure.

	#include [<exec/types.h>](../Includes_and_Autodocs_3._guide/node0654.html)
	#include [<devices/printer.h>](../Includes_and_Autodocs_3._guide/node0605.html)
	#include [<devices/prtbase.h>](../Includes_and_Autodocs_3._guide/node05FC.html)

	struct [IODRPReq](../Includes_and_Autodocs_3._guide/node0605.html#line173) PReq;
	struct [PrinterData](../Includes_and_Autodocs_3._guide/node05FC.html#line103) *PD;
	struct [PrinterExtendedData](../Includes_and_Autodocs_3._guide/node05FC.html#line275) *PED;

	/* open the printer device (any version); if it opened... */
	if (OpenDevice("printer.device", 0, &PReq, 0) == NULL) {

	    /* get pointer to printer data structure */
	    PD = (struct [PrinterData](../Includes_and_Autodocs_3._guide/node05FC.html#line103) *)PReq.io_Device;

	    /* write something directly to the printer */
	    (*PD->pd_PWrite)("Hello worldn", 12);

	    CloseDevice(&PReq); /* close the printer device */
	}

