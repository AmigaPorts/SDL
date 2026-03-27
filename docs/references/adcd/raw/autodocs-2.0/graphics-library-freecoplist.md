# graphics.library/FreeCopList



NAME

    FreeCopList -- deallocate intermediate copper list
SYNOPSIS

```c
    FreeCopList(coplist)
                  a0

    void FreeCopList( struct [CopList](../Includes_and_Autodocs_2._guide/node00AD.html#line62) *);
```
FUNCTION

    Deallocate all memory associated with this copper list.
INPUTS

```c
    coplist  - pointer to structure [CopList](../Includes_and_Autodocs_2._guide/node00AD.html#line62)
```
RESULTS

    memory returned to memory manager
BUGS

SEE ALSO

```c
    [graphics/copper.h](../Includes_and_Autodocs_2._guide/node00AD.html)
```
