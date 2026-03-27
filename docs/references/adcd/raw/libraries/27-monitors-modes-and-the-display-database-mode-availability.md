# 27 / / Monitors, Modes and the Display Database / Mode Availability


Even if the video monitor (NTSC, PAL, VGA, A2024) or ECS chips required to
support a given mode are not available, there will be a [DisplayInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line49) for
all of the display modes.  (This will not be the case for disk-based modes
such as Euro36, Euro72, etc.)

Thus, the graphics library provides the [ModeNotAvailable()](../Includes_and_Autodocs_2._guide/node045C.html) function to
determine whether a given mode is available, and if not, why not.  Data
corruption might cause the look-up function, [GetVPModeID()](../Libraries_Manual_guide/node033C.html#line19), to fail even
when it should not, so the careful programmer will always test the look-up
function's return value.


```c
    error =  ULONG ModeNotAvailable( ULONG modeID )
```
The modeID argument is again a 32-bit ModeID as shown in
<graphics/[displayinfo.h](../Includes_and_Autodocs_2._guide/node00BD.html#line152)>.  This function returns an error code, indicating
why this modeID is not available, or NULL if there is no known reason why
this mode should not be there.  The ULONG return values from this function
are a proper superset of the DisplayInfo.NotAvailable field (defined in
<graphics/[displayinfo.h](../Includes_and_Autodocs_2._guide/node00BD.html#line63)>).

The graphics library checks for the presence of the ECS chips at power up,
but the monitor attached to the system cannot be detected and so must be
specified by the user through a separate utility named AddMonitor.

