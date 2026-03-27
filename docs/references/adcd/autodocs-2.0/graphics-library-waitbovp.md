---
title: graphics.library/WaitBOVP
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-waitbovp
functions: [VBeamPos, WaitTOF]
libraries: [graphics.library]
---

# graphics.library/WaitBOVP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WaitBOVP -- Wait till vertical beam reached bottom of
                this viewport.
SYNOPSIS

```c
    WaitBOVP( vp )
              a0

    void WaitBOVP( struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) * );
```
FUNCTION

    Returns when the vertical beam has reached the bottom of this viewport
INPUTS

```c
    vp - pointer to [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure
```
RESULT

    This function will return sometime after the beam gets beyond
    the bottom of the viewport.  Depending on the multitasking load
    of the system, the actual beam position may be different than
    what would be expected in a lightly loaded system.
BUGS

```c
    Horrors! This function currently busy waits waiting for the
    beam to get to the right place.  It should use the copper
    interrupt to trigger and send signals like [WaitTOF](autodocs-2.0/graphics-library-waittof.md) does.
```
SEE ALSO

```c
    [WaitTOF()](autodocs-2.0/graphics-library-waittof.md) [VBeamPos()](autodocs-2.0/graphics-library-vbeampos.md)
```

---

## See Also

- [VBeamPos — graphics.library](../autodocs/graphics.library.md#vbeampos)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
