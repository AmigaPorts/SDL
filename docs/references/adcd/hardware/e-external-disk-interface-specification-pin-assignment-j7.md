---
title: E / / External Disk Interface Specification / Pin Assignment (J7)
manual: hardware
chapter: hardware
section: e-external-disk-interface-specification-pin-assignment-j7
functions: []
libraries: []
---

# E / / External Disk Interface Specification / Pin Assignment (J7)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   PIN NAME    DIR   NOTES
   --- ----    ---   -----
   1   RDY*    I/O   If motor on, indicates disk installed and up to
```c
                     speed.  If motor not on,  [identification mode](hardware/e-external-disk-interface-specification-identification-mode.md) . See
                     below.
```
   2   DKRD*    I    MFM input data to Amiga.
   3   GND
   4   GND
   5   GND
   6   GND
   7   GND
   8   MTRXD*   OC   Motor on data, clocked into drive's motor-on
                     flip-flop by the active transition of SELxB*.
                     Guaranteed setup time is 1.4 usec.
                     Guaranteed hold time is 1.4 usec.
   9   SEL2B*   OC   Select drive 2.*
   10  DRESB*   OC   Amiga system reset.  Drives should reset their
                     motor-on flip-flops and set their write-protect
                     flip-flops.
   11  CHNG*   I/O   Note: Nominally used as an open collector input.
                     Drive's change flop is set at power up or when no
                     disk is not installed.  Flop is reset when drive is
                     selected and the head stepped, but only if a disk
                     is installed.
   12  +5V           270 ma maximum; 410 ma surge
                     When below 3.75V, drives are required to reset their
                     motor-on flops, and set their write-protect flops.
   13  SIDEB*   O    Side 1 if active, side 0 if inactive
   14  WPRO*   I/O   Asserted by selected, write-protected disk.
   15  TK0*    I/O   Asserted by selected drive when read/write head
                     is positioned over track 0.
   16  DKWEB*   OC   Write gate (enable) to drive.
   17  DKWDB*   OC   MFM output data from Amiga.
   18  STEPB*   OC   Selected drive steps one cylinder in the direction
                     indicated by DIRB.
   19  DIRB     OC   Direction to step the head.  Inactive to step
```c
                     towards center of disk (higher-numbered tracks).
```
   20  SEL3B*   OC   Select drive 3. *
   21  SEL1B*   OC   Select drive 1. *
   22  INDEX*  I/O   Index is a pulse generated once per disk revolution,
                     between the end and beginning of cylinders.  The
                     8520 can be programmed to conditionally generate a
                     level 6 interrupt to the 680x0 whenever the INDEX*
                     input goes active.
   23  +12V          160 ma maximum; 540 ma surge.


   * Note: the drive select lines are shifted as they pass through

           a string of daisy chained devices. Thus the signal that appears
           as drive 2 select at the first drive shows up as drive 1 select
           at the second drive and so on...
