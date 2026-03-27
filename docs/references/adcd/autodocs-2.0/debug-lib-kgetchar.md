---
title: debug.lib/KGetChar
manual: autodocs-2.0
chapter: autodocs-2.0
section: debug-lib-kgetchar
functions: []
libraries: []
---

# debug.lib/KGetChar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    KGetChar - get a character from the console
               (defaults to the serial port at 9600 baud)
```
SYNOPSIS

```c
    char = KGetChar()
    D0
```
FUNCTION

    busy wait until a character arrives from the console.
    KGetChar is the assembly interface, _KGetChar and _kgetc
    are the C interfaces.
