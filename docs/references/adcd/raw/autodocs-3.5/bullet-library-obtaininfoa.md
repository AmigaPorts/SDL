# bullet.library/ObtainInfoA



    NAME
	ObtainInfoA -- Inquire tagged font and/or glyph metrics
	ObtainInfo -- varargs form of ObtainInfoA

    SYNOPSIS
	error = ObtainInfoA(engineHandle, tagList)
	                    A0            A1

	ULONG ObtainInfoA(struct [GlyphEngine](../Includes_and_Autodocs_3._guide/node0613.html#line25) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	error = ObtainInfo(engineHandle, firstTag, ...)

	ULONG ObtainInfo(struct [GlyphEngine](../Includes_and_Autodocs_3._guide/node0613.html#line25) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

    FUNCTION
	This function accepts a tagList whose tag field elements are
	valid for inquiry, and whose associated data fields are
	pointers to the destination in which to place the requested
	data.

	[Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) items that refer to data indirectly (OT_Indirect is set)
	return pointers that may be allocated or cached by the
	library.  This data must be treated as read-only data.  When
	the application is done with the data acquired via ObtainInfoA,
	it must perform a [ReleaseInfoA](../Includes_and_Autodocs_3._guide/node0089.html) to allow the library to release
	the data.

    INPUTS
	engineHandle -- the handle acquired via [OpenEngine](../Includes_and_Autodocs_3._guide/node0088.html).
	tagList -- a tagList containing OT_ tags valid for inquiry
		paired with the destination pointers for the inquiry
		results.  All destinations are longwords, whether they
		are pointers or values, and regardless of whether the
		value could fit in a smaller variable.

    RESULT
	This function returns a zero success indication, or a non-zero
	error code.

    EXAMPLE
	    ULONG pointSize;
	    struct [GlyphMap](../Includes_and_Autodocs_3._guide/node0613.html#line33) *glyph;
	    ...
	    if (!ObtainInfo(EngineHandle, OT_Glyph, &glyph, TAG_DONE)) {
		...
		ReleaseInfo(EngineHandle, OT_Glyph, glyph, TAG_DONE);
	    }

    SEE ALSO
	[ReleaseInfoA()](../Includes_and_Autodocs_3._guide/node0089.html), [diskfont/diskfonttag.h](../Includes_and_Autodocs_3._guide/node0655.html), [diskfont/oterrors.h](../Includes_and_Autodocs_3._guide/node0656.html)

