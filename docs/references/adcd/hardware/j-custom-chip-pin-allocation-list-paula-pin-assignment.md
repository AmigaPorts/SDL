---
title: J Custom Chip Pin Allocation List / Paula Pin Assignment
manual: hardware
chapter: hardware
section: j-custom-chip-pin-allocation-list-paula-pin-assignment
functions: []
libraries: []
---

# J Custom Chip Pin Allocation List / Paula Pin Assignment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   PIN #      DESIGNATION     FUNCTION                DEFINITION
   -----      -----------     ------------------      ----------

    01-07     D8-D2           Data bus lines 8 to 2       I/O
    08        VSS             Ground                      I
    09-10     D1-D0           Data bus lines 1 and 0      I/O
    11        RES*            System reset                I
    12        DMAL            DMA request line            O
    13-15     IPL0*-IPL2      Interrupt lines 0-2         O
    16        INT2*           Interrupt level 2           I
    17        INT3*           Interrupt level 3           I
    18        INT6*           Interrupt level 6           I
    19-26     RGA8-RGA1       Register address bus 8-1    I
    27        VCC             +5 Volt                     I
    28        CCK             Color clock                 I
    29        CCKQ            Color clock delay           I
    30        AUDB            Right audio                 O
    31        AUDA            Left audio                  O
    32        POT0X           Pot 0X                      I/O
    33        POT0Y           Pot 0Y                      I/O
    34        VSSANA          Analog ground               I
    35        POT1X           Pot 1X                      I/O
    36        POT1Y           Pot 1Y                      I/O
    37        DKRD*           Disk read data              I
    38        DKWD*           Disk write data             O
    39        DKWE            Disk write enable           O
    40        TXD             Serial transmit data        O
    41        RXD             Serial receive data         I
    42-48     D15-D9          Data bus lines 15 to 9      I/O
