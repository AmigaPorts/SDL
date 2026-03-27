# utility.library/RefreshTagItemClones



NAME

```c
    RefreshTagItemClones -- Rejuvenates a clone from the original. (V36)
```
SYNOPSIS

```c
    RefreshTagItemClones( cloneTagItems, originalTagItems )
                          A0             A1

    void RefreshTagItemClones( struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *cloneTagItems,
                              struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *originalTagItems );
```
FUNCTION

```c
    If (and only if) the tag items 'cloneTagItems' were created
    from 'originalTagItems' by [CloneTagItems()](../Includes_and_Autodocs_2._guide/node03D2.html), and if originalTagItems
    has not been changed in any way, you can reset the clone list
    to its original state by using this function.
```
INPUTS

```c
    [CloneTagItems](../Includes_and_Autodocs_2._guide/node03D2.html)    - return value from CloneTagItems(originalTagItems).
    OriginalTagItems - a tag list that hasn't changed.
```
RESULT

    None.
EXAMPLE

BUGS

SEE ALSO

```c
    [CloneTagItems()](../Includes_and_Autodocs_2._guide/node03D2.html), [AllocateTagItems()](../Includes_and_Autodocs_2._guide/node03CE.html), [FreeTagItems()](../Includes_and_Autodocs_2._guide/node03D7.html)
```
