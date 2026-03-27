---
title: 27 / User Copper Lists / Copper List Macros
manual: libraries
chapter: libraries
section: 27-user-copper-lists-copper-list-macros
functions: [CBump, VideoControl]
libraries: [graphics.library]
---

# 27 / User Copper Lists / Copper List Macros

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once this pointer to a user Copper list is available, you can use it with
system macros (<graphics/[gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md)>) to instruct the system what to add
to its own list of things for the Copper to do within a specific [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).
The file <graphics/[gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md)> provides the following five macro
functions that implement user Copper instructions.

[CINIT](autodocs-2.0/graphics-library-cinit.md) initializes the Copper list buffer. It is used to specify how many
instructions are going to be placed in the Copper list.  It is called as
follows.


```c
    CINIT(uCopList, num_entries);
```
The uCopList argument is a pointer tot he user Copper list and num_entries
is the number of entries in the list.

[CWAIT](autodocs-2.0/graphics-library-cwait.md) waits for the video beam to reach a particular horizontal and
vertical position.  Its format is:


```c
    CWAIT(uCopList, v, h)
```
Again, uCopList is the pointer to the Copper list.  The v argument is the
vertical position for which to wait, specified relative to the top of the
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).  The legal range of values (for both NTSC and PAL) is from 0 to
255; h is the horizontal position for which to wait.  The legal range of
values (for both NTSC and PAL) is from 0 to 226.

[CMOVE](autodocs-2.0/graphics-library-cmove.md) installs a particular value into a specified system register. Its
format is:


```c
    CMOVE(uCopList, reg, value)
```
Again, uCopList is the pointer to the Copper list.  The reg argument is
the register to be affected, specified in this form:  custom.register-name
where the register-name is one of the registers listed in the Custom
structure in <hardware/[custom.h](autodocs-2.0/includes-hardware-custom-h.md)>.  The value argument to [CMOVE](autodocs-2.0/graphics-library-cmove.md) is the
value to place in the register.

[CBump()](autodocs-2.0/graphics-library-cbump.md) increments the user Copper list pointer to the next position in
thelist.  It is usually invoked for the programmer as part of the macro
definitions [CWAIT](autodocs-2.0/graphics-library-cwait.md) or [CMOVE](autodocs-2.0/graphics-library-cmove.md).  Its format is:


```c
    CBump(uCopList)
```
where uCopList is the pointer to the user Copper list.

[CEND](autodocs-2.0/graphics-library-cend.md) terminates the user Copper list.  Its format is:


```c
    CEND(uCopList)
```
where uCopList is the pointer to the user Copper list.

Executing any of the user Copper list macros causes the system to
dynamically allocate special data structures called intermediate Copper
lists that are linked into your user Copper list (the list to which
uCopList points) describing the operation. When you call the function
[MrgCop](libraries/27-forming-a-basic-display-creating-the-display-instructions.md)(&view) as shown in the section called "[Forming A Basic Display](libraries/27-forming-a-basic-display-creating-the-display-instructions.md),"
the system uses all of its intermediate Copper lists to sort and merge
together the real Copper lists for the system ([LOFCprList and SHFCprList](autodocs-2.0/includes-graphics-view-h.md)).

When your program exits, you must return to the system all of the memory
that you allocated or caused to be allocated.  This means that you must
return the intermediate Copper lists, as well as the user Copper list data
structure.  Here are two different methods for returning this memory to
the system.


```c
    /* Returning memory to the system if you have NOT
     * obtained the ViewPort from Intuition.  */
    FreeVPortCopLists(viewPort);

    /* Returning memory to the system if you HAVE
     * obtained the ViewPort from Intuition.  */
    CloseScreen(screen);    /* Intuition only */
```
User Copper lists may be clipped, under Release 2 and later, to [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)
boundaries if the appropriate tag (VTAG_USERCLIP_SET) is passed to
[VideoControl()](libraries/27-mode-specification-viewport-interface.md).  Under earlier releases, the user Copper list would "leak"
through to lower ViewPorts.

---

## See Also

- [CBump — graphics.library](../autodocs/graphics.library.md#cbump)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
