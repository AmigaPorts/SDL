---
title: E / Amiga I/O Connector Pins / Expansion
manual: hardware
chapter: hardware
section: e-amiga-i-o-connector-pins-expansion
functions: []
libraries: []
---

# E / Amiga I/O Connector Pins / Expansion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

EXPANSION ...86 PIN EDGE (.1) (P2)
----------------------------------

See Appendix K for the  [100 pin](hardware/k-zorro-expansion-bus-physical-and-logical-signal-names.md)  Zorro II and Zorro III bus connector

   PIN     A500    A1000   A2000   A2000b  FUNCTION
   ---     ----    -----   -----   ------  --------
   1       x       x       x       x       ground
   2       x       x       x       x       ground
   3       x       x       x       x       ground
   4       x       x       x       x       ground
   5       x       x       x       x       +5VDC
   6       x       x       x       x       +5VDC
   7       x       x       x       x       No Connect
   8       x       x       x       x       -5VDC
   9       x       x                       No Connect
                           x       x       28MHz Clock
   10      x       x       x       x       +12VDC
   11      x       x       x               No Connect
```c
                                   x       /COPCFG (Configuration Out)
```
   12      x       x       x       x       CONFIG IN, Grounded
   13      x       x       x       x       Ground
   14      x       x       x       x       /C3 Clock
   15      x       x       x       x       CDAC Clock
   16      x       x       x       x       /C1 Clock
   17      x       x       x       x       /OVR
   18      x       x       x       x       RDY
   19      x       x       x       x       /INT2
   20              x                       /PALOPE
           x               x               No Connect
                                   x       /BOSS
   21      x       x       x       x       A5
   22      x       x       x       x       /INT6
   23      x       x       x       x       A6
   24      x       x       x       x       A4
   25      x       x       x       x       ground
   26      x       x       x       x       A3
   27      x       x       x       x       A2
   28      x       x       x       x       A7
   29      x       x       x       x       A1
   30      x       x       x       x       A8
   31      x       x       x       x       FC0
   32      x       x       x       x       A9
   33      x       x       x       x       FC1
   34      x       x       x       x       A10
   35      x       x       x       x       FC2
   36      x       x       x       x       A11
   37      x       x       x       x       Ground
   38      x       x       x       x       A12
   39      x       x       x       x       A13
   40      x       x       x       x       /IPL0
   41      x       x       x       x       A14
   42      x       x       x       x       /IPL1
   43      x       x       x       x       A15
   44      x       x       x       x       /IPL2
   45      x       x       x       x       A16
   46      x       x       x       x       BEER*
   47      x       x       x       x       A17
   48      x       x       x       x       /VPA
   49      x       x       x       x       Ground
   50      x       x       x       x       E Clock
   51      x       x       x       x       /VMA
   52      x       x       x       x       A18
   53      x       x       x       x       RST
   54      x       x       x       x       A19
   55      x       x       x       x       /HLT
   56      x       x       x       x       A20
   57      x       x       x       x       A22
   58      x       x       x       x       A21
   59      x       x       x       x       A23
   60      x       x       x               /BR
                                   x       /CBR
   61      x       x       x       x       Ground
   62      x       x       x       x       /BGACK
   63      x       x       x       x       D15
   64      x       x       x               /BG
                                   x       /CBG
   65      x       x       x       x       D14
   66      x       x       x       x       /DTACK
   67      x       x       x       x       D13
   68      x       x       x       x       R/W
   69      x       x       x       x       D12
   70      x       x       x       x       /LDS
   71      x       x       x       x       D11
   72      x       x       x       x       /UDS
   73      x       x       x       x       Ground
   74      x       x       x       x       /AS
   75      x       x       x       x       D0
   76      x       x       x       x       D10
   77      x       x       x       x       D1
   78      x       x       x       x       D9
   79      x       x       x       x       D2
   80      x       x       x       x       D8
   81      x       x       x       x       D3
   82      x       x       x       x       D7
   83      x       x       x       x       D4
   84      x       x       x       x       D6
   85      x       x       x       x       Ground
   86      x       x       x       x       D5

