---
title: 28 / Animation with GELs / The AnimKey
manual: libraries
chapter: libraries
section: 28-animation-with-gels-the-animkey
functions: [AddAnimOb]
libraries: [graphics.library]
---

# 28 / Animation with GELs / The AnimKey

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The system uses one pointer, known as the AnimKey, to keep track of all
the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md)s via their PrevOb and NextOb linkage fields.  The AnimKey acts
as the anchor for the list of AnimObs you are using and is initialized
with code such as the following:


```c
    struct AnimOb *animKey;

    InitAnimate(&animKey);
        /* Only do this once to initialize the AnimOb list */
```
As each new object is added (via [AddAnimOb()](libraries/28-animation-with-gels-adding-animation-objects.md)), it is linked in at the
beginning of the list, so AnimKey will always point to the object most
recently added to the list.  To search forward through the list, start
with the AnimKey and move forward on the NextOb link.  Continue to move
forward until the NextOb is NULL, indicating the end of the list.  The
PrevOb link will allow you to move back to a previous object.


    Set Up PrevOb and NextOb Correctly.
    -----------------------------------
    It is important that the NextOb link of the last object is NULL,
    and that the PrevOb of the first object is NULL.  In fact, the
    system expects the animation object lists to be exactly the way
    that they are described above.  If they are not, the system will
    produce unexpected results.

---

## See Also

- [AddAnimOb — graphics.library](../autodocs/graphics.library.md#addanimob)
