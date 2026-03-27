---
title: exec.library/AddIntServer
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-addintserver
functions: []
libraries: []
---

# exec.library/AddIntServer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddIntServer -- add an interrupt server to a system server chain
SYNOPSIS

```c
    AddIntServer(intNum, interrupt)
                 D0-0:4  A1

    void AddIntServer(ULONG, struct [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) *);
```
FUNCTION

```c
    This function adds a new interrupt server to a given server chain.
    The node is located on the chain in a priority dependent position.
    If this is the first server on a particular chain, interrupts will
    be enabled for that chain.

    Each link in the chain will be called in priority order until the
    chain ends or one of the servers returns with the 68000's Z condition
    code clear (indicating non-zero).  Servers on the chain should return
    with the Z flag clear if the interrupt was specifically for that
    server, and no one else.  VERTB servers should always return Z set.
    (Take care with High Level Language servers, the language may not
    have a mechanism for reliably setting the Z flag on exit).

    Servers are called with the following register conventions:

        D0 - scratch
        D1 - scratch

        A0 - scratch
        A1 - server is_Data pointer (scratch)

        A5 - jump vector register (scratch)
        A6 - scratch

        all other registers must be preserved
```
INPUTS

```c
    intNum - the Paula interrupt bit number (0 through 14). Processor
             level seven interrupts (NMI) are encoded as intNum 15.
             The PORTS, COPER, VERTB, EXTER and NMI interrupts are
             set up as server chains.
    interrupt - pointer to an [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) structure.
             By convention, the LN_NAME of the interrupt structure must
             point a descriptive string so that other users may
             identify who currently has control of the interrupt.
```
WARNING

```c
    Some compilers or assemblers may optimize code in unexpected ways,
    affecting the conditions codes returned from the function.  Watch
    out for a "MOVEM" instruction (which does not affect the condition
    codes) turning into "MOVE" (which does).
```
BUGS

```c
    The graphics library's VBLANK server, and some user code, currently
    assume that address register A0 will contain a pointer to the custom
    chips. If you add a server at a priority of 10 or greater, you must
    compensate for this by providing the expected value ($DFF000).
```
SEE ALSO

```c
    [RemIntServer](autodocs-2.0/exec-library-remintserver.md), [SetIntVector](autodocs-2.0/exec-library-setintvector.md), hardware/intbits.i,exec/interrupts.i
```
