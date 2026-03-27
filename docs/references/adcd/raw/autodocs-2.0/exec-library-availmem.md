# exec.library/AvailMem



NAME

    AvailMem -- memory available given certain requirements
SYNOPSIS

```c
    size = AvailMem(attributes)
    D0              D1

    ULONG AvailMem(ULONG);
```
FUNCTION

    This function returns the amount of free memory given certain
    attributes.

    To find out what the largest block of a particular type is, add
    MEMF_LARGEST into the requirements argument.  Returning the largest
    block is a slow operation.
WARNING

    Due to the effect of multitasking, the value returned may not
    actually be the amount of free memory available at that instant.
INPUTS

```c
    requirements - a requirements mask as specified in [AllocMem](../Includes_and_Autodocs_2._guide/node0332.html).  Any
                   of the [AllocMem](../Includes_and_Autodocs_2._guide/node0332.html) bits are valid, as is MEMF_LARGEST
                   which returns the size of the largest block matching
                   the requirements.
```
RESULT

```c
    size - total free space remaining (or the largest free block).
```
NOTE

```c
    For V36 Exec, AvailMem(MEMF_LARGEST) does a consistency check on
    the memory list.  Alert AN_MemoryInsane will be pulled if any mismatch
    is noted.
```
EXAMPLE

```c
    AvailMem(MEMF_CHIP|MEMF_LARGEST);
    /* return size of largest available chip memory chunk */
```
SEE ALSO

```c
    [exec/memory.h](../Includes_and_Autodocs_2._guide/node0089.html)
```
