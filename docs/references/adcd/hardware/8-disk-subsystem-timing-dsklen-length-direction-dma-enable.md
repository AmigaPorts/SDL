---
title: 8 / / Disk Subsystem Timing / DSKLEN - Length, Direction, DMA Enable
manual: hardware
chapter: hardware
section: 8-disk-subsystem-timing-dsklen-length-direction-dma-enable
functions: []
libraries: []
---

# 8 / / Disk Subsystem Timing / DSKLEN - Length, Direction, DMA Enable

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All of the control bits relating to this topic are contained in a
write-only register, called DSKLEN:




```c
           Table 8-6: DSKLEN Register ($DFF024)

       Bit
       Number  Name    Usage
       ------  ----    -----
       15      DMAEN   Secondary disk DMA enable
       14      WRITE   Disk write (RAM -> disk if 1)
       13-0    LENGTH  Number of words to transfer
```
The hardware requires a special sequence in order to start DMA to the
disk.  This sequence prevents accidental writes to the disk.
In short, the DMAEN bit in the DSKLEN register must be turned on twice
in order to actually enable the disk DMA hardware.
Here is the sequence you should follow:

   1. Enable disk DMA in the  [DMACON](hardware/7-system-control-hardware-dma-control.md)  register (See Chapter 7 for more
```c
      information)
```
   2. Set DSKLEN to $4000, thereby forcing the DMA for the disk to be
      turned off.
   3. Put the value you want into the DSKLEN register.
   4. Write this value again into the DSKLEN register. This actually
      starts the DMA.
   5. After the DMA is complete, set the DSKLEN register back to

      $4000, to prevent accidental writes to the disk.
As each data word is transferred, the length value is decremented. After
each transfer occurs, the value of the pointer is incremented. The pointer
points to the the next word of data to written or read. When the length
value counts down to 0, the transfer stops.

The recommended method of reading from the disk is to read an entire track
into a buffer and then search for the sector(s) that you want. Using the
 [DSKSYNC](hardware/8-disk-subsystem-timing-dsksync-disk-input-synchronizer.md)  register (described below) will guarantee word alignment of the
data.  With this process you need to read from the disk only once for the
entire track.  In a high speed loader, the step to the next head can occur
while the previous track is processed and checksummed. With this method
there are no time-critical sections in reading data, other high-priority
subsystems (such as graphics or audio) are be allowed to run.

If you have too little memory for track buffering (or for some other
reason decide not to read a whole track at once), the disk hardware
supports a limited set of sector-searching facilities. There is a register
that may be polled to examine the disk input stream.

There is a hardware bug that causes the last three bits of data sent to
the disk to be lost. Also, the last word in a disk-read DMA operation may
not come in (that is, one less word may be read than you asked for).

