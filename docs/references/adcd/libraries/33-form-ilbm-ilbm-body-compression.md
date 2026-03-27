---
title: 33 / / FORM ILBM / ILBM BODY Compression
manual: libraries
chapter: libraries
section: 33-form-ilbm-ilbm-body-compression
functions: []
libraries: []
---

# 33 / / FORM ILBM / ILBM BODY Compression

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The BODY contains pixel data for the image.  Width, Height, and depth
(Planes) is specified in the [BMHD](libraries/33-form-ilbm-interpreting-ilbms.md).

If the [BMHD](libraries/33-form-ilbm-interpreting-ilbms.md) Compression byte is 0, then the scan line data is not
compressed. If Compression=1, then each scan line is individually
compressed as follows:


```c
    while (not produced the desired number of bytes)

            /* get a byte, call it N */

            if (N >= 0 && N <= 127)
                    /* copy the next N+1 bytes literally */

            if (N >= -127 && N <= -1)
                    /* repeat the next byte N+1 times */

            if (N == -128)
                    /* skip it, presumably it's padding */
```
