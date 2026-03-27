---
title: rexxsyslib.library/LengthArgstring
manual: autodocs-2.0
chapter: autodocs-2.0
section: rexxsyslib-library-lengthargstring
functions: [CreateArgstring]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/LengthArgstring

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    LengthArgstring - Returns the length value stored in the argstring
SYNOPSIS

```c
    length = LengthArgstring(argstring)
    D0                       A0

    ULONG LengthArgstring(UBYTE *);
```
FUNCTION

```c
    This function returns the length value stored in the argstring.
    This is *NOT* the same as doing a strlen() type call on the
    argstring.  (Note that argstrings may contain NULLs)
```
INPUTS

    argstring - A pointer to an argstring that was created by ARexx
RESULTS

    length - The length of the argstring.
EXAMPLE

SEE ALSO

```c
    [CreateArgstring()](autodocs-2.0/rexxsyslib-library-createargstring.md)
```
BUGS

---

## See Also

- [CreateArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createargstring)
