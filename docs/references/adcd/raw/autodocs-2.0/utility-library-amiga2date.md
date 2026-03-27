# utility.library/Amiga2Date



NAME

```c
    Amiga2Date -- Calculate the date from a timestamp.  (V36)
```
SYNOPSIS

```c
    Amiga2Date( AmigaTime, Date )
                D0         A0

    void Amiga2Date( ULONG, struct [ClockData](../Includes_and_Autodocs_2._guide/node012C.html#line18) * );
```
FUNCTION

```c
    Fills in a [ClockData](../Includes_and_Autodocs_2._guide/node012C.html#line18) structure with the date and time calculated
    from a ULONG containing the number of seconds from 01-Jan-1978
    to the date.
```
INPUTS

    AmigaTime       - the number of seconds from 01-Jan-1978.
RESULTS

    Date            - filled in with the date/time specified by
                      AmigaTime.
NOTES

SEE ALSO

```c
    [CheckDate()](../Includes_and_Autodocs_2._guide/node03D1.html), [Date2Amiga()](../Includes_and_Autodocs_2._guide/node03D3.html)
```
BUGS

