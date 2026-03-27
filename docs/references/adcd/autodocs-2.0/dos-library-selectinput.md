---
title: dos.library/SelectInput
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-selectinput
functions: [Input, Output, SelectOutput]
libraries: [dos.library]
---

# dos.library/SelectInput

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SelectInput -- Select a filehandle as the default input channel (V36)
```
SYNOPSIS

```c
    old_fh = SelectInput(fh)
    D0                   D1

    BPTR SelectInput(BPTR)
```
FUNCTION

```c
    Set the current input as the default input for the process.
    This changes the value returned by [Input()](autodocs-2.0/dos-library-input.md).  old_fh should
    be closed or saved as needed.
```
INPUTS

    fh     - Newly default input handle
RESULT

    old_fh - Previous default input filehandle
SEE ALSO

```c
    [Input()](autodocs-2.0/dos-library-input.md), [SelectOutput()](autodocs-2.0/dos-library-selectoutput.md), [Output()](autodocs-2.0/dos-library-output.md)
```

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SelectOutput — dos.library](../autodocs/dos.library.md#selectoutput)
