# utility.library/Date2Amiga



NAME

```c
    Date2Amiga -- Calculate seconds from 01-Jan-1978.  (V36)
```
SYNOPSIS

```c
    AmigaTime = Date2Amiga( Date )
    D0                      A0

    ULONG Date2Amiga( struct [ClockData](../Includes_and_Autodocs_2._guide/node012C.html#line18) * );
```
FUNCTION

```c
    Calculates the number of seconds from 01-Jan-1978 to the date
    specified in the [ClockData](../Includes_and_Autodocs_2._guide/node012C.html#line18) structure.
```
INPUTS

```c
    Date            - pointer to a [ClockData](../Includes_and_Autodocs_2._guide/node012C.html#line18) structure containing the
                      date of interest.
```
RESULTS

    AmigaTime       - the number of seconds from 01-Jan-1978 to the
                      date specified in Date.
NOTES

    This function does no sanity checking of the data in Date.
SEE ALSO

```c
    [Amiga2Date()](../Includes_and_Autodocs_2._guide/node03CF.html), [CheckDate()](../Includes_and_Autodocs_2._guide/node03D1.html)
```
BUGS

