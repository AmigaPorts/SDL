---
title: intuition.library/LockPubScreenList
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-lockpubscreenlist
functions: [LockIBase, LockPubScreenList, OpenScreen]
libraries: [intuition.library]
---

# intuition.library/LockPubScreenList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    LockPubScreenList -- Prevent changes to the system list. (V36)
```
SYNOPSIS

```c
    [List](autodocs-2.0/includes-exec-lists-h.md) = LockPubScreenList()
    D0

    struct [List](autodocs-2.0/includes-exec-lists-h.md) *LockPubScreenList( VOID );
```
FUNCTION

```c
    Arbitrates access to public screen list while you quickly
    make a copy of it for display to the user.

    Note that this is intended only for the Public [Screen](autodocs-2.0/includes-intuition-screens-h.md) Manager
    program.
```
NOTES

```c
    The nodes on the list are [PubScreenNode](autodocs-2.0/includes-intuition-screens-h.md) structures.
    Act quickly while holding this lock.  The restrictions
    on [LockIBase()](autodocs-2.0/intuition-library-lockibase.md) apply here as well.
```
INPUTS

    None.
RESULT

    A pointer to the public screen list.
BUGS

SEE ALSO

```c
    [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md), Intuition V36 update documentation
```

---

## See Also

- [LockIBase — intuition.library](../autodocs/intuition.library.md#lockibase)
- [LockPubScreenList — intuition.library](../autodocs/intuition.library.md#lockpubscreenlist)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
