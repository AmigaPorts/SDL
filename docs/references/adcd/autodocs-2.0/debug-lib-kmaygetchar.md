---
title: debug.lib/KMayGetChar
manual: autodocs-2.0
chapter: autodocs-2.0
section: debug-lib-kmaygetchar
functions: []
libraries: []
---

# debug.lib/KMayGetChar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    KMayGetChar - return a character if present, but don't wait
                  (defaults to the serial port at 9600 baud)
```
SYNOPSIS

```c
    flagChar = KMayGetChar()
    D0
```
FUNCTION

    return either a -1, saying that there is no character present, or
    whatever character was waiting.  KMayGetChar is the assembly
    interface,  _KMayGetChar is the C interface.
