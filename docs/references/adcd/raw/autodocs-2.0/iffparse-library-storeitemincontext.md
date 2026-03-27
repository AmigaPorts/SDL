# iffparse.library/StoreItemInContext



NAME

    StoreItemInContext -- Store local context item in given context node.
SYNOPSIS

```c
    StoreItemInContext (iff, item, cn)
                        a0    a1   a2

    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)  *iff;
    struct [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82)   *item;
    struct [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68)        *cn;
```
FUNCTION

```c
    Adds the [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82) to the list of items for the given context
    node.  If an LCI with the same Type, ID, and Ident is already
    present in the [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68), it will be purged and replaced with the
    new one.  This is a raw form of [StoreLocalItem](../Includes_and_Autodocs_2._guide/node01DD.html).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct for this context.
    item    - pointer to a [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82) to be stored.
    cn      - pointer to context node in which to store item.
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [StoreLocalItem()](../Includes_and_Autodocs_2._guide/node01DD.html)
```
