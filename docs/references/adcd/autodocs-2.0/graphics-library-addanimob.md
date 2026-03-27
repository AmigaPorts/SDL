---
title: graphics.library/AddAnimOb
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-addanimob
functions: [Animate]
libraries: [graphics.library]
---

# graphics.library/AddAnimOb

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddAnimOb  --  Add an [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) to the linked list of AnimObs.
```
SYNOPSIS

```c
    AddAnimOb(anOb, anKey, rp)
              A0    A1     A2

    void AddAnimOb(struct [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) *,struct [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) **, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    Links this [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) into the current list pointed to by animKey.
    Initializes all the Timers of the AnimOb's components.
    Calls [AddBob](autodocs-2.0/graphics-library-addbob.md) with each component's [Bob](autodocs-2.0/includes-graphics-gels-h.md).
    rp->GelsInfo must point to an initialized [GelsInfo](autodocs-2.0/includes-graphics-rastport-h.md) structure.
```
INPUTS

```c
    anOb  = pointer to the [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) structure to be added to the list
    anKey = address of a pointer to the first [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) in the list
            (anKey = NULL if there are no AnimObs in the list so far)
    rp    = pointer to a valid [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
RESULT

BUGS

SEE ALSO

```c
    [Animate()](autodocs-2.0/graphics-library-animate.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md) [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)
```

---

## See Also

- [Animate — graphics.library](../autodocs/graphics.library.md#animate)
