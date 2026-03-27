---
title: Step 3
manual: amiga-mail
chapter: amiga-mail
section: step-3
functions: [OpenLibrary]
libraries: [exec.library]
---

# Step 3

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One of the level 1 outline tags is the OT_Engine tag.  This tag
refers to the name of this typeface's scaling engine.  At present
there is only one scaling engine available on the Amiga.  It is named
Bullet.  This is the IntelliFont scaling engine.  The name is left
over from the original implementation of the IntelliFont engine used
on the Amiga.  The scaling engine itself is in its own Exec library,
called bullet.library.  To open the engine, build a complete library
name by adding the string ".library" to the OT_Engine string, and
open it with OpenLibrary().  Don't assume that OT_Engine will always
be the string ``bullet''.  In the future, Commodore or some third
party developer may create additional scaling engines libraries that
will allow the Amiga to use other types of outline typefaces
(PostScript, Nimbus-Q, etc.).  Using the proper library name will
help ensure compatibility with future possible scaling engines.

All scaling engine libraries contain several functions:

OpenEngine()                  If successful, returns a pointer to
                               the library's GlyphEngine structure.
CloseEngine()                 Releases the GlyphEngine structure
```c
                               obtained in OpenEngine().
```
SetInfo()/SetInfoA()          Sets current parameters of a scaling
```c
                               engine (the current typeface, the
                               current point size, the current output
                               resolution, etc.)
```
ObtainInfo()/ObtainInfoA()    Queries a scaling engine for glyph
```c
                               information (a glyph's bitmap, the
                               kerning value between two glyphs, etc.).
```
ReleaseInfo()/ReleaseInfoA()  Releases data obtained with

```c
                               ObtainInfo()/ObtainInfoA().
```
To obtain a pointer to a GlyphEngine structure for a particular
scaling library, use that library's OpenEngine() routine.  The
function takes no arguments.

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
