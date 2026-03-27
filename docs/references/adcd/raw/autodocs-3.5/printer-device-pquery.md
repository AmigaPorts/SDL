# printer.device/PQuery



   NAME
	PQuery - read number of chars in input buffer

   SYNOPSIS
	error = (*PrinterData->pd_PQuery)(*length);
	D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) PRead(LONG *);

   FUNCTION
   	PQuery reads the number of data in the input buffer which can be
   	read from the printer port. The variable length points to is set
   	to the number of readable chars.

