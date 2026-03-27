# 4 Sprite Hardware / Summary of Sprite Color Registers


Sprite  [data words](../Hardware_Manual_guide/node00BC.html)  are used to select the color of the sprite pixels from
the system color register set as indicated in the following tables.

If the bit combinations from single sprites are as shown in Table 4-6,
then the colors will be taken from the registers shown.




          Table 4-6: Color Registers for Single Sprites


                     Single Sprites
                     --------------

               Sprite     Value    Color Register
               ------     -----    --------------
               0 or 1      00        Not used *
                           01            17
                           10            18
                           11            19

               2 or 3      00        Not used *
                           01            21
                           10            22
                           11            23

               4 or 5      00        Not used *
                           01            25
                           10            26
                           11            27

               6 or 7      00        Not used *
                           01            29
                           10            30
                           11            31

               * Selects transparent mode.
If the bit combinations from  [attached sprites](../Hardware_Manual_guide/node00C6.html)  are as shown in Table 4-7,
then the colors will be taken from the registers shown.




```c
           Table 4-7: Color Registers for  [Attached Sprites](../Hardware_Manual_guide/node00C6.html) 


                      [Attached Sprites](../Hardware_Manual_guide/node00C6.html) 
                     ------------------

               Value               Color Register
               -----               --------------
               0000           Selects transparent mode
               0001                      17
               0010                      18
               0011                      19
               0100                      20
               0101                      21
               0110                      22
               0111                      23
               1000                      24
               1001                      25
               1010                      26
               1011                      27
               1100                      28
               1101                      29
               1110                      30
               1111                      31
```
 [Interactions Among Sprites and Other Objects](../Hardware_Manual_guide/node00D1.html) 

