---
title: rexxsyslib.library/ClearRexxMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: rexxsyslib-library-clearrexxmsg
functions: [CreateArgstring, DeleteArgstring, DeleteRexxMsg, FillRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/ClearRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ClearRexxMsg - Releases and clears the argument array in a [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md)
```
SYNOPSIS

```c
    ClearRexxMsg(msgptr, count)
                 A0      D0

    VOID ClearRexxMsg(struct [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) *,ULONG);
```
FUNCTION

```c
    This function will [DeleteArgstring()](autodocs-2.0/rexxsyslib-library-deleteargstring.md) one or more argstrings from
    the [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) and clear the slot.  The count is used to select the
    number of slots to clear.
```
INPUTS

```c
    msgptr - A pointer to a [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md)
    count - The number of slots to be cleared.  The number can be from
            1 to 16.  (There are 16 slots)
```
RESULTS

    All of the slots in the given count will be cleared and the argstring
    will have been released.
SEE ALSO

```c
    [FillRexxMsg()](autodocs-2.0/rexxsyslib-library-fillrexxmsg.md), [DeleteRexxMsg()](autodocs-2.0/rexxsyslib-library-deleterexxmsg.md), [DeleteArgstring()](autodocs-2.0/rexxsyslib-library-deleteargstring.md), [CreateArgstring()](autodocs-2.0/rexxsyslib-library-createargstring.md)
```
BUGS

---

## See Also

- [CreateArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createargstring)
- [DeleteArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#deleteargstring)
- [DeleteRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#deleterexxmsg)
- [FillRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#fillrexxmsg)
