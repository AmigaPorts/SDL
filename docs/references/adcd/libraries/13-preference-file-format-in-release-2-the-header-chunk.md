---
title: 13 / / Preference File Format in Release 2 / The Header Chunk
manual: libraries
chapter: libraries
section: 13-preference-file-format-in-release-2-the-header-chunk
functions: []
libraries: []
---

# 13 / / Preference File Format in Release 2 / The Header Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The PRHD header chunk, contains a PrefHeader structure:


```c
    struct PrefHeader
    {
        UBYTE ph_Version;
        UBYTE ph_Type;
        ULONG ph_Flags;
    };
```
Currently all the fields are set to NULL.  In future revisions these
fields may be used to indicate a particular version and contents of a PREF
chunk.

