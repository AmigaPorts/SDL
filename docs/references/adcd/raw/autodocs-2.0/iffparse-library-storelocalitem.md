# iffparse.library/StoreLocalItem



NAME

    StoreLocalItem -- Insert a local context item into the context stack.
SYNOPSIS

```c
    error = StoreLocalItem (iff, item, position)
     d0                     a0    a1      d0

    LONG                    error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)  *iff;
    struct [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82)   *item;
    LONG                    position;
```
FUNCTION

```c
    Adds the local context item to the list of items for one of the
    context nodes on the context stack and purges any other item in the
    same context with the same ident, type and id.  The position argument
    determines where in the stack to add the item:

    IFFSLI_ROOT:
            Add item to list at root (default) stack position.
    IFFSLI_TOP:
            Add item to the top (current) context node.
    IFFSLI_PROP:
            Add element in top property context.  Top property context is
            either the top FORM chunk, or the top LIST chunk, whichever
            is closer to the top of the stack.

    Items added to the root context, or added to the top context before
    the [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) has been opened or after it has been closed, are put in
    the default context.  That is, they will be the local items found
    only after all other context nodes have been searched.  Items in the
    default context are also immune to being purged until the [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)
    struct itself is deleted with [FreeIFF()](../Includes_and_Autodocs_2._guide/node01C5.html).  This means that handlers
    installed in the root context will still be there after an [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)
    struct has been opened and closed.  (Note that this implies that
    items stored in a higher context will be deleted when that context
    ends.)
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    item    - pointer to [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82) struct to insert.
    position- where to store the item (IFFSLI_ROOT, _TOP or _PROP).
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [FindLocalItem()](../Includes_and_Autodocs_2._guide/node01C2.html), [StoreItemInContext()](../Includes_and_Autodocs_2._guide/node01DC.html), [EntryHandler()](../Includes_and_Autodocs_2._guide/node01BF.html), [ExitHandler()](../Includes_and_Autodocs_2._guide/node01C0.html)
```
