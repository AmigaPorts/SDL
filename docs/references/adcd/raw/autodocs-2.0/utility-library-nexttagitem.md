# utility.library/NextTagItem



NAME

```c
    NextTagItem -- Iterate [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) lists. (V36)
```
SYNOPSIS

```c
    next_tag = NextTagItem( tagItemPtr )
    D0                      A0

    struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *NextTagItem( struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) **tagItemPtr );
```
FUNCTION

```c
    Iterates through a (chained) array of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structures,
    skipping and chaining as dictated by system tags.  TAG_SKIP
    will cause it to skip the entry and the next, TAG_IGNORE ignores
    that single entry, and TAG_MORE has a pointer to another array
    of tags (and terminates the current array!)  TAG_DONE also
    terminates the current array.  Each call returns either the next
    tagitem you should examine, or NULL at the end.
```
INPUTS

```c
    tagItemPtr      - doubly-indirect reference to a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structure.
                      The pointer will be changed to keep track of the
                      iteration.
```
RESULT

```c
    next_tag        - Each [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) in the array or chain of arrays that
                      should be processed according to system Tag values
                      (in [utility/tagitem.h)](../Includes_and_Autodocs_2._guide/node012E.html) is returned in turn with
                      successive calls.
```
EXAMPLE

```c
    Iterate( struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tags );
    {
            struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tstate;
            struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tag;

            tstate = tags;
            while ( tag = NextTagItem( &tstate ) )
            {
                    switch ( tag->ti_Tag )
                    {
                    case TAG1:
                        ...
                        break;
                    case TAG2:
                        ...
                        break;
                    ...
                    }
            }
    }
```
NOTES


```c
    Do NOT use the value of *tagItemPtr, but rather use the pointer
    returned by NextTagItem().
```
BUGS

SEE ALSO

```c
    [utility/tagitem.h](../Includes_and_Autodocs_2._guide/node012E.html), [GetTagData()](../Includes_and_Autodocs_2._guide/node03D8.html), [PackBoolTags()](../Includes_and_Autodocs_2._guide/node03DB.html), [FindTagItem()](../Includes_and_Autodocs_2._guide/node03D6.html)
```
