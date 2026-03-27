# icon.library/AddFreeList



NAME

    AddFreeList - add memory to a free list.
SYNOPSIS

```c
    status = AddFreeList(free, mem, len)
      D0                  A0    A1   A2

    BOOL AddFreeList(struct [FreeList](../Includes_and_Autodocs_2._guide/node0135.html#line82) *, APTR, ULONG);
```
FUNCTION

```c
    This routine adds the specified memory to the free list.
    The free list will be extended (if required).  If there
    is not enough memory to complete the call, a null is returned.

    Note that AddFreeList does NOT allocate the requested memory.
    It only records the memory in the free list.
```
INPUTS

```c
    free -- a pointer to a [FreeList](../Includes_and_Autodocs_2._guide/node0135.html#line82) structure
    mem -- the base of the memory to be recorded
    len -- the length of the memory to be recorded
```
RESULTS

```c
    status -- TRUE if the call succeeded else FALSE;
```
SEE ALSO

```c
    [AllocEntry()](../Includes_and_Autodocs_2._guide/node0331.html), [FreeEntry()](../Includes_and_Autodocs_2._guide/node0354.html), [FreeFreeList()](../Includes_and_Autodocs_2._guide/node0188.html)
```
BUGS

    None
