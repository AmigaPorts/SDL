---
title: rexxsyslib.library/CreateArgstring
manual: autodocs-2.0
chapter: autodocs-2.0
section: rexxsyslib-library-createargstring
functions: [ClearRexxMsg, DeleteArgstring, FillRexxMsg, LengthArgstring]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/CreateArgstring

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CreateArgstring - Create an argument string structure
SYNOPSIS

```c
    argstr = CreateArgstring(string, length)
    D0,A0                    A0      D0

    UBYTE *CreateArgstring(UBYTE *, ULONG);
```
FUNCTION

```c
    Allocates a [RexxArg](autodocs-2.0/includes-rexx-storage-h.md) structure and copies the supplied string into it.
    The returned pointer points at the string part of the structure
    and can be treated like an ordinary string pointer.  (However, care
    must be taken that you do not change the string)
```
INPUTS

```c
    string - A pointer at your input string
    length - The number of bytes of your input string you wish copied.
             (NOTE:  You are limited to 65,535 byte strings)
```
RESULTS

    argstr - A pointer to the argument string.  The results are returned
             in both A0 and D0.  You should always check the result
             as an allocation failure would cause an error.
SEE ALSO

```c
    [DeleteArgstring()](autodocs-2.0/rexxsyslib-library-deleteargstring.md), [LengthArgstring()](autodocs-2.0/rexxsyslib-library-lengthargstring.md), [ClearRexxMsg()](autodocs-2.0/rexxsyslib-library-clearrexxmsg.md), [FillRexxMsg()](autodocs-2.0/rexxsyslib-library-fillrexxmsg.md)
```
BUGS

---

## See Also

- [ClearRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#clearrexxmsg)
- [DeleteArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#deleteargstring)
- [FillRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#fillrexxmsg)
- [LengthArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#lengthargstring)
