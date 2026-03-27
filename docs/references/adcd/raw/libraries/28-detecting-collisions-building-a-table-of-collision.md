# 28 / / Detecting Collisions / Building a Table of Collision Routines


The collision handler table is a structure, CollTable, defined in
<graphics/[gels.h](../Includes_and_Autodocs_2._guide/node00C3.html#line263)>.  It is accessed as the CollHandler member of the
[GelsInfo](../Libraries_Manual_guide/node0377.html#line6) structure.  The table only needs to be as large as the number of
bits for which you wish to provide collision processing.  It is safest,
though, to allocate space for all 16 entries, considering the small amount
of space required.

Call the routine [SetCollision()](../Includes_and_Autodocs_2._guide/node0477.html) to initialize the table entries that
correspond to the [HitMask](../Libraries_Manual_guide/node03B2.html) and [MeMask](../Libraries_Manual_guide/node03B2.html) bits that you plan to use.  Do not
set any of the table entries directly, instead give the address to
SetCollision() routine and let it handle the set up of the
[GelsInfo.CollTable](../Includes_and_Autodocs_2._guide/node00AF.html#line39) field.

For example, [SetCollision()](../Includes_and_Autodocs_2._guide/node0477.html) could be called as follows:


```c
    ULONG            num;
    VOID           (*routine)();
    struct GelsInfo *GInfo;

    VOID myCollisionRoutine(GELA, GELB)   /* sample collision routine */
    struct VSprite *GELA;
    struct VSprite *GELB;
    {
        /* process gels here - GELA and GELB point to the base VSprites */
        /* of the gels, you can use the user extensions to identify what */
        /* hit (if you need the info). */
    }

    /* GelsInfo must be allocated and initialized */

    routine = myCollisionRoutine;

    SetCollision(num, routine, GInfo)
```
The num argument is the collision table vector number (0-15).  The
(*routine)() argument is a pointer to your collision routine.  And the
GInfo argument is a pointer to the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) structure.

