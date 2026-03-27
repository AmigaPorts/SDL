---
title: 27 / / Viewport Size Specifications / ViewPort Height
manual: libraries
chapter: libraries
section: 27-viewport-size-specifications-viewport-height
functions: []
libraries: []
---

# 27 / / Viewport Size Specifications / ViewPort Height

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [DHeight](autodocs-2.0/includes-graphics-view-h.md) field of the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure determines how many video
lines will be reserved to show the height of this display segment.  The
size of the actual segment depends on whether you define a non-interlaced
or an interlaced display.  An interlaced ViewPort displays twice as many
lines as does a non-interlaced ViewPort in the same physical height.

For example, a complete [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) consisting of two [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)s might be defined
as follows:

  * [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) 1 is 150 lines, high-resolution mode (uses the top

```c
    three-quarters of the display).
```
  * [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) 2 is 49 lines of low-resolution mode (uses the bottom

```c
    quarter of the display and allows the space for the required
    blank line between ViewPorts).
```
Initialize the height directly in DHeight.  Nominal height for a
non-interlaced display is 200 lines for NTSC, 256 for PAL.  Nominal height
for an interlaced display is 400 lines for NTSC, 512 for PAL.

To set your [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) to the maximum supported (displayable) height, use
the following code fragment (this requires Release 2):


```c
    struct DimensionInfo querydims;
    struct Rectangle *oscan;
    struct ViewPort viewport;

    if (GetDisplayInfoData( NULL,(UBYTE *)&querydims,
                            sizeof(struct DimensionInfo),
                            DTAG_DIMS, modeID ))
    {
            /* Use StdOScan instead of MaxOScan to get standard   */
            /* overscan dimensions as set by the user in Overscan */
            /* Preferences                                        */
            oscan = &querydims.MaxOScan;
            viewPort->DHeight = oscan->MaxY - oscan->MinY + 1;
    }
```
