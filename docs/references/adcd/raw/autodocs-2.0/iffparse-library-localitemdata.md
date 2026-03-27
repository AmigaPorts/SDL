# iffparse.library/LocalItemData



NAME

    LocalItemData -- Get pointer to user data for local context item.
SYNOPSIS

```c
    data = LocalItemData (lci)
     d0                   a0

    UBYTE                   *data;
    struct [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82)   *lci;
```
FUNCTION

```c
    Returns pointer to the user data associated with the given local
    context item.  The size of the data area depends on the "usize"
    argument used when allocating this item.  If the pointer to the item
    given (lci) is NULL, the function also returns NULL.
```
INPUTS

    lci     - pointer to local context item or NULL.
RESULT

    data    - pointer to user data area or NULL if lci is NULL.
EXAMPLE

NOTES

BUGS

```c
    Currently, there is no way to determine the size of the user data
    area; you have to 'know'.
```
SEE ALSO

```c
    [AllocLocalItem()](../Includes_and_Autodocs_2._guide/node01B9.html), [FreeLocalItem()](../Includes_and_Autodocs_2._guide/node01C6.html)
```
