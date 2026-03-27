# card.resource/DeviceTuple



   NAME
	DeviceTuple -- Decode a device tuple

   SYNOPSIS
	return=DeviceTuple( tuple_data, storage)
		   	    a0		a1

	ULONG DeviceTuple( [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, struct [DeviceTData](../Includes_and_Autodocs_3._guide/node05E2.html#line37) *);

   FUNCTION
	Extracts SIZE, TYPE, and SPEED from a device tuple (generally
	obtained with [CopyTuple()](../Includes_and_Autodocs_3._guide/node0098.html)).

   INPUTS
	tuple_data - Pointer to a CISTPL_DEVICE tuple (generally obtained
	with [CopyTuple()](../Includes_and_Autodocs_3._guide/node0098.html)).

	storage - Pointer to a [DeviceTData](../Includes_and_Autodocs_3._guide/node05E2.html#line37) structure in which results
	are to be stored.

	struct	[DeviceTData](../Includes_and_Autodocs_3._guide/node05E2.html#line37) {
		ULONG	dtd_DTsize;		/* Size of card (bytes)	*/
		ULONG	dtd_DTspeed;		/* Speed in nanoseconds	*/
		[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)	dtd_DTtype;		/* Type of card		*/
		[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50)	dtd_DTflags;		/* Other flags		*/
	};


   RETURN
	SIZE (same as dtd_DTsize) if the [Device](../Includes_and_Autodocs_3._guide/node05FB.html#line23) Tuple could be decoded.
	FALSE (0) if the tuple is believed to be invalid.  The tuple is
	considered to be invalid if:

		The tuple link value is 0.

		The device type/speed byte is $00, or $FF.

		The device type is DTYPE_EXTEND, which is undefined
		as of this writing.

		The extended speed byte is a value which is
		undefined as of this writing.

		The extended speed byte is extended again which is
		undefined as of this writing.

		The device Size byte is $FF.

   NOTES
	Some cards may not have a size specified in the device
	tuple.  An example would be an I/O card.  The size would be
	returned as one (1) in this case.

	You should not call this function with a partial CISTPL_DEVICE
	tuple, or the return values may be junk.

   SEE ALSO
	[CopyTuple()](../Includes_and_Autodocs_3._guide/node0098.html), [resources/card.h](../Includes_and_Autodocs_3._guide/node05E2.html), resources/card.i

