# 8 / / Reading Controllers / Proportional Controller Registers


The following registers are used for the proportional controllers:

   [POT0DAT](../Hardware_Manual_guide/node003A.html)  - port 1 data (vertical/horizontal)
   [POT1DAT](../Hardware_Manual_guide/node003A.html)  - port 2 data (vertical/horizontal)

   Bit positions:

   Bits 15-8   POT0Y value or POT1Y value
   Bits 7-0    POT0X value or POT1X value

All counts are reset to zero when  [POTGO](../Hardware_Manual_guide/node018B.html)  is written with bit zero high.
Counts are normally read one frame after the scan circuitry is enabled.

