---
title: 3 / Screen Data Structures / The Intuition Screen Data Structure
manual: libraries
chapter: libraries
section: 3-screen-data-structures-the-intuition-screen-data-structure
functions: [MoveScreen, OpenScreen]
libraries: [intuition.library]
---

# 3 / Screen Data Structures / The Intuition Screen Data Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [structures](libraries/3-intuition-screens-screen-data-structures.md) mentioned above are unified along with other information in
Intuition's Screen data structure defined in the include file
<intuition/[screens.h](autodocs-2.0/includes-intuition-screens-h.md)>.  Notice that the Screen structure contains
instances of a ViewPort, RastPort and BitMap.


struct Screen


```c
    {
    struct Screen *NextScreen;
    struct Window *FirstWindow;
    WORD LeftEdge, TopEdge, Width, Height;
    WORD MouseY, MouseX;
    UWORD Flags;
    UBYTE *Title, *DefaultTitle;
    BYTE BarHeight, BarVBorder, BarHBorder, MenuVBorder, MenuHBorder;
    BYTE WBorTop, WBorLeft, WBorRight, WBorBottom;
    struct TextAttr *Font;
    struct ViewPort ViewPort;
    struct RastPort RastPort;
    struct BitMap BitMap;
    struct Layer_Info LayerInfo;
    struct Gadget *FirstGadget;
    UBYTE DetailPen, BlockPen;
    UWORD SaveColor0;
    struct Layer *BarLayer;
    UBYTE *ExtData, *UserData;
    };
```
In general, applications don't need to access the fields in the Screen
structure directly; they use Intuition functions to manipulate the screen
instead.  Likewise, applications do not set up the Screen themselves; they
use one of the [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) calls.  Here is a description of some of the
more interesting members of the Screen structure (it is not meant to be a
complete description of all the fields).

LeftEdge, TopEdge

```c
    The LeftEdge and TopEdge variables give the position of the screen
    relative to the upper left corner of the monitor's visible display
    (as set by the user in the [Overscan](libraries/27-effect-of-display-overscan-on-the-viewing-area.md) [preferences editor](libraries/13-preferences-in-release-2-preferences-editors-and-storage.md)).  If it is
    positioned down or to the right, the values are positive.  If the
    screen is positioned up or to the left, the values are negative.  The
    values are in screen resolution pixels.  In systems prior to [V36](libraries/1-programming-in-the-amiga-environment-operating-system.md),
    LeftEdge positioning is ignored and negative TopEdge positions are
    illegal.

    The screen position may be set when the screen is opened or later by
    calling the [MoveScreen()](libraries/3-other-screen-functions-screen-movement-and-scrolling.md) function. Note that the screen's actual
    display position may not exactly equal the coordinates given in the
    LeftEdge and TopEdge fields of the Screen structure.  This can cause
    a window which is opened in the visible part of the screen to be
    incorrectly positioned by a few pixels in each direction.  This
    complication is due to hardware constraints that limit the fineness
    of screen positioning.  For instance, [high resolution](libraries/3-intuition-screens-types-of-screens.md) screens can
    only be positioned in [low resolution](libraries/3-intuition-screens-types-of-screens.md) pixel coordinates, yet the
    values in the LeftEdge and TopEdge use high resolution pixel
    coordinates.  So when the screen is displayed, its position is
    rounded to a position available for the monitor.
```
MouseX, MouseY

    Position of the mouse with respect to the upper left corner of the
    screen.
ViewPort, RastPort, BitMap, LayerInfo

```c
    Actual instances of the graphics library [data structures](libraries/3-intuition-screens-screen-data-structures.md) associated
    with this screen (not pointers to structures).  For normal use of
    [custom screens](libraries/3-intuition-screens-custom-screen-functions.md), these structures may be ignored.
```
BarLayer

```c
    A pointer to the [Layer](libraries/30-layers-the-layer-structure.md) structure for the screen's [title bar](libraries/3-types-of-screens-screen-components.md).
```
WBorTop, WBorLeft, WBorRight, WBorBottom

```c
    Window border values, see the "[Intuition Windows](libraries/4-basic-window-structures-and-functions-window-border.md)" chapter for
    information on pre-calculating the size of window borders for windows
    that open in this screen.
```
Font

```c
    The default screen font, this can be used to pre-calculate the size
    of the [window borders](libraries/4-window-structures-and-functions-graphics-and-text-in.md) for windows that open in this screen.
```
UserData

    Free for application use.
Other Screen structure members provide information on the title bar layer,
and attributes of [menus](libraries/6-setting-up-menus-menu-layout.md) and [windows](libraries/4-window-structures-and-functions-graphics-and-text-in.md) opened in the screen.  Of particular
interest are the values that allow precalculation of window border size.
These variables will be discussed in the chapter "[Intuition Windows](libraries/4-basic-window-structures-and-functions-window-border.md)".

---

## See Also

- [MoveScreen — intuition.library](../autodocs/intuition.library.md#movescreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
