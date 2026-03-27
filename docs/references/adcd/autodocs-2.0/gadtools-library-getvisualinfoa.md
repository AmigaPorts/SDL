---
title: gadtools.library/GetVisualInfoA
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-getvisualinfoa
functions: [FreeVisualInfo, GetVisualInfoA, LockPubScreen, UnlockPubScreen]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/GetVisualInfoA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetVisualInfoA -- Get information GadTools needs for visuals. (V36)
    GetVisualInfo -- Varargs stub for GetVisualInfoA(). (V36)
```
SYNOPSIS

```c
    vi = GetVisualInfoA(screen, taglist)
    D0                  A0      A1

    APTR vi = GetVisualInfoA(struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) *, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *);

    vi = GetVisualInfo(screen, firsttag, ...)

    APTR vi = GetVisualInfo(struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) *, Tag, ...);
```
FUNCTION

```c
    Get a pointer to a (private) block of data containing various bits
    of information that GadTools needs to ensure the best quality
    visuals.  Use the result in the [NewGadget](autodocs-2.0/includes-libraries-gadtools-h.md) structure of any gadget
    you create, or as a parameter to the various menu calls.  Once the
    gadgets/menus are no longer needed (after the last CloseWindow),
    call [FreeVisualInfo()](autodocs-2.0/gadtools-library-freevisualinfo.md).
```
INPUTS

    screen - Pointer to the screen you will be opening on.
    taglist - Pointer to list of TagItems.
RESULT

    vi - Pointer to private data.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [FreeVisualInfo()](autodocs-2.0/gadtools-library-freevisualinfo.md), [intuition/LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md),
    [intuition/UnlockPubScreen()](autodocs-2.0/intuition-library-unlockpubscreen.md)
```

---

## See Also

- [FreeVisualInfo — gadtools.library](../autodocs/gadtools.library.md#freevisualinfo)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
