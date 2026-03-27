---
title: C / ECS Hardware and the Graphics Library / Genlock Extensions
manual: hardware
chapter: hardware
section: c-ecs-hardware-and-the-graphics-library-genlock-extensions
functions: []
libraries: []
---

# C / ECS Hardware and the Graphics Library / Genlock Extensions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The V36 graphics.library supports the new genlock capabilities of the
enhanced Denise chip in PAL or NTSC modes.  Any color registers may be
chosen as controlling video overlay (COLORKEY).  A single bitplane may be
chosen to control video overlay as well (BITPLANEKEY). The border areas
surrounding the active display window may also be set to be opaque or
transparent.

   BPLCON0   W   A,D     Bitplane control (miscellaneous control bits)
   BPLCON1   W     D     Bitplane control (horizontal scroll control)
   BPLCON2   W     D     Bitplane control (video priority control)
   BPLCON3   W     D     Bitplane control (enhanced features)

   Bit    BPLCON0   BPLCON1   BPLCON2   BPLCON3
   ----   --------  --------  --------  --------
   15
   14                          ZDBPSEL2 \
   13                          ZDBPSEL1  }         Select bitplane
   12                          ZDBPSEL0 /
   11                          ZDBPEN              Use BITPLANEKEY
   10                          ZDCTEN              Use COLORKEY
   09                          KILLEHB             Kill halfbrite
   08
   07
   06
   05                                   BRDRBLNK   Border blank
   04                                   BRDNTRAN   Border opaque
   03
   02
   01
   00     ENBPLCN3                                 Enable new BLPCON3

                                                     register.
The ECS genlock features are enabled on a ViewPort by ViewPort basis.

   Warning:
   --------
   Genlock has been designed to work with NTSC and PAL modes only.
   Genlock and 31 KHz programmable scan rates are not compatible modes.

