# 7 / / Setting and Clearing Bits / Blitter Interrupt


Bit 6, BLIT, signals "blitter finished." If this bit is a 1, it indicates
that the blitter has completed the requested data transfer. The blitter is
now ready to accept another task. This bit generates a  [level 3 interrupt](../Hardware_Manual_guide/node016F.html) .

