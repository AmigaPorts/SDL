---
title: K / Timing / Quick Interrupt Cycle Timing
manual: hardware
chapter: hardware
section: k-timing-quick-interrupt-cycle-timing
functions: []
libraries: []
---

# K / Timing / Quick Interrupt Cycle Timing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   No.  Name                                   Symbol  Min     Max
   ---  ----                                   ------  ---     ---
   1    Address setup to  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)                 TAFS    15ns     --
   2    Address hold from  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)                THAF    10ns     --
   3    [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  to  [/SLAVEn](hardware/k-signal-description-slot-control-signals-2.md)  delay               TSLV     --     25ns
   5    [DOE](hardware/k-signal-description-data-and-related-control-signals.md)  to  [/DSn](hardware/k-signal-description-data-and-related-control-signals.md)  delay                   TDS     10ns     --
   6    Data setup to  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)                  TRDS    0ns      --
   7     [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)  to  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  off                 TOFF    10ns     --
   8    Master signal hold from  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  off     THMC    0ns     5ns
   9    Slave signal hold from  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  off      THSC    0ns     15ns
   14   [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  off to  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  on               TREF    10ns     --
   17   Slave signal hold from  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  off     THSM    0ns     5ns
   18   Poll Phase time                        TPOL    30ns    100ns
   19   Vector Phase start to  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)  time    TVEC     --     100ns

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
             |   |<------18-------->| 14  |<- |                |   |    |
         ______  |                  ____->|   |<-19            ___________
    READ       \ |                 /    \ |   |               /
                \_________________/ |    \___________________/ |
                                    | |                        |
              3->|    |<-       17->| |<- |   |                |<---9-->|
         ___________  |               __  |   |                ___________
 /SLAVEn            \ |              /  \ |                   /
                     \______________/ |  \___________________/          |
                 |                    |                        |   |    |
                 |    |               |   |   |                |   |    |
                 |                    ___________________________  |    |
     DOE                             /                           \ |    |
         ___________________________/ |   |                       \_______
                                      |   |   |                |
                 |                 5->|   |<- |                |   |    |
         _______________________________  |   |                |   _______
    /DSn                                \ |                       /
                                         \_______________________/      |
                 |                                                 |    |
                 |                        |   |   |            |   |    |
                 |                            |   _____________________ |
  D31-D0 ________________________________________/                     \__
                                                 \_____________________/
                 |                            |                         |
                 |                         6->|   |<-          |   |    |
         ___________________________________  |   |            |   |    __
  /DTACK                                    \ |<------7------->|   |   /

                 |                           \________________________/
                 |                                                      |
                 |                            |                |   |    |


                Figure K-13: Quick Interrupt Cycle Timing
