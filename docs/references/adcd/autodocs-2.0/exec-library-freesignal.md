---
title: exec.library/FreeSignal
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-freesignal
functions: []
libraries: []
---

# exec.library/FreeSignal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeSignal -- free a signal bit
SYNOPSIS

```c
    FreeSignal(signalNum)
               D0

    void FreeSignal(BYTE);
```
FUNCTION

    This function frees a previously allocated signal bit for reuse.
    This call must be performed while running in the same task in which
    the signal was allocated.
WARNING

    Signals may not be allocated or freed from exception handling code.
NOTE

    Starting with V37, an attempt to free signal -1 is harmless.
INPUTS

```c
    signalNum - the signal number to free {0..31}.
```
