---
title: DR2D.doc / KERN
manual: devices
chapter: devices
section: dr2d-doc-kern
functions: []
libraries: []
---

# DR2D.doc / KERN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

KERN	(0x4B45524C)   	/* Kerning pair */

The KERN chunk describes a kerning pair.  A kerning pair sets the
distance between a specific pair of characters.


```c
    struct KERNstruct {
        short   Ch1, Ch2;   /* The pair to kern (allows for 16 bits...) */
        IEEE    XDisplace,  /* Amount to displace -left +right */
                YDisplace;  /* Amount to displace -down +up */
    };
```
The Ch1 and Ch2 fields contain the pair of characters to kern.  These
characters are typically stored as ASCII codes.  Notice that OFNT stores
the characters as a 16-bit value.  Normally, characters are stored as
8-bit values.  The wary programmer will be sure to cast assigns properly
to avoid problems with assigning an 8-bit value to a 16-bit variable.  The
remaining fields, XDisplace and YDisplace, supply the baseline shift from
Ch1 to Ch2.

