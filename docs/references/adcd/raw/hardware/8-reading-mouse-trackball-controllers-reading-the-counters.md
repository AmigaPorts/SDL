# 8 / / Reading Mouse/Trackball Controllers / Reading the Counters


The mouse/trackball counter contents can be accessed by reading register
addresses named  [JOY0DAT and JOY1DAT](../Hardware_Manual_guide/node0038.html) .  These registers contain counts for
ports 1 and 2 respectively.

The contents of each of these 16-bit registers are as follows:

   Bits 15-8     Mouse/trackball vertical count
   Bits  7-0     Mouse/trackball horizontal count

