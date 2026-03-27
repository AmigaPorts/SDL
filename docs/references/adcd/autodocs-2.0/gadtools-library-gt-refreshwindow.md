---
title: gadtools.library/GT_RefreshWindow
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-gt-refreshwindow
functions: [AddGList, GT_BeginRefresh, RefreshGList]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/GT_RefreshWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GT_RefreshWindow -- Refresh all the GadTools gadgets. (V36)
```
SYNOPSIS

```c
    GT_RefreshWindow(win, req)
                     A0   A1

    VOID GT_RefreshWindow(struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) *);
```
FUNCTION

```c
    Perform the initial refresh of all the GadTools gadgets you have
    created.  After you have opened your window, you must call this
    function.  Or, if you have opened your window without gadgets,
    you add the gadgets with [intuition.library/AddGList()](autodocs-2.0/intuition-library-addglist.md),
    refresh them using [intuition.library/RefreshGList()](autodocs-2.0/intuition-library-refreshglist.md), then call
    this function.
    You should not need this function at other times.
```
INPUTS

```c
    win - Pointer to the [Window](autodocs-2.0/includes-intuition-intuition-h.md) containing GadTools gadgets.
    req - Pointer to requester, or NULL if not a requester (currently
        ignored - use NULL).
```
RESULT

    None.
EXAMPLE

NOTES

    req must currently be NULL.  GadTools gadgets are not supported
    in requesters.  This field may allow such support at a future date.
BUGS

SEE ALSO

```c
    [GT_BeginRefresh()](autodocs-2.0/gadtools-library-gt-beginrefresh.md)
```

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [GT_BeginRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_beginrefresh)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
