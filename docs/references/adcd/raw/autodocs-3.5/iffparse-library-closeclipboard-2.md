# iffparse.library/CloseClipboard



   NAME
	CloseClipboard -- close and free an open [ClipboardHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line147). (V36)

   SYNOPSIS
	CloseClipboard(clipHandle);
	               A0

	VOID CloseClipboard(struct [ClipboardHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line147) *);

   FUNCTION
	Closes the clipboard.device and frees the [ClipboardHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line147) structure.

   INPUTS
	clipHandle - pointer to [ClipboardHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line147) struct created with
	             [OpenClipboard()](../Includes_and_Autodocs_3._guide/node036F.html). Starting with V39, this may be NULL.

   SEE ALSO
	[OpenClipboard()](../Includes_and_Autodocs_3._guide/node036F.html), [InitIFFasClip()](../Includes_and_Autodocs_3._guide/node036C.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

