---
title: layers.library/EndUpdate
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-endupdate
functions: []
libraries: []
---

# layers.library/EndUpdate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    EndUpdate -- remove damage list and restore state of layer to normal.
SYNOPSIS

```c
    EndUpdate( l, flag )
               a0  d0

    void EndUpdate( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *, UWORD);
```
FUNCTION

```c
    After the programmer has redrawn his picture he calls this
    routine to restore the ClipRects to point to his standard
    layer tiling. The layer is then unlocked for access by the
    layer library.

    Note: use flag = FALSE if you are only making a partial update.
        You may use the other region functions (graphics functions such as
        [OrRectRegion](autodocs-2.0/graphics-library-orrectregion.md), [AndRectRegion](autodocs-2.0/graphics-library-andrectregion.md), and [XorRectRegion](autodocs-2.0/graphics-library-xorrectregion.md) ) to clip adjust
        the DamageList to reflect a partial update.
```
INPUTS

    l - pointer to a layer
    flag - use TRUE if update was completed. The damage list is cleared.
           use FALSE if update not complete. The damage list is retained.
EXAMPLE


```c
    -- begin update for first part of two-part refresh --
    BeginUpdate(my_layer);

    -- do some refresh, but not all --
    my_partial_refresh_routine(my_layer);

    -- end update, false (not completely done refreshing yet) --
    EndUpdate(my_layer, FALSE);

    -- begin update for last part of refresh --
    BeginUpdate(my_layer);

    -- do rest of refresh --
    my_complete_refresh_routine(my_layer);

    -- end update, true (completely done refreshing now) --
    EndUpdate(my_layer, TRUE);
```
BUGS

SEE ALSO

```c
    [BeginUpdate](autodocs-2.0/layers-library-beginupdate.md), [graphics/layers.h](autodocs-2.0/includes-graphics-layers-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```
