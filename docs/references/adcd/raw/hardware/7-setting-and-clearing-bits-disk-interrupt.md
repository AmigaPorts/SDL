# 7 / / Setting and Clearing Bits / Disk Interrupt


Bits 12 and 1 of the  [interrupt registers](../Hardware_Manual_guide/node0164.html)  are assigned to disk interrupts.

Bit 12, DSKSYN, indicates that the  [sync register](../Hardware_Manual_guide/node0195.html)  matches disk data. This
bit generates a  [level 5 interrupt](../Hardware_Manual_guide/node016F.html) .

Bit 1, DSKBLK, indicates "disk block finished." It is used to indicate
that the specified disk DMA task that you have requested has been
completed. This bit generates a  [level 1 interrupt](../Hardware_Manual_guide/node016F.html) .

More information about disk data transfer and  [interrupts](../Hardware_Manual_guide/node0196.html)  may be found
in Chapter 8, "Interface Hardware."

