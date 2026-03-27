---
title: intuition.library/MoveWindowInFrontOf
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-movewindowinfrontof
functions: [MoveLayerInFrontOf, WindowToBack, WindowToFront]
libraries: [intuition.library, layers.library]
---

# intuition.library/MoveWindowInFrontOf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MoveWindowInFrontOf -- Arrange the relative depth of a window. (V36)
```
SYNOPSIS

```c
    MoveWindowInFrontOf( [Window](autodocs-2.0/includes-intuition-intuition-h.md), BehindWindow )
                         A0      A1

    VOID MoveWindowInFrontOf( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    Depth-arranges a window in front of an another window.
    Brings out the layers.library [MoveLayerInFrontOf()](autodocs-2.0/layers-library-movelayerinfrontof.md) to the
    Intuition user.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) =  window to re-position in front of another window
    BehindWindow =  window to re-position in front of
```
RESULT

    Repositions window.
BUGS

    Doesn't respect backdrop windows.
SEE ALSO

```c
    [WindowToFront()](autodocs-2.0/intuition-library-windowtofront.md), [WindowToBack()](autodocs-2.0/intuition-library-windowtoback.md), [layers.library/MoveLayerInFrontOf()](autodocs-2.0/layers-library-movelayerinfrontof.md)
```

---

## See Also

- [MoveLayerInFrontOf — layers.library](../autodocs/layers.library.md#movelayerinfrontof)
- [WindowToBack — intuition.library](../autodocs/intuition.library.md#windowtoback)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
