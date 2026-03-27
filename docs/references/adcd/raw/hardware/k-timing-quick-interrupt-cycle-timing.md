# K / Timing / Quick Interrupt Cycle Timing



   No.  Name                                   Symbol  Min     Max
   ---  ----                                   ------  ---     ---
   1    Address setup to  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)                 TAFS    15ns     --
   2    Address hold from  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)                THAF    10ns     --
   3    [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  to  [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3)  delay               TSLV     --     25ns
   5    [DOE](../Hardware_Manual_guide/node02B5.html#line5)  to  [/DSn](../Hardware_Manual_guide/node02B5.html#line17)  delay                   TDS     10ns     --
   6    Data setup to  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)                  TRDS    0ns      --
   7     [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  to  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  off                 TOFF    10ns     --
   8    Master signal hold from  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  off     THMC    0ns     5ns
   9    Slave signal hold from  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  off      THSC    0ns     15ns
   14   [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  off to  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  on               TREF    10ns     --
   17   Slave signal hold from  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  off     THSM    0ns     5ns
   18   Poll Phase time                        TPOL    30ns    100ns
   19   Vector Phase start to  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  time    TVEC     --     100ns

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
