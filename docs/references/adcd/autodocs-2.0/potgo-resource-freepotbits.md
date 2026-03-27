---
title: potgo.resource/FreePotBits
manual: autodocs-2.0
chapter: autodocs-2.0
section: potgo-resource-freepotbits
functions: []
libraries: []
---

# potgo.resource/FreePotBits

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreePotBits -- Free allocated bits in the potgo register.
SYNOPSIS

```c
    FreePotBits(allocated)
                D0

    void FreePotBits( UWORD );
```
FUNCTION

```c
    The FreePotBits routine frees previously allocated bits in the
    hardware potgo register that the application had allocated via
    [AllocPotBits](autodocs-2.0/potgo-resource-allocpotbits.md) and no longer wishes to use.  It accepts the
    return value from [AllocPotBits](autodocs-2.0/potgo-resource-allocpotbits.md) as its argument.
```
