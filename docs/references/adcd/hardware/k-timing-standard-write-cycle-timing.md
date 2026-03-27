---
title: K / Timing / Standard Write Cycle Timing
manual: hardware
chapter: hardware
section: k-timing-standard-write-cycle-timing
functions: []
libraries: []
---

# K / Timing / Standard Write Cycle Timing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   No.  Name                                   Symbol  Min     Max
   ---  ----                                   ------  ---     ---
   1    Address setup to  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)                 TAFS    15ns     --
   2    Address hold from  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)                THAF    10ns     --
   3    [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  to  [/SLAVEn](hardware/k-signal-description-slot-control-signals-2.md)  delay               TSLV     --     25ns
   4    [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  to  [DOE](hardware/k-signal-description-data-and-related-control-signals.md)  delay                   TDOE    30ns     --
   5    [DOE](hardware/k-signal-description-data-and-related-control-signals.md)  to  [/DSn](hardware/k-signal-description-data-and-related-control-signals.md)  delay                   TDS     10ns     --
   7    [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)  to  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  off                  TOFF    10ns     --
   8    Master signal hold from  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  off     THMC    0ns     5ns
   9    Slave signal hold from  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  off      THSC    0ns     15ns
   10   Write data setup to  [/DSn](hardware/k-signal-description-data-and-related-control-signals.md)              TWDS    5ns      --
   11   [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  to  [/CCS](hardware/k-signal-description-address-and-related-control-signals.md)  delay                  TCCS    35ns    175ns
   12   [/CCS](hardware/k-signal-description-address-and-related-control-signals.md)  off to  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  off                TOVL    40ns     --

         ______                                                ___________
    /FCS       \ |   |                                        /
                \____________________________________________/ |   |    |
                                                               |   |    |
              2->|   |<-                                    8->|   |<-  |
             _________                                         |   |    |
  A31-A8 ___/         \___________________________________________________
            \_________/
                                                               |   |    |
          1->|   |<-                                           |   |    |
             _____________________________________________________ |    |
   A7-A2 ___/                                                     \_______
            \_____________________________________________________/
                                                                   |    |
         __  |                                                 |   _______
    READ   \ |                                                 |  /
         ___\____________________________________________________/________

              3->|    |<-                                      |<---9-->|
         ___________  |                                        |        __
 /SLAVEn            \ |                                        |   |   /
                 |   \________________________________________________/ |
                 |                                                      |
                 |<---4--->|                                   |   |    |
                 |         ______________________________________  |    |
     DOE         |        /                                      \ |    |
         ________________/ |                                      \_______
                           |     |                             |
                 |      5->|     |<-                           |   |    |
         _________________________                             |   _______
    /DSn                          \                               /
                                 | \_____________________________/      |
                 |            |  |                                 |    |
                 |        10->|  |<-                               |    |
                 |            ____________________________________ |    |
  D31-D0 ____________________/                                    \_______
                             \____________________________________/
                 |                                                 |    |
                 |            |               |                |   |    |
         ___________________________________  |<------7------->|   |    __
  /DTACK                                    \ |                |   |   /

                 |     |                     \________________________/ |
             11->|     |<-                                              |
                 |     |                              12->|    |<- |    |
         ____________  |                                  ________________
    /CCS             \ |                                 /
                 |    \_________________________________/ |    |   |    |
                 |                                        |    |   |    |
                 |     |                                  |    |   |    |


                     Figure K-11: Write Cycle Timing
