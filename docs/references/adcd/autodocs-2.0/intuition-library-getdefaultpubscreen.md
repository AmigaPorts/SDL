---
title: intuition.library/GetDefaultPubScreen
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-getdefaultpubscreen
functions: [LockPubScreen, OpenWindow, SetDefaultPubScreen]
libraries: [intuition.library]
---

# intuition.library/GetDefaultPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetDefaultPubScreen -- Get name of default public screen. (V36)
```
SYNOPSIS

```c
    GetDefaultPubScreen( Namebuff )
                         A0

    VOID GetDefaultPubScreen( UBYTE * );
```
FUNCTION

```c
    Provides the name of the current default public screen.
    Only anticipated use is for Public [Screen](autodocs-2.0/includes-intuition-screens-h.md) Manager utilities,
    since it is easy to open a visitor window on the default
    public screen without specifying the name.
```
INPUTS

```c
    Namebuff = a buffer of MAXPUBSCREENNAME.  This can be NULL.
```
RESULT

    None.  Will provide the string "Workbench" in Namebuff if there
    is no current default public screen.
NOTE

```c
    This function actually "returns" in register D0 a pointer
    to the public screen.  Unfortunately, the lifespan of
    this pointer is not ensured; the screen could be closed
    at any time.  The *ONLY* legitimate use we can see for
    this return value is to compare for identity with the pointer
    to a public screen you either have a window open in, or
    a lock on using [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md), to determine if that
    screen is in fact the default screen.
```
BUGS

    The function prototype does not reflect the return value.
SEE ALSO

```c
    [SetDefaultPubScreen()](autodocs-2.0/intuition-library-setdefaultpubscreen.md), [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md)
```

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [SetDefaultPubScreen — intuition.library](../autodocs/intuition.library.md#setdefaultpubscreen)
