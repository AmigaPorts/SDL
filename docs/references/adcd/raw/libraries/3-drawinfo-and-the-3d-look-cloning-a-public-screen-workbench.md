# 3 / DrawInfo and the 3D Look / Cloning a Public Screen (Workbench)


User preferences for screen attributes are generally reflected in the
Workbench screen or in the default [public screen](../Libraries_Manual_guide/node00E6.html).  In some cases it may be
useful to create a new screen with the same attributes.

Under V34, information on a screen was available through the
[GetScreenData()](../Libraries_Manual_guide/node00FC.html#line20) call.  Due to extensions in V36 screen and graphics
capabilities, this call is no longer sufficient to completely describe the
display.  Applications should now use a variety of calls; the specific
call depends on the information required.

[LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34) returns a pointer to the Screen structure of a specific
screen.  [GetScreenDrawInfo()](../Libraries_Manual_guide/node00EE.html#line16) returns rendering information on the screen,
such as the pen array and font used.  [QueryOverscan()](../Libraries_Manual_guide/node00F0.html#line76) returns the overscan
information of a specific display mode (for more information, see the
section on "[Overscan and the Display Clip](../Libraries_Manual_guide/node00F0.html)").

The example below shows how to use [GetScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0220.html) to examine the
attributes of the Workbench screen so that a new screen with the same
attributes can be created.


```c
    struct DrawInfo *GetScreenDrawInfo( struct Screen * )
```
The attributes required to clone an existing screen are its width, height,
depth, pens and mode.  The pens and screen depth are available through the
[DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) structure.  The width and height may be obtained from the [Screen](../Libraries_Manual_guide/node00DE.html#line6)
structure.  (The width and height may be larger than the overscan area if
the screen is scrollable, and autoscroll may always be enabled as it does
not effect displays smaller than or equal to the overscan area.)

The screen's display mode can be obtained using the graphics library call
[GetVPModeID()](../Libraries_Manual_guide/node033C.html#line19).  This call returns the display ID of an existing screen
which can then be used as the data for the [SA_DisplayID](../Libraries_Manual_guide/node00E5.html#line74) tag in
[OpenScreenTagList()](../Libraries_Manual_guide/node00DF.html#line6).  Note that the example assumes the screen should be
open to the user's text overscan preference.  If an exact copy of the
display clip of the existing screen is required, use the [VideoControl()](../Libraries_Manual_guide/node0339.html#line15)
command of the graphics library to access the [ViewPortExtra](../Includes_and_Autodocs_2._guide/node00B8.html#line78) structure.

The colors of the screen may be copied using the graphics library calls
[GetRGB4()](../Libraries_Manual_guide/node0331.html#line41), [SetRGB4()](../Libraries_Manual_guide/node0331.html), [SetRGB4CM()](../Libraries_Manual_guide/node0331.html#line41) and [LoadRGB4()](../Libraries_Manual_guide/node0331.html#line41).  The example code does
not copy the colors.

The example copies the font from the cloned screen.  A reasonable
alternative would be to use the user's preference font, which may be
accessed through the [SA_SysFont](../Libraries_Manual_guide/node00E5.html#line130) tag.


```c
     [clonescreen.c](../Libraries_Manual_guide/node05B2.html) 
```
