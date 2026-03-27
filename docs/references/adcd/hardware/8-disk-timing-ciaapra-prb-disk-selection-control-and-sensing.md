---
title: 8 / / Disk Timing / CIAAPRA/PRB - Disk selection, control and sensing
manual: hardware
chapter: hardware
section: 8-disk-timing-ciaapra-prb-disk-selection-control-and-sensing
functions: []
libraries: []
---

# 8 / / Disk Timing / CIAAPRA/PRB - Disk selection, control and sensing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following table lists how 8520 chip bits used by the disk subsystem.
Bits labeled  [PA](hardware/f-8520-complex-interface-adapters-port-signal-assignments.md)  are input bits in CIAAPRA ($BFE001).  Bits labeled
 [PB](hardware/f-8520-complex-interface-adapters-port-signal-assignments.md)  are output bits located in CIAAPRB ($BFD100).  More information on
how the 8520 chips operate can be found in Appendix F.



                   Table 8-5: Disk Subsystem
Bit   Name         Function
---   ----         --------
PA5   DSKRDY*      Disk ready (active low). The drive will pull this line

                   low when the motor is known to be rotating at full
                   speed.  This signal is only valid when the motor is ON,
                   at other times configuration information may obscure
                   the meaning of this input.
PA4   DSKTRACK0*   Track zero detect.  The drive will pull this line low

                   when the disk heads are positioned over track zero.
                   Software must not attempt to step outwards when this
                   signal is active.  Some drives will refuse to step,
                   others will attempt the step, possibly causing
                   alignment damage.  All new drives must refuse to step
                   outward in this condition.
PA3   DSKPROT*     Disk is write protected (active low).

PA2   DSKCHANGE*   Disk has been removed from the drive.  The signal goes

                   low whenever a disk is removed.  It remains low until
                   a disk is inserted AND a step pulse is received.
      ---------
PB7   DSKMOTOR*    Disk motor control (active low).  This signal is

```c
                   nonstandard on the Amiga system.  Each drive will latch
                   the motor signal at the time its select signal turns
                   on.  The disk drive motor will stay in this state until
                   the next time select turns on.  DSKMOTOR* also controls
                   the activity light on the front of the disk drive.

                   All software that selects drives must set up the motor
                   signal before selecting any drives.  The drive will
                   "remember" the state of its motor when it is not
                   selected.  All drive motors turn off after system
                   reset.

                   After turning on the motor, software must further wait
                   for one half second (500ms), or for the DSKRDY* line to
                   go low.
```
PB6   DSKSEL3*     Select drive 3 (active low).

PB5   DSKSEL2*     Select drive 2 (active low).

PB4   DSKSEL1*     Select drive 1 (active low).

PB3   DSKSEL0*     Select drive 0 (internal drive) (active low).

PB2   DSKSIDE      Specify which disk head to use.  Zero indicates the

                   upper head.  DSKSIDE must be stable for 100
                   microseconds before writing. After writing, at least
                   1.3 milliseconds must pass before switching DSKSIDE.
PB1   DSKDIREC     Specify the direction to seek the heads.  Zero implies

                   seek towards the center spindle.  Track zero is at the
                   outside of the disk.  This line must be set up before
                   the actual step pulse, with a separate write to the
                   register.
PB0   DSKSTEP*     Step the heads of the disk.  This signal must always be

```c
                   used as a quick pulse (high, momentarily low, then
                   high).

                   The drives used for the Amiga are guaranteed to get to
                   the next track within 3 milliseconds.  Some drives will
                   support a much faster rate, others will fail.  Loops
                   that decrement a counter to provide delay are not
                   acceptable.  See  [Appendix F](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  for a better solution.

                   When reversing directions, a minimum of 18 milliseconds
                   delay is required from the last step pulse.  Settle
                   time for Amiga drives is specified at 15 milliseconds.
```
FLAG  DSKINDEX*    Disk index pulse ($BFDD00, bit 4).  Can be used to

```c
                   create a level 6  [interrupt](hardware/8-floppy-disk-controller-disk-interrupts.md) .  See  [Appendix F](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  for
                   details.
```
