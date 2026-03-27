---
title: Additional Info / Body Compression
manual: devices
chapter: devices
section: additional-info-body-compression
functions: []
libraries: []
---

# Additional Info / Body Compression

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The BODY contains pixel data for the image.  Width, Height, and depth
(Planes) is specified in the BMHD.

If the BMHD Compression byte is 0, then the scan line data is not
compressed. If Compression=1, then each scan line is individually
compressed as follows:

More than 2 bytes the same stored as BYTE code value n from  -1 to -127
  followed by byte to be repeated (-n) + 1 times.
Varied bytes stored as BYTE code n from 0 to 127 followed by n+1 bytes
of data.

The byte code -128 is a NOP.

