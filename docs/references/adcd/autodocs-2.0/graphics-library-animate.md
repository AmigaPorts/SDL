---
title: graphics.library/Animate
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-animate
functions: [AddAnimOb]
libraries: [graphics.library]
---

# graphics.library/Animate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Animate  --  Processes every [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) in the current animation list.
```
SYNOPSIS

```c
    Animate(anKey, rp)
            A0     A1

    void Animate(struct [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) **, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    For every [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) in the list
        - update its location and velocities
        - call the AnimOb's special routine if one is supplied
        - for each component of the [AnimOb](autodocs-2.0/includes-graphics-gels-h.md)
            - if this sequence times out, switch to the new one
            - call this component's special routine if one is supplied
            - set the sequence's VSprite's y,x coordinates based
              on whatever these routines cause
```
INPUTS

```c
    ankey = address of the variable that points to the head [AnimOb](autodocs-2.0/includes-graphics-gels-h.md)
    rp    = pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
```
RESULT

BUGS

SEE ALSO

```c
    [AddAnimOb()](autodocs-2.0/graphics-library-addanimob.md) [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AddAnimOb — graphics.library](../autodocs/graphics.library.md#addanimob)
