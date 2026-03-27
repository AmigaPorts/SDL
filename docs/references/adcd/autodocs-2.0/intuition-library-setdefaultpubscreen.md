---
title: intuition.library/SetDefaultPubScreen
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-setdefaultpubscreen
functions: [OpenScreen, OpenWindow]
libraries: [intuition.library]
---

# intuition.library/SetDefaultPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetDefaultPubScreen -- Choose a new default public screen. (V36)
```
SYNOPSIS

```c
    SetDefaultPubScreen( Name )
                         A0

    VOID SetDefaultPubScreen( UBYTE * );
```
FUNCTION

    Establishes a new default public screen for visitor windows.

    This screen is used by windows asking for a named public screen
    that doesn't exist and the FALLBACK option is selected, and for
    windows asking for the default public screen directly.
INPUTS

```c
    Name = name of chosen public screen to be the new default.
    A value of NULL means that the Workbench screen is to
    be the default public screen.
```
RESULT

    None
BUGS

SEE ALSO

```c
    [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md), [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md), Intuition V36 update documentation
```

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
