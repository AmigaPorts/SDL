---
title: dos.library/CheckSignal
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-checksignal
functions: []
libraries: []
---

# dos.library/CheckSignal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CheckSignal -- Checks for break signals (V36)
```
SYNOPSIS

```c
    signals = CheckSignal(mask)
    D0                    D1

    ULONG CheckSignals(ULONG)
```
FUNCTION

    This function checks to see if any signals specified in the mask have
    been set and if so, returns them.  Otherwise it returns FALSE.
    All signals specified in mask will be cleared.
INPUTS

    mask    - Signals to check for.
RESULT

    signals - Signals specified in mask that were set.
SEE ALSO

