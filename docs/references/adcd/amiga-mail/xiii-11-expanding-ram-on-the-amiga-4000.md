---
title: XIII-11: Expanding RAM on the Amiga 4000
manual: amiga-mail
chapter: amiga-mail
section: xiii-11-expanding-ram-on-the-amiga-4000
functions: []
libraries: []
---

# XIII-11: Expanding RAM on the Amiga 4000

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Expanding RAM on the Amiga 4000


by Adam Levin-Delson

Commodore currently sells the Amiga 4000 with two megabytes of Chip
RAM and four megabytes of Fast RAM.  Chip RAM refers to memory that
both the CPU and the Amiga's custom chips can access directly.  The
custom chips cannot directly access Fast RAM.  Two megabytes is the
maximum amount of Chip RAM that the computer can presently access,
but Fast RAM can be upgraded to a maximum of either four or 16
megabytes, depending upon the type of RAM used.


Memory Layout

All the A4000's RAM is packaged in SIMM (single in-line memory
module) format, which is easy to handle, making upgrading a simple
procedure.  A single four-megabyte SIMM is used to give the Amiga its
four megabytes of Fast RAM.  This leaves three more Fast RAM SIMM
slots, each capable of holding another four megabytes for a total of
eight, twelve, or the maximum of sixteen megabytes of Fast RAM.  It
is possible to use less expensive one megabyte SIMMs as Fast RAM, but
since SIMM types cannot be mixed this would require the removal of
the existing four-megabyte SIMM.  Since there are only four SIMM
slots, using one-megabyte SIMMs would yield a maximum of four
megabytes of memory.

The single slot for Chip RAM is unique in that it has no neighboring
slot to its right.  This allows the use of a double-sided SIMM (with
chips on both sides), instead of the single-sided SIMMs as required
by the spacing of the Fast RAM SIMM slots.  A single two-megabyte
SIMM is used to give the Amiga its two megabytes of Chip RAM.  This
SIMM may be removed and a one-megabyte SIMM used in its place, giving
a total of one megabyte of Chip RAM.


Adding Memory

Adding SIMMs to the existing Fast RAM requires no additional action.
Changing from four megabyte to one megabyte SIMMs (or vice versa)
requires changing a jumper on the motherboard.  This jumper (J852) is
on the left side of the motherboard (the same side as the SIMM slots
are on).  It is labelled ``SIMM SIZE'' and has two positions: ``256K
x 32'' and ``1M x 32''.  Jumper the ``256K'' pin and the center pin
for one megabyte SIMMs, the ``1M'' pin and the center pin for four
megabyte SIMMs.

No jumper change is required when switching between one-megabyte and
two-megabyte Chip RAM SIMMs.


SIMM Specifications

Each one megabyte Fast RAM SIMM must meet the following specifications:

physical:       72-pin, single-sided SIMM with a maximum height of
```c
                one inch (If this SIMM is to be used as Chip RAM,
                it may be double-sided).
```
electrical:     80-nanosecond DRAM, 256 kilobytes by 32 bits or 256


                kilobytes by 36 bits.
Each two megabyte Fast RAM SIMM must meet the following specifications:

physical:       72-pin, SIMM with a maximum height of one inch (This SIMM
```c
                is only suitable as Chip RAM.  As such, it may be
                double-sided).
```
electrical:     80-nanosecond DRAM, 512 kilobytes by 32 bits or 512


                kilobytes by 36 bits.
Each four megabyte Fast RAM SIMM must meet the following specifications:

physical:       72-pin, single-sided SIMM with a maximum height of one
                inch.
electrical:     80-nanosecond DRAM, 1 megabyte by 32 bits or 1 megabyte

                by 36bits.
The ``by 36 bits'' parts are overkill in that only the first 32 bits
are used, but they may be more readily available than the ``by 32
bits'' parts.


Amiga 4000 Block Diagram

Below is a block diagram of a production A4000 motherboard.  It shows
the approxomate position of most of its major chips and most of the
jumpers that may be of interest to delelopers.

J100/J104 - Both are three pin jumpers.  Together, these jumpers
determine the source of the CPU clock.  For both J100 and J104, if
pins 1 and 2 are connected, the CPU daughterboard uses the internal
clock on the motherboard.  If pins 2 and 3 are connected, the
daughterboard uses its own clock.  As the 68040 daughterboard has its
own clock, pins 2 and 3 are the default.  These two jumpers must be
set to the same clock!

J212 - This is a three pin jumper.  If pins 1 and 2 are connected,
the system defaults to an NTSC system.  If pins 2 and 3 are
connected, the system defaults to a PAL system.

J351 - This is a two pin shunt.  If it is closed, the system will
assume floppy drive DF1: is a 880K floppy drive.  If it is open, the
system assumes DF1: is a 1.76M floppy drive.

J850 - This is a two pin shunt.  If it is closed, the system will use
the DSACK signal to terminate a bus cycle.  If it is open, the system
will use the STERM signal.

J852 - This is a three pin jumper.  If pins 1 and 2 are connected,
the system assumes that the Fast RAM SIMMs are 4 Megabyte SIMMs.  If
pins 2 and 3 are connected, the system assumes that the Fast RAM
SIMMs are 1 Megabyte SIMMs.


SIMM Manufacturers

The following companies make the listed SIMMs which are known to work
in the A4000.  This list is not intended to endorse any particular
manufacturer, nor to imply that other sources do not exist.  This
list is included solely for completeness of information.




    Part             Commodore      Manufacturer        Manufacturer
                    part number     part number
1 megabyte SIMMs    391396-01       Motorola            MCM32256S-80

                                                        MCM32L256S-80
                                    Micron              MT8D25632M-80
2 megabyte SIMMs    391517-01       Motorola            MCM32512S-80

                                    Micron              MT16D51232M-80
                                    Texas Instruments   TM512CBK32-80
4 megabyte SIMMs    391518-01       Motorola            MCM32100S-80

                                    Micron              MT8D132M-80
                                    Texas Instruments   TM124BBK32-80
