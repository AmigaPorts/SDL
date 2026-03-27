---
title: C / ECS Hardware and the Graphics Library / SuperHires Mode
manual: hardware
chapter: hardware
section: c-ecs-hardware-and-the-graphics-library-superhires-mode
functions: []
libraries: []
---

# C / ECS Hardware and the Graphics Library / SuperHires Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

SuperHires mode provides a 35ns pixel display rate - twice the horizontal
resolution of Hires mode, and four times the Lores rates. The nominal
resolution of a SuperHires viewport is 1280 pixels. The maximum plane
depth for a SuperHires viewport is 2 bitplanes which saturates DMA
bandwidth as much as four Hires bitplanes. This mode is controlled by the
graphics.library by writing to the BPLCON0 register in the LOF copperlist
(/SHF if interlaced).

   BPLCON0  chg  W  A,D  Bitplane control register (misc control bits)


```c
            Bit      Use
            ---      ---
            15       HIRES       Set it to zero if SHRES enabled
            14       BPU2 \
            13       BPU1  }     Depth of SuperHires mode (1 or 2)
            12       BPU0 /
            11       HAM         Incompatible w/ SuperHires mode
            10       DPF         Compatible with SuperHires mode
            09
            08
            07
            06       SHRES       SuperHires 35ns pixel enable bit
            05       BPLHWRM
            04       SPRHWRM
            03       LPEN        Compatible with SuperHires mode
            02       LACE        Compatible with SuperHires mode
            01
            [00](hardware/c-ecs-hardware-and-the-graphics-library-genlock-extensions.md) 
```
   Warning:
   --------
   Programmers must not rely on interpreting ViewPort->Modes bits
   directly when determining the mode of a ViewPort.

   Beginning with the V36 graphics.library, the ViewPort->Modes field is
   used for backward compatibility only.

   Under V1.3 and earlier the ViewPort->Modes field mirrored some of the
   BPLCON0 bits most notably Hires and Lace. However, other logical
   defines in this field such as the Viewport->Modes PF2PRI bit conflict
   with the SHRES bit assignment in the actual hardware.

   For this reason, in release 2.0 of the operating system
   (graphics.library V36 and later), programmers will need to use the
   new DataBase/ModeID scheme to determine their ViewPort's mode, and to
   specify a mode when creating, cloning, or copying ViewPorts.

