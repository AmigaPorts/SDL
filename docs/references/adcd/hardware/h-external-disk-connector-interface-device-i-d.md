---
title: H External Disk Connector Interface / Device I.D.
manual: hardware
chapter: hardware
section: h-external-disk-connector-interface-device-i-d
functions: []
libraries: []
---

# H External Disk Connector Interface / Device I.D.

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This interface supports a method of establishing the type of disk(s)
attached. The I.D. sequence is as follows.

  1. Drive  [MTRXD-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  low: Turn on the disk drive motor.
  2. Drive  [SELxB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  low: Activate drive select x, where x is the number of
       the selected drive.
  3. Drive  [SELxB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  high: Deactivate drive select x..
  4. Drive  [MTRXD-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  high: Turn off disk drive motor.
  5. Drive  [SELxB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  low: Activate drive select x.
  6. Drive  [SELxB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  high: Deactivate drive select x.
  7. Drive  [SELxB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  low: Activate drive select x.
  8. Read and save state of  [RDY](hardware/h-external-disk-connector-interface-signals-when-driving-a.md) .
  9. Drive  [SELxB-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  high: Deactivate drive select x.

Repeat steps 7 through 9, 31 more times for a total of 32 iterations, in
order to read 32 bits of data. The most significant bit is read first.

Steps 1 through 4 in the algorithm above turn on and off the disk drive
motor. This initializes the  [serial shift register](hardware/f-8520-complex-interface-adapters-serial-shift-register-sdr.md) . After initialization,
the  [SELxB](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  signal is driven (first active then) inactive as in steps 5
and 6. Keep in mind that the  [SELxB](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  signal is active-low.

Steps 7, 8 and 9 form a loop where (7) the  [SELxB](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  signal is driven active
(low), (8) the serial input data is read on  [RDY](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  (pin 1) and (9) the
 [SELxB](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  signal is again driven high (inactive).  This loop is performed 32
times, once for each of the bits in the input stream that comprise the
device I.D.

Convert the 32 values of  [RDY-](hardware/h-external-disk-connector-interface-signals-when-driving-a.md)  into a two 16-bit word. The most
significant bit is the first value and so on. This 32-bit quantity is the
device I.D..

The following I.D.s are defined:

  0000 0000 0000 0000 0000 0000 0000 0000  Reserved ($0000 0000)
  1111 1111 1111 1111 1111 1111 1111 1111  Amiga standard 3.25($FFFF FFFF)
  1010 1010 1010 1010 1010 1010 1010 1010  Reserved ($AAAA AAAA)
  0101 0101 0101 0101 0101 0101 0101 0101  48 TPI double-density,
```c
                                           double-sided ($5555 5555)
```
  1000 0000 0000 0000 1000 0000 0000 0000  Reserved ($8000 8000)
  0111 1111 1111 1111 0111 1111 1111 1111  Reserved ($7FFF 7FFF)
  0000 1111 xxxx xxxx 0000 1111 xxxx xxxx  Available for users ($0Fxx 0Fxx)
  1111 0000 xxxx xxxx 1111 0000 xxxx xxxx  Extension reserved ($F0xx F0xx)
  xxxx 0000 0000 0000 xxxx 0000 0000 0000  Reserved ($x000 x000)
  xxxx 1111 1111 1111 xxxx 1111 1111 1111  Reserved ($x000 x000)
  0011 0011 0011 0011 0011 0011 0011 0011  Reserved ($3333 3333)
  1100 1100 1100 1100 1100 1100 1100 1100  Reserved ($CCCC CCCC)

