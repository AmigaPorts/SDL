# utility.library/FilterTagItems



NAME

```c
    FilterTagItems - Remove selected items from a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list. (V36)
```
SYNOPSIS

```c
    nvalid = FilterTagItems(tagList, tagArray, logic)
    D0                     A0       A1        D0

    ULONG FilterTagItems(struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tagList, Tag *tagArray,
                         LONG logic);
```
FUNCTION

```c
    Removes TagItems from a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list (by changing ti_Tag to
    TAG_IGNORE) depending on whether its ti_Tag value is
    found in an array of TagValues.

    If the 'logic' parameter is TAGFILTER_AND, then all items
    not appearing in the list are excluded.

    If 'logic' is TAGFILTER_NOT, then items not found in the
    array are preserved, and the ones in the array are cast out.
```
INPUTS

```c
    tagList         - input list of tag items which is to be filtered
                      by having selected items changed to TAG_IGNORE.
    tagArray        - an array of Tag values, terminated by TAG_END,
                      as specified in the notes on [TagInArray()](../Includes_and_Autodocs_2._guide/node03E1.html).
    logic           - specification whether items in TagArray are to
                      be included or excluded in the filtered result.
```
RESULT

    nvalid          - number of valid items left in resulting filtered
                      list.
BUGS

SEE ALSO

```c
    [TagInArray()](../Includes_and_Autodocs_2._guide/node03E1.html)
```
