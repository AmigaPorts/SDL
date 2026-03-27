# 27 / / / Run-Time Name Binding of Mode Information


It is useful to associate common names with the various display modes.
The Release 2 graphics library includes a provision for binding a name to
a display mode so that it will be available via a query.  This will be
useful in the implementation of a standard screen-format requester.  Note
however that no names are bound initially since the bound names will take
up RAM at all times.  Instead defaults are used.

Bound names will override the defaults though, so that, until the
screen-format requester is localized to a non-English language, the modes
can be localized by binding foreign language names to them.  Here is an
example of how to query the run-time name binding of a given mode from a
[DisplayInfoHandle](../Includes_and_Autodocs_2._guide/node00BD.html#line32).


#include <graphics/displayinfo.h>

check_name_bound( handle )
DisplayInfoHandle handle;
{
```c
    struct NameInfo query;

    /* fill the buffer with Mode dimension information */

    if(GetDisplayInfoData(handle, (UBYTE *)&query,sizeof(query),
       DTAG_NAME,NULL)))
    {
        printf("%s", query.Name);
    }
```
}

