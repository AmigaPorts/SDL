# 28 / Using Virtual Sprites / Specification of VSprite Structure


The VSprite structure is defined in the include file <graphics/[gels.h](../Includes_and_Autodocs_2._guide/node00C3.html#line73)> as
follows:


```c
    /* VSprite structure definition */
    struct VSprite {
        struct VSprite *NextVSprite;
        struct VSprite *PrevVSprite;
        struct VSprite *DrawPath;
        struct VSprite *ClearPath;
        WORD            OldY, OldX;
        WORD            Flags;
        WORD            Y, X;
        WORD            Height;
        WORD            Width;
        WORD            Depth;
        WORD            MeMask;
        WORD            HitMask;
        WORD           *ImageData;
        WORD           *BorderLine;
        WORD           *CollMask;
        WORD           *SprColors;
        struct Bob     *VSBob;
        BYTE            PlanePick;
        BYTE            PlaneOnOff;
        VUserStuff      VUserExt;
        };
```
There are two primary ways to allocate and fill in space for VSprite data.
They can be statically declared, or a memory allocation function can be
called and they can be filled in programmatically.  The declaration to
statically set up a VSprite structure is listed below.


```c
    /* VSprite static data definition.
    ** must set the following for TRUE VSprites:
    **    VSPRITE flag.
    **    Width to 1.
    **    Depth to 2.
    **    VSBob to NULL.
    */
    struct VSprite myVSprite =
        {
        NULL, NULL, NULL, NULL, 0, 0, VSPRITE, 0, 0, 5, 1, 2, 0, 0,
        &myImage, 0, 0, &mySpriteColors, NULL, 0x3, 0, 0
        };
```
This static allocation gives the required VSprite structure, but does not
allocate or set up collision masks for the VSprite.  Note that the VSprite
structure itself does not need to reside in Chip memory.

Refer to the [makeVSprite()](../Libraries_Manual_guide/node059C.html#line89) and [freeVSprite()](../Libraries_Manual_guide/node059C.html#line288) functions in the [animtools.c](../Libraries_Manual_guide/node059C.html)
listing at the end of the chapter for an example of dynamically
allocating, initializing and freeing a VSprite structure.

