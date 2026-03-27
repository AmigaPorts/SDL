---
title: 33 IFFParse Library / IFF FORM Specifications
manual: libraries
chapter: libraries
section: 33-iffparse-library-iff-form-specifications
functions: []
libraries: []
---

# 33 IFFParse Library / IFF FORM Specifications

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The specifications for Amiga [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) formats are maintained by Commodore
Applications and Technical Support ([CATS](libraries/1-introduction-commodore-applications-and-technical-support.md)) and updated periodically.  The
latest specifications are published in the Amiga ROM Kernel Reference
Manual: [Devices](devices/appendix-a-iff-interchange-file-format.md) (3rd edition) and also available in electronic form
directly from CATS.  Between updates of the IFF Manual, selected new FORMs
and changes to existing FORMs are documented in Amiga Mail a technical
newsletter for Amiga developers published by Commodore's CATS group.

Some of the most commonly used IFF FORMs are the four that were originally
specified in the EA IFF-85 standard:



```c
             ___________________________________
            |                                   |
            |  [ILBM](libraries/33-iff-form-specifications-form-ilbm.md)  Bitmap images and palettes |
            |  [FTXT](libraries/33-iff-form-specifications-form-ftxt.md)  Simple formatted text      |
            |  SMUS  Simple musical scores      |
            |  8SVX  8-bit sound samples        |
            |___________________________________|
```
Of these four, ILBM is the most commonly encountered FORM, and FTXT is
becoming increasingly important since the Release 2 conclip command passes
clipped console text through the clipboard as FTXT.  All data clipped to
the clipboard must be in an [IFF](libraries/33-iffparse-library-the-structure-of-iff-files.md) format.

This section will provide a brief summary of the ILBM and FTXT FORMs and
their most used common chunks.  Please consult the EA-IFF specifications
for additional information.

 [FORM ILBM](libraries/33-iff-form-specifications-form-ilbm.md)    [FORM FTXT](libraries/33-iff-form-specifications-form-ftxt.md) 

