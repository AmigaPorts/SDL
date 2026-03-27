---
title: intuition.library/PubScreenStatus
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-pubscreenstatus
functions: [OpenScreen]
libraries: [intuition.library]
---

# intuition.library/PubScreenStatus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    PubScreenStatus -- Change status flags for a public screen. (V36)
```
SYNOPSIS

```c
    ResultFlags = PubScreenStatus( [Screen](autodocs-2.0/includes-intuition-screens-h.md), StatusFlags )
    D0                             A0      D0

    UWORD PubScreenStatus( struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) *, UWORD );
```
FUNCTION

    Changes status flags for a given public screen.

    Do not apply this function to a screen if your program
    isn't the screen's "owner", in particular, don't call
    this function for the Workbench screen.
INPUTS

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md) = pointer to public screen
    StatusFlags = values currently:
      PSNF_PRIVATE: make this screen unavailable to visitor windows
```
RESULT

    Returns 0 in the lowest order bit of the return value
    if the screen wasn't public, or because it can not be taken
    private because visitors are open in it.

    All other bits in the return code are reserved for future
    enhancement.
BUGS

SEE ALSO

```c
    [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md), Intuition V36 update documentation
```

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
