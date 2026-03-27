# commodities.library/CxObjType



NAME

```c
    CxObjType -- obtain the type of a commodity object. (V36)
```
SYNOPSIS

```c
    type = CxObjType(co);
                     A0

    ULONG CxObjType(CxObj *);
```
FUNCTION

    This function should not really be necessary. It returns
    the type of a commodity object, which you should already
    know, since you created it in the first place.
INPUTS

    co - the commodity object to inquire about
RESULTS

```c
    type - the type of the commodity object, possible values are
           defined in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html)
```
SEE ALSO

```c
    [CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html)
```
