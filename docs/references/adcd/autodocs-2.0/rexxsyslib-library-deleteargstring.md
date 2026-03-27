---
title: rexxsyslib.library/DeleteArgstring
manual: autodocs-2.0
chapter: autodocs-2.0
section: rexxsyslib-library-deleteargstring
functions: [ClearRexxMsg, CreateArgstring, FillRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/DeleteArgstring

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeleteArgstring - Releases an Argstring created by [CreateArgstring()](autodocs-2.0/rexxsyslib-library-createargstring.md)
```
SYNOPSIS

```c
    DeleteArgstring(argstring)
                    A0

    VOID DeleteArgstring(UBYTE *);
```
FUNCTION

    Releases an argstring.  The argstring must have been created by ARexx
INPUTS

    argstring - A pointer to the string buffer of an argstring.
RESULTS

SEE ALSO

```c
    [CreateArgstring()](autodocs-2.0/rexxsyslib-library-createargstring.md), [ClearRexxMsg()](autodocs-2.0/rexxsyslib-library-clearrexxmsg.md), [FillRexxMsg()](autodocs-2.0/rexxsyslib-library-fillrexxmsg.md)
```
BUGS

---

## See Also

- [ClearRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#clearrexxmsg)
- [CreateArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createargstring)
- [FillRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#fillrexxmsg)
