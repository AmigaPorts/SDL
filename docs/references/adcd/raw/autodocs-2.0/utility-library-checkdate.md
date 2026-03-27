# utility.library/CheckDate



NAME

```c
    CheckDate -- Checks [ClockData](../Includes_and_Autodocs_2._guide/node012C.html#line18) struct for legal date. (V36)
```
SYNOPSIS

```c
    AmigaTime = CheckDate( Date )
    D0                     A0

    ULONG CheckDate( struct [ClockData](../Includes_and_Autodocs_2._guide/node012C.html#line18) * );
```
FUNCTION

    Determines if the Date is a legal date and returns the number
    of seconds to Date from 01-Jan-1978 if it is.
INPUTS

```c
    Date            - pointer to a [ClockData](../Includes_and_Autodocs_2._guide/node012C.html#line18) structure.
```
RESULTS

```c
    AmigaTime       - 0 if Date invalid; otherwise, the number of
                      seconds to Date from 01-Jan-1978.
```
NOTES

BUGS

```c
    The wday field of the [ClockData](../Includes_and_Autodocs_2._guide/node012C.html#line18) structure is not checked.
```
SEE ALSO

```c
    [Amiga2Date()](../Includes_and_Autodocs_2._guide/node03CF.html), [Date2Amiga()](../Includes_and_Autodocs_2._guide/node03D3.html)
```
