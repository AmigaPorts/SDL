---
title: 28 / / Adding User Extensions To Gel Data Structures
manual: libraries
chapter: libraries
section: 28-adding-user-extensions-to-gel-data-structures
functions: [DoCollision]
libraries: [graphics.library]
---

# 28 / / Adding User Extensions To Gel Data Structures

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section describes how to expand the size and scope of the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md),
[Bob](libraries/28-using-bobs-the-bob-structure.md) and [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) data structures.  In the definition for these structures,
there is an item called UserExt at the end of each.  If you want to expand
these structures (to hold your own special data), you define the UserExt
member before the <graphics/[gels.h](autodocs-2.0/includes-graphics-gels-h.md)> file is included.  If this member has
already been defined when the <graphics/gels.h> file is parsed,  the
compiler preprocessor will extend the structure definition automatically.
If these members have not been defined, the system will make them SHORTs,
and you may still consider these as being reserved for your private use.

To show the kind of use you can make of this feature, the example below
adds speed and acceleration figures to each GEL by extending the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md)
structure.  When your collision routine is called, it could use these
values to transfer energy between the two colliding objects (say, billiard
balls).  You would have to set up additional routines, executed between
calls to [DoCollision()](libraries/28-graphics-sprites-bobs-and-animation-function-reference.md), that would add the values to the GELs position
appropriately.  You could do this with code similar o the following:


```c
     struct myInfo
         {
         short xvelocity;
         short yvelocity;
         short xaccel;
         short yaccel;
         };
```
These members are for example only.  You may use any definition for your
user extensions.  You would then also provide the following line, to
extend the [VSprites](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure, use:


     /* Redefine VUserStuff for my own use. */
     #define VUserStuff struct myInfo
To extend the [Bob](libraries/28-using-bobs-the-bob-structure.md)s structure, use:


     #define BUserStuff struct myInfo
To extend the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md)s structure, use:


     #define AUserStuff struct myInfo
When the system is compiling the <graphics/[gels.h](autodocs-2.0/includes-graphics-gels-h.md)> file with your program,
the compiler preprocessor substitutes "struct myInfo" everywhere that
UserExt is used in the header. The structure is thereby customized to
include the items you wish to associate with it.


    Typedef Cannot Be Used.
    -----------------------
    You cannot use the C-language construct typedef for the above
    statements.  If you want to substitute your own data type for one of
    the UserStuff variables, you must use a #define.

---

## See Also

- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
