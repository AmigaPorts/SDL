---
title: J Custom Chip Pin Allocation List / Denise Pin Assignment
manual: hardware
chapter: hardware
section: j-custom-chip-pin-allocation-list-denise-pin-assignment
functions: []
libraries: []
---

# J Custom Chip Pin Allocation List / Denise Pin Assignment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   PIN #      DESIGNATION     FUNCTION                DEFINITION
   -----      -----------     ------------------      ----------

```c
    01-07     D6-D0           Data bus lines 6 to 0       I/O
    08        M1H             Mouse 1 horizontal          I
    09        M0H             Mouse 0 horizontal          I
    10-17     RGA8-RGA1       Register address bus 8-1    I
    18        BURST*          Color burst                 O
    19        VCC             +5 Volt                     I
    20-23     R0-R3           Video red bits 0-3          O
    24-27     B0-B3           Video blue bits 0-3         O
    28-31     G0-G3           Video green bits 0-3        O
    32        /CSYNC          Composite sync              I
    33        ZD*             Background indicator        O
    34        N/C             Not connected               N/C (old Denise)
              CDAC            CDAC clock                  I   (ECS Denise)
    35        7M              7.15909  MHZ                I
    36        CCK             Color clock                 I
    37        VSS             Ground                      I
    38        M0V             Mouse 0 vertical            I
    39        M1V             Mouse 1 vertical            I
    40-48     D15-D7          Data bus lines 15 to 7      I/O
```
