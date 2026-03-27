---
title: 1 / General Development Guidelines / Hardware Programming Guidelines
manual: libraries
chapter: libraries
section: 1-general-development-guidelines-hardware-programming
functions: []
libraries: []
---

# 1 / General Development Guidelines / Hardware Programming Guidelines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you find it necessary to program the hardware directly, then it is your
responsibility to write code that will work correctly on the various
models and configurations of the Amiga.  Be sure to properly request and
gain control of the hardware resources you are manipulating, and be
especially careful in the following areas:

  * Kickstart 2.0 uses the 8520 Complex Interface Adaptor (CIA) chips

```c
    differently than 1.3 did.  To ensure compatibility, you must always
    ask for CIA access using the cia.resource [AddICRVector()](autodocs-2.0/cia-resource-addicrvector.md) and
    [RemICRVector()](autodocs-2.0/cia-resource-remicrvector.md) functions.  Do not make assumptions about what the
    system might be using the CIA chips for.  If you write directly to
    the CIA chip registers, do not expect system services such as the
    trackdisk device to function.  If you are leaving the system up, do
    not read or write to the CIA Interrupt Control Registers directly;
    use the cia.resource [AbleICR()](autodocs-2.0/cia-resource-ableicr.md), and [SetICR()](autodocs-2.0/cia-resource-seticr.md) functions.  Even if you
    are taking over the machine, do not assume the initial contents of
    any of the CIA registers or the state of any enabled interrupts.
```
  * All [custom chip](libraries/1-programming-in-the-amiga-environment-the-custom-chips.md) registers are Read-only or Write-only.  Do not read

    Write-only registers, and do not write to Read-only registers.
  * Never write data to, or interpret data from the unused bits or

```c
    addresses in the [custom chip](libraries/1-programming-in-the-amiga-environment-the-custom-chips.md) space.  To be software-compatible with
    future chip revisions, all undefined bits must be set to zeros on
    writes, and must be masked out on reads before interpreting the
    contents of the register.
```
  * Never write past the current end of [custom chip](libraries/1-programming-in-the-amiga-environment-the-custom-chips.md) space.  Custom chips

    may be extended or enhanced to provide additional registers, or to
    use bits that are currently undefined in existing registers.
  * Never read, write, or use any currently undefined address ranges or

    registers.  The current and future usage of such areas is reserved
    and is subject to change.
  * Never assume that a [hardware register](hardware/amiga-hardware-reference-manual-b-register-summary-address.md) will be initialized to any

    particular value.  Different versions of the OS may leave registers
    set to different values.  Check the Amiga Hardware Reference Manual
    to ensure that you are setting up all the registers that affect your
    code.
