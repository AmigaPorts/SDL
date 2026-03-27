# expansion.library/FreeExpansionMem



NAME

    FreeExpansionMem - allocate standard device expansion memory
SYNOPSIS

```c
    FreeExpansionMem( startSlot, numSlots )
                      D0         D1
```
FUNCTION

```c
    (Not typically called by user code)

    This function allocates numslots of expansion space (each slot
    is E_SLOTSIZE bytes).  It is the inverse function of
    [AllocExpansionMem()](../Includes_and_Autodocs_2._guide/node03B2.html).
```
INPUTS

    startSlot - the slot number that was allocated, or -1 for error.
    numSlots - the number of slots to be freed.
RESULTS

EXAMPLES

EXCEPTIONS

```c
    If the caller tries to free a slot that is already in the
    free list, FreeExpansionMem will [Alert()](../Includes_and_Autodocs_2._guide/node032E.html) (e.g. crash the
    system).
```
SEE ALSO

```c
    [AllocExpansionMem](../Includes_and_Autodocs_2._guide/node03B2.html)
```
BUGS

