# graphics.library/VideoControl



NAME

```c
    VideoControl -- Modify the operation of a ViewPort's [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) (V36)
```
SYNOPSIS

```c
    error = VideoControl( cm , tags )
    d0                    a0   a1

    ULONG VideoControl( struct [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) * );
```
FUNCTION
   [Process](../Includes_and_Autodocs_2._guide/node0078.html#line38) the commands in the VideoControl command [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) buffer
   using cm as the target, with respect to its "attached" [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40).

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
    mode, that is, at the next [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html) for the ColorMap->cm_vp;
    you may intall a static list of videocontrol TagItems into the
    [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) with the BATCH_ITEMS_SET command; and then enable/disable
    batch mode processing of those items via the BATCH_CM control
    command)
```
   VTAG_BATCH_CM      [_SET | _CLR | _GET] -- onoffinquire batch mode
   VTAG_BATCH_ITEMS   [_SET | _ADD | _GET] -- setaddget batched TagLists

   private commands (used internally by intuition -- do not call):

   VTAG_VPMODEID      [_SET | _CLR | _GET] -- force [GetVPModeID()](../Includes_and_Autodocs_2._guide/node044A.html) return


INPUTS

```c
    cm   = pointer to struct [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) obtained via [GetColorMap()](../Includes_and_Autodocs_2._guide/node0445.html).
    tags = pointer to a table of videocontrol tagitems.
```
RESULT
```c
    error = NULL if no error occured in the control operation.
```
   (non-NULL if bad colormap pointer, no tagitems or bad tag)


```c
    The operating characteristics of the [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) and its attached
    [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) are modified. The result will be incorporated into the
    [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) when its copper lists are reassembled via [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html).
```
BUGS

SEE ALSO

```c
    [graphics/videocontrol.h](../Includes_and_Autodocs_2._guide/node00B0.html), [GetColorMap()](../Includes_and_Autodocs_2._guide/node0445.html), [FreeColorMap()](../Includes_and_Autodocs_2._guide/node043E.html)
```
