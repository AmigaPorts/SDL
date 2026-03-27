# 20 / / Summary of System Controlled Memory Handling Routines


[AllocMem()](../Libraries_Manual_guide/node02A7.html) and [FreeMem()](../Libraries_Manual_guide/node02A7.html#line11)

    These are system-wide memory allocation and deallocation routines.
    They use a memory free-list owned and managed by the system.
[AvailMem()](../Libraries_Manual_guide/node02AD.html)

    This routine returns the number of free bytes in a specified type of
    memory.
[TypeOfMem()](../Libraries_Manual_guide/node02AD.html#line14)

    This routine returns the memory attributes of a specified memory
    address.
[CopyMem()](../Libraries_Manual_guide/node02AF.html)/[CopyMemQuick()](../Libraries_Manual_guide/node02AF.html#line16)

```c
    CopyMem() is a general purpose memory copy routine. CopyMemQuick() is
    an optimized version of CopyMemQuick(), but has restrictions on the
    size and alignment of the arguments.
```
