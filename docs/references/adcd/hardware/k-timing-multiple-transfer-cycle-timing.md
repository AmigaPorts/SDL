---
title: K / Timing / Multiple Transfer Cycle Timing
manual: hardware
chapter: hardware
section: k-timing-multiple-transfer-cycle-timing
functions: []
libraries: []
---

# K / Timing / Multiple Transfer Cycle Timing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   No.  Name                                   Symbol  Min     Max
   ---  ----                                   ------  ---     ---
   1    Address setup to  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)                 TAFS    15ns     --
   2    Address hold from  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)                THAF    10ns     --
   3    [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  to  [/SLAVEn](hardware/k-signal-description-slot-control-signals-2.md) ,  [/MTACK](hardware/k-signal-description-data-and-related-control-signals.md)  delay     TSLV     --     25ns
   4    [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  to  [DOE](hardware/k-signal-description-data-and-related-control-signals.md)  delay                   TDOE    30ns     --
   5    [DOE](hardware/k-signal-description-data-and-related-control-signals.md)  to  [/DSn](hardware/k-signal-description-data-and-related-control-signals.md) ,  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  delay          TDS     10ns     --
   6    Data setup to  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)                  TRDS    0ns      --
   7    [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)  to  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md) ,  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  off         TOFF    10ns     --
   8    Master signal hold from  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  off     THMC    0ns     5ns
   9    Slave signal hold from  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  off      THSC    0ns     15ns
   10   Write data setup to  [/DSn](hardware/k-signal-description-data-and-related-control-signals.md)              TWDS    5ns      --
   13   Address,  [READ](hardware/k-signal-description-address-and-related-control-signals.md)  setup to  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)        TAMS    5ns      --
   14   [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  off to  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  on               TREF    10ns     --
   15   Address,  [READ](hardware/k-signal-description-address-and-related-control-signals.md)  hold from  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)       THAM    0ns      --
   16   [/MTACK](hardware/k-signal-description-data-and-related-control-signals.md)  off to  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)                  TBCD    10ns     --
   17   Slave signal hold from  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  off     THSM    0ns     5ns

         ______                                                ___________
    /FCS       \ |   |                                        /
                \____________________________________________/ |   |    |
                                                               |   |    |
              2->|   |<-                                    8->|   |<-  |
             _________                                         |   |    |
  A31-A8 ___/         \___________________________________________________
            \_________/
                                                               |   |    |
          1->|   |<-             13->|   |<-                   |   |    |
             ______________________  _____________  ______________ |    |
   A7-A2 ___/                      \/             \/              \_______
            \______________________/\_____________/\______________/
                                                                   |    |
             |   |                   |   |     |<-14-->|   15->|   |<-  |
         ________________  |        ___  |     |  ___  |       ___________
   /MTCR                 \ |       /   \ |     | /   \ |      /
                          \_______/     \_______/     \______/ |        |
                 |                   |                         |<--17-->|
                 |         |         |                 |       |        |
         __________________________  |             _______________________
    READ                           \ |            /
                 |         |        \____________/             |        |
              3->|   |<-   |                           |       |<---9-->|
         __________  |     |                           |       |        __
 /SLAVEn           \ |                                                 /
                    \_________________________________________________/ |
                 |                                                      |
                 |   |     |                   16->|   |<-     |   |    |
         __________  |     |                       _______________________
  /MTACK           \ |                            /
                    \____________________________/ |   |
                 |                                 |   |       |   |    |
              4->|    |<-  |                                   |   |    |
                 |    |  ________________________________________  |    |
     DOE         |    | /                                        \ |
         ______________/   |                                   |  \_______
                           |                                   |
                 | 5->|    |<-                                 |   |    |
         ________________  |        ___  |        ___          ___________
    /DSn                 \ |       /   \ |       /   \        /
                          \_______/     \_______/     \______/ |
                 |    |                |                       |   |    |
                 |    |    |   |   10->| |<-                   |   |    |
                               ______  ___________        ________ |
  D31-D0 _____________________/      \/           \______/        \_______
                              \______/\___________/      \________/
                 |    |                                            |    |
                 |    |   6->| |<-                       |<-7->|   |    |
         __________________  | |      ___           ___  |     | _________
  /DTACK                   \ |       /   \         /   \ |      /

                            \_______/     \_______/     \______/
                 |    |                                            |    |
                 |    |      |                           |         |    |

               Figure K-12: Multiple Transfer Cycle Timing
