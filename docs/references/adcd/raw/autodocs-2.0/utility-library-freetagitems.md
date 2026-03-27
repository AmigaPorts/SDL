# utility.library/FreeTagItems



NAME

```c
    FreeTagItems --  Frees allocated [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) lists. (V36)
```
SYNOPSIS

```c
    FreeTagItems( tagList )
                    A0

    void FreeTagItems( struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tagList );
```
FUNCTION

```c
    Frees the memory of a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list allocated either by
    [AllocateTagItems()](../Includes_and_Autodocs_2._guide/node03CE.html) or [CloneTagItems()](../Includes_and_Autodocs_2._guide/node03D2.html).
```
INPUTS

    TagList         - list to free.  Must be created by functions
                      specified. A value of NULL for 'tagList' is safe.
RESULT

    None.
BUGS

SEE ALSO

```c
    [AllocateTagItems()](../Includes_and_Autodocs_2._guide/node03CE.html), [CloneTagItems()](../Includes_and_Autodocs_2._guide/node03D2.html)
```
