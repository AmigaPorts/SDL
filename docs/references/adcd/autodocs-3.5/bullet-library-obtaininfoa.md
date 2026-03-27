---
title: bullet.library/ObtainInfoA
manual: autodocs-3.5
chapter: autodocs-3.5
section: bullet-library-obtaininfoa
functions: []
libraries: []
---

# bullet.library/ObtainInfoA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ObtainInfoA -- Inquire tagged font and/or glyph metrics
	ObtainInfo -- varargs form of ObtainInfoA

    SYNOPSIS
	error = ObtainInfoA(engineHandle, tagList)
	                    A0            A1

	ULONG ObtainInfoA(struct [GlyphEngine](autodocs-3.5/include-diskfont-glyph-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	error = ObtainInfo(engineHandle, firstTag, ...)

	ULONG ObtainInfo(struct [GlyphEngine](autodocs-3.5/include-diskfont-glyph-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

    FUNCTION
	This function accepts a tagList whose tag field elements are
	valid for inquiry, and whose associated data fields are
	pointers to the destination in which to place the requested
	data.

	[Tag](autodocs-3.5/include-utility-tagitem-h.md) items that refer to data indirectly (OT_Indirect is set)
	return pointers that may be allocated or cached by the
	library.  This data must be treated as read-only data.  When
	the application is done with the data acquired via ObtainInfoA,
	it must perform a [ReleaseInfoA](autodocs-3.5/bullet-library-releaseinfoa.md) to allow the library to release
	the data.

    INPUTS
	engineHandle -- the handle acquired via [OpenEngine](autodocs-3.5/bullet-library-openengine.md).
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
	    struct [GlyphMap](autodocs-3.5/include-diskfont-glyph-h.md) *glyph;
	    ...
	    if (!ObtainInfo(EngineHandle, OT_Glyph, &glyph, TAG_DONE)) {
		...
		ReleaseInfo(EngineHandle, OT_Glyph, glyph, TAG_DONE);
	    }

    SEE ALSO
	[ReleaseInfoA()](autodocs-3.5/bullet-library-releaseinfoa.md), [diskfont/diskfonttag.h](autodocs-3.5/include-diskfont-diskfonttag-h.md), [diskfont/oterrors.h](autodocs-3.5/include-diskfont-oterrors-h.md)

