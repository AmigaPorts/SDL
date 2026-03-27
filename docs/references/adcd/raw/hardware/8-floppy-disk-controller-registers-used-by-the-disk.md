# 8 / Floppy Disk Controller / Registers Used by the Disk Subsystem


The disk subsystem uses two ports on the system's  [8520 CIA](../Hardware_Manual_guide/node012E.html)  chips, and
several registers in the Paula chip:

   [CIAAPRA](../Hardware_Manual_guide/node018F.html)    ($BFE001)    four input bits for disk sensing
   [CIABPRB](../Hardware_Manual_guide/node018F.html)    ($BFD100)    eight output bits for disk selection, control
                             and stepping
   [ADKCON](../Hardware_Manual_guide/node0194.html)     ($DFF09E)    control bits (write only register)
   [ADKCONR](../Hardware_Manual_guide/node0194.html)    ($DFF010)    control bits (read only register)
   [DSKPTH](../Hardware_Manual_guide/node0191.html)     ($DFF020)    DMA pointer (32 bits)
   [DSKLEN](../Hardware_Manual_guide/node0192.html)     ($DFF024)    length of DMA
   [DSKBYTR](../Hardware_Manual_guide/node0193.html)    ($DFF01A)    Disk data byte and status read
   [DSKSYNC](../Hardware_Manual_guide/node0195.html)    ($DFF07E)    Disk sync finder; holds a match word

