# 27 / / / Mode Specification, ViewPort Interface


When working directly with graphics, the interface is based on [View](../Libraries_Manual_guide/node032B.html#line51) and
[ViewPort](../Libraries_Manual_guide/node032B.html#line59) structures, rather than on Intuition's [Screen](../Libraries_Manual_guide/node00DE.html#line6) structure.  As
previously mentioned, new information must be associated with the ViewPort
to specify the new Release 2 modes, and also with the View to specify what
virtual monitor the whole View will be displayed on.  There is also a lot
of information to associate with a ViewPort regarding enhanced genlock
capabilities.

This association of this new data with the [View](../Libraries_Manual_guide/node032B.html#line51) is made through a display
database system which has been added to the Release 2 graphics library.
All correctly written programs that allocate a [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) structure for a
[ViewPort](../Libraries_Manual_guide/node032B.html#line59) use the [GetColorMap()](../Libraries_Manual_guide/node0331.html) function to do it.  Hence, in Release 2 the
ColorMap structure is used as the general purpose black box extension of
the ViewPort data.

To set or obtain the data in the extended structures, Release 2 provides a
new function named [VideoControl()](../Includes_and_Autodocs_2._guide/node0488.html) which takes a [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) as an argument.
This allows the setting and getting of the new extended display data.
This mechanism is used to associate a [DisplayInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line49) handle (not a ModeID)
with a [ViewPort](../Libraries_Manual_guide/node032B.html#line59).  A DisplayInfo handle is an abstract link to the display
database area associated with a particular ModeID.  This handle is passed
to the graphics database functions when getting or setting information
about the mode. Using VideoControl(), a program can enable, disable, or
obtain the state of a ViewPort's ColorMap, mode, genlock and other
features.  The function uses a tag based interface and returns NULL if no
error occurred.


```c
    error = BOOL VideoControl( struct ColorMap *cm, struct TagItem *tag );
```
The first argument is a pointer to a [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) structure as returned by the
[GetColorMap()](../Libraries_Manual_guide/node0331.html) function.  The second argument is a pointer to an array of
video control tag items, used to indicate whether information is being
given or requested as well as to pass (or receive the information).  The
tags you can use with [VideoControl()](../Includes_and_Autodocs_2._guide/node0488.html) include the following:

VTAG_ATTACH_CM_GET (or _SET) is used to obtain the [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) structure from
the indicated [ViewPort](../Libraries_Manual_guide/node032B.html#line59) or attach a given ColorMap to it.

VTAG_VIEWPORTEXTRA_GET (or _SET) is used to obtain the [ViewPortExtra](../Libraries_Manual_guide/node032C.html#line16)
structure from the indicated [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) structure or attach a given
ViewPortExtra to it.  A ViewPortExtra structure is an extension of the
[ViewPort](../Libraries_Manual_guide/node032B.html#line59) structure and should be allocated and freed with [GfxNew()](../Libraries_Manual_guide/node032C.html#line22) and
[GfxFree()](../Includes_and_Autodocs_2._guide/node044C.html) and associated with the ViewPort with [VideoControl()](../Includes_and_Autodocs_2._guide/node0488.html).

VTAG_NORMAL_DISP_GET (or _SET) is used to obtain or set the [DisplayInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line49)
structure for the standard or "normal" mode.

See <graphics/[videocontrol.h](../Includes_and_Autodocs_2._guide/node00B0.html#line22)> for a list of all the available tags.  See
the [section on genlocking](../Libraries_Manual_guide/node036C.html) for information on using [VideoControl()](../Includes_and_Autodocs_2._guide/node0488.html) to
interact with the Amiga's genlock capabilities.  Note that the graphics
library will modify the tag list passed to VideoControl().

