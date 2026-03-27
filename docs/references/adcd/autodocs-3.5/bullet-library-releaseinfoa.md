---
title: bullet.library/ReleaseInfoA
manual: autodocs-3.5
chapter: autodocs-3.5
section: bullet-library-releaseinfoa
functions: []
libraries: []
---

# bullet.library/ReleaseInfoA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ReleaseInfoA -- Release data obtained with [ObtainInfoA](autodocs-3.5/bullet-library-obtaininfoa.md)
	ReleaseInfo -- varargs form of ReleaseInfoA

    SYNOPSIS
	error = ReleaseInfoA(engineHandle, tagList)
	                     A0            A1

	ULONG ReleaseInfoA(struct [GlyphEngine](autodocs-3.5/include-diskfont-glyph-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	error = ReleaseInfo(engineHandle, firstTag, ...)

	ULONG ReleaseInfo(struct [GlyphEngine](autodocs-3.5/include-diskfont-glyph-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

    FUNCTION
	This function releases the data obtained with [ObtainInfoA](autodocs-3.5/bullet-library-obtaininfoa.md).
	Data associated with tags that are not indirect, i.e. for which
	OT_Indirect is not set, need not be released, but it is not an
	error to do so.  Released data may be immediately freed or may
	become a candidate to be expunged from memory when the system
	reaches a low memory condition, depending on the library's
	internal implementation.

	Each ReleaseInfoA tag item must be associated with a prior
	[ObtainInfoA](autodocs-3.5/bullet-library-obtaininfoa.md).

    INPUTS
	engineHandle -- the handle acquired via [OpenEngine](autodocs-3.5/bullet-library-openengine.md).
	tagList -- a tagList containing OT_ tags valid for inquiry
		paired with the data previously acquired for them with
		[ObtainInfoA](autodocs-3.5/bullet-library-obtaininfoa.md).  Null pointers quietly accepted and
		ignored for indirect data.

    RESULT
	This function has no result.  The only error that can occur is
	when the Obtain and Release pairs are mismatched: the
	application is assumed not to do that.

    EXAMPLE
	    ULONG pointSize;
	    struct [GlyphMap](autodocs-3.5/include-diskfont-glyph-h.md) *glyph;
	    ...
	    error = ObtainInfo(EngineHandle, OT_Glyph, &glyph, TAG_DONE);
	    ...
	    ReleaseInfo(EngineHandle, OT_Glyph, glyph, TAG_DONE);

    SEE ALSO
	ReleaseInfoA(), [diskfont/diskfonttag.h](autodocs-3.5/include-diskfont-diskfonttag-h.md), [diskfont/oterrors.h](autodocs-3.5/include-diskfont-oterrors-h.md)

