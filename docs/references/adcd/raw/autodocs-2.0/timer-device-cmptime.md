# timer.device/CmpTime



NAME

```c
    CmpTime -- Compare two [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structures.
```
SYNOPSIS

```c
    result = CmpTime( Dest, Source )
    D0                A0    A1

    LONG CmpTime( struct [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) *, struct [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) *);
```
FUNCTION

```c
    This routine compares [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structures

    A0 and A1 will be left unchanged
```
INPUTS

```c
    Dest, Source -- pointers to [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structures.
```
RESULTS

    result will be   0 if Dest has same time as source
                    -1 if Dest has more time than source
                    +1 if Dest has less time than source
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/AddTime()](../Includes_and_Autodocs_2._guide/node04F8.html),
    [timer.device/SubTime()](../Includes_and_Autodocs_2._guide/node04FC.html)
```
BUGS

```c
    Older version of this document had the sense of the return
    codes wrong; the code hasn't changed but the document has.
```
