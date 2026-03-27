---
title: 28 / Using Bobs / The Bob Structure
manual: libraries
chapter: libraries
section: 28-using-bobs-the-bob-structure
functions: []
libraries: []
---

# 28 / Using Bobs / The Bob Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Bob structure is defined in the include file <graphics/[gels.h](autodocs-2.0/includes-graphics-gels-h.md)> as
follows:

struct Bob
  {
  WORD               Flags;     /* general purpose flags                 */
  WORD              *SaveBuffer;/* buffer for background save            */
  WORD              *ImageShadow; /* shadow mask of image                */
  struct Bob        *Before;   /* draw this Bob before Bobs on this list */
  struct Bob        *After;     /* draw this Bob after Bobs on this list */
  struct VSprite    *BobVSprite;/* this Bob's VSprite definition         */
  struct AnimComp   *BobComp;   /* pointer to this Bob's AnimComp def    */
  struct DBufPacket *DBuffer;   /* pointer to this Bob's dBuf packet     */
  BUserStuff         BUserExt;  /* Bob user extension                    */
  };

The Bob structure itself does not need to be in Chip memory. The (global)
static declaration of a Bob structure could be done like so:


```c
    struct Bob myBob =
        {
        0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0
        };
```
However, since most of the Bob structure members are pointers, it is more
common to allocate and set the Bob up dynamically. Refer to the [makeBob()](libraries/lib-examples-animtools-c.md)
and [freeBob()](libraries/lib-examples-animtools-c.md) functions in the "[animtools.c](libraries/lib-examples-animtools-c.md)" example at the end of the
chapter for an example of allocating, initializing and freeing a Bob
structure.

 [Linking Bob and VSprite Structures](libraries/28-the-bob-structure-linking-bob-and-vsprite-structures.md) 

