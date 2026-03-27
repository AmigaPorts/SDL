# utility.library/FilterTagChanges



NAME

```c
    FilterTagChanges -- Eliminate TagItems which specify no change. (V36)
```
SYNOPSIS

```c
    FilterTagChanges( changeList, oldValues, apply)
                      A0          A1         D0

    void FilterTagChanges( struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *changeList,
                           struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *oldValues, LONG apply );
```
FUNCTION

```c
    Eliminate items from a "change list" that specify values already
    in effect in existing list.  Optionally update the existing list
    if the Boolean 'Apply' is true.

    The elimination is done by changing the ti_Tag field to TAG_IGNORE.
    So, this function may change the input tag list(s).
```
INPUTS

    changeList      - specification of new tag-value pairs.
    oldValues       - a list of existing tag item pairs.
    apply           - Boolean specification as to whether the values in
                      oldValues are to be updated to the values in
                      changeList.
RESULT

    None.
EXAMPLE

```c
    Assume you have an attribute list for an object (oldValues)
    which looks like this:

            ATTR_Size,  "large",
            ATTR_Color, "orange",
            ATTR_Shape, "square",

    If you receive a new TagList containing some changes (changeList),
    which looks like this:

            ATTR_Size,  "large",
            ATTR_Shape, "triangle"

    If you call FilterTagChanges(), changeList will be modified to
    contain only those attributes which are different from the
    oldValues.  All other tagitems will have their tag-values set to
    TAG_IGNORE.  The resulting changeList will become:

            TAG_IGNORE, "large",
            ATTR_Shape, "triangle"

    If apply was set to TRUE, oldValues would be:

            ATTR_Size,  "large"
            ATTR_Color, "orange"
            ATTR_Shape, "triangle"
```
BUGS

SEE ALSO

