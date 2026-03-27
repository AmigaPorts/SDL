---
title: 6 Blitter Hardware / Blitter Operations and System DMA
manual: hardware
chapter: hardware
section: 6-blitter-hardware-blitter-operations-and-system-dma
functions: []
libraries: []
---

# 6 Blitter Hardware / Blitter Operations and System DMA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The operations of the blitter affect the performance of the rest of the
system. The following sections explain how system performance is affected
by blitter direct memory access priority, DMA time slot allocation, bus
sharing between the 680x0 and the display hardware, the operations of the
blitter and Copper, and different playfield display sizes.

The blitter performs its various data-fetch, modify, and store operations
through DMA sequences, and it shares memory access with other devices in
the system. Each device that accesses memory has a priority level assigned
to it, which indicates its importance relative to other devices.

Disk DMA, audio DMA, display DMA, and sprite DMA all have the highest
priority level.  Display DMA has  [priority](hardware/7-system-control-hardware-video-priorities.md)  over sprite DMA under certain
circumstances.  Each of these four devices is allocated a group of time
slots during each horizontal scan of the video beam. If a device does not
request one of its allocated time slots, the slot is open for other uses.
These devices are given first priority because missed DMA cycles can cause
lost data, noise in the sound output, or on-screen interruptions.

The Copper has the next priority because it has to perform its operations
at the same time during each display frame to remain synchronized with the
display beam sweeping across the screen.

The lowest priorities are assigned to the blitter and the 68000, in that
order. The blitter is given the higher priority because it performs data
copying, modifying, and line drawing operations operations much faster
than the 68000.

During a horizontal scan line (about 63 microseconds), there are 227.5
"color clocks", or memory access cycles.  A memory cycle is approximately
280 ns in duration.  The total of 227.5 cycles per horizontal line
includes both display time and non-display time.  Of this total time, 226
cycles are available to be allocated to the various devices that need
memory access.

The time-slot allocation per horizontal line is:


```c
      4 cycles for memory refresh
      3 cycles for disk DMA
      4 cycles for audio DMA (2 bytes per channel)
     16 cycles for sprite DMA (2 words per channel)
     80 cycles for bitplane DMA (even- or odd-numbered slots
          according to the display size used)
```
Figure 6-9 shows one complete horizontal scan line and how the clock
cycles are allocated.


```c
     [Figure 6-9: DMA Time Slot Allocation](hardware/hard-pics-6-9-pic.md) 
```
The 68000 uses only the even-numbered memory access cycles. The 68000
spends about half of a complete processor instruction time doing internal
operations and the other half accessing memory. Therefore, the allocation
of alternate memory cycles to the 68000 makes it appear to the 68000 that
it has the memory all of the time, and it will run at full speed.

Some 68000 instructions do not match perfectly with the allocation of even
cycles and cause cycles to be missed. If cycles are missed, the 68000 must
wait until its next available memory slot before continuing. However, most
instructions do not cause cycles to be missed, so the 68000 runs at full
speed most of the time if there is no blitter DMA interference.

Figure 6-10 illustrates the normal cycle of the 68000.

   Avoid the TAS instruction.
   --------------------------
   The 68000 test-and-set instruction (TAS) should never be used in the
   Amiga; the indivisible read-modify-write cycle that is used only in
   this instruction will not fit into a DMA memory access slot.




      |                                                       |
      |<- - - - - - - - average 68000 cycle - - - - - - - - ->|
      |                                                       |
      |                                                       |
      |                           |                           |
      |<- - - - internal  - - - ->|<- - - - - memory  - - - ->|
      |         operation         |           access          |
      |         portion           |           portion         |
      |                           |                           |
      |                           |                           |
      |        odd cycle,         |         even cycle,       |
      |        assigned to        |         available to      |
      |        other devices      |         the 68000         |
      |                           |                           |
      |                           |                           |
      |                           |                           |
      |                           |                           |

                   Figure 6-10: Normal 68000 Cycle
If the display contains four or fewer low resolution bitplanes, the 68000
can be granted alternate memory cycles (if it is ready to ask for the
cycle and is the highest priority item at the time). However, if there are
more than four bitplanes, bitplane DMA will begin to steal cycles from the
68000 during the display.

During the display time for a six bitplane display (low resolution, 320
pixels wide), 160 time slots will be taken by bitplane DMA for each
horizontal line. As you can see from Figure 6-11, bitplane DMA steals 50
percent of the open slots that the processor might have used if there were
only four bitplanes displayed.


                          - timing cycle -
      T                                                     T + 7

      +               *               +               *
   _______________________________________________________________
  |       |       |       |       |       |       |       |       |
  |       |   4   |   6   |   2   |       |   3   |   5   |   1   |
  |_______|_______|_______|_______|_______|_______|_______|_______|



       Figure 6-11: Time Slots Used by a Six Bitplane Display
If you specify four high resolution bitplanes (640 pixels wide), bitplane
DMA needs all of the available memory time slots during the display time
just to fetch the 40 data words for each line of the four bitplanes
(40 * 4 = 160 time slots).  This effectively locks out the 68000 (as well
as the blitter or Copper) from any memory access during the display,
except during horizontal and  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md) .



                          - timing cycle -
      T                                                     T + 7
   _______________________________________________________________
  |       |       |       |       |       |       |       |       |
  |   4   |   2   |   3   |   1   |   4   |   2   |   3   |   1   |
  |_______|_______|_______|_______|_______|_______|_______|_______|



      Figure 6-12: Time Slots Used by a High Resolution Display
Each horizontal line in a normal, full-sized display contains 320 pixels
in low resolution mode or 640 pixels in high resolution mode.  Thus,
either 20 or 40 words will be fetched during the horizontal line display
time. If you want to  [scroll a playfield](hardware/3-playfield-hardware-moving-scrolling-playfields.md) , one extra data word per line must
be fetched from the memory.

 [Display size](hardware/3-forming-basic-playfield-defining-the-size-of-the-display.md)  is adjustable (see Chapter 3, "Playfield Hardware"), and
bitplane DMA takes precedence over sprite DMA.  As shown in  [Figure 6-9](hardware/hard-pics-6-9-pic.md) 
larger displays may block out one or more of the highest-numbered sprites,
especially with scrolling.

As mentioned above, the blitter normally has a higher priority than the
processor for DMA cycles.  There are certain cases, however, when the
blitter and the 68000 can share memory cycles. If given the chance, the
blitter would steal every available Chip memory cycle. Display, disk, and
audio DMA take precedence over the blitter, so it cannot block them from
bus access.  Depending on the setting of the blitter DMA mode bit,
commonly referred to as the "blitter-nasty" bit, the processor may be
blocked from bus access.  This bit is called DMAF_BLITHOG (bit 10) and is
in register  [DMACON](hardware/7-system-control-hardware-dma-control.md) .

If DMAF_BLITHOG is a 1, the blitter will keep the bus for every available
Chip memory cycle.  This could potentially be every cycle (ROM and Fast
memory are not typically Chip memory cycles).

If DMAF_BLITHOG is a 0, the DMA manager will monitor the 68000 cycle
requests.  If the 68000 is unsatisfied for three consecutive memory
cycles, the blitter will release the bus for one cycle.

