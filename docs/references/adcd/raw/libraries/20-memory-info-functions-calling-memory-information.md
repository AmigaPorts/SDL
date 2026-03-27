# 20 / / Memory Info Functions / Calling Memory Information Functions


The following example shows how to find out how much memory of a
particular type is available.


```c
    ULONG size;

    size = AvailMem(MEMF_CHIP|MEMF_LARGEST);
```
[AvailMem()](../Includes_and_Autodocs_2._guide/node0337.html) returns the size of the largest chunk of available chip memory.


```c
    [AvailMem()](../Includes_and_Autodocs_2._guide/node0337.html) May Not Be Totally Accurate.
    ---------------------------------------
    Because of multitasking, the return value from AvailMem() may be
    inaccurate by the time you receive it.
```
The following example shows how to determine the type of memory of a
specified memory address.


```c
    ULONG memtype;

    memtype = TypeOfMem((APTR)0x090000);
    if ((memtype & MEMF_CHIP) == MEMF_CHIP) {/* ...It's chip memory... */}
```
[TypeOfMem()](../Includes_and_Autodocs_2._guide/node0387.html) returns the attributes of the memory at a specific address. If
it is passed an invalid memory address, TypeOfMem() returns NULL. This
routine is normally used to determine if a particular chunk of memory is
in chip memory.

