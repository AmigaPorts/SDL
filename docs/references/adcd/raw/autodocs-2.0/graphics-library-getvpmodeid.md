# graphics.library/GetVPModeID



NAME

```c
    GetVPModeID -- get the 32 bit DisplayID from a [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40). (V36)
```
SYNOPSIS

```c
    modeID =  GetVPModeID( vp )
    d0                     a0

    ULONG GetVPModeID( struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) *);
```
FUNCTION

```c
    returns the normal display modeID, if one is currently  associated
    with this [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40).
```
INPUTS

```c
    vp -- pointer to a [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure.
```
RESULT


```c
    modeID -- a 32 bit DisplayInfoRecord identifier associated with
              this [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40), or INVALID_ID.
```
NOTES

```c
    Test the return value of this function against INVALID_ID, not NULL.
    (INVALID_ID is defined in [graphics/displayinfo.h)](../Includes_and_Autodocs_2._guide/node00BD.html).
```
BUGS

SEE ALSO

```c
    [graphics/displayinfo.h](../Includes_and_Autodocs_2._guide/node00BD.html), [ModeNotAvailable()](../Includes_and_Autodocs_2._guide/node045C.html)
```
