---
title: F 8520 Complex Interface Adapters / Interrupt Control Register (ICR)
manual: hardware
chapter: hardware
section: f-8520-complex-interface-adapters-interrupt-control
functions: []
libraries: []
---

# F 8520 Complex Interface Adapters / Interrupt Control Register (ICR)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are five sources of interrupts on the 8520:

   - [Underflow from Timer A](hardware/f-interval-timers-timer-a-timer-b-one-shot-continuous.md)  (timer counts down past 0)
   - [Underflow from Timer B](hardware/f-interval-timers-timer-a-timer-b-one-shot-continuous.md) 
   - [TOD alarm](hardware/f-8520-complex-interface-adapters-time-of-day-clock.md) 
   - [Serial port full/empty](hardware/f-serial-shift-register-sdr-input-mode.md) 
   - [Flag](hardware/f-register-functional-description-handshaking.md) 

A single register provides masking and interrupt information.  The
interrupt control register consists of a write-only MASK register and a
read-only DATA register.  Any interrupt will set the corresponding bit in
the DATA register.  Any interrupt that is enabled by a 1-bit in that
position in the MASK will set the IR bit (MSB) of the DATA register and
bring the  [IRQ](hardware/f-interface-signals-irq-interrupt-request-output.md)  pin low.  In a multichip system, the IR bit can be polled to
detect which chip has generated an interrupt request.

When you read the DATA register, its contents are cleared (set to 0), and
the  [IRQ](hardware/f-interface-signals-irq-interrupt-request-output.md)  line returns to a high state.  Since it is cleared on a read, you
must assure that your interrupt polling or interrupt service code can
preserve and respond to all bits which may have been set in the DATA
register at the time it was read.  With proper preservation and response,
it is easily possible to intermix polled and direct interrupt service
methods.

You can set or clear one or more bits of the MASK register without
affecting the current state of any of the other bits in the register. This
is done by setting the appropriate state of the MSBit, which is called the
set/clear bit.  In bits 6-0, you yourself form a mask that specifies which
of the bits you wish to affect.  Then, using bit 7, you specify HOW the
bits in corresponding positions in the mask are to be affected.

*  If bit 7 is a 1, then any bit 6-0 in your own mask byte which is set
   to a 1 sets the corresponding bit in the MASK register.  Any bit that
   you have set to a 0 causes the MASK register bit to remain in its
   current state.

*  If bit 7 is a 0, then any bit 6-0 in your own mask byte which is set
   to a 1 clears the corresponding bit in the MASK register.  Again, any
   0 bit in your own mask byte causes no change in the contents of the
   corresponding MASK register bit.

If an interrupt is to occur based on a particular condition, then that
corresponding MASK bit must be a 1.

Example:  Suppose you want to set the  [Timer A](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  interrupt bit (enable the
 [Timer A](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  interrupt), but want to be sure that all other interrupts are
cleared.  Here is the sequence you can use:


```c
        INCLUDE "hardware/cia.i"
        XREF    _ciaa                   ; From amiga.lib
        lea     _ciaa,a0                ; Defined in amiga.lib
        move.b  #%01111110,ciaicr(a0)
```
MSB is 0, means clear any bit whose value is 1 in the rest of the byte


```c
        INCLUDE "hardware/cia.i"
        XREF    _ciaa                   ; From amiga.lib
        lea     _ciaa,a0                ; Defined in amiga.lib
        move.b  #%10000001,ciaicr(a0)
```
MSB is 1, means set any bit whose value is 1 in the rest of the byte (do
not change any values wherein the written value bit is a zero)

 [Read Interrupt Control Register](hardware/f-interrupt-control-register-icr-read-interrupt-control.md) 
 [Write Interrupt Control Mask](hardware/f-interrupt-control-register-icr-write-interrupt-control.md) 

