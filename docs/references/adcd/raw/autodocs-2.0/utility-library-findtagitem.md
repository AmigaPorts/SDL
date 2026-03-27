# utility.library/FindTagItem



NAME

```c
    FindTagItem -- Scans [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list for a Tag. (V36)
```
SYNOPSIS

```c
    tag = FindTagItem( tagVal, tagList)
    D0                 D0      A0

    struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *FindTagItem( Tag tagVal, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tagList );
```
FUNCTION

```c
    Scans a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) "List", which is in fact a chain of arrays
    of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structures as defined in [utility/tagitem.h](../Includes_and_Autodocs_2._guide/node012E.html).
    Returns a pointer to the FIRST item with ti_Tag matching the
    'TagVal' parameter.
```
INPUTS

```c
    tagVal          - Tag value to search for.
    tagList         - beginning of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list to scan.
```
RESULT

    Returns a pointer to the item with ti_Tag matching 'TagVal'.
    Returns NULL if there is no match or if TagList is NULL.
BUGS

SEE ALSO

```c
    [utility/tagitem.h](../Includes_and_Autodocs_2._guide/node012E.html), [GetTagData()](../Includes_and_Autodocs_2._guide/node03D8.html), [PackBoolTags()](../Includes_and_Autodocs_2._guide/node03DB.html), [NextTagItem()](../Includes_and_Autodocs_2._guide/node03DA.html)
```
