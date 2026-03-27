---
title: K / / Signal Description / Addressing and Control Signals
manual: hardware
chapter: hardware
section: k-signal-description-addressing-and-control-signals
functions: []
libraries: []
---

# K / / Signal Description / Addressing and Control Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These signals are various items used for the addressing of devices in
Zorro II mode by the local bus and any expansion DMA devices.  Most of
these signals are very much like 68000 generated bus signals
bi-directionally buffered to allow any DMA device on the bus to drive the
local bus when such a device is the bus master.

Read Enable (READ)
   This is the read enable for the bus, which is equivalent to the
   68000's R/W output.  READ asserted during a bus cycle indicates a
   read cycle, READ negated indicates a write cycle.  Note that this
   signal may become valid in a cycle earlier than a 68000 R/W line
   would, but it  remains valid at least as long at the cycle's end.

Address Bus (A1-A23)
   This is logically equivalent to the 68000's address bus, providing 16
   megabytes of address space, although much of that space is not
   assigned to the expansion bus (see the memory map in  [Figure K-1](hardware/k-general-the-zorro-iii-rationale.md) .

Address Strobe  (/AS) := ( [/CCS](hardware/k-signal-description-address-and-related-control-signals.md) ) for Zorro III
   This is equivalent to the 68000 /AS, called  [/CCS](hardware/k-signal-description-address-and-related-control-signals.md) , for Compatibility
   Cycle Strobe, in the Zorro III nomenclature.  The falling edge of
   this strobe indicates that addresses are valid, the READ line is
   valid, and a Zorro II cycle is starting.  The rising edge signals the
   end of a Zorro II bus cycle, signaling the current slave to negate
   all slave-driven signals as quickly as possible.  Note that  [/CCS](hardware/k-signal-description-address-and-related-control-signals.md) ,
   like /AS, can stay asserted during a read-modify-write access over
   multiple cycle boundaries.  To correctly support such cycles, a
   device must consider both the state of  [/CCS](hardware/k-signal-description-address-and-related-control-signals.md)  and the state of the data
   strobes.  Many current Zorro II cards don't correctly support this
   680x0 style bus lock.

Data Bus (D0-D15)
   This is a buffered version of the 680x0 data bus, providing 16 bits
   of data accessible by word or either byte.  A PIC uses the  [DOE](hardware/k-signal-description-slot-control-signals.md)  signal
   to determine when the bus is to be driven on reads, and the data
   strobes to determine when data is valid on writes.

Data Strobes (/UDS, /LDS) := ( [/DS3, /DS2](hardware/k-signal-description-data-and-related-control-signals.md) ) for Zorro III
   These strobes fall on data valid during writes, and indicate byte
   select for both reads and writes.  The lower strobe is used for the
   lower byte (even byte), the upper strobe is used for the upper byte
   (odd byte).  There is one slight difference between these lines and
   the 68000 data strobes.  On reads of Zorro II memory space, both  [/DS3](hardware/k-signal-description-data-and-related-control-signals.md) 
   and  [/DS2](hardware/k-signal-description-data-and-related-control-signals.md)  will be asserted, no matter what the actual size of the
   requested transfer is.  This is required to support caching of the
   Zorro II memory space.  For Zorro II I/O space, these strobes
   indicate the actual, requested byte enables, just as would a 68000
   bus master.

Data Transfer Acknowledge (/DTACK)
   This signal is used to normally terminate both Zorro bus cycles.  For
   Zorro II modes, it is equivalent to the 68000's Data Transfer
   Acknowledge input. It can be asserted by the bus slave during a Zorro
   II cycle at any time, but won't be sampled by the bus master until
   the falling edge of the S4 state on the bus.  Data will
   subsequently be latched on the S6 falling edge after this,
   and the cycle terminated with /AS negated during S7.  If a
   Zorro II slave does nothing, this /DTACK will be driven by the bus
   controller with no wait states, making the bus essentially a 4-cycle
```c
    [synchronous](hardware/k-basic-zorro-iii-bus-cycles-design-goals.md)  bus.  Any slow device on the bus that needs wait states
```
   has two options.  It can modify the automatic /DTACK negating XRDY to
   hold off /DTACK.  Alternately, it may assert /OVR to inhibit the bus
   controller's generation of /DTACK, allowing the slave to create its
   own /DTACK.  Any /DTACK supplied by a slave must be driven with an
```c
    [open-collector](hardware/k-expansion-bus-loading-open-collector-signals.md)  or similar type output; the backplane provides a
```
   passive pullup.

Processor Status (FC0-FC2)
   These signals are the cycle type or memory space bits, equivalent for
   the most part with the 68000 Processor Status outputs.  They function
   mainly as extensions to the bus address, indicating which type of
   access is taking place.  For Zorro II devices, any use of these lines
   must be gated with  [/BGACK](hardware/k-signal-description-dma-control-signals.md) , since they are not driven valid by Zorro
   II bus masters.  However, when operating on the Zorro III backplane,
   Zorro II masters that don't drive the function codes will be seen
   generating an FC1 = 0, which results in a valid memory access.  Zorro
   II cycles are not generated for invalid memory spaces when the CPU is
   the bus master.

/DTACK Override (/OVR)
   This signal is driven by a Zorro II slave to allow that slave to
   prevent the bus controller's /DTACK generation.  This allows the
   slave to generate its own /DTACK.  The previous use of this line to
   disable motherboard memory mapping, which was unsupported on the
   A2000 expansion bus, has now been completely removed.  The use of
   XDRY or /OVR in combination with /DTACK is completely up to the board
   designer -- both methods are equally valid ways for a slave to delay
   /DTACK.  In  [Zorro III mode](hardware/k-zorro-expansion-bus-physical-and-logical-signal-names.md) , this pin is used for something completely
   different.

External Ready (XRDY)
   This active high signal allows a slave to delay the bus controller's
   assertion of /DTACK, in order to add wait states.  XRDY must be
   negated within 60ns of the bus master's assertion of /AS, and it will
   remain negated until the slave wants /DTACK.  The /DTACK signal will
   be asserted by the bus controller shortly following the assertion of
   XRDY, providing the bus cycle is a S4 or later.  XRDY is a wired-OR
   from all PICs, and as such, must be driven by an  [open collector](hardware/k-expansion-bus-loading-open-collector-signals.md)  or
   equivalent output.  In  [Zorro III mode](hardware/k-zorro-expansion-bus-physical-and-logical-signal-names.md) , this pin is used for something
   completely different.

