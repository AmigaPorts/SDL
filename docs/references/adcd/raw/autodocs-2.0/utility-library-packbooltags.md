# utility.library/PackBoolTags



NAME

```c
    PackBoolTags --  Builds a "Flag" word from a TagList. (V36)
```
SYNOPSIS

```c
    boolflags = PackBoolTags( initialFlags, tagList, boolMap )
    D0                        D0            A0       A1

    ULONG PackBoolTags( ULONG initialFlags, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *tagList,
                        struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *boolMap );
```
FUNCTION


```c
    Picks out the Boolean TagItems in a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list and converts
    them into bit-flag representations according to a correspondence
    defined by the [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list 'BoolMap.'

    A Boolean [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) is one where only the logical value of
    the ti_Data is relevant.  If this field is 0, the value is
    FALSE, otherwise TRUE.
```
INPUTS

```c
    initialFlags    - a starting set of bit-flags which will be changed
                      by the processing of TRUE and FALSE Boolean tags
                      in tagList.
    tagList         - a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list which may contain several TagItems
                      defined to be "Boolean" by their presence in
                      boolMap.  The logical value of ti_Data determines
                      whether a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) causes the bit-flag value related
                      by boolMap to set or cleared in the returned flag
                      longword.
    boolMap         - a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list defining the Boolean Tags to be
                      recognized, and the bit (or bits) in the returned
                      longword that are to be set or cleared when a
                      Boolean Tag is found to be TRUE or FALSE in
                      tagList.
```
RESULT

```c
    boolflags       - the accumulated longword of bit-flags, starting
                      with InitialFlags and modified by each Boolean
                      [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) encountered.
```
EXAMPLE


```c
    /* define some nice user tag values ... */
    enum mytags { tag1 = TAG_USER+1, tag2, tag3, tag4, tag5 };

    /* this [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list defines the correspondence between Boolean tags
     * and bit-flag values.
     */
    struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31)       boolmap[] = {
        { tag1,  0x0001 },
        { tag2,  0x0002 },
        { tag3,  0x0004 },
        { tag4,  0x0008 },
        { TAG_DONE }
    };

    /* You are probably passed these by some client, and you want
     * to "collapse" the Boolean content into a single longword.
     */

    struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31)       boolexample[] = {
        { tag1,  TRUE },
        { tag2,  FALSE },
        { tag5, Irrelevant },
        { tag3,  TRUE },
        { TAG_DONE }
    };

    /* Perhaps 'boolflags' already has a current value of 0x800002. */
    boolflags = PackBoolTags( boolflags, boolexample, boolmap );

    /* The resulting new value of 'boolflags' will be 0x80005. /*
```
BUGS

    There are some undefined cases if there is duplication of
    a given Tag in either list.  It is probably safe to say that
    the *last* of identical Tags in TagList will hold sway.
SEE ALSO

```c
    [utility/tagitem.h](../Includes_and_Autodocs_2._guide/node012E.html), [GetTagData()](../Includes_and_Autodocs_2._guide/node03D8.html), [FindTagItem()](../Includes_and_Autodocs_2._guide/node03D6.html), [NextTagItem()](../Includes_and_Autodocs_2._guide/node03DA.html)
```
