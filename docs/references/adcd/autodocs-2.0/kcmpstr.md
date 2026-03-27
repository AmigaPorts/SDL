---
title: KCmpStr
manual: autodocs-2.0
chapter: autodocs-2.0
section: kcmpstr
functions: []
libraries: []
---

# KCmpStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    KCmpStr - compare two null terminated strings
SYNOPSIS

```c
    mismatch = KCmpStr(string1, string2)
    D0                A0       A1
```
FUNCTION

    string1 is compared to string2 using the ASCII coalating
    sequence.
