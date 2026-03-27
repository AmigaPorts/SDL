---
title: intuition.library/ScreenToFront
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-screentofront
functions: [ScreenToBack]
libraries: [intuition.library]
---

# intuition.library/ScreenToFront

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ScreenToFront -- Make the specified screen the frontmost.
SYNOPSIS

```c
    ScreenToFront( [Screen](autodocs-2.0/includes-intuition-screens-h.md) )
                   A0

    VOID ScreenToFront( struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) * );
```
FUNCTION

```c
    Brings the specified [Screen](autodocs-2.0/includes-intuition-screens-h.md) to the front of the display.
```
INPUTS

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md) = a pointer to a [Screen](autodocs-2.0/includes-intuition-screens-h.md) structure
```
RESULT

    None
BUGS

SEE ALSO

```c
    [ScreenToBack()](autodocs-2.0/intuition-library-screentoback.md)
```

---

## See Also

- [ScreenToBack — intuition.library](../autodocs/intuition.library.md#screentoback)
