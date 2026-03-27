# datatypes.library/PrintDTObjectA



    NAME
	PrintDTObjectA - Call the DTM_PRINT method on a separate process.
```c
                                                               (V39)

    SYNOPSIS
```
	retval = PrintDTObjectA (object, window, requester, msg);
	d0			 a0	 a1	 a2	    a3

	ULONG PrintDTObjectA (Object *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *,
			      struct [dtPrint](../Includes_and_Autodocs_3._guide/node0606.html#line420) *);

	retval = PrintDTObject (object, window, requester, data, ...);

	ULONG PrintDTObject (Object *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *,
			     ULONG, ...);

    FUNCTION
	This function is used to asyncronously perform the object's DTM_PRINT
	method.

	Once the application has performed the PrintDTObjectA() function,
	it must not manipulate the printerIO union until it receives a
	IDCMP_IDCMPUPDATE message that contains the DTA_PrinterStatus
	tag.

	To abort a print, the application sends the DTM_ABORTPRINT method
	to the object.  This in turn signals the print process with a
	SIGBREAKF_CTRL_C.

    INPUTS
	object - Pointer to the DataTypes object.
	window - Pointer to the window that the object has been added to.
	requester - Pointer to the requester that the object has been
	    added to.

    RETURNS
	Returns TRUE if successful, FALSE on error.


    SEE ALSO
