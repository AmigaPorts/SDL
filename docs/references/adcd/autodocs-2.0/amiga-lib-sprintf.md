---
title: amiga.lib/sprintf
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-sprintf
functions: [RawDoFmt]
libraries: [exec.library]
---

# amiga.lib/sprintf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    sprintf - format a C-like string into a string buffer.
SYNOPSIS

```c
    sprintf(destination formatstring [,value [, values] ] );
```
FUNCTION

```c
    Performs string formatting identical to [printf](autodocs-2.0/amiga-lib-printf.md), but directs the output
    into a specific destination in memory. This uses the ROM version
    of [printf](autodocs-2.0/amiga-lib-printf.md) [(exec.library/RawDoFmt()](autodocs-2.0/exec-library-rawdofmt.md)), so it is very small.

    Assembly programmers can call this by placing values on the
    stack, followed by a pointer to the formatstring, followed
    by a pointer to the destination string.
```
INPUTS

```c
    destination - the address of an area in memory into which the
                  formatted output is to be placed.
    formatstring - pointer to a null terminated string describing the
                   desired output formatting (see [printf()](autodocs-2.0/amiga-lib-printf.md) for a
                   description of this string).
    value(s) - numeric information to be formatted into the output
               stream.
```
SEE ALSO

```c
     [printf()](autodocs-2.0/amiga-lib-printf.md), [exec.library/RawDoFmt()](autodocs-2.0/exec-library-rawdofmt.md)
```

---

## See Also

- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
