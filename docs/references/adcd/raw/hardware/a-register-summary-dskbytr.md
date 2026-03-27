# A Register Summary / DSKBYTR


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
DSKBYTR    01A      R       P     Disk data byte and status read


```c
                 This register is the disk-microprocessor data
                 buffer.  Data from the disk (in read mode) is
                 loaded into this register one byte at a time, and
                 bit 15 (DSKBYT) is set true.

                 BIT#
                 ----  ---------  --------------------------------
                 15    DSKBYT     Disk byte ready (reset on read)
                 14    DMAON      Mirror of bit 15 (DMAEN) in  [DSKLEN](../Hardware_Manual_guide/node0032.html) ,
                                  ANDed with Bit09 (DMAEN) in  [DMACON](../Hardware_Manual_guide/node002F.html) 
                 13    DISKWRITE  Mirror of bit 14 (WRITE) in  [DSKLEN](../Hardware_Manual_guide/node0032.html) 
                 12    WORDEQUAL  This bit true only while the
                                   [DSKSYNC](../Hardware_Manual_guide/node0034.html)  register equals the data
                                  from disk.
                 11-08  X         Not used
                 07-00 DATA       Disk byte data
```
