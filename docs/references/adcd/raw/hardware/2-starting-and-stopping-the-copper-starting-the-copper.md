# 2 / Starting and Stopping the Copper / Starting the Copper After Reset


At power-on or reset time, you must initialize one of the Copper
 [location registers (COP1LC or COP2LC)](../Hardware_Manual_guide/node0050.html)  and write to its  [strobe address](../Hardware_Manual_guide/node0051.html) 
before Copper DMA is turned on. This ensures a known start address and
known state. Usually,  [COP1LC](../Hardware_Manual_guide/node0050.html)  is used because this particular register is
reused during each [vertical blanking](../Hardware_Manual_guide/node0169.html)  time. The following sequence of
instructions shows how to initialize a  [location register](../Hardware_Manual_guide/node0050.html) . It is assumed
that the user has already created the correct  [Copper instruction list](../Hardware_Manual_guide/node0053.html)  at
location "mycoplist."

;
; Install the copper list
;
```c
     LEA     CUSTOM,a1           ; a1 = address of custom chips
     LEA     MYCOPLIST(pc),a0    ; Address of our copper list
     MOVE.L  a0,[COP1LC](../Hardware_Manual_guide/node0050.html)(a1)       ; Write whole longword address
     MOVE.W  [COPJMP1](../Hardware_Manual_guide/node0051.html)(a1),d0      ; Causes copper to load PC from  [COP1LC](../Hardware_Manual_guide/node0050.html) 
```
;
; Then enable copper and raster dma
;
```c
     MOVE.W  #(DMAF_SETCLR!DMAF_COPPER!DMAF_RASTER!DMAF_MASTER),[DMACON](../Hardware_Manual_guide/node0170.html)(a1)
```
;

Now, if the contents of  [COP1LC](../Hardware_Manual_guide/node0050.html)  are not changed, every time
 [vertical blanking](../Hardware_Manual_guide/node0169.html)  occurs the Copper will restart at the same location
for each subsequent video screen. This forms a repeatable loop which, if
the list is correctly formulated, will cause the displayed screen to be
stable.

