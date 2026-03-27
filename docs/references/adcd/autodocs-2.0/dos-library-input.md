---
title: dos.library/Input
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-input
functions: [Input, Output, SelectInput]
libraries: [dos.library]
---

# dos.library/Input

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Input -- Identify the program's initial input file handle
SYNOPSIS

```c
    file = Input()
    D0

    BPTR Input(void)
```
FUNCTION

```c
    Input() is used to identify the initial input stream allocated when
    the program was initiated.  Never close the filehandle returned by
    Input!
```
RESULTS

    file - BCPL pointer to a file handle
SEE ALSO

```c
    [Output()](autodocs-2.0/dos-library-output.md), [SelectInput()](autodocs-2.0/dos-library-selectinput.md)
```

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SelectInput — dos.library](../autodocs/dos.library.md#selectinput)
