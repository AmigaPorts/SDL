---
title: 28 / Animation with GELs / Your Own Animation Routine Calls
manual: libraries
chapter: libraries
section: 28-animation-with-gels-your-own-animation-routine-calls
functions: [Animate]
libraries: [graphics.library]
---

# 28 / Animation with GELs / Your Own Animation Routine Calls

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) and [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) structures can include pointers for your own
routines that you want the system to call.  These pointers are stored in
the AnimOb's AnimORoutine field and in the AnimComp's AnimCRoutine field,
respectively.

When [Animate()](libraries/28-animation-with-gels-moving-the-objects.md) is called, the system performs the following steps for
every [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) in the AnimKey list:


```c
    * Updates the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md)'s location and velocities.

    * Calls the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md).AnimORoutine routine if one is supplied.

    * The for each [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) of the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md):

         · If this sequence times out, switches to the new [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md).

         · Calls the [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md).AnimCRoutine if one is supplied.

         · Sets the underlying [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md)'s x,y coordinates.
```
If you want a routine to be called, you put the address of the routine in
either [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md).AnimCRoutine or [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md).AnimORoutine member as needed.  If
no routine is to be called, you must set these fields to NULL.  Your
routines will be passed one parameter, a pointer to the AnimOb or AnimComp
it was related to.  You can use the user structure extensions discussed
earlier to hold the variables you need for your own routines.

For example, if you provide a routine such as this:


```c
    VOID MyOCode(struct AnimOb *anOb)
    {
    /* whatever needs to be done */
    }
```
Then, if you put the address of the routine in an [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) structure:


```c
    myAnimOb.AnimORoutine = MyOCode;
```
MyOCode() will be called with the address of this [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) when [Animate()](libraries/28-animation-with-gels-moving-the-objects.md)
processes this AnimOb.

---

## See Also

- [Animate — graphics.library](../autodocs/graphics.library.md#animate)
