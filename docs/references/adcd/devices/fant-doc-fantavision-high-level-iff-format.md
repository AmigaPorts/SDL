---
title: FANT.doc / Fantavision high-level IFF format
manual: devices
chapter: devices
section: fant-doc-fantavision-high-level-iff-format
functions: []
libraries: []
---

# FANT.doc / Fantavision high-level IFF format

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
FORM FANT
    FHDR

    - background -
    FORM ILBM   if Background is non-zero
        BMHD
        BODY

    - bitmap list -
    NOTE:  If a bitmap has a mask, it will be compute during load time.

    FORM ILBM   times NumberOfBitMaps
        BMHD
        BODY

    - sound list -
{   FORM 8SVX   times NumberOfSounds
```c
        VHDR
        BODY
    SEFX    }   Default parameters for sound

    - frame list -
```
{   FRAM        times NumberOfFrames
    SEFX        if sound for channel 1.
    SEFX        if sound for channel 2.
    POLY        times NumberOfPolys
  { CSTR        Text of poly if PolyType = pTEXTBLOCK
```c
    CSTR  } }   Name of font
```
*/

