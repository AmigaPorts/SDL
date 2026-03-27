---
title: E / Amiga I/O Connector Pins / External Disk
manual: hardware
chapter: hardware
section: e-amiga-i-o-connector-pins-external-disk
functions: []
libraries: []
---

# E / Amiga I/O Connector Pins / External Disk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

EXTERNAL DISK ...DB23 FEMALE
----------------------------

For A1000, A500, A2000 and A3000 with A2000 and A3000 differences noted.

1   [RDY*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)                             13  [SIDEB*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 
2   [DKRD*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)                            14  [WPRO*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 
3   GND                              15  [TK0*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 
4   GND                              16  [DKWEB*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 
5   GND                              17  [DKWDB*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 
6   GND                              18  [STEPB*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 
7   GND                              19  [DIRB](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 
8   [MTRXD*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)                           20  [SEL3B*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) (A2000/A3000 not used (1))
9   [SEL2B*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) (A2000/A3000 [SEL3B*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) (1))  21  [SEL1B*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) (A2000/A3000 [SEL2B*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) (1))
10  [DRESB*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)                           22  [INDEX*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 
11  [CHNG*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)                            23  [+12](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 
12  [+5](hardware/e-external-disk-interface-specification-pin-assignment-j7.md) 

(1)  [SEL1B*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)  is not drive 1, but rather the first external drive.  Not

    all select lines may be implemented.
