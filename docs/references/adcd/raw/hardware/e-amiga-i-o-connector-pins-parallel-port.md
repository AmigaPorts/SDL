# E / Amiga I/O Connector Pins / Parallel Port


Parallel (Centronics) Port
--------------------------

   PIN     A1000       A500/A2000/A3000    Commodore PCs
   ---     -----       ----------------   -------------
   1       [DRDY*](../Hardware_Manual_guide/node0102.html#line3)           STROBE*         STROBE*
   2       [Data 0](../Hardware_Manual_guide/node0102.html#line9)          [Data 0](../Hardware_Manual_guide/node0102.html#line9)          [Data 0](../Hardware_Manual_guide/node0102.html#line9) 
   3       [Data 1](../Hardware_Manual_guide/node0102.html#line9)          [Data 1](../Hardware_Manual_guide/node0102.html#line9)          [Data 1](../Hardware_Manual_guide/node0102.html#line9) 
   4       [Data 2](../Hardware_Manual_guide/node0102.html#line9)          [Data 2](../Hardware_Manual_guide/node0102.html#line9)          [Data 2](../Hardware_Manual_guide/node0102.html#line9) 
   5       [Data 3](../Hardware_Manual_guide/node0102.html#line9)          [Data 3](../Hardware_Manual_guide/node0102.html#line9)          [Data 3](../Hardware_Manual_guide/node0102.html#line9) 
   6       [Data 4](../Hardware_Manual_guide/node0102.html#line9)          [Data 4](../Hardware_Manual_guide/node0102.html#line9)          [Data 4](../Hardware_Manual_guide/node0102.html#line9) 
   7       [Data 5](../Hardware_Manual_guide/node0102.html#line9)          [Data 5](../Hardware_Manual_guide/node0102.html#line9)          [Data 5](../Hardware_Manual_guide/node0102.html#line9) 
   8       [Data 6](../Hardware_Manual_guide/node0102.html#line9)          [Data 6](../Hardware_Manual_guide/node0102.html#line9)          [Data 6](../Hardware_Manual_guide/node0102.html#line9) 
   9       [Data 7](../Hardware_Manual_guide/node0102.html#line9)          [Data 7](../Hardware_Manual_guide/node0102.html#line9)          [Data 7](../Hardware_Manual_guide/node0102.html#line9) 
   10      [ACK*](../Hardware_Manual_guide/node0102.html#line17)            [ACK*](../Hardware_Manual_guide/node0102.html#line17)            [ACK*](../Hardware_Manual_guide/node0102.html#line17) 
   11      [BUSY](../Hardware_Manual_guide/node0102.html#line25) (data)     [BUSY](../Hardware_Manual_guide/node0102.html#line25)            [BUSY](../Hardware_Manual_guide/node0102.html#line25) 
   12      [POUT](../Hardware_Manual_guide/node0102.html#line28) (clk)      [POUT](../Hardware_Manual_guide/node0102.html#line28)            [POUT](../Hardware_Manual_guide/node0102.html#line28) 
   13      [SEL](../Hardware_Manual_guide/node0102.html#line31)             [SEL](../Hardware_Manual_guide/node0102.html#line31)             [SEL](../Hardware_Manual_guide/node0102.html#line31) 
   14      GND             +5v pullup      AUTOFDXT
   15      GND             NC              ERROR*
   16      GND             [RESET*](../Hardware_Manual_guide/node0102.html#line36)          INIT*
   17      GND             GND             SLCT IN*
   18-22   GND             GND             GND
   23      + 5             GND             GND
   24      NC              GND             GND
   25      [Reset*](../Hardware_Manual_guide/node0102.html#line36)          GND             GND

