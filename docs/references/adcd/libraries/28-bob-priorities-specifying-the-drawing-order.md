---
title: 28 / / Bob Priorities / Specifying the Drawing Order
manual: libraries
chapter: libraries
section: 28-bob-priorities-specifying-the-drawing-order
functions: []
libraries: []
---

# 28 / / Bob Priorities / Specifying the Drawing Order

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To specify the priorities of the Bobs, use the [Before](libraries/28-using-bobs-the-bob-structure.md) and [After](libraries/28-using-bobs-the-bob-structure.md) pointers.
Before points to the Bob that this Bob should be drawn before, and After
points to the Bob that this Bob should be drawn after.  By following these
pointers, from Bob to Bob, the system can determine the order in which the
Bobs should be drawn.  (Take care to avoid circular dependencies in this
list!)


```c
    Note:
    -----
    This terminology is often confusing, but, due to historical reasons,
    cannot be changed.  The system does not draw the Bobs on the [Before](libraries/28-using-bobs-the-bob-structure.md)
    list first, it draws the Bobs on the [After](libraries/28-using-bobs-the-bob-structure.md) list first. Next, it draws
    the current Bob, and, finally, the Bobs on the Before list.
```
For example, to assure that myBob1 always appears in front of myBob2, The
[Before](libraries/28-using-bobs-the-bob-structure.md) and [After](libraries/28-using-bobs-the-bob-structure.md) pointers must be initialized so that the system will
always draw myBob1 after myBob2.


```c
    myBob2.Before = &myBob1;     /* draw Bob2 before drawing Bob1 */
    myBob2.After  = NULL;        /* draw Bob2 after  no other Bob */
    myBob1.After  = &myBob2;     /* draw Bob1 after  drawing Bob2 */
    myBob1.Before = NULL;        /* draw Bob1 before no other Bob */
```
As the system goes through the [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list, it checks the Bob's [After](libraries/28-using-bobs-the-bob-structure.md)
pointer.  If this is not NULL, it follows the After pointer until it hits
a NULL.  Then it starts rendering the Bobs, going back up the [Before](libraries/28-using-bobs-the-bob-structure.md)
pointers until it hits a NULL.  Then it continues through the GelsInfo
list.  So, it is important that all Before and After pointers of a group
properly point to each other.


```c
    Note:
    -----
    In a screen with a number of complex GELs, you may want to specify
    the [Before](libraries/28-using-bobs-the-bob-structure.md) and [After](libraries/28-using-bobs-the-bob-structure.md) order for Bobs that are not in the same
    AnimOb.  This will keep large objects together.  If you do not do
    this, you may have an object drawn with half of its Bobs in front of
    another object!  Also, in sequences you only set the Before and
    After pointers for the active AnimComp in the sequence.
```
