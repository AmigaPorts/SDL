---
title: iffparse.library/IDtoStr
manual: autodocs-2.0
chapter: autodocs-2.0
section: iffparse-library-idtostr
functions: []
libraries: []
---

# iffparse.library/IDtoStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IDtoStr -- Convert a longword identifier to a null-terminated string.
SYNOPSIS

```c
    str = IDtoStr (id, buf)
    d0             d0  a0

    STRPTR  str;
    LONG    id;
    STRPTR  buf;
```
FUNCTION

    Writes the ASCII equivalent of the given longword ID into buf as a
    null-terminated string.
INPUTS

```c
    id      - longword ID.
    buf     - character buffer to accept string (at least 5 chars).
```
RESULT

    str     - the value of 'buf'.
EXAMPLE

NOTES

BUGS

SEE ALSO

