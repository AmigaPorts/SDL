---
title: amiga.lib/CheckRexxMsg
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-checkrexxmsg
functions: []
libraries: []
---

# amiga.lib/CheckRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CheckRexxMsg - Check if a [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) is from ARexx
```
SYNOPSIS

```c
    result = CheckRexxMsg(message)
    D0                    A0

    BOOL CheckRexxMsg(struct [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) *);
```
FUNCTION

```c
    This function checks to make sure that the message is from ARexx
    directly.  It is required when using the Rexx Variable Interface
    routines (RVI) that the message be from ARexx.

    While this function is new in the V37 amiga.lib, it is safe to
    call it in all versions of the operating system.  It is also
    PURE code, thus usable in resident/pure executables.
```
NOTE

    This is a stub in amiga.lib.  It is only available via amiga.lib.
    The stub has two labels.  One, _CheckRexxMsg, takes the arguments
    from the stack.  The other, CheckRexxMsg, takes the arguments in
    registers.
EXAMPLE

```c
    if (CheckRexxMsg(rxmsg))
    {
            /* [Message](autodocs-2.0/includes-exec-ports-h.md) is one from ARexx */
    }
```
INPUTS

```c
    message         A pointer to the [RexxMsg](autodocs-2.0/includes-rexx-storage-h.md) in question
```
RESULTS

    result          A boolean - TRUE if message is from ARexx.
SEE ALSO

```c
    [GetRexxVar()](autodocs-2.0/amiga-lib-getrexxvar.md), [SetRexxVar()](autodocs-2.0/amiga-lib-setrexxvar.md)
```
