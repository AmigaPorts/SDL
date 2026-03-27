---
title: cia.resource/AddICRVector
manual: autodocs-2.0
chapter: autodocs-2.0
section: cia-resource-addicrvector
functions: []
libraries: []
---

# cia.resource/AddICRVector

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddICRVector -- attach an interrupt handler to a [CIA](autodocs-2.0/includes-hardware-cia-h.md) bit.
```
SYNOPSIS

```c
    interrupt = AddICRVector( Resource, iCRBit, interrupt )
    D0                        A6        D0      A1

    struct [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) *AddICRVector( struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *, WORD,
            struct [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) * );
```
FUNCTION

```c
    Assign interrupt processing code to a particular interrupt bit
    of the [CIA](autodocs-2.0/includes-hardware-cia-h.md) ICR.  If the interrupt bit has already been
    assigned, this function will fail, and return a pointer to the
    owner interrupt.  If it succeeds, a null is returned.

    This function will also enable the [CIA](autodocs-2.0/includes-hardware-cia-h.md) interrupt for the given
    ICR bit.
```
INPUTS

```c
    iCRBit          Bit number to set (0..4).
    interrupt       Pointer to interrupt structure.
```
RESULT

    interrupt       Zero if successful, otherwise returns a
                        pointer to the current owner interrupt
                        structure.
NOTE

```c
    A processor interrupt may be generated immediatly if this call
    is successful.

    In general, it is probably best to only call this function
    while DISABLED so that the resource to which the interrupt
    handler is being attached may be set to a known state before
    the handler is called. You MUST NOT change the state of the
    resource before attaching your handler to it.

    The [CIA](autodocs-2.0/includes-hardware-cia-h.md) resources are special in that there is more than one
    of them in the system. Because of this, the C language stubs
    in amiga.lib for the [CIA](autodocs-2.0/includes-hardware-cia-h.md) resources require an extra parameter
    to specify which [CIA](autodocs-2.0/includes-hardware-cia-h.md) resource to use. The synopsys for the
    amiga.lib stubs is as follows:

    interrupt = AddICRVector( Resource, iCRBit, interrupt )
    D0                        A6        D0      A1

    struct [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) *AddICRVector( struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *, WORD,
            struct [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) *);

    ***WARNING***

    Never assume that any of the [CIA](autodocs-2.0/includes-hardware-cia-h.md) hardware is free for use.
    Always use the AddICRVector() function to obtain ownership
    of the [CIA](autodocs-2.0/includes-hardware-cia-h.md) hardware registers your code will use.

    Note that there are two (2) interval timers per [CIA](autodocs-2.0/includes-hardware-cia-h.md).  If
    your application needs one of the interval timers, you
    can try to obtain any one of the four (4) until AddICRVector()
    succeeds.  If all four interval timers are in-use, your
    application should exit cleanly.

    If you just want ownership of a [CIA](autodocs-2.0/includes-hardware-cia-h.md) hardware timer, or register,
    but do not want interrupts generated, use the AddICRVector()
    function to obtain ownership, and use the [AbleICR()](autodocs-2.0/cia-resource-ableicr.md) function
    to turn off (or on) interrupts as needed.

    Note that CIA-B generates level 6 interrupts (which can degrade
    system performance by blocking lower priority interrupts).  As
    usual, interrupt handling code should be optimized for speed.

    Always call [RemICRVector()](autodocs-2.0/cia-resource-remicrvector.md) when your code exits to release
    ownership of any [CIA](autodocs-2.0/includes-hardware-cia-h.md) hardware obtained with AddICRVector().
```
SEE ALSO

```c
    [cia.resource/RemICRVector()](autodocs-2.0/cia-resource-remicrvector.md), [cia.resource/AbleICR()](autodocs-2.0/cia-resource-ableicr.md)
```
