# timer.device/SubTime



NAME

    SubTime -- Subtract one time request from another.
SYNOPSIS

```c
    SubTime( Dest, Source )
             A0    A1

    void SubTime( struct [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) *, struct [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) *);
```
FUNCTION

```c
    This routine subtracts one [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structure from another.  The
    results are stored in the destination (Dest - Source -> Dest)

    A0 and A1 will be left unchanged
```
INPUTS

```c
    Dest, Source -- pointers to [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structures.
```
NOTES

    This function may be called from interrupts.
SEE ALSO

```c
    [timer.device/AddTime()](../Includes_and_Autodocs_2._guide/node04F8.html),
    [timer.device/CmpTime()](../Includes_and_Autodocs_2._guide/node04F9.html)
```
BUGS

