---
title: intuition.library/ScreenToBack
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-screentoback
functions: [ScreenToFront]
libraries: [intuition.library]
---

# intuition.library/ScreenToBack

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ScreenToBack -- Send the specified screen to the back of the display.
SYNOPSIS

```c
    ScreenToBack( [Screen](autodocs-2.0/includes-intuition-screens-h.md) )
                  A0

    VOID ScreenToBack( struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) * );
```
FUNCTION

    Sends the specified screen to the back of the display.
INPUTS

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md) = pointer to a [Screen](autodocs-2.0/includes-intuition-screens-h.md) structure
```
RESULT

    None
BUGS

SEE ALSO

```c
    [ScreenToFront()](autodocs-2.0/intuition-library-screentofront.md)
```

---

## See Also

- [ScreenToFront — intuition.library](../autodocs/intuition.library.md#screentofront)
