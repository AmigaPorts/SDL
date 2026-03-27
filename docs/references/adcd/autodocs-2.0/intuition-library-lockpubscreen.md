---
title: intuition.library/LockPubScreen
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-lockpubscreen
functions: [CloseWindow, GetScreenData, LockPubScreen, OpenWindow, UnlockPubScreen]
libraries: [intuition.library]
---

# intuition.library/LockPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    LockPubScreen -- Prevent a public screen from closing. (V36)
```
SYNOPSIS

```c
    screen = LockPubScreen( Name )
    D0                      A0

    struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) *LockPubScreen( UBYTE * );
```
FUNCTION

```c
    Prevents a public screen (or the Workbench) from closing
    while you examine it in preparation of opening a visitor window.

    The sequence you use to open a visitor window that needs to
    examine fields in the screen it is about to open on is:
            LockPubScreen()
            ... examine fields ...
            [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) on public screen
            [UnlockPubScreen()](autodocs-2.0/intuition-library-unlockpubscreen.md)
            ... use your window ...
            [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md)
```
NOTE

```c
    You needn't hold the "pubscreen lock" for the duration that
    your window is opened.  LockPubScreen() basically has the
    same effect as an open visitor window: it prevents the
    screen from being closed.

    If you pass the string "Workbench" or you pass NULL and there
    is no default public screen, the Workbench screen will
    be automatically opened if it is not already present.
```
INPUTS

```c
    Name = name string for public screen or NULL for default public
    screen.  The string "Workbench" indicates the Workbench
    screen.
```
RESULT

    Returns pointer to a screen, if successful, else NULL.
    The call can fail for reasons including that the named
    public screen doesn't exist or is in private state.
BUGS

SEE ALSO

```c
    [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md), [UnlockPubScreen()](autodocs-2.0/intuition-library-unlockpubscreen.md), [GetScreenData()](autodocs-2.0/intuition-library-getscreendata.md)
```

---

## See Also

- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
