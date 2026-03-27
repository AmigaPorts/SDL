# 3 / Basic Playfield / Displaying and Redisplaying the Playfield


You start playfield display by making certain that the bitplane pointers
are set and bitplane DMA is turned on. You turn on bitplane DMA by writing
a 1 to bit BPLEN in the  [DMACON](../Hardware_Manual_guide/node0170.html)  (for DMA control) register. See Chapter
7, System Control Hardware, for instructions on setting this register.

Each time the playfield is redisplayed, you have to reset the bitplane
pointers. Resetting is necessary because the pointers have been
incremented to point to each successive word in memory and must be
repointed to the first word for the next display. You write
 [Copper instructions](../Hardware_Manual_guide/node0053.html)  to handle the redisplay or perform this operation as
part of a  [vertical blanking](../Hardware_Manual_guide/node0169.html)  task.

