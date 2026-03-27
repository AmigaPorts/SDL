---
title: intuition.library/UnlockPubScreen
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-unlockpubscreen
functions: [LockPubScreen, UnlockPubScreen]
libraries: [intuition.library]
---

# intuition.library/UnlockPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    UnlockPubScreen -- Release lock on a public screen. (V36)
```
SYNOPSIS

```c
    UnlockPubScreen( Name, [Screen] )
                     A0    A1

    VOID UnlockPubScreen( UBYTE *, struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) * );
```
FUNCTION

```c
    Releases lock gotten by [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md).
    It is best to identify the locked public screen by
    the pointer returned from [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md).  To do this,
    supply a NULL 'Name' pointer and the screen pointer.

    In rare circumstances where it would be more convenient to pass
    a non-NULL pointer to the public screen name string, the
    'Screen' parameter is ignored.
```
INPUTS

```c
    Name = pointer to name of public screen.  If Name is NULL,
        then argument 'Screen' is used as a direct pointer to
        a public screen.
    [Screen](autodocs-2.0/includes-intuition-screens-h.md) = pointer to a public screen.  Used only if Name
        is NULL.  This pointer MUST have been returned
        by [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md).
        It is safe to call UnlockPubScreen() with NULL Name
        and [Screen](autodocs-2.0/includes-intuition-screens-h.md) (the function will have no effect).
```
RESULT

BUGS

SEE ALSO

```c
    [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md)
```

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
