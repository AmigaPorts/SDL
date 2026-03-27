---
title: H External Disk Connector Interface / Summary Table
manual: hardware
chapter: hardware
section: h-external-disk-connector-interface-summary-table
functions: []
libraries: []
---

# H External Disk Connector Interface / Summary Table

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
     Pin #   Name        Note
     -----   ----        ----
     1       [RDY-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)        I/O     ID and ready
     2       [DKRD-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)       I       MFM input
     3       GRND        G       -
     4       GRND        G       -
     5       GRND        G       -
     6       GRND        G       -
     7       GRND        G       -
     8       [MTRXD-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      O       Motor control.
     9       [SEL2B-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      O*      Select drive 2
     10      [DRESB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      O       Reset
     11      [CHNG-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)       I/O     Disk changed
     12      +5v         PWR     540 mA average 870 mA surge
     13      [SIDEB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      O       Side 1 if low
     14      [WPRO-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)       I/O     Write protect
     15      [TK0-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)        I/O     Track 0
     16      [DKWEB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      O       Write gate
     17      [DKWDB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      O       Write data
     18      [STEPB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      O       Step
     19      [DIRB](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)        O       Direction (high is out)
     20      [SEL3B-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      O*      Select drive 3
     21      [SEL1B-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      O*      Select drive 1
     22      [INDEX-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)      I/O     Index
     23      +12v        PWR     120 mA average 370 mA surge
```
   Key to Class:


```c
        G       ground, note connector shield grounded.
        I       input pulled up to 5v by 1K ohm.
        I/O     input in driver, but bidirectional input (1k pullup)
        O       output pulled though 1K to 5v
        O*      output, separates resources.
        PWR     available for external use, but currently used up by
                external drive.
```
