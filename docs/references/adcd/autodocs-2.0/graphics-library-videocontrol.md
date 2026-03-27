---
title: graphics.library/VideoControl
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-videocontrol
functions: [FreeColorMap, GetColorMap, GetVPModeID, MakeVPort]
libraries: [graphics.library]
---

# graphics.library/VideoControl

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    VideoControl -- Modify the operation of a ViewPort's [ColorMap](autodocs-2.0/includes-graphics-view-h.md) (V36)
```
SYNOPSIS

```c
    error = VideoControl( cm , tags )
    d0                    a0   a1

    ULONG VideoControl( struct [ColorMap](autodocs-2.0/includes-graphics-view-h.md) *, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) * );
```
FUNCTION
   [Process](autodocs-2.0/includes-dos-dosextens-h.md) the commands in the VideoControl command [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) buffer
   using cm as the target, with respect to its "attached" [ViewPort](autodocs-2.0/includes-graphics-view-h.md).

   viewport commands:

   VTAG_ATTACH_CM     [_SET        | _GET] -- setget attached viewport
   VTAG_VIEWPORTEXTRA [_SET        | _GET] -- setget attached vp_extra
   VTAG_NORMAL_DISP   [_SET        | _GET] -- setget DisplayInfoHandle
```c
                                                      (natural mode)
```
   VTAG_COERCE_DISP   [_SET        | _GET] -- setget DisplayInfoHandle

```c
                                                      (coerced mode)
```
   genlock commands:

   VTAG_BORDERBLANK   [_SET | _CLR | _GET] -- onoffinquire blanking
   VTAG_BORDERNOTRANS [_SET | _CLR | _GET] -- onoffinquire notransparency
   VTAG_CHROMAKEY     [_SET | _CLR | _GET] -- onoffinquire chroma mode
   VTAG_BITPLANEKEY   [_SET | _CLR | _GET] -- onoffinquire bitplane mode
   VTAG_CHROMA_PEN    [_SET | _CLR | _GET] -- setclrget chromakey pen #
   VTAG_CHROMA_PLANE  [_SET |      | _GET] -- setget bitplanekey plane #

   copper commands

   VTAG_USERCLIP      [_SET | _CLR | _GET] -- onoffinquire clipping of

```c
                                              UserCopperList at bottom
                                              edge of ColorMap->cm_vp
                                              (defaults to off)
```
   buffer commands:

   VTAG_NEXTBUF_CM                         -- link to more VTAG commands
   VTAG_END_CM                             -- terminate command buffer

   batch mode commands:

   (if you want your videocontol taglist to be processed in "batch"

```c
    mode, that is, at the next [MakeVPort()](autodocs-2.0/graphics-library-makevport.md) for the ColorMap->cm_vp;
    you may intall a static list of videocontrol TagItems into the
    [ColorMap](autodocs-2.0/includes-graphics-view-h.md) with the BATCH_ITEMS_SET command; and then enable/disable
    batch mode processing of those items via the BATCH_CM control
    command)
```
   VTAG_BATCH_CM      [_SET | _CLR | _GET] -- onoffinquire batch mode
   VTAG_BATCH_ITEMS   [_SET | _ADD | _GET] -- setaddget batched TagLists

   private commands (used internally by intuition -- do not call):

   VTAG_VPMODEID      [_SET | _CLR | _GET] -- force [GetVPModeID()](autodocs-2.0/graphics-library-getvpmodeid.md) return


INPUTS

```c
    cm   = pointer to struct [ColorMap](autodocs-2.0/includes-graphics-view-h.md) obtained via [GetColorMap()](autodocs-2.0/graphics-library-getcolormap.md).
    tags = pointer to a table of videocontrol tagitems.
```
RESULT
```c
    error = NULL if no error occured in the control operation.
```
   (non-NULL if bad colormap pointer, no tagitems or bad tag)


```c
    The operating characteristics of the [ColorMap](autodocs-2.0/includes-graphics-view-h.md) and its attached
    [ViewPort](autodocs-2.0/includes-graphics-view-h.md) are modified. The result will be incorporated into the
    [ViewPort](autodocs-2.0/includes-graphics-view-h.md) when its copper lists are reassembled via [MakeVPort()](autodocs-2.0/graphics-library-makevport.md).
```
BUGS

SEE ALSO

```c
    [graphics/videocontrol.h](autodocs-2.0/includes-graphics-videocontrol-h.md), [GetColorMap()](autodocs-2.0/graphics-library-getcolormap.md), [FreeColorMap()](autodocs-2.0/graphics-library-freecolormap.md)
```

---

## See Also

- [FreeColorMap — graphics.library](../autodocs/graphics.library.md#freecolormap)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
