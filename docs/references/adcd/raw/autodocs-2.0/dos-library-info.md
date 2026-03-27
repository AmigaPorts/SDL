# dos.library/Info



NAME

    Info -- Returns information about the disk
SYNOPSIS

```c
    success = Info( lock, parameterBlock )
    D0              D1    D2

    BOOL Info(BPTR, struct [InfoData](../Includes_and_Autodocs_2._guide/node0068.html#line118) *)
```
FUNCTION

```c
    Info() can be used to find information about any disk in use.
    'lock' refers to the disk, or any file on the disk. The parameter
    block is returned with information about the size of the disk,
    number of free blocks and any soft errors.
```
INPUTS

```c
    lock           - BCPL pointer to a lock
    parameterBlock - pointer to an [InfoData](../Includes_and_Autodocs_2._guide/node0068.html#line118) structure
                     (longword aligned)
```
RESULTS

    success - boolean
SPECIAL NOTE:

```c
    Note that [InfoData](../Includes_and_Autodocs_2._guide/node0068.html#line118) structure must be longword aligned.
```
