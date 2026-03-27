---
title: exec.library/SetSR
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-setsr
functions: []
libraries: []
---

# exec.library/SetSR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetSR -- get and/or set processor status register
SYNOPSIS

```c
    oldSR = SetSR(newSR, mask)
    D0            D0     D1

    ULONG SetSR(ULONG, ULONG);
```
FUNCTION

```c
    This function provides a means of modifying the CPU status register
    in a "safe" way (well, how safe can a function like this be
    anyway?).  This function will only affect the status register bits
    specified in the mask parameter.  The prior content of the entire
    status register is returned.
```
INPUTS

    newSR - new values for bits specified in the mask.
        All other bits are not effected.
    mask - bits to be changed
RESULTS

    oldSR - the entire status register before new bits
EXAMPLES

```c
    To get the current SR:
        currentSR = SetSR(0,0);
    To change the processor interrupt level to 3:
        oldSR = SetSR($0300,$0700);
    Set processor interrupts back to prior level:
        SetSR(oldSR,$0700);
```
