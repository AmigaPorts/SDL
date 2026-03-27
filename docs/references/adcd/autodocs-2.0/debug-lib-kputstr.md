---
title: debug.lib/KPutStr
manual: autodocs-2.0
chapter: autodocs-2.0
section: debug-lib-kputstr
functions: []
libraries: []
---

# debug.lib/KPutStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    KPutStr - put a string to the console
               (defaults to the serial port at 9600 baud)
```
SYNOPSIS

```c
    KPutStr(string)
            A0
```
FUNCTION

    put a null terminated string to the console.  This function will
    not return until the string has been completely transmitted.
INPUTS

    KPutStr is the assembly interface, a string pointer must be in A0.
    _KPutStr and _kputs are the C interfaces, the string pointer must
    be on the stack.
