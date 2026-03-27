---
title: bullet.library/OpenEngine
manual: autodocs-3.5
chapter: autodocs-3.5
section: bullet-library-openengine
functions: []
libraries: []
---

# bullet.library/OpenEngine

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	OpenEngine -- Acquire engine handle

    SYNOPSIS
	engineHandle = OpenEngine()

	struct [GlyphEngine](autodocs-3.5/include-diskfont-glyph-h.md) *OpenEngine(void)

    FUNCTION
	This function establishes a context for access to the bullet
	library.  This context remains valid until it is closed via
	[CloseEngine](autodocs-3.5/bullet-library-closeengine.md).  Each specific context isolates the specification
	of the various font attributes from other contexts concurrently
	accessing the bullet library.  A context can be shared among
	different tasks.

    RESULT
	This function returns an engineHandle, or NULL if for some
	reason no engineHandle can be created.

    EXAMPLE
	    BulletBase = OpenLibrary("bullet.library", 0);
	    if (!BulletBase)
		EndGame(ERROR_LibOpen, "bullet.library", 0);
	    EngineHandle = OpenEngine();
	    if (!EngineHandle)
		EndGame(ERROR_InternalCall, "OpenEngine");

    SEE ALSO
	[CloseEngine()](autodocs-3.5/bullet-library-closeengine.md)

