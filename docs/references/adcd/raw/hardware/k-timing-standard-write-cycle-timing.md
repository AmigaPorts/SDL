# K / Timing / Standard Write Cycle Timing



   No.  Name                                   Symbol  Min     Max
   ---  ----                                   ------  ---     ---
   1    Address setup to  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)                 TAFS    15ns     --
   2    Address hold from  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)                THAF    10ns     --
   3    [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  to  [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3)  delay               TSLV     --     25ns
   4    [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  to  [DOE](../Hardware_Manual_guide/node02B5.html#line5)  delay                   TDOE    30ns     --
   5    [DOE](../Hardware_Manual_guide/node02B5.html#line5)  to  [/DSn](../Hardware_Manual_guide/node02B5.html#line17)  delay                   TDS     10ns     --
   7    [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  to  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  off                  TOFF    10ns     --
   8    Master signal hold from  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  off     THMC    0ns     5ns
   9    Slave signal hold from  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  off      THSC    0ns     15ns
   10   Write data setup to  [/DSn](../Hardware_Manual_guide/node02B5.html#line17)              TWDS    5ns      --
   11   [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  to  [/CCS](../Hardware_Manual_guide/node02B4.html#line53)  delay                  TCCS    35ns    175ns
   12   [/CCS](../Hardware_Manual_guide/node02B4.html#line53)  off to  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  off                TOVL    40ns     --

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
