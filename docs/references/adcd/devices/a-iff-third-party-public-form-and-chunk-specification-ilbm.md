---
title: A / IFF Third Party Public Form and Chunk Specification / ILBM.DPI.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-ilbm
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / ILBM.DPI.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Dots per inch chunk

ILBM DPI chunk
--------------

Registered by:

Spencer Shanson
16 Genesta Rd
Plumstead
London SE18 3ES
ENGLAND

1-16-90

ILBM.DPI   Dots Per Inch   to allow output of an image at the
same resolution it was scanned at

typedef struct {
	UWORD dpi_x;
	UWORD dpi_y;
	} DPIHeader ;

For example, an image scanned at horizontal resolution of
240dpi and vertical resolution of 300dpi would be saved as:

44504920 00000004 00F0 012C
D P I    size     dpi_x dpi_y

