# 3 / Forming a Dual-playfield Display / Activating Dual-Playfield Mode


Writing a 1 to bit 10 (called DBLPF) of the bitplane control register
 [BPLCON0](../Hardware_Manual_guide/node0092.html)  selects dual-playfield mode. Selecting dual-playfield mode changes
both the way the hardware groups the bitplanes for color interpretation --
all odd-numbered bitplanes are grouped together and all even-numbered
bitplanes are grouped together, and the way hardware can move the
bitplanes on the screen.

