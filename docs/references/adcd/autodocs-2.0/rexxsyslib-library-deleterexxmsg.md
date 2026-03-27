---
title: rexxsyslib.library/DeleteRexxMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: rexxsyslib-library-deleterexxmsg
functions: [ClearRexxMsg, CreateRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/DeleteRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeleteRexxMsg - Releases a [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) structure created by [CreateRexxMsg()](autodocs-2.0/rexxsyslib-library-createrexxmsg.md)
```
SYNOPSIS

```c
    DeleteRexxMsg(packet)
                  A0

    VOID DeleteRexxMsg(struct [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) *);
```
FUNCTION

```c
    The function releases an ARexx message packet that was allocated
    with [CreateRexxMsg()](autodocs-2.0/rexxsyslib-library-createrexxmsg.md).  Any argument fields in the [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) structure
    should be cleared before calling this function as it does
    not release them for you.
```
INPUTS

```c
    packet - A pointer to a [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) structure allocated by [CreateRexxMsg()](autodocs-2.0/rexxsyslib-library-createrexxmsg.md)
```
EXAMPLE

```c
    if (rmsg=CreateRexxMsg(myport,"myapp","MYAPP_PORT"))
    {
            /* Do my think with rmsg */
            ClearRexxMsg(rmsg,16);  /* We may not want to clear all 16 */
            DeleteRexxMsg(rmsg);
    }
```
SEE ALSO

```c
    [CreateRexxMsg()](autodocs-2.0/rexxsyslib-library-createrexxmsg.md), [ClearRexxMsg()](autodocs-2.0/rexxsyslib-library-clearrexxmsg.md)
```
BUGS

---

## See Also

- [ClearRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#clearrexxmsg)
- [CreateRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createrexxmsg)
