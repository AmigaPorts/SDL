---
title: debug.lib/KGetNum
manual: autodocs-2.0
chapter: autodocs-2.0
section: debug-lib-kgetnum
functions: []
libraries: []
---

# debug.lib/KGetNum

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    KGetNum - get a number from the console
SYNOPSIS

```c
    number = KGetNum()
    D0
```
FUNCTION

    get a signed decimal integer from the console.  This will busy
    wait until the number arrives.
