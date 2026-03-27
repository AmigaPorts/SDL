# 8 / Controller Port Interface / Registers used with Controller Port


The Amiga chip registers that handle the  [controller port](../Hardware_Manual_guide/node017D.html)  I/O are listed
below.

   [JOY0DAT](../Hardware_Manual_guide/node0038.html)  ($DFF00A)  Counter for digital (mouse) input (port 1)
   [JOY1DAT](../Hardware_Manual_guide/node0038.html)  ($DFF00C)  Counter for digital (mouse) input (port 2)
   [CIAAPRA](../Hardware_Manual_guide/node012E.html)  ($BFE001)  Input and output for pin 6 (port 1 & 2 fire buttons)
   [POT0DAT](../Hardware_Manual_guide/node003A.html)  ($DFF012)  Counter for proportional input (port 1)
   [POT1DAT](../Hardware_Manual_guide/node003A.html)  ($DFF014)  Counter for proportional input (port 2)
   [POTGO](../Hardware_Manual_guide/node018B.html)    ($DFF034)  Write proportional pin values and start counters
   [POTGOR](../Hardware_Manual_guide/node018B.html)   ($DFF016)  Read proportional pin values
   [BPLCON0](../Hardware_Manual_guide/node0022.html)  ($DFF100)  Bit 3  [enables the light pen](../Hardware_Manual_guide/node018A.html#line26)  latch
   [VPOSR](../Hardware_Manual_guide/node018A.html)    ($DFF004)  Read  [light pen position](../Hardware_Manual_guide/node018A.html)  (high order bits)
   [VHPOSR](../Hardware_Manual_guide/node018A.html)   ($DFF006)  Read  [light pen position](../Hardware_Manual_guide/node018A.html)  (low order bits)

