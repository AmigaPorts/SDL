# expansion.library/GetCurrentBinding



NAME

    GetCurrentBinding - sets static board configuration area
SYNOPSIS

```c
    actual = GetCurrentBinding( currentBinding, size )
                                A0              D0:16
```
FUNCTION

```c
    This function writes the contents of the "currentBinding"
    structure out of a private place.  It may be set via
    [SetCurrentBinding()](../Includes_and_Autodocs_2._guide/node03BE.html).  This is really a kludge, but it is
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

    size - The size of the user's binddriver structure.
        Do not pass in less than sizeof(struct CurrentBinding).
```
RESULTS

```c
    actual - the true size of a [CurrentBinding](../Includes_and_Autodocs_2._guide/node00FC.html#line62) structure is returned.
```
SEE ALSO

    GetCurrentBinding
