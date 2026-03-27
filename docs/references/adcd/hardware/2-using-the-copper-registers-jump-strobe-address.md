---
title: 2 / Using the Copper Registers / Jump Strobe Address
manual: hardware
chapter: hardware
section: 2-using-the-copper-registers-jump-strobe-address
functions: []
libraries: []
---

# 2 / Using the Copper Registers / Jump Strobe Address

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you write to a Copper strobe address, the Copper reloads its program
counter from the corresponding  [location register](hardware/2-using-the-copper-registers-location-registers.md) . The Copper can write
its own location registers and strobe addresses to perform programmed
jumps. For instance, you might  [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  an indirect address into the
 [COP2LC](hardware/2-using-the-copper-registers-location-registers.md)  location register. Then, any  [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  instruction that addresses
COPJMP2 strobes this indirect address into the program counter.

There are two jump strobe addresses:


```c
     COPJMP1/Restart Copper from address contained in  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md) .
     COPJMP2/Restart Copper from address contained in  [COP2LC](hardware/2-using-the-copper-registers-location-registers.md) .
```
