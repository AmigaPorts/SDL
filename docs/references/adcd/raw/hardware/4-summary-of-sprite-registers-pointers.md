# 4 / Summary of Sprite Registers / Pointers


Pointers are registers that are used by the system to point to the current
data being used. During a screen display, the registers are incremented to
point to the data being used as the screen display progresses. Therefore,
pointer registers must be freshly written during the start of the
 [vertical blanking](../Hardware_Manual_guide/node0169.html)  period.

 [SPR0PTH and SPR0PTL](../Hardware_Manual_guide/node00CB.html) 

