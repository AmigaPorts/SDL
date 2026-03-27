# 3 / Screen Data Structures / The Intuition Screen Data Structure


The [structures](../Libraries_Manual_guide/node00DC.html#line7) mentioned above are unified along with other information in
Intuition's Screen data structure defined in the include file
<intuition/[screens.h](../Includes_and_Autodocs_2._guide/node00DD.html#line97)>.  Notice that the Screen structure contains
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
use one of the [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) calls.  Here is a description of some of the
more interesting members of the Screen structure (it is not meant to be a
complete description of all the fields).

LeftEdge, TopEdge

```c
    The LeftEdge and TopEdge variables give the position of the screen
    relative to the upper left corner of the monitor's visible display
    (as set by the user in the [Overscan](../Libraries_Manual_guide/node0314.html) [preferences editor](../Libraries_Manual_guide/node0228.html#line8)).  If it is
    positioned down or to the right, the values are positive.  If the
    screen is positioned up or to the left, the values are negative.  The
    values are in screen resolution pixels.  In systems prior to [V36](../Libraries_Manual_guide/node0014.html),
    LeftEdge positioning is ignored and negative TopEdge positions are
    illegal.

    The screen position may be set when the screen is opened or later by
    calling the [MoveScreen()](../Libraries_Manual_guide/node00FB.html) function. Note that the screen's actual
    display position may not exactly equal the coordinates given in the
    LeftEdge and TopEdge fields of the Screen structure.  This can cause
    a window which is opened in the visible part of the screen to be
    incorrectly positioned by a few pixels in each direction.  This
    complication is due to hardware constraints that limit the fineness
    of screen positioning.  For instance, [high resolution](../Libraries_Manual_guide/node00D8.html#line14) screens can
    only be positioned in [low resolution](../Libraries_Manual_guide/node00D8.html#line14) pixel coordinates, yet the
    values in the LeftEdge and TopEdge use high resolution pixel
    coordinates.  So when the screen is displayed, its position is
    rounded to a position available for the monitor.
```
MouseX, MouseY

    Position of the mouse with respect to the upper left corner of the
    screen.
ViewPort, RastPort, BitMap, LayerInfo

```c
    Actual instances of the graphics library [data structures](../Libraries_Manual_guide/node00DC.html) associated
    with this screen (not pointers to structures).  For normal use of
    [custom screens](../Libraries_Manual_guide/node00DF.html), these structures may be ignored.
```
BarLayer

```c
    A pointer to the [Layer](../Libraries_Manual_guide/node03E4.html) structure for the screen's [title bar](../Libraries_Manual_guide/node00DB.html).
```
WBorTop, WBorLeft, WBorRight, WBorBottom

```c
    Window border values, see the "[Intuition Windows](../Libraries_Manual_guide/node010A.html)" chapter for
    information on pre-calculating the size of window borders for windows
    that open in this screen.
```
Font

```c
    The default screen font, this can be used to pre-calculate the size
    of the [window borders](../Libraries_Manual_guide/node0107.html#line14) for windows that open in this screen.
```
UserData

    Free for application use.
Other Screen structure members provide information on the title bar layer,
and attributes of [menus](../Libraries_Manual_guide/node018B.html#line5) and [windows](../Libraries_Manual_guide/node0107.html) opened in the screen.  Of particular
interest are the values that allow precalculation of window border size.
These variables will be discussed in the chapter "[Intuition Windows](../Libraries_Manual_guide/node010A.html)".

