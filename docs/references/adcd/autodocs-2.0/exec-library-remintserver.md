---
title: exec.library/RemIntServer
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-remintserver
functions: []
libraries: []
---

# exec.library/RemIntServer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemIntServer -- remove an interrupt server from a server chain
SYNOPSIS

```c
    RemIntServer(intNum, interrupt)
                 D0      A1

    void RemIntServer(ULONG,struct [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) *);
```
FUNCTION

    This function removes an interrupt server node from the given
    server chain.

    If this server was the last one on this chain, interrupts for this
    chain are disabled.
INPUTS

```c
    intNum - the Paula interrupt bit (0..14)
    interrupt - pointer to an interrupt server node
```
BUGS

    Before V36 Kickstart, the feature that disables the interrupt
    would not function.  For most server chains this does not
    cause a problem.
SEE ALSO

```c
    [AddIntServer](autodocs-2.0/exec-library-addintserver.md), [hardware/intbits.h](autodocs-2.0/includes-hardware-intbits-h.md)
```
