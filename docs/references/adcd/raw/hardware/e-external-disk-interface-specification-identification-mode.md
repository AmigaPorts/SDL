# E / / External Disk Interface Specification / Identification Mode


An identification mode is provided for reading a 32-bit serial
identification data stream from an external device.  To initialize this
mode, the motor must be turned on, then off.  See pin 8,  [MTRXD*](../Hardware_Manual_guide/node0110.html#line12)  for a
discussion of how to turn the motor on and off.  The transition from motor
on to motor off reinitializes the serial shift register. After
initialization, the  [SELxB*](../Hardware_Manual_guide/node0110.html)  signal should be left in the inactive state.
Now enter a loop where  [SELxB*](../Hardware_Manual_guide/node0110.html)  is driven active, read serial input data
on  [RDY*](../Hardware_Manual_guide/node0110.html)  (pin 1), and drive  [SELxB*](../Hardware_Manual_guide/node0110.html)  inactive.  Repeat this loop a total
of 32 times to read in 32 bits of data.  The most significant bit is
received first.

DEFINED IDENTIFICATIONS
-----------------------

   $0000 0000 - no drive present.
   $FFFF FFFF - Amiga standard 3.25 diskette.
   $5555 5555 - 48 TPI double-density, double-sided.

As with other peripheral ID's, users should contact Amiga, Inc.
for ID assignment.

The serial input data is active low and must therefore be inverted
to be consistent with the above table.

