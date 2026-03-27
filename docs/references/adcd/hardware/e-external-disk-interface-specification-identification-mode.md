---
title: E / / External Disk Interface Specification / Identification Mode
manual: hardware
chapter: hardware
section: e-external-disk-interface-specification-identification-mode
functions: []
libraries: []
---

# E / / External Disk Interface Specification / Identification Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An identification mode is provided for reading a 32-bit serial
identification data stream from an external device.  To initialize this
mode, the motor must be turned on, then off.  See pin 8,  [MTRXD*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)  for a
discussion of how to turn the motor on and off.  The transition from motor
on to motor off reinitializes the serial shift register. After
initialization, the  [SELxB*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)  signal should be left in the inactive state.
Now enter a loop where  [SELxB*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)  is driven active, read serial input data
on  [RDY*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)  (pin 1), and drive  [SELxB*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)  inactive.  Repeat this loop a total
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

