# utility.library/AllocateTagItems



NAME

```c
    AllocateTagItems --  Allocate a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) array (or chain). (V36)
```
SYNOPSIS

```c
    tagList = AllocateTagItems( numItems )
    D0                          D0

    struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *AllocateTagItems( ULONG numItems);
```
FUNCTION

```c
    Allocates the specified number of usable TagItems slots, and does
    so in a format that the function [FreeTagItems](../Includes_and_Autodocs_2._guide/node03D7.html) can handle.

    Note that to access the TagItems in 'tagList', you should use
    the function [NextTagItem()](../Includes_and_Autodocs_2._guide/node03DA.html).  This will insure you respect any
    chaining (TAG_MORE) that the list uses, and will skip any
    TAG_IGNORE items that AllocateTagItems() might use to stash
    size and other information.
```
INPUTS

```c
    numItems        - the number of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) slots you want to allocate.
```
RESULT

```c
    tagList         - the allocated chain of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structures.  Will
                      return NULL if unsuccessful.
```
BUGS

SEE ALSO

```c
    [FreeTagItems()](../Includes_and_Autodocs_2._guide/node03D7.html), [CloneTagItems()](../Includes_and_Autodocs_2._guide/node03D2.html)
```
