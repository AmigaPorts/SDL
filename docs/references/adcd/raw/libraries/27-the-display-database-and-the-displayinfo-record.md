# 27 / / / The Display Database and the DisplayInfo Record


For each ModeID, the graphics library has a body of data that enables the
set up of the display hardware and provides applications with information
about the properties of the display mode.

The display information in the database is accessed by searching it for a
record with a given ModeID.  For performance reasons, a look-up function
named [FindDisplayInfo()](../Includes_and_Autodocs_2._guide/node043B.html) is provided which, given a ModeID, will return a
handle to the internal data record about the attributes of the display.

This handle is then used for queries to the display database and
specification of display mode to the low-level graphics routines.  It is
never used as a pointer.  The private data structure associated with a
given ModeID is called a [DisplayInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line49).  From the <graphics/[displayinfo.h](../Includes_and_Autodocs_2._guide/node00BD.html#line30)>
include file:


```c
    /* the "public" handle to a DisplayInfo  */

     typedef APTR DisplayInfoHandle;
```
In order to obtain database information about an existing [ViewPort](../Libraries_Manual_guide/node032B.html#line59), you
must first gain reference to its 32-bit ModeID.  A graphics function
[GetVPModeID()](../Includes_and_Autodocs_2._guide/node044A.html) simplifies this operation:


```c
    modeID = ULONG GetVPModeID(struct ViewPort *vp )
```
The vp argument is pointer to a [ViewPort](../Libraries_Manual_guide/node032B.html#line59) structure.  This function returns
the normal display ModeID, if one is currently associated with this
ViewPort.  If no ModeID exists this function returns INVALID_ID.

Each new valid 32-bit ModeID is associated with data initialized by the
graphics library at powerup.  This data is accessed by obtaining a handle
to it with the graphics function [FindDisplayInfo()](../Includes_and_Autodocs_2._guide/node043B.html).


```c
    handle = DisplayInfoHandle FindDisplayInfo(ULONG modeID);
```
Given a 32-bit ModeID key (modeID in the prototype above)
[FindDisplayInfo()](../Includes_and_Autodocs_2._guide/node043B.html) returns a handle to a valid [DisplayInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line49) Record found in
the graphics database, or NULL.  Using this handle, you can obtain
information about this video mode, including its default dimensions,
properties and whether it is currently available for use.

For instance, you can use a [DisplayInfoHandle](../Includes_and_Autodocs_2._guide/node00BD.html#line32) with the [GetDisplayInfoData()](../Libraries_Manual_guide/node033D.html)
function to look up the properties of a mode ([see below](../Libraries_Manual_guide/node033D.html)).  Or use the
DisplayInfoHandle with [VideoControl()](../Libraries_Manual_guide/node0339.html#line15) and the [VTAG_NORMAL_DISP_SET](../Libraries_Manual_guide/node0339.html#line44) tag to
set up a custom [ViewPort](../Libraries_Manual_guide/node032B.html#line59).

