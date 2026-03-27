---
title: cia.resource/AbleICR
manual: autodocs-2.0
chapter: autodocs-2.0
section: cia-resource-ableicr
functions: []
libraries: []
---

# cia.resource/AbleICR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AbleICR -- Enable/disable ICR interrupts.
SYNOPSIS

```c
    oldMask = AbleICR( Resource, mask )
    D0                 A6        D0

    WORD AbleICR( struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *, WORD );
```
FUNCTION

```c
    This function provides a means of enabling and disabling 8520
    [CIA](autodocs-2.0/includes-hardware-cia-h.md) interrupt control registers. In addition it returns the
    previous enable mask.
```
INPUTS

    mask            A bit mask indicating which interrupts to be
                        modified. If bit 7 is clear the mask
                        indicates interrupts to be disabled. If
                        bit 7 is set, the mask indicates
                        interrupts to be enabled. Bit positions
                        are identical to those in 8520 ICR.
RESULTS

    oldMask         The previous enable mask before the requested
                        changes. To get the current mask without
                        making changes, call the function with a
                        null parameter.
EXAMPLES

```c
    Get the current mask:
        mask = AbleICR(0)
    Enable both timer interrupts:
        AbleICR(0x83)
    Disable serial port interrupt:
        AbleICR(0x08)
```
EXCEPTIONS

```c
    Enabling the mask for a pending interrupt will cause an
    immediate processor interrupt (that is if everything else is
    enabled). You may want to clear the pending interrupts with
    [SetICR()](autodocs-2.0/cia-resource-seticr.md) prior to enabling them.
```
NOTE

```c
    The [CIA](autodocs-2.0/includes-hardware-cia-h.md) resources are special in that there is more than one
    of them in the system. Because of this, the C language stubs
    in amiga.lib for the [CIA](autodocs-2.0/includes-hardware-cia-h.md) resources require an extra parameter
    to specify which [CIA](autodocs-2.0/includes-hardware-cia-h.md) resource to use. The synopsys for the
    amiga.lib stubs is as follows:

    oldMask = AbleICR( Resource, mask )
    D0                 A6        D0

    WORD AbleICR( struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *, WORD );
```
SEE ALSO

```c
    [cia.resource/SetICR()](autodocs-2.0/cia-resource-seticr.md)
```
