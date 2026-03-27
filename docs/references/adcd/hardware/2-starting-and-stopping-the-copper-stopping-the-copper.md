---
title: 2 / Starting and Stopping the Copper / Stopping the Copper
manual: hardware
chapter: hardware
section: 2-starting-and-stopping-the-copper-stopping-the-copper
functions: []
libraries: []
---

# 2 / Starting and Stopping the Copper / Stopping the Copper

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

No stop instruction is provided for the Copper. To ensure that it will
stop and do nothing until the screen display ends and the program counter
starts again at the top of the instruction list, the last instruction
should be to  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for an event that cannot occur. A typical instruction
is to  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for VP = $FF and HP = $FE. An HP of greater than $E2 is not
possible. When the screen display ends and  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  starts, the
Copper will automatically be pointed to the top of its instruction list,
and this final  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  instruction never finishes.

You can also stop the Copper by disabling its ability to use DMA for
retrieving instructions or placing data. The register called  [DMACON](hardware/7-system-control-hardware-dma-control.md) 
controls all of the DMA channels. Bit 7, COPEN, enables Copper DMA when
set to 1.

For information about  [controlling the DMA](hardware/7-system-control-hardware-dma-control.md) , see Chapter 7, "System
Control Hardware."

