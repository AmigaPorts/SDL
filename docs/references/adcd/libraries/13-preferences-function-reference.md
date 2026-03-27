---
title: 13 Preferences / Function Reference
manual: libraries
chapter: libraries
section: 13-preferences-function-reference
functions: [AllocIFF, CloseIFF, CurrentChunk, EndNotify, FindProp, FreeIFF, GetDefPrefs, GetPrefs, InitIFFasDOS, OpenIFF, ParseIFF, PropChunk, SetPrefs, StartNotify]
libraries: [dos.library, iffparse.library, intuition.library]
---

# 13 Preferences / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the system functions that relate
to the use of Preferences.  See the Amiga ROM Kernel Reference Manual:
Includes and Autodocs for details on each function call.


               Table 13-3: Functions Used with Preferences
  _______________________________________________________________________
 |                                                                       |
 |      Function                Description                              |
 |=======================================================================|
 |      [GetPrefs()](autodocs-2.0/intuition-library-getprefs.md)  Old 1.3 (V34) function for making a copy of the      |
 |                  Preferences structure                                |
 |      [SetPrefs()](autodocs-2.0/intuition-library-setprefs.md)  Old 1.3 (V34) function for overwriting Preferences   |
 |                  with new data                                        |
 |   [GetDefPrefs()](autodocs-2.0/intuition-library-getdefprefs.md)  Old 1.3 (V34) function for copying default           |
 |                  Preferences from ROM                                 |
 |-----------------------------------------------------------------------|
 |   [StartNotify()](autodocs-2.0/dos-library-startnotify.md)  Release 2 DOS library function for monitoring a      |
 |                  .prefs file for changes                              |
 |     [EndNotify()](autodocs-2.0/dos-library-endnotify.md)  Ends notification started with StartNotify()         |
 |-----------------------------------------------------------------------|
 |      [AllocIFF()](autodocs-2.0/iffparse-library-allociff.md)  IFFParse library function that creates an IFFHandle  |
 |                  for parsing                                          |
 |  [InitIFFasDOS()](autodocs-2.0/iffparse-library-initiffasdos.md)  Initialize the IFFHandle as a DOS stream             |
 |       OpenIFF()  Initialize an IFFHandle for reading or writing a new |
 |                  stream                                               |
 |     [PropChunk()](autodocs-2.0/iffparse-library-propchunk.md)  Specify a property chunk to store                    |
 |      [ParseIFF()](autodocs-2.0/iffparse-library-parseiff.md)  Parse an [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) file from the IFFHandle stream          |
 |  [CurrentChunk()](autodocs-2.0/iffparse-library-currentchunk.md)  Returns the top level context of an IFF stream       |
 |      [FindProp()](autodocs-2.0/iffparse-library-findprop.md)  Search for a property chunk previously declared with |
 |                  PropChunk()                                          |
 |      [CloseIFF()](autodocs-2.0/iffparse-library-closeiff.md)  Closes an IFF context opened with OpenIFF()          |
 |       [FreeIFF()](autodocs-2.0/iffparse-library-freeiff.md)  Frees the IFFHandle created with AllocIFF()          |
 |_______________________________________________________________________|

---

## See Also

- [AllocIFF — iffparse.library](../autodocs/iffparse.library.md#allociff)
- [CloseIFF — iffparse.library](../autodocs/iffparse.library.md#closeiff)
- [CurrentChunk — iffparse.library](../autodocs/iffparse.library.md#currentchunk)
- [EndNotify — dos.library](../autodocs/dos.library.md#endnotify)
- [FindProp — iffparse.library](../autodocs/iffparse.library.md#findprop)
- [FreeIFF — iffparse.library](../autodocs/iffparse.library.md#freeiff)
- [GetDefPrefs — intuition.library](../autodocs/intuition.library.md#getdefprefs)
- [GetPrefs — intuition.library](../autodocs/intuition.library.md#getprefs)
- [InitIFFasDOS — iffparse.library](../autodocs/iffparse.library.md#initiffasdos)
- [OpenIFF — iffparse.library](../autodocs/iffparse.library.md#openiff)
- [ParseIFF — iffparse.library](../autodocs/iffparse.library.md#parseiff)
- [PropChunk — iffparse.library](../autodocs/iffparse.library.md#propchunk)
- [SetPrefs — intuition.library](../autodocs/intuition.library.md#setprefs)
- [StartNotify — dos.library](../autodocs/dos.library.md#startnotify)
