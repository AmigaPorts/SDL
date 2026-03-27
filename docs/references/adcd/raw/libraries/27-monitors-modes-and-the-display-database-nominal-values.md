# 27 / / Monitors, Modes and the Display Database / Nominal Values


Some of the display information is initialized in ROM for each mode such
as recommended nominal (or default) dimensions.  Even though this
information is presumably static, it would still be a mistake to hardcode
assumptions about these nominal values into your code.

Gathering information about the nominal dimensions of various modes is
handled in a fashion similar to to the basic queries above.  Here is an
example of how to query the nominal dimensions of a given mode from a
[DisplayInfoHandle](../Includes_and_Autodocs_2._guide/node00BD.html#line32).


#include <graphics/displayinfo.h>

check_dimensions( handle )
DisplayInfoHandle handle;
{
```c
    struct DimensionInfo query;

    /* fill the buffer with Mode dimension information */

    if(GetDisplayInfoData(handle, (UBYTE *)&query,sizeof(query),
       DTAG_DIMS,NULL)))
    {
        /* display Nominal dimensions of this Mode */

        printf("nominal width  = %ld",
                query.Nominal.MaxX - query.Nominal.MinX + 1);

        printf("nominal height = %ld",
                query.Nominal.MaxY - query.Nominal.MinY + 1);
    }
```
}

