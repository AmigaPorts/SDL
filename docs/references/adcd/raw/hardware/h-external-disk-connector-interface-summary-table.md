# H External Disk Connector Interface / Summary Table





```c
     Pin #   Name        Note
     -----   ----        ----
     1       [RDY-](../Hardware_Manual_guide/node01AA.html#line14)        I/O     ID and ready
     2       [DKRD-](../Hardware_Manual_guide/node01AA.html#line52)       I       MFM input
     3       GRND        G       -
     4       GRND        G       -
     5       GRND        G       -
     6       GRND        G       -
     7       GRND        G       -
     8       [MTRXD-](../Hardware_Manual_guide/node01AA.html#line79)      O       Motor control.
     9       [SEL2B-](../Hardware_Manual_guide/node01AA.html#line3)      O*      Select drive 2
     10      [DRESB-](../Hardware_Manual_guide/node01AA.html#line97)      O       Reset
     11      [CHNG-](../Hardware_Manual_guide/node01AA.html#line70)       I/O     Disk changed
     12      +5v         PWR     540 mA average 870 mA surge
     13      [SIDEB-](../Hardware_Manual_guide/node01AA.html#line34)      O       Side 1 if low
     14      [WPRO-](../Hardware_Manual_guide/node01AA.html#line22)       I/O     Write protect
     15      [TK0-](../Hardware_Manual_guide/node01AA.html#line8)        I/O     Track 0
     16      [DKWEB-](../Hardware_Manual_guide/node01AA.html#line64)      O       Write gate
     17      [DKWDB-](../Hardware_Manual_guide/node01AA.html#line57)      O       Write data
     18      [STEPB-](../Hardware_Manual_guide/node01AA.html#line40)      O       Step
     19      [DIRB](../Hardware_Manual_guide/node01AA.html#line45)        O       Direction (high is out)
     20      [SEL3B-](../Hardware_Manual_guide/node01AA.html#line3)      O*      Select drive 3
     21      [SEL1B-](../Hardware_Manual_guide/node01AA.html#line3)      O*      Select drive 1
     22      [INDEX-](../Hardware_Manual_guide/node01AA.html#line28)      I/O     Index
     23      +12v        PWR     120 mA average 370 mA surge
```
   Key to Class:


```c
        G       ground, note connector shield grounded.
        I       input pulled up to 5v by 1K ohm.
        I/O     input in driver, but bidirectional input (1k pullup)
        O       output pulled though 1K to 5v
        O*      output, separates resources.
        PWR     available for external use, but currently used up by
                external drive.
```
