---
title: bullet.library/CloseEngine
manual: autodocs-3.5
chapter: autodocs-3.5
section: bullet-library-closeengine
functions: []
libraries: []
---

# bullet.library/CloseEngine

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CloseEngine -- Release an engine handle

    SYNOPSIS
	CloseEngine(engineHandle)
	            A0

	void CloseEngine(struct [GlyphEngine](autodocs-3.5/include-diskfont-glyph-h.md) *);

    FUNCTION
	This function releases the engine handle acquired with
	[OpenEngine](autodocs-3.5/bullet-library-openengine.md).  It first releases any data acquired with
	[ObtainInfoA](autodocs-3.5/bullet-library-obtaininfoa.md) associated with the engineHandle that has not yet
	been released.

    INPUTS
	engineHandle -- the handle acquired via [OpenEngine](autodocs-3.5/bullet-library-openengine.md).  If zero,
		no operation is performed.

    RESULT
	This function has no result.  The only error that can occur is
	when the when an invalid engineHandle is supplied: the
	application is assumed not to do that.

    EXAMPLE
	EndGame(code, arg1, arg2, arg3, arg3)
	{
	    ...
	    CloseEngine(EngineHandle);
	    ...
	}

    SEE ALSO
	[OpenEngine()](autodocs-3.5/bullet-library-openengine.md)

