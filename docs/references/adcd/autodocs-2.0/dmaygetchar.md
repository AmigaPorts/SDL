---
title: DMayGetChar
manual: autodocs-2.0
chapter: autodocs-2.0
section: dmaygetchar
functions: []
libraries: []
---

# DMayGetChar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DMayGetChar - return a char iff present, but don't block
SYNOPSIS

```c
    flagChar = DMayGetChar()
    D0
```
FUNCTION

    return either a -1, saying that there is no char present, or
    the char that was waiting
