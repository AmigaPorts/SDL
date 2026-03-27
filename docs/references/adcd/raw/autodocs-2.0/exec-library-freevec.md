# exec.library/FreeVec



NAME

```c
    FreeVec -- return [AllocVec()](../Includes_and_Autodocs_2._guide/node0335.html) memory to the system  (V36)
```
SYNOPSIS

```c
    FreeVec(memoryBlock)
            A1

    void FreeVec(void *);
```
FUNCTION

```c
    Free an allocation made by the [AllocVec()](../Includes_and_Autodocs_2._guide/node0335.html) call.  The memory will
    be returned to the system pool from which it came.
```
NOTE

```c
    If a block of memory is freed twice, the system will Guru. The
    Alert is AN_FreeTwice ($01000009).   If you pass the wrong pointer,
    you will probably see AN_MemCorrupt $01000005.  Future versions may
    add more sanity checks to the memory lists.
```
INPUTS

    memoryBlock - pointer to the memory block to free, or NULL.
SEE ALSO

```c
    [AllocVec](../Includes_and_Autodocs_2._guide/node0335.html)
```
