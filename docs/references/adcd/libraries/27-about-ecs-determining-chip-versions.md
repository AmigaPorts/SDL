---
title: 27 / / About ECS / Determining Chip Versions
manual: libraries
chapter: libraries
section: 27-about-ecs-determining-chip-versions
functions: []
libraries: []
---

# 27 / / About ECS / Determining Chip Versions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

It is possible to ascertain whether the ECS chips are in the machine at
run time by looking in the ChipRevBits0 field of the GfxBase structure.
If this field contains the flag for the chip you are interested in (as
defined in the <[gfxbase.h](autodocs-2.0/includes-graphics-gfxbase-h.md)> include file), then that chip is present.

For example, if the C statement ([GfxBase](autodocs-2.0/includes-graphics-gfxbase-h.md)->ChipRevBits0 & GFXF_HR_AGNUS)
evaluates to non-zero, then the machine contains the ECS version of the
Agnus chip and has advanced features such as the ability to handle larger
rasters.  Older Agnus chips were capable of handling rasters up to 1,024
by 1,024 pixels.  The ECS Agnus can handle rasters up to 16,384 by 16,384
pixels.

If ([GfxBase](autodocs-2.0/includes-graphics-gfxbase-h.md)->ChipRevBits0 & GFXF_HR_DENISE) is non-zero, then the ECS
version of the Denise chip is present.  Having both the ECS Agnus and ECS
Denise present allows for the special SuperHires, VGA and Productivity
display modes available in Release 2.  For more information on ECS and the
custom chips, refer to the Amiga [Hardware](hardware/amiga-hardware-reference-manual-c-enhanced-chip-set.md) Reference Manual.

