---
title: IV-69/hide.h
manual: amiga-mail
chapter: amiga-mail
section: iv-69-hide-h
functions: []
libraries: []
---

# IV-69/hide.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Hide.h

Copyright (c) 1991-1999 Amiga, Inc.

This example is provided in electronic form by Amiga, Inc.
for use with the Amiga Mail Volume II technical publication.
Amiga Mail Volume II contains additional information on the correct
usage of the techniques and operating system functions presented in
these examples.  The source and executable code of these examples may
only be distributed in free electronic form, via bulletin board or
as part of a fully non-commercial and freely redistributable
diskette.  Both the source and executable code (including comments)
must be included, without modification, in any copy.  This example
may not be published in printed form or distributed with any
commercial product. However, the programming techniques and support
routines set forth in these examples may be used in the development
of original executable software products for Amiga
computers.

All other rights reserved.

This example is provided "as-is" and is subject to change; no
warranties are made.  All use is at your own risk. No liability or
responsibility is assumed.
*/


UWORD chip      ImageI1Data[] =
{
/* Plane 0 */
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8208, 0x0000, 0x0000,
    0x8208, 0x7FFF, 0xFFFF, 0xFEF8, 0x4000, 0x0000, 0x00A8, 0x4000,
    0x0000, 0x0048, 0x4000, 0x0000, 0x00A8, 0x4000, 0x0000, 0x0048,
    0x4000, 0x0000, 0x00A8, 0x4000, 0x0000, 0x0008, 0x4000, 0x0000,
    0x0008, 0x4000, 0x0000, 0x00E8, 0x4000, 0x0000, 0x0008, 0xFFFF,
    0xFFFF, 0xFFF8,
/* Plane 1 */
    0xFFFF, 0xFFFF, 0xFFF8, 0x8000, 0x0000, 0x4100, 0x8000, 0x0000,
    0x4100, 0x8000, 0x0000, 0x0100, 0xC000, 0x0000, 0x0110, 0xC000,
    0x0000, 0x0110, 0xC000, 0x0000, 0x0110, 0xC000, 0x0000, 0x0110,
    0xC000, 0x0000, 0x0110, 0xC000, 0x0000, 0x0110, 0xC000, 0x0000,
    0x0110, 0xC000, 0x0000, 0x0110, 0xFFFF, 0xFFFF, 0xFFF0, 0x0000,
    0x0000, 0x0000,
};

struct Image    ImageI1 =
{
    0, 0,                    /* Upper left corner */
    45, 14, 2,               /* Width, Height, Depth */
    ImageI1Data,             /* Image data */
    0x0003, 0x0000,          /* PlanePick, PlaneOnOff */
    NULL                     /* Next image */
};

UWORD chip      ImageI2Data[] =
{
/* Plane 0 */
    0x0000, 0x0000, 0x0000, 0x7FFF, 0xFFFF, 0xBEF8, 0x7FFF, 0xFFFF,
    0xBEF8, 0x7FFF, 0xFFFF, 0xFEF8, 0x4000, 0x0000, 0x00E8, 0x4000,
    0x0000, 0x00E8, 0x4000, 0x0000, 0x00E8, 0x4000, 0x0000, 0x00E8,
    0x4000, 0x0000, 0x00E8, 0x4000, 0x0000, 0x00A8, 0x4000, 0x0000,
    0x00A8, 0x4000, 0x0000, 0x00E8, 0x4000, 0x0000, 0x0008, 0xFFFF,
    0xFFFF, 0xFFF8,
/* Plane 1 */
    0xFFFF, 0xFFFF, 0xFFF8, 0xFFFF, 0xFFFF, 0x7DF0, 0xFFFF, 0xFFFF,
    0x7DF0, 0x8000, 0x0000, 0x0100, 0xC000, 0x0000, 0x0150, 0xC000,
    0x0000, 0x01B0, 0xC000, 0x0000, 0x0150, 0xC000, 0x0000, 0x01B0,
    0xC000, 0x0000, 0x0150, 0xC000, 0x0000, 0x01F0, 0xC000, 0x0000,
    0x01F0, 0xC000, 0x0000, 0x0110, 0xFFFF, 0xFFFF, 0xFFF0, 0x0000,
    0x0000, 0x0000,
};

struct Image    ImageI2 =
{
    0, 0,                    /* Upper left corner */
    45, 14, 2,               /* Width, Height, Depth */
    ImageI2Data,             /* Image data */
    0x0003, 0x0000,          /* PlanePick, PlaneOnOff */
    NULL                     /* Next image */
};

struct DiskObject AppIconDObj =
{
```c
    0,
    0,
    {                        /* Embedded Gadget Structure */
        NULL,                /* Next Gadget Pointer */
        0, 0, 45, 15,        /* Left,Top,Width,Height */
        GFLG_GADGHIMAGE,
        0,                   /* Activation Flags */
        0,                   /* Gadget Type */
        (APTR) & ImageI1,    /* Render Image */
        (APTR) & ImageI2,    /* Select Image */
        NULL,                /* Gadget Text */
        NULL,                /* Mutual Exclude */
        NULL,                /* Special Info */
        0,                   /* Gadget ID */
        NULL,                /* User Data */
    },
    0,                       /* Icon Type */
    NULL,                    /* Default Tool */
    NULL,                    /* Tool Type Array */
    NO_ICON_POSITION,        /* Current X */
    NO_ICON_POSITION,        /* Current Y */
    NULL,                    /* Drawer Structure */
    NULL,                    /* Tool Window */
    0                        /* Stack Size */
```
};

