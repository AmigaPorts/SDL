# 2 / Starting and Stopping the Copper / Stopping the Copper


No stop instruction is provided for the Copper. To ensure that it will
stop and do nothing until the screen display ends and the program counter
starts again at the top of the instruction list, the last instruction
should be to  [WAIT](../Hardware_Manual_guide/node004B.html)  for an event that cannot occur. A typical instruction
is to  [WAIT](../Hardware_Manual_guide/node004B.html)  for VP = $FF and HP = $FE. An HP of greater than $E2 is not
possible. When the screen display ends and  [vertical blanking](../Hardware_Manual_guide/node0169.html)  starts, the
Copper will automatically be pointed to the top of its instruction list,
and this final  [WAIT](../Hardware_Manual_guide/node004B.html)  instruction never finishes.

You can also stop the Copper by disabling its ability to use DMA for
retrieving instructions or placing data. The register called  [DMACON](../Hardware_Manual_guide/node0170.html) 
controls all of the DMA channels. Bit 7, COPEN, enables Copper DMA when
set to 1.

For information about  [controlling the DMA](../Hardware_Manual_guide/node0170.html) , see Chapter 7, "System
Control Hardware."

