---
title: intuition.library/SetEditHook
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-setedithook
functions: []
libraries: []
---

# intuition.library/SetEditHook

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetEditHook -- Set global processing for string gadgets. (V36)
```
SYNOPSIS

```c
    OldHook = SetEditHook( [Hook](autodocs-2.0/includes-utility-hooks-h.md) )
    D0                     A0

    struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) *SetEditHook( struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) * );
```
FUNCTION

    Sets new global editing hook for string gadgets.

    WARNING: This function is wholly untested.  Do *NOT* use
    this in a commercial product until further notice.
INPUTS

```c
    [Hook](autodocs-2.0/includes-utility-hooks-h.md) -- A pointer to a struct [Hook](autodocs-2.0/includes-utility-hooks-h.md) which determines a function
      in your code to be called every time the user types a key.
      This is done before control is passed to the gadget custom
      editing hook, so effects ALL string gadgets.
```
RESULT

    Returns previous global edit hook structure.
BUGS

    Unknown, risky.
SEE ALSO

