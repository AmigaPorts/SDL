---
title: dos.library/IsInteractive
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-isinteractive
functions: []
libraries: []
---

# dos.library/IsInteractive

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IsInteractive -- Discover whether a file is "interactive"
SYNOPSIS

```c
    status = IsInteractive( file )
    D0                      D1

    BOOL IsInteractive(BPTR)
```
FUNCTION

    The return value 'status' indicates whether the file associated
    with the file handle 'file' is connected to a virtual terminal.
INPUTS

    file - BCPL pointer to a file handle
RESULTS

    status - boolean
SEE ALSO

