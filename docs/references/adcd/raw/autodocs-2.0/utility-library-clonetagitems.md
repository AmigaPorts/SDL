# utility.library/CloneTagItems



NAME

```c
    CloneTagItems -- Copies a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list.  (V36)
```
SYNOPSIS

```c
    newTagList = CloneTagItems( tagList )
    D0                          A0

    struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *CloneTagItems( struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tagList );
```
FUNCTION

```c
    Copies the essential contents of a tagItem list.  Internally,
    it uses [AllocateTagItems()](../Includes_and_Autodocs_2._guide/node03CE.html) so that you can use [FreeTagItems()](../Includes_and_Autodocs_2._guide/node03D7.html).
```
INPUTS

```c
    tagList         - [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list to clone.
```
RESULT

    newTagList      - resultant copy.
BUGS

SEE ALSO

```c
    [AllocateTagItems()](../Includes_and_Autodocs_2._guide/node03CE.html), [FreeTagItems()](../Includes_and_Autodocs_2._guide/node03D7.html), [RefreshTagItemClones()](../Includes_and_Autodocs_2._guide/node03DC.html)
```
