---
title: A / Amiga.lib / Clib
manual: libraries
chapter: libraries
section: a-amiga-lib-clib
functions: [RawDoFmt]
libraries: [exec.library]
---

# A / Amiga.lib / Clib

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[FastRand()](autodocs-2.0/amiga-lib-fastrand.md)

    Generates a pseudo-random number.  The seed value is taken from
    stack, shifted left one position, exclusive-or'ed with hex value
    $1D872B41 and returned.
[RangeRand()](autodocs-2.0/amiga-lib-rangerand.md)

```c
    RangeRand() accepts a value from 1 to 65535, and returns a value
    within that range (a 16-bit integer).  Note that this function is
    implemented in C.
```
[fclose()](autodocs-2.0/amiga-lib-stdio.md)

    Closes a file.
[fgetc()](autodocs-2.0/amiga-lib-stdio.md)

    Gets a character from a file.
[fprintf()](autodocs-2.0/amiga-lib-stdio.md)

    Prints a formatted output line to a file.
[fputc()](autodocs-2.0/amiga-lib-stdio.md)

    Puts character to file.
[fputs()](autodocs-2.0/amiga-lib-stdio.md)

    Writes a string to file.
[getchar()](autodocs-2.0/amiga-lib-stdio.md)

    Gets a character from stdin.
[printf()](autodocs-2.0/amiga-lib-printf.md)

    Puts format data to stdout.
[putchar()](autodocs-2.0/amiga-lib-stdio.md)

    Puts character to stdout.
[puts()](autodocs-2.0/amiga-lib-stdio.md)

    Puts a string to stdout, followed by newline.
[sprintf()](autodocs-2.0/amiga-lib-sprintf.md)

```c
    Formats data into a string (see Exec [RawDoFmt()](autodocs-2.0/exec-library-rawdofmt.md) ).
```

---

## See Also

- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
