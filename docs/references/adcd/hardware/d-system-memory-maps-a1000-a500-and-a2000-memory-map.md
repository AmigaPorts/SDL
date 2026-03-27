---
title: D System Memory Maps / A1000, A500 and A2000 Memory Map
manual: hardware
chapter: hardware
section: d-system-memory-maps-a1000-a500-and-a2000-memory-map
functions: []
libraries: []
---

# D System Memory Maps / A1000, A500 and A2000 Memory Map

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Address Range           Description
-----------------       ------------------------------------------------
00 0000 - 03 FFFF       256K Chip RAM (A1000 Chip RAM,

```c
                            1st 256K for A500/A2000)
```
04 0000 - 07 FFFF       256K bytes of Chip RAM (2nd 256K for A500/A2000)

08 0000 - 0F FFFF       512K  [Extended chip RAM](hardware/c-new-features-of-the-enhanced-chip-set-new-memory-limits.md)  (to 1 MB for A2000).

10 0000 - 1F FFFF       Reserved. Do not use.

20 0000 - 9F FFFF       Primary  [8 MB Auto-config space](hardware/k-changes-from-a2000-bus-bus-memory-mapping-and-cache.md) .

A0 0000 - BE FFFF       Reserved. Do not use.

BF D000 - BF DF00        [8520-B](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  (access at even-byte addresses only)
    -         -
BF E001 - BF EF01        [8520-A](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  (access at odd-byte addresses only)

```c
    -         -
                        The underlined digit chooses which of the
                         [16 internal registers](hardware/f-8520-complex-interface-adapters-chip-register-map.md)  of the 8520 is to be
                        accessed.  See Appendix F.
```
C0 0000 - DF EFFF       Reserved.  Do not use.
   |
   | C0 0000 - D7 FFFF  Internal expansion (slow) memory (on some systems).
   |
   | D8 0000 - DB FFFF  Reserved.  Do not use.
   |
   | DC 0000 - DC FFFF  Real time clock (not accessable on all systems).
   |
   | DF F000 - DF FFFF  Chip registers.  See  [Appendix A](hardware/amiga-hardware-reference-manual-a-register-summary.md)  and  [Appendix B](hardware/amiga-hardware-reference-manual-b-register-summary-address.md) .
   +--

E0 0000 - E7 FFFF       Reserved.  Do not use.

E8 0000 - E8 FFFF        [Auto-config space](hardware/k-changes-from-a2000-bus-bus-memory-mapping-and-cache.md) .  Boards appear here before

                        the system relocates them to their final address.
E9 0000 - EF FFFF       Secondary  [auto-config space](hardware/k-changes-from-a2000-bus-bus-memory-mapping-and-cache.md)  (usually 64K I/O

```c
                        boards).
```
F0 0000 - FB FFFF       Reserved.  Do not use.

FC 0000 - FF FFFF       256K System ROM.

