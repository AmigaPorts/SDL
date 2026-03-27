---
title: mathffp.library/SPCeil
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathffp-library-spceil
functions: [SPFloor]
libraries: [mathffp.library]
---

# mathffp.library/SPCeil

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SPCeil -- Compute Ceil function of a number.
SYNOPSIS

```c
    x = SPCeil(y)
    D0         D0

    float SPCeil(float y);
```
FUNCTION

```c
    Calculate the least integer greater than or equal to x and return it.
    This identity is true.  Ceil(x) = -Floor(-x).
```
INPUTS

    y       - Motorola Fast Floating Point Format Number.
RESULT

    x       - Motorola Fast Floating Point Format Number.
BUGS

    None.
SEE ALSO

```c
    [SPFloor()](autodocs-2.0/mathffp-library-spfloor.md)
```

---

## See Also

- [SPFloor — mathffp.library](../autodocs/mathffp.library.md#spfloor)
