# 27 / / Monitors, Modes and Display Database / Accessing DisplayInfo


Basic information about a display can be obtained by calling the Release 2
graphics function [GetDisplayInfoData()](../Includes_and_Autodocs_2._guide/node0446.html).  You also call this function
during the set up of a [ViewPort](../Libraries_Manual_guide/node032B.html#line59).

   result = ULONG GetDisplayInfoData( DisplayInfoHandle handle, UBYTE *buf,

```c
                                  ULONG size, ULONG tagID, ULONG modeID )
```
Set the handle argument to the [DisplayInfoHandle](../Includes_and_Autodocs_2._guide/node00BD.html#line32) returned by a previous
call to [FindDisplayInfo()](../Libraries_Manual_guide/node033C.html#line4).  This function will also accept a 32-bit ModeID
directly as an argument.  The handle argument should be set to NULL in
that case.

The buf argument points to a destination buffer you have set up to hold
the information about the properties of the display.  The size argument
gives the size of the buffer which depends on the type of inquiry you make.

The tagID argument specifies the type information you want to know about
and may be set as follows:


```c
    DTAG_DISP  Returns display properties and availability information
               (the buffer should be set to the size of a [DisplayInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line49)
               structure).

    DTAG_DIMS  Returns default dimensions and overscan information (the
               buffer should be set to the size of a [DimensionInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line91)
               structure).

    DTAG_MNTR  Returns monitor type, view position, scan rate, and
               compatibility (the buffer should be set to the size of a
               [MonitorInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line108) structure).

    DTAG_NAME  Returns the user friendly name for this mode (the buffer
               should be set to the size of a [NameInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line133) structure).
```
If the call succeeds, result is positive and reports the number of bytes
actually transferred to the buffer.  If the call fails (no information for
the ModeID was available), result is zero.

