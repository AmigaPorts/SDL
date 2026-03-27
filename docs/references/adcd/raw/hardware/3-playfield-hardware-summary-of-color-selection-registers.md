# 3 Playfield Hardware / Summary of Color Selection Registers


This section contains summaries of the playfield color selection registers
including color register contents, example colors, and the differences in
color selection in high resolution and low resolution modes. The Amiga has
32 color registers and each one has 4 bits of red, 4 bits of green, and 4
bits of blue information.  Table 3-15 shows the bit assignments of each
color register.  All color registers are write-only.




```c
              Color Register Bits           Contents
              -------------------           --------
                   15 - 12           Unused (set these to 0)
                   11 -  8                  Red data
                    7 -  4                 Green data
                    3 -  0                  Blue data

                 Table 3-15: Color Register Contents
```
 [Some Sample Color Register Contents](../Hardware_Manual_guide/node0094.html) 
 [Color Selection in Low Resolution Mode](../Hardware_Manual_guide/node0095.html) 
 [Color Selection in High Resolution Mode](../Hardware_Manual_guide/node0096.html) 
 [Color Selection in Hold-And-Modify Mode](../Hardware_Manual_guide/node0097.html) 
 [Color Selection in Extra Half Brite (EHB) Mode](../Hardware_Manual_guide/node0098.html) 

