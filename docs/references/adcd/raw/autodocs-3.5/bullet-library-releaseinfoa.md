# bullet.library/ReleaseInfoA



    NAME
	ReleaseInfoA -- Release data obtained with [ObtainInfoA](../Includes_and_Autodocs_3._guide/node0087.html)
	ReleaseInfo -- varargs form of ReleaseInfoA

    SYNOPSIS
	error = ReleaseInfoA(engineHandle, tagList)
	                     A0            A1

	ULONG ReleaseInfoA(struct [GlyphEngine](../Includes_and_Autodocs_3._guide/node0613.html#line25) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	error = ReleaseInfo(engineHandle, firstTag, ...)

	ULONG ReleaseInfo(struct [GlyphEngine](../Includes_and_Autodocs_3._guide/node0613.html#line25) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

    FUNCTION
	This function releases the data obtained with [ObtainInfoA](../Includes_and_Autodocs_3._guide/node0087.html).
	Data associated with tags that are not indirect, i.e. for which
	OT_Indirect is not set, need not be released, but it is not an
	error to do so.  Released data may be immediately freed or may
	become a candidate to be expunged from memory when the system
	reaches a low memory condition, depending on the library's
	internal implementation.

	Each ReleaseInfoA tag item must be associated with a prior
	[ObtainInfoA](../Includes_and_Autodocs_3._guide/node0087.html).

    INPUTS
	engineHandle -- the handle acquired via [OpenEngine](../Includes_and_Autodocs_3._guide/node0088.html).
	tagList -- a tagList containing OT_ tags valid for inquiry
		paired with the data previously acquired for them with
		[ObtainInfoA](../Includes_and_Autodocs_3._guide/node0087.html).  Null pointers quietly accepted and
		ignored for indirect data.

    RESULT
	This function has no result.  The only error that can occur is
	when the Obtain and Release pairs are mismatched: the
	application is assumed not to do that.

    EXAMPLE
	    ULONG pointSize;
	    struct [GlyphMap](../Includes_and_Autodocs_3._guide/node0613.html#line33) *glyph;
	    ...
	    error = ObtainInfo(EngineHandle, OT_Glyph, &glyph, TAG_DONE);
	    ...
	    ReleaseInfo(EngineHandle, OT_Glyph, glyph, TAG_DONE);

    SEE ALSO
	ReleaseInfoA(), [diskfont/diskfonttag.h](../Includes_and_Autodocs_3._guide/node0655.html), [diskfont/oterrors.h](../Includes_and_Autodocs_3._guide/node0656.html)

