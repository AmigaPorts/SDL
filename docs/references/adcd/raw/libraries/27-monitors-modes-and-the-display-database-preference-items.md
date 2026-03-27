# 27 / / Monitors, Modes and the Display Database / Preference Items


Some display information is changed in response to user Preference
specification.  Until further notice, this will be reserved as a system
activity and use private interface methods.

One Preferences setting that may affect the display data is the user's
preferred overscan limits to the monitor associated with this mode.  Here
is an example of how to query the overscan dimensions of a given mode from
a [DisplayInfoHandle](../Includes_and_Autodocs_2._guide/node00BD.html#line32).


 #include <graphics/displayinfo.h>

check_overscan( handle )
DisplayInfoHandle handle;
{
```c
    struct DimensionInfo query;

    /* fill the buffer with Mode dimension information */

    if(GetDisplayInfoData(handle, (UBYTE *)&query,sizeof(query),
       DTAG_DIMS,NULL)))
    {
        /* display standard overscan dimensions of this Mode */

        printf("overscan width  = %ld",
                query.StdOScan.MaxX - query.StdOScan.MinX + 1);

        printf("overscan height = %ld",
                query.StdOScan.MaxY - query.StdOScan.MinY + 1);
    }
```
}

