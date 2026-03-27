---
title: intuition.library/EndRefresh
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-endrefresh
functions: [BeginRefresh, EndRefresh, EndUpdate, UnlockLayerRom]
libraries: [graphics.library, intuition.library, layers.library]
---

# intuition.library/EndRefresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    EndRefresh -- End the optimized refresh state of the window.
SYNOPSIS

```c
    EndRefresh( [Window](autodocs-2.0/includes-intuition-intuition-h.md), Complete )
                A0      D0

    VOID EndRefresh( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, BOOL );
```
FUNCTION

```c
    This function gets you out of the special refresh state of your
    window.  It is called following a call to [BeginRefresh()](autodocs-2.0/intuition-library-beginrefresh.md), which
    routine puts you into the special refresh state.  While your window
    is in the refresh state, the only rendering that will be wrought in
    your window will be to those areas which were recently revealed and
    need to be refreshed.

    After you've done all the refreshing you want to do for this window,
    you should call this routine to restore the window to its
    non-refreshing state.  Then all rendering will go to the entire
    window, as usual.

    The 'Complete' argument is a boolean TRUE or FALSE value used to
    describe whether or not the refreshing you've done was all the
    refreshing that needs to be done at this time.  Most often, this
    argument will be TRUE.  But if, for instance, you have multiple
    tasks or multiple procedure calls which must run to completely
    refresh the window, then each can call its own Begin/EndRefresh()
    pair with a Complete argument of FALSE, and only the last calls
    with a Complete argument of TRUE.

    WARNING:  Passing this function the value of FALSE has its
    pitfalls.  Please see the several caveats in the autodoc for
    [BeginRefresh()](autodocs-2.0/intuition-library-beginrefresh.md).

    For your information, this routine calls the Layers library function
    [EndUpdate()](autodocs-2.0/layers-library-endupdate.md), unlocks your layers (calls [UnlockLayerRom()](autodocs-2.0/graphics-library-unlocklayerrom.md)), clears
    the LAYERREFRESH bit in your [Layer](autodocs-2.0/includes-graphics-clip-h.md) Flags, and clears the
    WFLG_WINDOWREFRESH bit in your window Flags.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window currently in optimized-refresh mode
    Complete = Boolean TRUE or FALSE describing whether or not this
       window is completely refreshed
```
RESULT

    None
BUGS

SEE ALSO

```c
    [BeginRefresh()](autodocs-2.0/intuition-library-beginrefresh.md), [layers.library/EndUpdate()](autodocs-2.0/layers-library-endupdate.md),
    [graphics.library/UnlockLayerRom()](autodocs-2.0/graphics-library-unlocklayerrom.md)
```

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [EndUpdate — layers.library](../autodocs/layers.library.md#endupdate)
- [UnlockLayerRom — graphics.library](../autodocs/graphics.library.md#unlocklayerrom)
