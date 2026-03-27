---
title: 13 / Preferences in Release 2 / Other File Formats in Release 2
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-other-file-formats-in-release-2
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / Other File Formats in Release 2

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Not every Preferences file is stored as an [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) file of type PREF.  The
[palette.ilbm](libraries/13-preferences-in-release-2-preferences-editors-and-storage.md) and [pointer.ilbm](libraries/13-preferences-in-release-2-preferences-editors-and-storage.md) files contain a regular ILBM FORM to store
their imagery.  The [win.pat](libraries/13-preferences-in-release-2-preferences-editors-and-storage.md) and [wb.pat](libraries/13-preferences-in-release-2-preferences-editors-and-storage.md) files use a raw format with 16
bytes reserved, followed by a WORD giving the total size of the pattern, a
WORD giving the bitplane count, and byte arrays (currently 32 bytes) for
each bitplane.  The format of the wbconfig.prefs file is private.

