---
title: dos.library/Output
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-output
functions: [Input, Output]
libraries: [dos.library]
---

# dos.library/Output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Output -- Identify the programs' initial output file handle
SYNOPSIS

```c
    file = Output()
    D0

    BPTR Output(void)
```
FUNCTION

```c
    Output() is used to identify the initial output stream allocated
    when the program was initiated.  Never close the filehandle returned
    by Output().
```
RESULTS

    file - BCPL pointer to a file handle
SEE ALSO

```c
    [Input()](autodocs-2.0/dos-library-input.md)
```

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
