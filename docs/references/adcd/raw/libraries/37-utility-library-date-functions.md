# 37 Utility Library / Date Functions


To ease date-related calculations, the utility library has some functions
to convert a date, specified in a ClockData structure, in the number of
seconds since 00:00:00 01-Jan-78 and vice versa. To indicate the date, the
ClockData structure (in <utility/[date.h](../Includes_and_Autodocs_2._guide/node012C.html#line18)>) is used.


```c
    struct ClockData
    {
        UWORD sec;     /* seconds (0 - 59)*/
        UWORD min;     /* minutes (0 - 59) */
        UWORD hour;    /* hour (0 - 23) */
        UWORD mday;    /* day of the month (1 - 31) */
        UWORD month;   /* month of the year (1 - 12)
        UWORD year;    /* 1978 - */
        UWORD wday;    /* day of the week (0 - 6, where 0 is Sunday) */
    };
```
The following functions are available to operate on ClockData:

  ________________________________________________________________
 |                                                                |
 | [Amiga2Date()](../Includes_and_Autodocs_2._guide/node03CF.html)  Calculate the date from the specified timestamp  |
 |               (in seconds).                                    |
 |  [CheckDate()](../Includes_and_Autodocs_2._guide/node03D1.html)  Check the legality of a date.                    |
 | [Date2Amiga()](../Includes_and_Autodocs_2._guide/node03D3.html)  Calculate the timestamp from the specified date. |
 |________________________________________________________________|



            Table 37-5: Utility Library Date Functins
[Amiga2Date()](../Includes_and_Autodocs_2._guide/node03CF.html) takes a number of seconds from 01-Jan-78 as argument and
fills in the supplied ClockData structure with the date and time.

[CheckDate()](../Includes_and_Autodocs_2._guide/node03D1.html) checks if the supplied ClockData structure is valid, and
returns the number of seconds from 01-Jan-78 if it is. Note that this
function currently does not take the supplied day of the week in account.

[Date2Amiga()](../Includes_and_Autodocs_2._guide/node03D3.html) takes a ClockData structure as argument and returns the
number of seconds since 01-Jan-78. The supplied ClockData structure MUST
be valid, since no checking is done.

The following example shows various uses of the utility library date
functions.


```c
     [a2d.c](../Libraries_Manual_guide/node0588.html) 
```
