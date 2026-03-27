---
title: cia.resource/RemICRVector
manual: autodocs-2.0
chapter: autodocs-2.0
section: cia-resource-remicrvector
functions: []
libraries: []
---

# cia.resource/RemICRVector

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemICRVector -- Detach an interrupt handler from a [CIA](autodocs-2.0/includes-hardware-cia-h.md) bit.
```
SYNOPSIS

```c
    RemICRVector( Resource, iCRBit, interrupt )
                  A6        D0      A1

    void RemICRVector( struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *, WORD, struct [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) *);
```
FUNCTION

```c
    Disconnect interrupt processing code for a particular
    interrupt bit of the [CIA](autodocs-2.0/includes-hardware-cia-h.md) ICR.

    This function will also disable the [CIA](autodocs-2.0/includes-hardware-cia-h.md) interrupt for the
    given ICR bit.
```
INPUTS

```c
    iCRBit          Bit number to set (0..4).
    interrupt       Pointer to interrupt structure.
```
RESULT

NOTE

```c
    The [CIA](autodocs-2.0/includes-hardware-cia-h.md) resources are special in that there is more than one
    of them in the system. Because of this, the C language stubs
    in amiga.lib for the [CIA](autodocs-2.0/includes-hardware-cia-h.md) resources require an extra parameter
    to specify which [CIA](autodocs-2.0/includes-hardware-cia-h.md) resource to use. The synopsys for the
    amiga.lib stubs is as follows:

    RemICRVector( Resource, iCRBit, interrupt )
                  A6        D0      A1

    void RemICRVector( struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *, WORD, struct [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) *);
```
SEE ALSO

```c
    [cia.resource/AddICRVector()](autodocs-2.0/cia-resource-addicrvector.md)
```
