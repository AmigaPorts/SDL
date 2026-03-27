---
title: J Custom Chip Pin Allocation List / Fat Agnus Pin Assignment
manual: hardware
chapter: hardware
section: j-custom-chip-pin-allocation-list-fat-agnus-pin-assignment
functions: []
libraries: []
---

# J Custom Chip Pin Allocation List / Fat Agnus Pin Assignment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   PIN #      DESIGNATION     FUNCTION                DEFINITION
   -----      -----------     ------------------      ----------

```c
    01-14     RD15-RD2        Register bus lines 15 to 2  I/O
    17        INT3*           Blitter ready interrupt     O
    18        DMAL            Request audio/disk DMA      I
    18        RD1             Register bus line 1         I/O
    18        RST*            Reset                       I
    19        BLS*            Blitter slowdown            I
    20        DBR*            Data bus request            O
    21        RRW             DRAM Write/Read             O
    22        PRW             Processor Write/Read        I
    23        RGEN*           RG Enable                   I
    24        AS*             Address Strobe              I
    25        RAMEN*          RAM Enable                  I
    26-33     RGA8-RGA1       Register address bus 8-1    O
    34        28MHZ           Master clock                I
    35        XCLK            Alternate master clock      I
    36        XCLKEN*         Master clock enable         I
    37        CDAC*           Inverted shifted 7MHZ clk   O
    38        7MHZ            28MHZ clk divided by four   O
    39        CCKQ            Color clock delay           O
    40        CCK             Color clock                 O
    41        TEST            Test - access registers     I (old Fat Agnus)
              NTSC/PAL        Select video environment    I (ECS Fat Agnus)
    43-51     MA0-MA8         Output bus lines 0 to 8     O
    52        LDS*            Lower data strobe           I
    53        UDS*            Upper data strobe           I
    54        CASL*           Column addr strobe lower    O
    55        CASU*           Column addr strobe upper    O
    56        RAS1*           Row address strobe one      O
    57        RAS0*           Row address strobe zero     O
    59-77     A19-A1          Address bus lines 19 to 1   I
    78        LP*             Light pen                   O
    79        VSY*            Vertical synch              I/O
    80        CSY*            Composite video synch       O
    81        HSY*            Horizontal synch            I/O
    84        RD0             Register bus line 0         I/O
```
