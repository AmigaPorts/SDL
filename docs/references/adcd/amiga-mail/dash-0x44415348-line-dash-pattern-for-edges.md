---
title: DASH (0x44415348)       / Line dash pattern for edges /
manual: amiga-mail
chapter: amiga-mail
section: dash-0x44415348-line-dash-pattern-for-edges
functions: []
libraries: []
---

# DASH (0x44415348)       / Line dash pattern for edges /

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chunk describes the on-off dash pattern associated with a line.


```c
    struct DASHstruct {
        ULONG       ID;
        ULONG       Size;
        USHORT      DashID;                 /* ID of the dash pattern */
        USHORT      NumDashes;              /* Should always be even */
        IEEE        Dashes[NumDashes];      /* On-off pattern */
    };
```
DashID is the number assigned to this specific dash pattern.
References to this dash pattern by other DR2D chunks are made using
this number.

The Dashes[] array contains the actual dash pattern.  The first number
in the array (element 0) is the length of the "on" portion of the
pattern.  The second number (element 1) specifies the "off" portion
of the pattern.  If there are more entries in the Dashes array, the
pattern will continue.  Even-index elements specify the length of an
"on" span, while odd-index elements specify the length of an "off"
span.  There must be an even number of entries.  These lengths are not
in the same units as specified in the PPRF chunk, but are multiples of
the line width, so a line of width 2.5 and a dash pattern of 1.0, 2.0
would have an "on" span of length 1.0 x 2.5 = 2.5 followed by an
"off" span of length 2.0 x 2.5 = 5.  The following figure shows
several dash pattern examples.  Notice that for lines longer than the
dash pattern, the pattern repeats.

   [figure 1 - dash patterns](amiga-mail/vii-1-dr2d-1-pic.md) 

By convention, DashID 0 is reserved to mean `No line pattern at all',
i.e. the edges are invisible.  This DASH pattern should not be defined
by a DR2D DASH chunk.  Again by convention, a NumDashes of 0 means
that the line is solid.

