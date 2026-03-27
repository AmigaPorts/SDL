---
title: 28 / Animation with GELs / Adding Animation Objects
manual: libraries
chapter: libraries
section: 28-animation-with-gels-adding-animation-objects
functions: [AddAnimOb]
libraries: [graphics.library]
---

# 28 / Animation with GELs / Adding Animation Objects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Use the routine [AddAnimOb()](autodocs-2.0/graphics-library-addanimob.md) to add animation objects to the controlled
object list.  This routine will link the [PrevOb](libraries/28-animation-with-gels-the-animkey.md) and [NextOb](libraries/28-animation-with-gels-the-animkey.md) pointers to
chain all the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md)s that the system is controlling.


```c
    struct RastPort myRPort;
    struct AnimOb myAnimOb;
    struct AnimOb *animKey;  /* Must be initialized with InitAnimate() */

    AddAnimOb(&myAnimOb, &animKey, &myRPort);
```

---

## See Also

- [AddAnimOb — graphics.library](../autodocs/graphics.library.md#addanimob)
