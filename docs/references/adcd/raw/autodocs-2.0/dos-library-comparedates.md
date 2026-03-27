# dos.library/CompareDates



NAME

```c
    CompareDates -- Compares two datestamps (V36)
```
SYNOPSIS

```c
    result = CompareDates(date1,date2)
    D0                     D1     D2

    LONG CompareDates(struct [DateStamp](../Includes_and_Autodocs_2._guide/node0068.html#line53) *,struct [DateStamp](../Includes_and_Autodocs_2._guide/node0068.html#line53) *)
```
FUNCTION

    Compares two times for relative magnitide.  <0 is returned if date1 is
    later than date2, 0 if they are equal, or >0 if date2 is later than
    date1.  NOTE: this is NOT the same ordering as strcmp!
INPUTS

    date1, date2 - DateStamps to compare
RESULT

    result -  <0, 0, or >0 based on comparison of two date stamps
SEE ALSO

```c
    [DateStamp()](../Includes_and_Autodocs_2._guide/node0290.html), [DateToStr()](../Includes_and_Autodocs_2._guide/node0291.html), [StrToDate()](../Includes_and_Autodocs_2._guide/node0302.html)
```
