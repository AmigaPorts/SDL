---
title: 2 / Starting and Stopping the Copper / Starting the Copper After Reset
manual: hardware
chapter: hardware
section: 2-starting-and-stopping-the-copper-starting-the-copper
functions: []
libraries: []
---

# 2 / Starting and Stopping the Copper / Starting the Copper After Reset

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

At power-on or reset time, you must initialize one of the Copper
 [location registers (COP1LC or COP2LC)](hardware/2-using-the-copper-registers-location-registers.md)  and write to its  [strobe address](hardware/2-using-the-copper-registers-jump-strobe-address.md) 
before Copper DMA is turned on. This ensures a known start address and
known state. Usually,  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  is used because this particular register is
reused during each [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  time. The following sequence of
instructions shows how to initialize a  [location register](hardware/2-using-the-copper-registers-location-registers.md) . It is assumed
that the user has already created the correct  [Copper instruction list](hardware/2-coprocessor-hardware-putting-together-a-copper.md)  at
location "mycoplist."

;
; Install the copper list
;
```c
     LEA     CUSTOM,a1           ; a1 = address of custom chips
     LEA     MYCOPLIST(pc),a0    ; Address of our copper list
     MOVE.L  a0,[COP1LC](hardware/2-using-the-copper-registers-location-registers.md)(a1)       ; Write whole longword address
     MOVE.W  [COPJMP1](hardware/2-using-the-copper-registers-jump-strobe-address.md)(a1),d0      ; Causes copper to load PC from  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md) 
```
;
; Then enable copper and raster dma
;
```c
     MOVE.W  #(DMAF_SETCLR!DMAF_COPPER!DMAF_RASTER!DMAF_MASTER),[DMACON](hardware/7-system-control-hardware-dma-control.md)(a1)
```
;

Now, if the contents of  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  are not changed, every time
 [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  occurs the Copper will restart at the same location
for each subsequent video screen. This forms a repeatable loop which, if
the list is correctly formulated, will cause the displayed screen to be
stable.

