---
title: rexxsyslib.library/FillRexxMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: rexxsyslib-library-fillrexxmsg
functions: [ClearRexxMsg, CreateArgstring, CreateRexxMsg, DeleteArgstring]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/FillRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FillRexxMsg - Fill the argument strings as needed
SYNOPSIS

```c
    result = FillRexxMsg(msgptr, count, mask)
    D0                   A0      D0     D1 [0:15]

    BOOL FillRexxMsg(struct [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) *,ULONG,ULONG);
```
FUNCTION

```c
    This function will convert and install up to 16 argument strings into
    a [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) structure.  The message packet's argument fields must be
    set to either a pointer to a NULL terminated string or an integer value
    The mask, bits 0 to 15, correspond to the type of value is stored
    in the argument slot.  If the bit is cleared, the argument is a
    string pointer; if the bit is set, the argument is an integer.
```
INPUTS

```c
    msgptr - Pointer to a [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) (allocated via CreateRexxMsg)
    count - The number of argument slots to fill in.  This number should
            be from 1 to 16.

    mask - A bit mask corresponding to the 16 fields that is used to
           determine the type of the field.
```
RESULTS

    result - A boolean.  If it is TRUE, the call worked.  If it is false,
             some allocation did not work.  All argstrings that were
             created will be released.
SEE ALSO

```c
    [ClearRexxMsg()](autodocs-2.0/rexxsyslib-library-clearrexxmsg.md), [CreateArgstring()](autodocs-2.0/rexxsyslib-library-createargstring.md), [DeleteArgstring()](autodocs-2.0/rexxsyslib-library-deleteargstring.md), [CreateRexxMsg()](autodocs-2.0/rexxsyslib-library-createrexxmsg.md)
```
BUGS

---

## See Also

- [ClearRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#clearrexxmsg)
- [CreateArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createargstring)
- [CreateRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createrexxmsg)
- [DeleteArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#deleteargstring)
