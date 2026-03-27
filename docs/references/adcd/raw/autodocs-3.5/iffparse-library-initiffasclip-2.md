# iffparse.library/InitIFFasClip



   NAME
	InitIFFasClip -- initialize an [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) as a clipboard stream. (V36)

   SYNOPSIS
	InitIFFasClip(iff);
	              A0

	VOID InitIFFasClip(struct [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) *);

   FUNCTION
	Initializes the given [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) to be a clipboard stream. The
	function initializes the stream processing vectors to operate on
	streams of the [ClipboardHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line147) type. The iff_Stream field will still
	need to be initialized to point to a [ClipboardHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line147) as returned from
	[OpenClipboard()](../Includes_and_Autodocs_3._guide/node036F.html).

   INPUTS
	iff - pointer to [IFFHandle](../Includes_and_Autodocs_3._guide/node05E8.html#line43) structure.

   SEE ALSO
	[InitIFF()](../Includes_and_Autodocs_3._guide/node036B.html), [OpenClipboard()](../Includes_and_Autodocs_3._guide/node036F.html), [<libraries/iffparse.h>](../Includes_and_Autodocs_3._guide/node05E8.html)

