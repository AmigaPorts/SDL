---
title: intuition.library/WBenchToFront
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-wbenchtofront
functions: [ScreenToBack, WBenchToBack, WBenchToFront]
libraries: [intuition.library]
---

# intuition.library/WBenchToFront

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WBenchToFront -- Bring the Workbench screen in front of all screens.
SYNOPSIS

```c
    Success = WBenchToFront()
    D0

    BOOL WBenchToFront( VOID );
```
FUNCTION

```c
    Causes the Workbench [Screen](autodocs-2.0/includes-intuition-screens-h.md), if it's currently opened, to come to
    the foreground.  This does not 'move' the screen up or down, instead
    only affects the depth-arrangement of the screen.
```
INPUTS

    None
RESULT

    If the Workbench screen was opened, this function returns TRUE,
    otherwise it returns FALSE.
BUGS

SEE ALSO

```c
    [WBenchToBack()](autodocs-2.0/intuition-library-wbenchtoback.md), [ScreenToBack()](autodocs-2.0/intuition-library-screentoback.md)
```

---

## See Also

- [ScreenToBack — intuition.library](../autodocs/intuition.library.md#screentoback)
- [WBenchToBack — intuition.library](../autodocs/intuition.library.md#wbenchtoback)
- [WBenchToFront — intuition.library](../autodocs/intuition.library.md#wbenchtofront)
