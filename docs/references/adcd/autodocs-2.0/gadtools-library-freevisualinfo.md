---
title: gadtools.library/FreeVisualInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-freevisualinfo
functions: [CloseScreen, CloseWindow, FreeVisualInfo, GetVisualInfoA, UnlockPubScreen]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/FreeVisualInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeVisualInfo -- Return any resources taken by GetVisualInfo. (V36)
```
SYNOPSIS

```c
    FreeVisualInfo(vi)
                   A0

    VOID FreeVisualInfo(APTR);
```
FUNCTION

```c
    FreeVisualInfo() returns any memory or other resources that
    were allocated by [GetVisualInfoA()](autodocs-2.0/gadtools-library-getvisualinfoa.md).  You should only call this function
    once you are done with using the gadgets (i.e. after [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md)),
    but while the screen is still valid (i.e. before [CloseScreen()](autodocs-2.0/intuition-library-closescreen.md) or
    [UnlockPubScreen()](autodocs-2.0/intuition-library-unlockpubscreen.md)).
```
INPUTS

```c
    vi - Pointer that was obtained by calling [GetVisualInfoA()](autodocs-2.0/gadtools-library-getvisualinfoa.md).
```
RESULT

    None.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [GetVisualInfoA()](autodocs-2.0/gadtools-library-getvisualinfoa.md)
```

---

## See Also

- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [FreeVisualInfo — gadtools.library](../autodocs/gadtools.library.md#freevisualinfo)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
