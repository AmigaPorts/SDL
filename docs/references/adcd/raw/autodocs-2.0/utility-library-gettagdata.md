# utility.library/GetTagData



NAME

```c
    GetTagData -- Obtain data corresponding to Tag. (V36)
```
SYNOPSIS

```c
    value = GetTagData(tagVal, default, tagList)
    D0                 D0      D1       A0

    ULONG GetTagData(Tag TagVal, ULONG Default, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *TagList)
```
FUNCTION

```c
    Searches a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list for a matching Tag value, and returns the
    corresponding ti_Data value for the [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) found.  If none
    found, will return the value passed it as 'default'.
```
INPUTS

```c
    tagVal          - Tag value to search for.
    default         - value to be returned if tagVal is not found.
    tagList         - the [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list to search.
```
RESULT

```c
    value           - The ti_Data value for first matching [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31), or
                      'default' if a ti_Tag matching 'Tag' is not found.
```
BUGS

SEE ALSO

```c
    [utility/tagitem.h](../Includes_and_Autodocs_2._guide/node012E.html), [FindTagItem()](../Includes_and_Autodocs_2._guide/node03D6.html), [PackBoolTags()](../Includes_and_Autodocs_2._guide/node03DB.html), [NextTagItem()](../Includes_and_Autodocs_2._guide/node03DA.html)
```
