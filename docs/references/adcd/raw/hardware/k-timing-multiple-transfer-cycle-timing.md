# K / Timing / Multiple Transfer Cycle Timing



   No.  Name                                   Symbol  Min     Max
   ---  ----                                   ------  ---     ---
   1    Address setup to  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)                 TAFS    15ns     --
   2    Address hold from  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)                THAF    10ns     --
   3    [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  to  [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3) ,  [/MTACK](../Hardware_Manual_guide/node02B5.html#line44)  delay     TSLV     --     25ns
   4    [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  to  [DOE](../Hardware_Manual_guide/node02B5.html#line5)  delay                   TDOE    30ns     --
   5    [DOE](../Hardware_Manual_guide/node02B5.html#line5)  to  [/DSn](../Hardware_Manual_guide/node02B5.html#line17) ,  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  delay          TDS     10ns     --
   6    Data setup to  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)                  TRDS    0ns      --
   7    [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  to  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) ,  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  off         TOFF    10ns     --
   8    Master signal hold from  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  off     THMC    0ns     5ns
   9    Slave signal hold from  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  off      THSC    0ns     15ns
   10   Write data setup to  [/DSn](../Hardware_Manual_guide/node02B5.html#line17)              TWDS    5ns      --
   13   Address,  [READ](../Hardware_Manual_guide/node02B4.html#line6)  setup to  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)        TAMS    5ns      --
   14   [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  off to  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  on               TREF    10ns     --
   15   Address,  [READ](../Hardware_Manual_guide/node02B4.html#line6)  hold from  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)       THAM    0ns      --
   16   [/MTACK](../Hardware_Manual_guide/node02B5.html#line44)  off to  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)                  TBCD    10ns     --
   17   Slave signal hold from  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  off     THSM    0ns     5ns

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
