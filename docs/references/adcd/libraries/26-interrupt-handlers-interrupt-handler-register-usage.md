---
title: 26 / / Interrupt Handlers / Interrupt Handler Register Usage
manual: libraries
chapter: libraries
section: 26-interrupt-handlers-interrupt-handler-register-usage
functions: [SetIntVector]
libraries: [exec.library]
---

# 26 / / Interrupt Handlers / Interrupt Handler Register Usage

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here are the register conventions for interrupt handlers.

 D0 Contains no valid information.

 D1 Contains the 4703 [INTENAR](hardware/7-interrupts-interrupt-control-registers.md) and [INTREQR](hardware/7-interrupts-interrupt-control-registers.md) registers values AND'ed

    together.  This results in an indication of which interrupts are
    enabled and active.
 A0 Points to the base address of the Amiga custom chips.  This

    information is useful for performing indexed instruction access to
    the chip registers.
 A1 Points to the data area specified by the [is_Data](libraries/26-servicing-interrupts-interrupt-data-structure.md) field of the

```c
    [Interrupt](libraries/26-servicing-interrupts-interrupt-data-structure.md) structure.  Because this pointer is always fetched
    (regardless of whether you use it), it is to your advantage to make
    some use of it.
```
 A5 Is used as a vector to your interrupt code.

 A6 Points to the Exec library base (SysBase).  You may use this register

    to call Exec functions or set it up as a base register to access your
    own library or device.
Interrupt handlers are established by passing the Exec function
[SetIntVector()](autodocs-2.0/exec-library-setintvector.md), your initialized [Interrupt](libraries/26-servicing-interrupts-interrupt-data-structure.md) structure, and the 4703
interrupt bit number of interest.  The parameters for this function are as
follows:


```c
    SetIntVector(ULONG intNumber, struct Interrupt *interrupt)
```
The first argument is the bit number for which this interrupt server is to
respond (example INTB_VERTB).  The possible bits for interrupts are
defined in <hardware/[intbits.h](autodocs-2.0/includes-hardware-intbits-h.md)>.  The second argument is the address of an
[interrupt server node](libraries/26-servicing-interrupts-interrupt-data-structure.md) as described earlier in this chapter.  Keep in mind
that certain interrupts are established as server chains and should not be
accessed as handlers.

The following example demonstrates initialization and installation of an
assembler interrupt handler.  See the "[Resources](devices/15-resources.md)" chapter for more
information on allocating resources, and the "[Serial Device](devices/12-serial-device.md)" chapter in
the Amiga ROM Kernel Reference Manual: Devices for the more common method
of serial communications.


```c
     [rbf.c](libraries/lib-examples-rbf-c.md) 
```
The assembler interrupt handler code, RBFHandler, reads the complete word
of serial input data from the serial hardware and then separates the
character and flag bytes into separate buffers. When the buffers are full,
the handler signals the main process causing main to print the character
buffer contents, remove the handler, and exit.


```c
     [rbfhandler.asm](libraries/lib-examples-rbfhandler-asm.md) 

    NOTE.
    -----
    The data structure containing the signal to use, task address
    pointer, and buffers is allocated and initialized in main(), and
    passed to the handler via the [is_Data](libraries/26-servicing-interrupts-interrupt-data-structure.md) pointer of the [Interrupt](libraries/26-servicing-interrupts-interrupt-data-structure.md)
    structure.
```

---

## See Also

- [SetIntVector — exec.library](../autodocs/exec.library.md#setintvector)
