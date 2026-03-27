---
title: dos.library/SelectOutput
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-selectoutput
functions: [Input, Output, SelectInput]
libraries: [dos.library]
---

# dos.library/SelectOutput

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SelectOutput -- Select a filehandle as the default input channel (V36)
```
SYNOPSIS

```c
    old_fh = SelectOutput(fh)
    D0                    D1

    BPTR SelectOutput(BPTR)
```
FUNCTION

```c
    Set the current output as the default output for the process.
    This changes the value returned by [Output()](autodocs-2.0/dos-library-output.md).  old_fh should
    be closed or saved as needed.
```
INPUTS

    fh     - Newly desired output handle
RESULT

    old_fh - Previous current output
SEE ALSO

```c
    [Output()](autodocs-2.0/dos-library-output.md), [SelectInput()](autodocs-2.0/dos-library-selectinput.md), [Input()](autodocs-2.0/dos-library-input.md)
```

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SelectInput — dos.library](../autodocs/dos.library.md#selectinput)
