# 11 Intuition Special Functions / Current Time Values


The function [CurrentTime()](../Includes_and_Autodocs_2._guide/node020A.html) gets the current time values.  To use this
function, first declare the variables Seconds and Micros.  Then, when the
application call the function, the current time is copied into the
argument pointers.


```c
    void CurrentTime( ULONG *seconds, ULONG *micros );
```
See the DOS library Autodocs in the AmigaDOS Manual (Bantam Books) for
more information on functions dealing with the date and time.  The DOS
library includes such functions as [DateToStr()](../Includes_and_Autodocs_2._guide/node0291.html), [StrToDate()](../Includes_and_Autodocs_2._guide/node0302.html), [SetFileDate()](../Includes_and_Autodocs_2._guide/node02F5.html)
and [CompareDates()](../Includes_and_Autodocs_2._guide/node028B.html).

