# 14 / / Icon Library Data Structures / The Gadget Structure


To hold the icon's image, Workbench uses an Intuition [Gadget](../Libraries_Manual_guide/node0149.html) structure,
defined in <intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line215)>.  Workbench restricts some of the
values of the gadget.  All unused fields should be set to 0 or NULL.  The
Intuition gadget structure members that Workbench icons use are listed
below.


```c
    Gadget Names in Assembly Language Are Different.
    ------------------------------------------------
    The assembly language version of the [Gadget](../Libraries_Manual_guide/node0149.html) structure has leading
    "gg_" for each variable name.
```
[Width](../Libraries_Manual_guide/node0149.html#line33)

```c
    This is the width (in pixels) of the icon's active region.  Any mouse
    button press within this range will be interpreted as having selected
    this icon.
```
[Height](../Libraries_Manual_guide/node0149.html#line33)

```c
    This is the height (in pixels) of the icon's active region.  Any
    mouse button press within this range will be interpreted as having
    selected this icon.
```
[Flags](../Libraries_Manual_guide/node0149.html#line33)

```c
    The gadget must be of type [GADGIMAGE](../Libraries_Manual_guide/node014A.html#line23).  Three highlight modes are
    supported:   [GADGHCOMP](../Libraries_Manual_guide/node014A.html#line8), [GADGHIMAGE](../Libraries_Manual_guide/node014A.html#line16), and GADGBACKFILL.  GADGHCOMP
    complements everything within the area defined by [CurrentX](../Libraries_Manual_guide/node0241.html#line72), [CurrentY](../Libraries_Manual_guide/node0241.html#line72),
    Width, Height.  GADGHIMAGE uses an alternate selection image.
    GADGBACKFILL is similar to GADGHCOMP, but ensures that there is no
    "ring" around the selected image.  It does this by first
    complementing the image, and then flooding all color 3 pixels that
    are on the border of the image to color 0.  All other flag bits
    should be 0.
```
[Activation](../Libraries_Manual_guide/node0149.html#line53)

```c
    The activation should have only [RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) and [GADGIMMEDIATE](../Libraries_Manual_guide/node014B.html#line9) set.
```
[Type](../Libraries_Manual_guide/node0149.html#line58)

```c
    The gadget type should be [BOOLGADGET](../Libraries_Manual_guide/node0149.html#line63).
```
[GadgetRender](../Libraries_Manual_guide/node0149.html#line91)

```c
    Set this to an appropriate [Image](../Libraries_Manual_guide/node01BA.html) structure.
```
[SelectRender](../Libraries_Manual_guide/node0149.html#line102)

```c
    Set this to an appropriate alternate Image structure if and only if
    the highlight mode is [GADGHIMAGE](../Libraries_Manual_guide/node014A.html#line16).
```
The [Image](../Libraries_Manual_guide/node01BA.html) structure is typically the same size as the gadget, except that
[Height](../Libraries_Manual_guide/node01BA.html#line32) is often one pixel less than the gadget height. This allows a blank
line between the icon image and the icon name. The image depth must be 2;
[PlanePick](../Libraries_Manual_guide/node01BA.html#line63) must be 3; and [PlaneOnOff](../Libraries_Manual_guide/node01BA.html#line69) should be 0. The [NextImage](../Libraries_Manual_guide/node01BA.html#line74) field
should be null.

