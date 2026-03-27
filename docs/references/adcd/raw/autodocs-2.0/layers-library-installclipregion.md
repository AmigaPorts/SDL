# layers.library/InstallClipRegion



NAME

    InstallClipRegion -- Install clip region in layer
SYNOPSIS

```c
    oldclipregion = InstallClipRegion( l,  region )
    d0                                 a0  a1

    struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *InstallClipRegion( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *, struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *);
```
FUNCTION

```c
    Installs a transparent Clip region in the layer. All
    subsequent graphics calls will be clipped to this region.
    You MUST remember to call InstallClipRegion(l,NULL) before
    calling DeleteLayer(l) or the Intuition function [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html)
    if you have installed a non-NULL ClipRegion in l.
```
INPUTS

    l - pointer to a layer
    region - pointer to a region
RESULTS

    oldclipregion - The pointer to the previous ClipRegion that
        was installed. Returns NULL if no previous ClipRegion installed.

        Note: If the system runs out of memory while computing the
            resulting ClipRects the LAYERS_CLIPRECTS_LOST bit will
            be set in l->Flags.
BUGS

```c
    If the system runs out of memory during normal layer operations,
    the [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) list may get swept away and not restored.
    As soon as there is enough memory and the layer library
    gets called again the [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) list will be rebuilt.
```
SEE ALSO

```c
    [BeginUpdate](../Includes_and_Autodocs_2._guide/node038E.html) [EndUpdate](../Includes_and_Autodocs_2._guide/node0396.html),
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html), [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
