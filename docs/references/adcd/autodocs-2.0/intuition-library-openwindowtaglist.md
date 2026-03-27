---
title: intuition.library/OpenWindowTagList
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-openwindowtaglist
functions: [OpenScreenTagList, OpenWindow]
libraries: [intuition.library]
---

# intuition.library/OpenWindowTagList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    OpenWindowTagList -- [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) with [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) extension. (V36)
    OpenWindowTags -- Varargs stub for OpenWindowTagList (V36)
```
SYNOPSIS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = OpenWindowTagList( [NewWindow](autodocs-2.0/includes-intuition-intuition-h.md), TagItems )
    D0                          A0         A1

    struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *OpenWindowTagList( struct [NewWindow](autodocs-2.0/includes-intuition-intuition-h.md) *,
            struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) * );

    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = OpenWindowTags( [NewWindow](autodocs-2.0/includes-intuition-intuition-h.md), Tag1, ... )

    struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *OpenWindowTags( struct [NewWindow](autodocs-2.0/includes-intuition-intuition-h.md) *, ULONG, ... );
```
FUNCTION

```c
    A variation of [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) that allow direct specification of
    a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) array of extension data.  Recommended over using the
    ExtNewWindow.Extension field.

    If you omit the [NewWindow](autodocs-2.0/includes-intuition-intuition-h.md) (pass NULL), a set of defaults
    are used, and overridden by the tag items.  Even without
    any tag items at all, a reasonable window opens on the Workbench
    or default public screen.

    See [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) for all the details.
```
INPUTS

```c
    [NewWindow](autodocs-2.0/includes-intuition-intuition-h.md) - (optional) pointer to a [NewWindow](autodocs-2.0/includes-intuition-intuition-h.md) structure.
    TagItems - (optional) pointer to [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) array, with tag
            values as described under the description for
            [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md).
```
RESULT

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) - newly created window, per your specifications.
```
EXAMPLE

```c
    See [OpenScreenTagList()](autodocs-2.0/intuition-library-openscreentaglist.md) for an example of how to create
    a "varargs" version of this function for convenient C
    language programming.
```
NOTES


BUGS


SEE ALSO

```c
    [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md)
```

---

## See Also

- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
