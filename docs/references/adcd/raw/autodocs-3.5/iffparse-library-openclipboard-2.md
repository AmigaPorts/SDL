# iffparse.library/OpenClipboard



   NAME
	OpenClipboard -- create a handle on a clipboard unit. (V36)

   SYNOPSIS
	ch = OpenClipboard(unitNumber)
	D0                 D0

	struct [ClipboardHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line147) *OpenClipboard(LONG);

   FUNCTION
	Opens the clipboard.device and opens a stream for the specified unit
	(usually PRIMARY_CLIP). This handle structure will be used as the
	clipboard stream for IFFHandles initialized as clipboard streams by
	[InitIFFasClip()](../Includes_and_Autodocs_3._guide/node036C.html).

   INPUTS
	unitNumber - clipboard unit number (usually PRIMARY_CLIP).

   RESULT
	ch - pointer to [ClipboardHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line147) structure or NULL if unsuccessful.

   BUGS
	This function had several bugs prior to V39.

       First bug was that if the clipboard.device couldn't open, two calls
	to [FreeSignal()](../Includes_and_Autodocs_3._guide/node0210.html) were made with uninitialized values as parameters.
	The result of this was a corrupt signal mask in the [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) field.

	Second bug was that [OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html) was called with an IO request that
	didn't have a valid [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) pointer in it.

	Third bug was that the two message ports allocated by the function
	(ClipboardHandle->cbh_CBport and ClipboardHandle->cbh_SatisfyPort)
	were not being initialized correctly and would cause a system crash
	if a message ever got to either of them.

   SEE ALSO
	[InitIFFasClip()](../Includes_and_Autodocs_3._guide/node036C.html), [CloseClipboard()](../Includes_and_Autodocs_3._guide/node035B.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

