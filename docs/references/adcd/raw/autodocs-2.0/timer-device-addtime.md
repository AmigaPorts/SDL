# timer.device/AddTime



NAME

    AddTime -- Add one time request to another.
SYNOPSIS

```c
    AddTime( Dest, Source )
             A0    A1

    void AddTime( struct [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) *, struct [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) *);
```
FUNCTION

```c
    This routine adds one [timeval](../Includes_and_Autodocs_2._guide/node0053.html#line26) structure to another.  The
    results are stored in the destination (Dest + Source -> Dest)

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
    [timer.device/CmpTime()](../Includes_and_Autodocs_2._guide/node04F9.html),
    [timer.device/SubTime()](../Includes_and_Autodocs_2._guide/node04FC.html)
```
BUGS

