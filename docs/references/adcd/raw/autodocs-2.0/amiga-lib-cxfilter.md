# amiga.lib/CxFilter



NAME

```c
    CxFilter -- create a commodity filter object. (V36)
```
SYNOPSIS

```c
    filterObj = CxFilter(description);

    CxObj *CxFilter(STRPTR)
```
FUNCTION

```c
    Creates an input event filter object that matches the
    'description' string. If 'description' is NULL, the filter will not
    match any messages.

    A filter may be modified by the functions [SetFilter()](../Includes_and_Autodocs_2._guide/node01B3.html), using
    a description string, and [SetFilterIX()](../Includes_and_Autodocs_2._guide/node01B4.html), which takes a
    binary Input Expression as a parameter.

    This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html), defined
    in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html).
```
INPUTS

```c
    description - the description string in the same format as strings
                  expected by [commodities.library/SetFilter()](../Includes_and_Autodocs_2._guide/node01B3.html)
```
RESULTS

```c
    filterObj - a pointer to the filter object, or NULL if there
                was not enough memory. If there is a problem in the
                description string, the internal error code of the filter
                object will be set to so indicate. This error code may be
                interrogated using the function [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html).
```
SEE ALSO

```c
    [commodities.library/CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html), [commodities.library/SetFilter()](../Includes_and_Autodocs_2._guide/node01B3.html),
    [commodities.library/SetFilterIX()](../Includes_and_Autodocs_2._guide/node01B4.html), [commodities.library/CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html)
```
