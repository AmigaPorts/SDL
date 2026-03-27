---
title: gadtools.library/GT_EndRefresh
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-gt-endrefresh
functions: [EndRefresh, GT_BeginRefresh]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/GT_EndRefresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GT_EndRefresh -- End refreshing friendly to GadTools. (V36)
```
SYNOPSIS

```c
    GT_EndRefresh(win, complete)
                  A0   D0

    VOID GT_EndRefresh(struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, BOOL complete);
```
FUNCTION

```c
    Invokes the [intuition.library/EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md) function in a manner
    friendly to the [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) Toolkit.  This function call permits
    GadTools gadgets to refresh themselves at the correct time.
    Call this function to [EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md) when you have used
    [GT_BeginRefresh()](autodocs-2.0/gadtools-library-gt-beginrefresh.md).
```
INPUTS

```c
    win - Pointer to [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure for which a IDCMP_REFRESHWINDOW
        IDCMP event was received.
    complete - TRUE when done with refreshing.
```
RESULT

    None.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [intuition.library/EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md)
```

---

## See Also

- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [GT_BeginRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_beginrefresh)
