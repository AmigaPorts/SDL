---
title: iffparse.library/GoodID
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-goodid
functions: [GoodType]
libraries: [iffparse.library]
---

# iffparse.library/GoodID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GoodID -- Test if an identifier follows the IFF 85 specification.
SYNOPSIS

```c
    isok = GoodID (id)
     d0            d0

    LONG isok, id;
```
FUNCTION

    Tests the given longword identifier to see if it meets all the EA IFF
    85 specifications for a chunk ID.  If so, it returns non-zero,
    otherwise 0.
INPUTS

    id      - potential 32 bit identifier.
RESULT

    isok    - non-zero if this is a valid ID, 0 otherwise.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [GoodType()](autodocs-2.0/iffparse-library-goodtype.md)
```

---

## See Also

- [GoodType — iffparse.library](../autodocs/iffparse.library.md#goodtype)
