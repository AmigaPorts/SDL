---
title: rexxsyslib.library/CreateRexxMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: rexxsyslib-library-createrexxmsg
functions: [ClearRexxMsg, DeleteRexxMsg, FillRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/CreateRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CreateRexxMsg - Create an ARexx message structure
SYNOPSIS

```c
    rexxmsg = CreateRexxMsg(port, extension, host)
    D0,A0                   A0    A1         D0

    struct [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) *CreateRexxMsg(struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *, UBYTE *, UBYTE *);
```
FUNCTION

```c
    This functions allocates an ARexx message packet.  The [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md)
    consists of a standard EXEC message structure extended to include
    the ARexx specific information.
```
INPUTS

    port - A pointer to a public or private message port.  This *MUST*
           be a valid port as this is where the message will be replied.

    extension - A pointer to a NULL terminated string that is to be used
                as the default extension for the REXX scripts.  If this
                is NULL, the default is "REXX"

    host - A pointer to a NULL terminated string that is to be used
           as the default host port.  The name must be the same as the
           name of the public message port that is to be the default host.
           If this field is NULL, the default is REXX.
RESULTS

```c
    rexxmsg - A [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) structure
```
NOTES

```c
    The extension and host strings must remain valid for as long as the
    [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) exists as only the pointer to those strings are stored.
```
SEE ALSO

```c
    [DeleteRexxMsg()](autodocs-2.0/rexxsyslib-library-deleterexxmsg.md), [ClearRexxMsg()](autodocs-2.0/rexxsyslib-library-clearrexxmsg.md), [FillRexxMsg()](autodocs-2.0/rexxsyslib-library-fillrexxmsg.md)
```
BUGS

---

## See Also

- [ClearRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#clearrexxmsg)
- [DeleteRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#deleterexxmsg)
- [FillRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#fillrexxmsg)
