# 8 / / Disk Subsystem Timing / DSKPTH - Pointer to Data


You specify the 32-bit wide address from which or to which the data is to
be transferred. The lowest bit of the address must be zero, and the buffer
must be in Chip memory.  The value must be written as a single long word
to the DSKPTH register ($DFF020).

