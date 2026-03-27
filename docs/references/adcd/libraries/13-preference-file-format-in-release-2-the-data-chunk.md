---
title: 13 / / Preference File Format in Release 2 / The Data Chunk
manual: libraries
chapter: libraries
section: 13-preference-file-format-in-release-2-the-data-chunk
functions: []
libraries: []
---

# 13 / / Preference File Format in Release 2 / The Data Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The data Chunk that follows the header Chunk depends on the kind of
Preferences data the file contains.  The types of Preferences data Chunks
that are currently part of the system are:




```c
    Table 13-2: [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) Chunk Types in Release 2 Preferences Data Files

    Chunk Name     Used With
    ----------     ---------
       [FONT](libraries/13-preferences-in-release-2-font.md)        Fonts, used for all font Preferences files.
                   In future the PrefHeader may indicate what the
                   font is used for.
       [ICTL](libraries/13-preferences-in-release-2-ictl.md)        IControl
       [INPT](libraries/13-preferences-in-release-2-inpt.md)        Input
       [OSCN](libraries/13-preferences-in-release-2-oscn.md)        Overscan
       [PGFX](libraries/13-preferences-in-release-2-pgfx.md)        PrinterGfx
       [PTXT](libraries/13-preferences-in-release-2-ptxt.md)        PrinterText
       [SCRM](libraries/13-preferences-in-release-2-scrm.md)        ScreenMode
       [SERL](libraries/13-preferences-in-release-2-serl.md)        Serial
```
Each chunk contains a structure applicable to the type.

