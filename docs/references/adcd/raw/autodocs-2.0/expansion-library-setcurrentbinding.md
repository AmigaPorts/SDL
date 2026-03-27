# expansion.library/SetCurrentBinding



NAME

    SetCurrentBinding - sets static board configuration area
SYNOPSIS

```c
    SetCurrentBinding( currentBinding, size )
                       A0              D0:16
```
FUNCTION

```c
    This function records the contents of the "currentBinding"
    structure in a private place.  It may be read via
    [GetCurrentBinding()](../Includes_and_Autodocs_2._guide/node03B7.html).  This is really a kludge, but it is
    the only way to pass extra arguments to a newly configured
    device.

    A [CurrentBinding](../Includes_and_Autodocs_2._guide/node00FC.html#line62) structure has the name of the currently
    loaded file, the product string that was associated with
    this driver, and a pointer to the head of a singly linked
    list of [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structures (linked through the cd_NextCD
    field).

    Many devices may not need this information; they have hard
    coded into themselves their manufacture number.  It is
    recommended that you at least check that you can deal with
    the product code in the linked [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structures.
```
INPUTS

```c
    currentBinding - a pointer to a [CurrentBinding](../Includes_and_Autodocs_2._guide/node00FC.html#line62) structure

    size - The size of the user's binddriver structure.  No
        more than this much data will be copied.  If size is
        less than the library's idea a [CurrentBinding](../Includes_and_Autodocs_2._guide/node00FC.html#line62) size,
        then the library's structure will be null padded.
```
SEE ALSO

```c
    [GetCurrentBinding](../Includes_and_Autodocs_2._guide/node03B7.html)
```
