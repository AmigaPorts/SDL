---
title: K / / Signal Description / System Control Signals
manual: hardware
chapter: hardware
section: k-signal-description-system-control-signals
functions: []
libraries: []
---

# K / / Signal Description / System Control Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The signals in this group are available for various types of system
control; most of these have an immediate or near immediate effect on
expansion cards and/or the system CPU itself.

Bus Error (/BERR)
   This is a general indicator of a bus fault condition.  Any expansion
   card capable of detecting a hardware error relating directly to that
   card can assert /BERR when that bus error condition is detected,
   especially any sort of harmful hardware error condition.  This signal
   is the strongest possible indicator of a bad situation, as it causes
   all PICs to get  off the bus, and will usually generate a level 2
   exception on the host CPU. For any condition that can be handled in
   software and doesn't pose an immediate threat to hardware,
   notification via a standard processor interrupt  is the better
   choice.  The bus controller will drive /BERR in the event of a
   detected bus collision or DMA error (an attempt by a bus master to
   access local bus resources it doesn't have valid access permission
   for). All cards must monitor /BERR and be prepared to tri-state all
   of their on-bus output buffers whenever this signal is asserted.  The
   current bus master should, if possible, retry the bus cycle after
   /BERR is negated unless conditions warrant otherwise.  Since any
   number of devices may assert /BERR, and all bus cards must monitor
   it, any device that drives /BERR must drive with an  [open collector](hardware/k-expansion-bus-loading-open-collector-signals.md)  or
   similar device capable of sinking at least 12ma, and any device that
   monitors /BERR should place a minimal load on it  (1 "F" type load or
   less).  This signal is pulled high by a passive backplane resistor.

System Reset (/RST, /BUSRST) := ( [/RESET, /IORST](hardware/k-signal-description-system-control-signals-2.md) ) for Zorro III
   The bus supplies two versions of the system reset signal.  The /RST
   signal is bidirectional and unbuffered, allowing an expansion card to
   hard reset the system.  It should only be used by boards that need
   this reset capability, and is driven only by an  [open collector](hardware/k-expansion-bus-loading-open-collector-signals.md)  or
   similar device.  The /BUSRST signal is a buffered output-only version
   of the reset signal that should be used as the normal reset input to
   boards not concerned with resetting the system on their own.  All
   expansion devices are required to reset their  [autoconfiguration](hardware/k-autoconfig-tm-the-autoconfig-mechanism.md)  logic
   when /BUSRST is asserted.  This signal is pulled high by a passive
   backplane resistor.

System Halt (/HLT)
   This signal is similar to the 68000 processor halt signal, and is
   driven by a PIC with an  [open-collector](hardware/k-expansion-bus-loading-open-collector-signals.md)  or similar gate only. Its main
   use is to indicate a full-system reset.  Based on the 68000
   conventions, an I/O-only reset, such as initiated by the 680x0 RESET
   instruction, will drive only /RST and /BUSRST on the bus.  A
   full-system reset, such as a powerup reset or a keyboard reset,
   drives /HLT low as well.  PICs that wish to reset the system CPU as
   well as the bus and I/O devices drive /RST and /HLT, some bus devices
   such as processor cards may internally reset only on full-system
   resets.  This signal is pulled high by a passive backplane resistor.

System Interrupts
   Six of the decoded, level sensitive 680x0 interrupt inputs were
   originally available on the expansion bus, and these are labelled as
   /INT2, /INT6, /EINT1, /EINT4, /EINT5, /EINT7 on the Zorro II bus.
   Only the /INT2 and /INT6 interrupt inputs are actually supported by
   Amiga, Inc. as part of the Zorro II specification; the A2000
   hardware did not provide the software with the required support
   mechanisms for the safe use of these lines. Each of these interrupt
   lines are shared by wired ORing, thus each line must be driven by an
```c
    [open-collector](hardware/k-expansion-bus-loading-open-collector-signals.md)  or equivalent output type, and all are pulled high by
```
   passive backplane resistors.

