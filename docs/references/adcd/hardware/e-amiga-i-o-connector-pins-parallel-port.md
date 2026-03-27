---
title: E / Amiga I/O Connector Pins / Parallel Port
manual: hardware
chapter: hardware
section: e-amiga-i-o-connector-pins-parallel-port
functions: []
libraries: []
---

# E / Amiga I/O Connector Pins / Parallel Port

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Parallel (Centronics) Port
--------------------------

   PIN     A1000       A500/A2000/A3000    Commodore PCs
   ---     -----       ----------------   -------------
   1       [DRDY*](hardware/e-parallel-interface-specification-pin-assignment-j8.md)           STROBE*         STROBE*
   2       [Data 0](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 0](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 0](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   3       [Data 1](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 1](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 1](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   4       [Data 2](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 2](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 2](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   5       [Data 3](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 3](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 3](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   6       [Data 4](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 4](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 4](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   7       [Data 5](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 5](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 5](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   8       [Data 6](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 6](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 6](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   9       [Data 7](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 7](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          [Data 7](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   10      [ACK*](hardware/e-parallel-interface-specification-pin-assignment-j8.md)            [ACK*](hardware/e-parallel-interface-specification-pin-assignment-j8.md)            [ACK*](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   11      [BUSY](hardware/e-parallel-interface-specification-pin-assignment-j8.md) (data)     [BUSY](hardware/e-parallel-interface-specification-pin-assignment-j8.md)            [BUSY](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   12      [POUT](hardware/e-parallel-interface-specification-pin-assignment-j8.md) (clk)      [POUT](hardware/e-parallel-interface-specification-pin-assignment-j8.md)            [POUT](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   13      [SEL](hardware/e-parallel-interface-specification-pin-assignment-j8.md)             [SEL](hardware/e-parallel-interface-specification-pin-assignment-j8.md)             [SEL](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 
   14      GND             +5v pullup      AUTOFDXT
   15      GND             NC              ERROR*
   16      GND             [RESET*](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          INIT*
   17      GND             GND             SLCT IN*
   18-22   GND             GND             GND
   23      + 5             GND             GND
   24      NC              GND             GND
   25      [Reset*](hardware/e-parallel-interface-specification-pin-assignment-j8.md)          GND             GND

