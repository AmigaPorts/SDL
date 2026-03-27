---
title: intuition.library/ObtainGIRPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-obtaingirport
functions: [ObtainGIRPort, ReleaseGIRPort]
libraries: [intuition.library]
---

# intuition.library/ObtainGIRPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ObtainGIRPort -- Set up a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) for a custom gadget. (V36)
```
SYNOPSIS

```c
    RPort = ObtainGIRPort( GInfo )
    D0                     A0

    struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *ObtainGIRPort( struct [GadgetInfo](autodocs-2.0/includes-intuition-cghooks-h.md) * );
```
FUNCTION

```c
    Sets up a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) for use (only) by custom gadget hook routines.
    This function must be called EACH time a hook routine needing
    to perform gadget rendering is called, and must be accompanied
    by a corresponding call to [ReleaseGIRPort()](autodocs-2.0/intuition-library-releasegirport.md).

    Note that if a hook function passes you a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) pointer,
    e.g., GM_RENDER, you needn't call ObtainGIRPort() in that case.
```
INPUTS

```c
    A pointer to a [GadgetInfo](autodocs-2.0/includes-intuition-cghooks-h.md) structure, as passed to each custom
    gadget hook function.
```
RESULT

```c
    A pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) that may be used for gadget rendering.
    This pointer may be NULL, in which case you should do no rendering.
    You may (optionally) pass a null return value to [ReleaseGIRPort()](autodocs-2.0/intuition-library-releasegirport.md).
```
BUGS

SEE ALSO

```c
    [ReleaseGIRPort()](autodocs-2.0/intuition-library-releasegirport.md), [Custom](autodocs-2.0/includes-hardware-custom-h.md) [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) documentation
```

---

## See Also

- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
- [ReleaseGIRPort — intuition.library](../autodocs/intuition.library.md#releasegirport)
