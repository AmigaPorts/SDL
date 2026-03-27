---
title: H External Disk Connector Interface / Signals When Driving a Disk
manual: hardware
chapter: hardware
section: h-external-disk-connector-interface-signals-when-driving-a
functions: []
libraries: []
---

# H External Disk Connector Interface / Signals When Driving a Disk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following describes the interface under driver control.


SEL1B-, SEL2B-, SEL3B-

   Select lines for the three external disk drives active low.


TK0-

   A selected drive pulls this signal low whenever its read-write head
   is on track 00.


RDY-

   When a disk drive's motor is on, this line indicates the selected
   disk is installed and rotating at speed. The driver ignores this
   signal. When the motor is off this is used as a  [ID](hardware/h-external-disk-connector-interface-device-i-d.md)  data line. See
   below.


WPRO- (Pin #14)

   A selected drive pulls this signal low whenever it has a
   write-protected diskette installed.


INDEX- (Pin #22)

   A selected drive pulses this signal low once for each revolution of
   its motor.


SIDEB- (Pin #13)

   The system drives this signal to all disk drives -- low for side 1,
   high for side 0.


STEPB- (Pin #18)

   Pulsed to step the selected drive's head.


DIRB (Pin #19)

   The system drives this signal high or low to tell the selected drive
   which way to step when the STEPB- pulse arrives. Low means step in
   (to higher-numbered track); high means step out.


DKRD- (Pin #2)

   A selected drive will put out read data on this line.


DKWDB- (Pin #17)

   The system drives write data to all disks via this signal. The data
   is only written when DKWEB- is active (low). Data is written only to
   selected drives.


DKWEB- (Pin #16)

   This signal causes a selected drive to start writing data (provided
   by DKWDB-) onto the disk.


CHNG- (Pin #11)

   A selected drive will drive this signal low whenever its internal
   "disk change" latch is set. This latch is set when the drive is first
   powered on, or whenever there is no diskette in the drive. To reset
   the latch, the system must select the drive, and step the head. Of
   course, the latch will not reset if there is no diskette installed.


MTRXD- (Pin #8)

   This is the motor control line for all four disk drives. When the
   system wants to turn on a disk drive motor, it first deselects the
   drive (if selected), pulls MTRXD- low, and selects the drive. To turn
   the motor off, the system deselects the drive, pulls MTRXD- high, and
   selects the drive. The system will always set MTRXD- at least 1.4
   microseconds before it selects the drive, and will not change MTRXD-
   for at least 1.4 microseconds after selecting the drive. All external
   drives must have logic equivalent to a D flip-flop, whose D input is
   the MTRXD- signal, and whose clock input is activated by the
   off-to-on (high-to-low) transition of its SELxB- signal. As noted
   above, both the setup and hold times of MTRXD- with respect to SELxB-
   will always be at least 1.4 microseconds. The output of this
   flip-flop controls the disk drive motor. Thus, the system can control
   all four motors using only one signal on the cable (MTRXD-).


DRESB- (Pin #10)

   This signal is a buffered version of the system reset signal. Three
   things can make it go active (low):

   *  System power-up (DRESB- will go low for approximately one

```c
      second);
```
   *  System CPU executes a  [RESET](hardware/7-system-control-hardware-reset-and-early-startup-operation.md)  instruction (DRESB- will go low for

```c
      approximately 17 microseconds);
```
   *   [Hard reset](hardware/g-keyboard-interface-hard-reset.md)  from keyboard (lasts as long as keyboard reset is

```c
      held down).
```
   External disk drives should respond to DRESB- by shutting off their
   motor flip-flops and write protecting themselves.


A level of 3.75v or below on the 5v+ requires external disks to
write-protect and reset the motor on line.

