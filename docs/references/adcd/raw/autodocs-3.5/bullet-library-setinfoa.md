# bullet.library/SetInfoA



    NAME
	SetInfoA -- Set font and/or glyph metrics
	SetInfo -- varargs form of SetInfoA

    SYNOPSIS
	error = SetInfoA(engineHandle, tagList)
	                 A0            A1

	ULONG SetInfoA(struct [GlyphEngine](../Includes_and_Autodocs_3._guide/node0613.html#line25) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	error = SetInfo(engineHandle, firstTag, ...)

	ULONG SetInfo(struct [GlyphEngine](../Includes_and_Autodocs_3._guide/node0613.html#line25) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

    FUNCTION
	This function accepts a tagList whose tag field elements are
	valid for specification, and whose associated data fields are
	used to supply the specified data.

	Data that is supplied via an indirect pointer (OT_Indirect) to
	an array or structure is copied from that array or structure
	into the internal memory of the library.  Changes to the data
	after this call do not affect the engine.

    INPUTS
	engineHandle -- the handle acquired via [OpenEngine](../Includes_and_Autodocs_3._guide/node0088.html).
	tagList -- a tagList containing OT_ tags valid for
		specification paired with the specification data.

    RESULT
	This function returns a zero success indication, or a non-zero
	error code.

    EXAMPLE
	    if (!(error = SetInfo(EngineHandle, OT_PointHeight, fpoints,
		    OT_GlyphCode, GC_daggerdbl, TAG_DONE)) {
		error = ObtainInfo(EngineHandle, OT_Glyph, &glyph);
		...
		ReleaseInfo(EngineHandle, OT_Glyph, glyph);
	    }

    SEE ALSO
	[diskfont/diskfonttag.h](../Includes_and_Autodocs_3._guide/node0655.html), [diskfont/oterrors.h](../Includes_and_Autodocs_3._guide/node0656.html),

