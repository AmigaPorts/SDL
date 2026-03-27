# iffparse.library/AllocLocalItem



NAME

    AllocLocalItem -- Create a local context item structure.
SYNOPSIS

```c
    item = AllocLocalItem (type, id, ident, usize)
     d0                     d0   d1   d2     d3

    struct [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82) *item;
    LONG                    type, id, ident, usize;
```
FUNCTION

```c
    Allocates and initializes a [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82) structure with "usize"
    bytes of associated user data.  This is the only supported way to
    create such an item.  The user data can be accessed with the
    [LocalItemData](../Includes_and_Autodocs_2._guide/node01CD.html) function.  An item created with this function
    automatically has its purge vectors set up correctly to dispose of
    itself and its associated user data area.  Any additional cleanup
    should be done with a user-supplied purge vector.
```
INPUTS

    type,id - additional longword identification values.
    ident   - longword identifier for class of context item.
    usize   - number of bytes of user data to allocate for this item.
RESULT

```c
    item    - pointer to initialized [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82) or NULL if the
              allocation failed.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [FreeLocalItem()](../Includes_and_Autodocs_2._guide/node01C6.html), [LocalItemData()](../Includes_and_Autodocs_2._guide/node01CD.html), [StoreLocalItem()](../Includes_and_Autodocs_2._guide/node01DD.html),
    [StoreItemInContext()](../Includes_and_Autodocs_2._guide/node01DC.html), [SetLocalItemPurge()](../Includes_and_Autodocs_2._guide/node01D8.html)
```
