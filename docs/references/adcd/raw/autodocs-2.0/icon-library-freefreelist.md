# icon.library/FreeFreeList



NAME

    FreeFreeList - free all memory in a free list.
SYNOPSIS

```c
    FreeFreeList(free)
                 A0

    void FreeFreeList(struct [FreeList](../Includes_and_Autodocs_2._guide/node0135.html#line82) *);
```
FUNCTION

```c
    This routine frees all memory in a free list, and the
    free list itself.  It is useful for easily getting
    rid of all memory in a series of structures.  There is
    a free list in a Workbench object, and this contains
    all the memory associated with that object.

    A [FreeList](../Includes_and_Autodocs_2._guide/node0135.html#line82) is a list of [MemList](../Includes_and_Autodocs_2._guide/node0089.html#line57) structures.  See the
    [MemList](../Includes_and_Autodocs_2._guide/node0089.html#line57) and [MemEntry](../Includes_and_Autodocs_2._guide/node0089.html#line41) documentation for more information.

    If the [FreeList](../Includes_and_Autodocs_2._guide/node0135.html#line82) itself is in the free list, it must be
    in the first [MemList](../Includes_and_Autodocs_2._guide/node0089.html#line57) in the [FreeList](../Includes_and_Autodocs_2._guide/node0135.html#line82).
```
INPUTS

```c
    free -- a pointer to a [FreeList](../Includes_and_Autodocs_2._guide/node0135.html#line82) structure
```
RESULTS

    None
SEE ALSO

```c
    [AllocEntry()](../Includes_and_Autodocs_2._guide/node0331.html), [FreeEntry()](../Includes_and_Autodocs_2._guide/node0354.html), [AddFreeList()](../Includes_and_Autodocs_2._guide/node0183.html)
```
BUGS

    None
