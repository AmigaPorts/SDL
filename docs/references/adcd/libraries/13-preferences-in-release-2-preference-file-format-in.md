---
title: 13 / Preferences in Release 2 / Preference File Format in Release 2
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-preference-file-format-in
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / Preference File Format in Release 2

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To understand the format of Preferences files, you must be familiar with
[IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) file standard (see the Amiga ROM Kernel Reference Manual: [Devices](devices/appendix-a-iff-interchange-file-format.md) for
the complete specification).

In general all Preferences files are stored in the [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) format with a type
of PREF (see the [exceptions](libraries/13-preferences-in-release-2-other-file-formats-in-release-2.md) noted below).  Each file contains at least two
Chunks, a header Chunk and a data Chunk.

 [The Header Chunk](libraries/13-preference-file-format-in-release-2-the-header-chunk.md)    [The Data Chunk](libraries/13-preference-file-format-in-release-2-the-data-chunk.md) 

