---
title: intuition.library/ReleaseGIRPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-releasegirport
functions: [ObtainGIRPort]
libraries: [intuition.library]
---

# intuition.library/ReleaseGIRPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ReleaseGIRPort -- Release a custom gadget [RastPort](autodocs-2.0/includes-graphics-rastport-h.md). (V36)
```
SYNOPSIS

```c
    ReleaseGIRPort( RPort )
                    A0

    VOID ReleaseGIRPort( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) * );
```
FUNCTION

```c
    The corresponding function to [ObtainGIRPort()](autodocs-2.0/intuition-library-obtaingirport.md), it releases
    arbitration used by Intuition for gadget RastPorts.
```
INPUTS

```c
    Pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) returned by [ObtainGIRPort()](autodocs-2.0/intuition-library-obtaingirport.md).
    This pointer can be NULL, in which case nothing happens.
```
RESULT

    None
BUGS

SEE ALSO

```c
    [ObtainGIRPort()](autodocs-2.0/intuition-library-obtaingirport.md), [Custom](autodocs-2.0/includes-hardware-custom-h.md) [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) documentation
```

---

## See Also

- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
