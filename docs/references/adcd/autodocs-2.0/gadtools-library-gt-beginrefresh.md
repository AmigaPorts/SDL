---
title: gadtools.library/GT_BeginRefresh
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-gt-beginrefresh
functions: [BeginRefresh, GT_EndRefresh]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/GT_BeginRefresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GT_BeginRefresh -- Begin refreshing friendly to GadTools. (V36)
```
SYNOPSIS

```c
    GT_BeginRefresh(win)
                    A0

    VOID GT_BeginRefresh(struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *);
```
FUNCTION

```c
    Invokes the [intuition.library/BeginRefresh()](autodocs-2.0/intuition-library-beginrefresh.md) function in a manner
    friendly to the [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) Toolkit.  This function call permits the
    GadTools gadgets to refresh themselves at the correct time.
    Call [GT_EndRefresh()](autodocs-2.0/gadtools-library-gt-endrefresh.md) function when done.
```
INPUTS

```c
    win - Pointer to [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure for which a IDCMP_REFRESHWINDOW
        IDCMP event was received.
```
RESULT

    None.
EXAMPLE

NOTES

```c
    The nature of GadTools precludes the use of the IDCMP flag
    WFLG_NOCAREREFRESH.  You must handle IDCMP_REFRESHWINDOW events
    in at least the minimal way, namely:

            case IDCMP_REFRESHWINDOW:
                GT_BeginRefresh(win);
                GT_EndRefresh(win, TRUE);
                break;
```
BUGS

SEE ALSO

```c
    [intuition.library/BeginRefresh()](autodocs-2.0/intuition-library-beginrefresh.md)
```

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [GT_EndRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_endrefresh)
