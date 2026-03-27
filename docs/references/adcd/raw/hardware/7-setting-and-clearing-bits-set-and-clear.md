# 7 / / Setting and Clearing Bits / Set and Clear


The  [interrupt registers](../Hardware_Manual_guide/node0164.html) , as well as the  [DMA control register](../Hardware_Manual_guide/node0170.html) , use a
special way of selecting which of the bits are to be set or cleared. Bit
15 of these registers is called the SET/CLR bit.

When you wish to set a bit (make it a 1), you must place a 1 in the
position you want to set and a 1 into position 15.

When you wish to clear a bit (make it a 0), you must place a 1 in the
position you wish to clear and a 0 into position 15.

Positions 14-0 are bit selectors. You write a 1 to any one or more bits to
select that bit. At the same time you write a 1 or 0 to bit 15 to either
set or clear the bits you have selected. Positions 14-0 that have 0 value
will not be affected when you do the write. If you want to set some bits
and clear others, you will have to write this register twice (once for
setting some bits, once for clearing others).

