---
title: 32 Expansion Library / AUTOCONFIG(TM)
manual: libraries
chapter: libraries
section: 32-expansion-library-autoconfig-tm
functions: []
libraries: []
---

# 32 Expansion Library / AUTOCONFIG(TM)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga AUTOCONFIG protocol is designed to allow the dynamic assignment
of available address space to expansion boards, eliminating the need for
user configuration via jumpers. Such expansion boards include memory
boards, hard disk controllers, network interfaces, and other special
purpose expansion devices. Some expansion devices, such as RAM boards,
require no special driver software.  Other types of expansion devices may
use a disk-loaded driver from the DEVS: or SYS:Expansion drawer, or an
on-board ROM driver (for example, a self-booting hard disk controller).

This chapter will concentrate on the software and driver side of Zorro
expansion devices, using a Zorro II device as an example. Zorro III
devices have additional identifying bits and memory size options which are
described in the Zorro III hardware documentation. For more information on
Zorro II and Zorro III expansion hardware, see the "[Zorro Expansion Bus](hardware/amiga-hardware-reference-manual-k-zorro-expansion-bus.md)"
appendix of the Amiga Hardware Reference Manual, 3rd Edition from
Addison-Wesley.  For additional information specific to Zorro II boards,
see the Commodore publication A500/A2000 Technical Reference Manual.

AUTOCONFIG occurs whenever the Amiga is powered on or reset.  During early
system initialization, expansion.library identifies the expansion boards
that are installed in the Amiga and dynamically assigns an appropriate
address range for each board to reside at.  During this AUTOCONFIG
process, each expansion board first appears in turn at $E80000 (Zorro II)
or $FF000000 (Zorro III), presenting readable identification information,
generally in a PAL or a ROM, at the beginning of the board.  The
identification includes the size of the board, its address space
preferences, type of board (memory or other), and a unique Hardware
Manufacturer Number assigned by Commodore Applications and Technical
Support ([CATS](libraries/1-introduction-commodore-applications-and-technical-support.md)), West Chester, Pennsylvania.

The unique Hardware Manufacturer number, in combination with a
vendor-supplied product number, provides a way for boards to be identified
and for disk-based drivers to be matched with expansion boards.  All
expansion boards for the Amiga must implement the AUTOCONFIG protocol.


```c
    Note:
    -----
    A unique Hardware Manufacturer number assigned by [CATS](libraries/1-introduction-commodore-applications-and-technical-support.md) is not the
    same as a Developer number.
```
