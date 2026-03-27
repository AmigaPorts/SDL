---
title: rexxsyslib.library/IsRexxMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: rexxsyslib-library-isrexxmsg
functions: [CreateRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/IsRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IsRexxMsg - Function to determine if a message came from ARexx
SYNOPSIS

```c
    result = IsRexxMsg(msgptr)
    D0                 A0

    BOOL IsRexxMsg(struct [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) *);
```
FUNCTION

    This function can be used to determine if a message came from an
    ARexx program.
INPUTS

```c
    msgptr - A pointer to the suspected [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md).
```
RESULTS

    result - A boolean:  TRUE if it is an ARexx message, FALSE if not.
SEE ALSO

```c
    [CreateRexxMsg()](autodocs-2.0/rexxsyslib-library-createrexxmsg.md)
```
BUGS

---

## See Also

- [CreateRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createrexxmsg)
