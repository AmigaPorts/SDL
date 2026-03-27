---
title: bullet.library/SetInfoA
manual: autodocs-3.5
chapter: autodocs-3.5
section: bullet-library-setinfoa
functions: []
libraries: []
---

# bullet.library/SetInfoA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetInfoA -- Set font and/or glyph metrics
	SetInfo -- varargs form of SetInfoA

    SYNOPSIS
	error = SetInfoA(engineHandle, tagList)
	                 A0            A1

	ULONG SetInfoA(struct [GlyphEngine](autodocs-3.5/include-diskfont-glyph-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	error = SetInfo(engineHandle, firstTag, ...)

	ULONG SetInfo(struct [GlyphEngine](autodocs-3.5/include-diskfont-glyph-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

    FUNCTION
	This function accepts a tagList whose tag field elements are
	valid for specification, and whose associated data fields are
	used to supply the specified data.

	Data that is supplied via an indirect pointer (OT_Indirect) to
	an array or structure is copied from that array or structure
	into the internal memory of the library.  Changes to the data
	after this call do not affect the engine.

    INPUTS
	engineHandle -- the handle acquired via [OpenEngine](autodocs-3.5/bullet-library-openengine.md).
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
	[diskfont/diskfonttag.h](autodocs-3.5/include-diskfont-diskfonttag-h.md), [diskfont/oterrors.h](autodocs-3.5/include-diskfont-oterrors-h.md),

