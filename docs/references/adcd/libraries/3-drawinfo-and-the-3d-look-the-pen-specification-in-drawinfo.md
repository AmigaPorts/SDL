---
title: 3 / DrawInfo and the 3D Look / The Pen Specification in DrawInfo
manual: libraries
chapter: libraries
section: 3-drawinfo-and-the-3d-look-the-pen-specification-in-drawinfo
functions: [FreeScreenDrawInfo, GetScreenDrawInfo, LockPubScreen, OpenScreenTagList, UnlockPubScreen]
libraries: [intuition.library]
---

# 3 / DrawInfo and the 3D Look / The Pen Specification in DrawInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The drawing pen specification in [DrawInfo.dri_Pens](libraries/3-intuition-screens-drawinfo-and-the-3d-look.md) allows applications to
use appropriate colors for graphic operations such as drawing text,
shading 3D objects and filling items selected by the user.

Intuition has two default sets of pens, one for multi-bitplane screens and
one for single bitplane screens.  In addition, there is a special
compatibility mode for screens that do not specify the [SA_Pens](libraries/3-custom-screen-functions-screen-attributes.md) tag.

New 3D Look

    The is the full 3D look as found by default on the Workbench screen
    in Release 2.  Objects are drawn so that light appears to come from
    the upper left of the screen with shadows cast to the lower right
    giving them a three-dimensional look.
Monochrome New Look

```c
    It is impossible to produce the full 3D look in a single bitplane
    (two color) screen.  Intuition provides a fallback pen specification
    that is used in monochrome screens with no loss of information.
```
Compatible New Look

```c
    [Custom screens](libraries/3-intuition-screens-custom-screen-functions.md) that do not provide the [SA_Pens](libraries/3-custom-screen-functions-screen-attributes.md) tag are assumed to
    have no knowledge of the pen array.  They are rendered in a special
    version of the monochrome new look, which uses the screen's [DetailPen](libraries/3-custom-screen-functions-screen-attributes.md)
    and [BlockPen](libraries/3-custom-screen-functions-screen-attributes.md) to get its colors.  This is provided for compatibility
    with V34 and older [versions](libraries/1-programming-in-the-amiga-environment-operating-system.md) of the operating system.
```
It is very easy for an application to use the default pen specification.
Simply specify an empty pen specification (in C, {~0}), and Intuition will
fill in all of the values with defaults appropriate for the screen.  This
technique is demonstrated in the first two examples ([newlookscreen.c](libraries/lib-examples-newlookscreen-c.md) and
[screen34to37.c](libraries/lib-examples-screen34to37-c.md))listed earlier in this chapter.

For certain applications, a custom pen specification is required.  A
custom pen specification is set up when the screen is opened by using the
[SA_Pens](libraries/3-custom-screen-functions-screen-attributes.md) tag and a pointer to a pen array.  Currently, Intuition uses nine
pens to support the 3D look.  The application can specify all of these, or
only a few pens and Intuition will fill in the rest.  Intuition will only
fill in pens that are past the end of those specified by the application,
there is no facility for using default values for "leading" pens (those at
the beginning of the array) without using the defaults for the rest of the
pens.

Using the pen specification of an existing [public screen](libraries/3-intuition-screens-public-screen-functions.md) is a bit more
involved.  First, the application must get a pointer to the screen
structure of the public screen using the [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) call.  A copy of
the screen's [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structure may then be obtained by calling
[GetScreenDrawInfo()](libraries/3-drawinfo-and-the-3d-look-cloning-a-public-screen-workbench.md).  The DrawInfo structure contains a copy of the pen
specification for the screen that can be used in the [OpenScreenTagList()](libraries/3-intuition-screens-custom-screen-functions.md)
call with the [SA_Pens](libraries/3-custom-screen-functions-screen-attributes.md) tag.  The pen array is copied to the data structures
of the new screen (it is not kept as a pointer to the information passed),
so the application may immediately call [FreeScreenDrawInfo()](libraries/3-intuition-screens-function-reference.md) and
[UnlockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) after the new screen is open.


```c
     [publicscreen.c](libraries/lib-examples-publicscreen-c.md) 
```
Beginning with V36, the pen specification for the Workbench screen happens
to match the Intuition default specification, however, this is not
required and may change in the future.  To create a screen that uses the
pens defined in the Workbench screen, the application must get a copy of
the pen array from the Workbench screen and use this copy with the [SA_Pens](libraries/3-custom-screen-functions-screen-attributes.md)
tag as described above.

Here is a list of the pens defined under V36 that support the 3D look
along with their uses.  To read the value of a particular pen, use UWORD
penvalue = myDrawInfo->dri_Pens[PENNAME], where myDrawInfo is a pointer to
a [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structure and PENNAME is taken from the list below:

DETAILPEN

    Pen compatible with V34. Used to render text in the screen's title bar.
BLOCKPEN

    Pen compatible with V34. Used to fill the screen's title bar.
TEXTPEN

    Pen for regular text on BACKGROUNDPEN.
SHINEPEN

    Pen for the bright edge on 3D objects.
SHADOWPEN

    Pen for the dark edge on 3D objects.
FILLPEN

    Pen for filling the active window borders and selected gadgets.
FILLTEXTPEN

    Pen for text rendered over FILLPEN.
BACKGROUNDPEN

    Pen for the background color.  Currently must be zero.
HIGHLIGHTTEXTPEN

    Pen for "special color" or highlighted text on BACKGROUNDPEN.

---

## See Also

- [FreeScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#freescreendrawinfo)
- [GetScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#getscreendrawinfo)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
