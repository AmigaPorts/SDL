---
title: intuition.library/NextPubScreen
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-nextpubscreen
functions: [LockPubScreen, OpenScreen]
libraries: [intuition.library]
---

# intuition.library/NextPubScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NextPubScreen -- Identify next public screen in the cycle. (V36)
```
SYNOPSIS

```c
    Buff = NextPubScreen( [Screen](autodocs-2.0/includes-intuition-screens-h.md), NameBuff )
    D0                    A0      A1

    UBYTE *NextPubScreen( struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) *, UBYTE * );
```
FUNCTION

    Returns name of next public screen in system rotation, to
    allow visitor windows to provide function to "jump" among
    public-screens in a cycle.
INPUTS

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md) = pointer to the screen your window is currently open in,
      or NULL, if you don't have a pointer to a public screen.
    NameBuff = pointer to a buffer of MAXPUBSCREENNAME+1 characters,
      for Intuition to fill in with the name of the next public
      screen in rotation.
```
RESULT

    Returns NULL if there are no public screens, otherwise a
    pointer to your NameBuff.
NOTES

```c
    There is no guarantee that the public screen whose name
    was returned by this function will exist or be in "public" state
    by the time you call [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md), etc.  You must handle
    cases where [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md), etc. will fail.
```
BUGS

```c
    Due to a bug, your buffer needs to be (MAXPUBSCREENNAME + 1)
    characters big, which is one more than originally documented.

    The starting screen and cycle order of the public screens isn't
    defined, so do not draw conclusions about the order you
    see in the current version of Intuition.  We reserve the
    right to add meaning to the ordering at a future time.
```
SEE ALSO

```c
    [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md), Intuition V36 update documentation
```

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
