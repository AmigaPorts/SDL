---
title: cia.resource/SetICR
manual: autodocs-2.0
chapter: autodocs-2.0
section: cia-resource-seticr
functions: []
libraries: []
---

# cia.resource/SetICR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetICR -- Cause, clear, and sample ICR interrupts.
SYNOPSIS

```c
    oldMask = SetICR( Resource, mask )
    D0                A6        D0

    WORD SetICR( struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *, WORD );
```
FUNCTION

```c
    This function provides a means of reseting, causing, and
    sampling 8520 [CIA](autodocs-2.0/includes-hardware-cia-h.md) interrupt control registers.
```
INPUTS

    mask            A bit mask indicating which interrupts to be
                        effected. If bit 7 is clear the mask
                        indicates interrupts to be reset.  If bit
                        7 is set, the mask indicates interrupts to
                        be caused. Bit positions are identical to
                        those in 8520 ICR.
RESULTS

    oldMask         The previous interrupt register status before
                        making the requested changes.  To sample
                        current status without making changes,
                        call the function with a null parameter.
EXAMPLES

```c
    Get the interrupt mask:
        mask = SetICR(0)
    Clear serial port interrupt:
        SetICR(0x08)
```
NOTE

```c
    The [CIA](autodocs-2.0/includes-hardware-cia-h.md) resources are special in that there is more than one
    of them in the system. Because of this, the C language stubs
    in amiga.lib for the [CIA](autodocs-2.0/includes-hardware-cia-h.md) resources require an extra parameter
    to specify which [CIA](autodocs-2.0/includes-hardware-cia-h.md) resource to use. The synopsys for the
    amiga.lib stubs is as follows:

    oldMask = SetICR( Resource, mask )
    D0                A6        D0

    WORD SetICR( struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *, WORD );

    ***WARNING***

    Never read the contents of the [CIA](autodocs-2.0/includes-hardware-cia-h.md) interrupt control registers
    directly.  Reading the contents of one of the [CIA](autodocs-2.0/includes-hardware-cia-h.md) interrupt
    control registers clears the register.  This can result in
    interrupts being missed by critical operating system code, and
    other applications.
```
EXCEPTIONS

    Setting an interrupt bit for an enabled interrupt will cause
    an immediate interrupt.
SEE ALSO

```c
    [cia.resource/AbleICR()](autodocs-2.0/cia-resource-ableicr.md)
```
