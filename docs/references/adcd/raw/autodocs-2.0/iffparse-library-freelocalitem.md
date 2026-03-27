# iffparse.library/FreeLocalItem



NAME

    FreeLocalItem -- Deallocate a local context item structure.
SYNOPSIS

```c
    FreeLocalItem (lci)
                   a0

    struct [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82) *lci;
```
FUNCTION

```c
    Frees the memory for the local context item and any associated user
    memory as allocated with [AllocLocalItem](../Includes_and_Autodocs_2._guide/node01B9.html).  User purge vectors should
    call this function after they have freed any other resources
    associated with this item.

    Note that FreeLocalItem() does NOT call the custom purge vector set
    up through SetLocalItemPurge(); all it does is free the local context
    item.  (This implies that your custom purge vector would want to call
    this to ultimately free the LocalContextItem.)  (This description
    still seems muddy; how to clear it up?)
```
INPUTS

```c
    lci     - pointer to [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82) created with [AllocLocalItem](../Includes_and_Autodocs_2._guide/node01B9.html).
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [AllocLocalItem()](../Includes_and_Autodocs_2._guide/node01B9.html)
```
