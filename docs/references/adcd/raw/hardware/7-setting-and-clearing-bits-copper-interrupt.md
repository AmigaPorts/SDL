# 7 / / Setting and Clearing Bits / Copper Interrupt


Bit 4, COPER, is used by the Copper to issue a  [level 3 interrupt](../Hardware_Manual_guide/node016F.html) . The
Copper can change the content of any of the bits of this register, as it
can write any value into most of the machine registers. However, this bit
has been reserved for specifically identifying the Copper as the interrupt
source.

Generally, you use this bit when you want to sense that the display beam
has reached a specific position on the screen, and you wish to change
something in memory based on this occurrence.

