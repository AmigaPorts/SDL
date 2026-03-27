# printer.device/PRead



   NAME
	PRead - internal read from printer port

   SYNOPSIS
	error = (*PrinterData->pd_PRead)(buffer, length, tv);
	D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) PRead(UBYTE *, ULONG *, struct [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) *);

   FUNCTION
	PRead reads a buffer of data from the printer port. The variable
	length points to is set to the actual number of read bytes.

	tv points to a struct [timeval](../Includes_and_Autodocs_3._guide/node0607.html#line29) or is NULL in which case the default
	time is PrinterExtendedData.ped_TimeoutSecs. If the time of tv
	ellapes before the [CMD_READ](../Includes_and_Autodocs_3._guide/node057F.html) at the printer port is done two different
	things may happen: If at least one char is read PRead() returns. If
	no char is read but [PQuery](../Includes_and_Autodocs_3._guide/node0515.html) returns a value larger 0 the read is
	repeated with that length to read all outstanding data.

