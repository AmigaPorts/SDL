---
title: debug.lib/KPutChar
manual: autodocs-2.0
chapter: autodocs-2.0
section: debug-lib-kputchar
functions: []
libraries: []
---

# debug.lib/KPutChar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    KPutChar - put a character to the console
               (defaults to the serial port at 9600 baud)
```
SYNOPSIS

```c
    char = KPutChar(char)
    D0              D0
```
FUNCTION

    Put a character to the console.  This function will not return
    until the character has been completely transmitted.
INPUTS

    KPutChar is the assembly interface, the character must be in D0.
    _KPutChar and _kputc are the C interfaces, the character must be
    a longword on the stack.
