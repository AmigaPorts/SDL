# graphics.library/ExtendFont



   NAME
	ExtendFont -- ensure tf_Extension has been built for a font (V36)

   SYNOPSIS
	success = ExtendFont(font, fontTags)
	D0                   A0    A1

	ULONG ExtendFont(struct [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	success = ExtendFontTags(font, Tag1, ...)  (V39)

	ULONG ExtendFontTags(struct [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) *, ULONG, ...);

   FUNCTION
	To extend a [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) structure.

   INPUTS
	font - The font to extend.
	fontTags - An optional taglist.  If NULL, then a default is used.
	           Currently, the only tag defined is TA_DeviceDPI.

   RESULT
	success - 1 if the [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) was properly extended, else 0.

   NOTES
	The varargs stub was missing from amiga.lib until V39.

   SEE ALSO
	[graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)

