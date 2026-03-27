---
title: intuition.library/OpenScreenTagList
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-openscreentaglist
functions: [OpenScreen, OpenScreenTagList]
libraries: [intuition.library]
---

# intuition.library/OpenScreenTagList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    OpenScreenTagList -- [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md) with [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) extension array. (V36)
    OpenScreenTags -- Varargs stub for OpenScreenTagList. (V36)
```
SYNOPSIS

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md) = OpenScreenTagList( [NewScreen](autodocs-2.0/includes-intuition-screens-h.md), TagItems )
    D0                          A0         A1

    struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) *OpenScreenTagList( struct [NewScreen](autodocs-2.0/includes-intuition-screens-h.md) *,
            struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) * );

    [Screen](autodocs-2.0/includes-intuition-screens-h.md) = OpenScreenTags( [NewScreen](autodocs-2.0/includes-intuition-screens-h.md), Tag1, ... )

    struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) *OpenScreenTags( struct [NewScreen](autodocs-2.0/includes-intuition-screens-h.md) *,
            ULONG, ... );
```
FUNCTION

```c
    Provides an extension to the parameters passed to [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md).
    This extensions is in the form of (a pointer to) an array of
    [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) structures, which have to fields: ti_Tag, an ID identifying
    the meaning of the other field, ti_Data.  See [<utility/tagitem.h>](autodocs-2.0/includes-utility-tagitem-h.md).

    The tag items can supplement or override the values in [NewScreen](autodocs-2.0/includes-intuition-screens-h.md).
    In fact, you can pass a NULL value of the [NewScreen](autodocs-2.0/includes-intuition-screens-h.md) pointer.
    For that matter, if you pass NULL in both arguments, you'll get
    a screen with defaults in all fields, including display mode,
    depth, colors, dimension, title, and so on.  We ask that
    you at least supply a title when you open a screen.

    See [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md) documentation for parameter specifications.
```
INPUTS

```c
    [NewScreen](autodocs-2.0/includes-intuition-screens-h.md)     - (optional) pointer to a [NewScreen](autodocs-2.0/includes-intuition-screens-h.md) structure.
    TagItems      - (optional) pointer to (an array of) [TagItem](autodocs-2.0/includes-utility-tagitem-h.md)
                    structures, terminated by the value TAG_END.
```
RESULT

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md)     - an open Intuition screen.  See [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md) for
            extended error codes when [Screen](autodocs-2.0/includes-intuition-screens-h.md) is returned NULL.
```
EXAMPLE

```c
    The version using a variable number of arguments must be
    created for each particular compiler, and may not have
    an analogue in all versions.  For vanilla, 32-bit C
    parameter passing conventions, this works (and will
    appear in amiga.lib):

    struct [Screen](autodocs-2.0/includes-intuition-screens-h.md)      *
    OpenScreenTags( ns, tag1 )
    struct [NewScreen](autodocs-2.0/includes-intuition-screens-h.md)  *ns;
    ULONG                   tag1;
    {
        struct [Screen](autodocs-2.0/includes-intuition-screens-h.md)  *OpenScreenTagList();

        return ( OpenScreenTagList( ns, (struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *) &tag1 ) );
    }
```
NOTES

```c
    We recommend this extension to [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md) over using the
    field ExtNewScreen.Extension.  However, the ExtNewScreen.Extension
    is a convenient way to supply a few tags to V36 Intuition which
    will be ignored by V34 Intuition.  See [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md) documentation
    for lots of details.
```
BUGS


SEE ALSO

```c
    [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md)
```

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
