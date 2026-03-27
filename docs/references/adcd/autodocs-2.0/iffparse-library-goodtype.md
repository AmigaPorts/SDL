---
title: iffparse.library/GoodType
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-goodtype
functions: [GoodID, GoodType]
libraries: [iffparse.library]
---

# iffparse.library/GoodType

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GoodType -- Test if a type follows the IFF 85 specification.
SYNOPSIS

```c
    isok = GoodType (type)
     d0               d0

    LONG isok, type;
```
FUNCTION

```c
    Tests the given longword type identifier to see if it meets all the
    EA IFF 85 specifications for a FORM type (requirements for a FORM
    type are more stringent than those for a simple chunk ID).  If it
    complies, GoodType() returns non-zero, otherwise 0.
```
INPUTS

    type    - potential 32 bit format type identifier.
RESULT

    isok    - non-zero if this is a valid type id, 0 otherwise.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [GoodID()](autodocs-2.0/iffparse-library-goodid.md)
```

---

## See Also

- [GoodID — iffparse.library](../autodocs/iffparse.library.md#goodid)
- [GoodType — iffparse.library](../autodocs/iffparse.library.md#goodtype)
