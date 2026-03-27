---
title: 8 / / Timing / ADKCON and ADKCONR - Audio and Disk Control Register
manual: hardware
chapter: hardware
section: 8-timing-adkcon-and-adkconr-audio-and-disk-control-register
functions: []
libraries: []
---

# 8 / / Timing / ADKCON and ADKCONR - Audio and Disk Control Register

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ADKCON is the write-only address and ADKCONR is the read-only address for
this register.  Not all of the bits are dedicated to the disk.  Bit 15 of
this register allows independent setting or clearing of any bit or bits.
If bit 15 is a one on a write, any ones in positions 0-14 will set the
corresponding bit.  If bit 15 is a zero, any ones will clear the
corresponding bit.




```c
               Table 8-8: ADKCON and ADKCONR Register

     Bit
     Number  Name       Function
     ------  ----       --------
     15      SET/CLR    Control bit that allows setting or clearing of
                        individual bits without affecting the rest of
                        the register.

                        If bit 15 is a 1, the specified bits are set.
                        If bit 15 is a 0, the specified bits are cleared.

     14      PRECOMP1   MSB of Precompensation specifier
     13      PRECOMP0   LSB of Precompensation specifier

                        Value of 00 selects none.
                        Value of 01 selects 140 ns.
                        Value of 10 selects 280 ns.
                        Value of 11 selects 560 ns.

     12      MFMPREC    Value of 0 selects GCR Precompensation.
                        Value of 1 selects MFM Precompensation.

     10      WORDSYNC   Value of 1 enables synchronizing and starting of
                        DMA on disk read of a word.  The word on which to
                        synchronize must be written into the  [DSKSYNC](hardware/8-disk-subsystem-timing-dsksync-disk-input-synchronizer.md) 
                        address ($DFF07E).  This capability is highly
                        useful.

     9       MSBSYNC    Value of 1 enables sync on most significant bit
                        of the input (usually used for GCR).

     8       FAST       Value of 1 selects two microseconds per bit cell
                        (usually MFM).  Data must be valid raw MFM.
                        0 selects four microseconds per bit (usually GCR).

     [7-0](hardware/5-producing-complex-sounds-modulating-sound.md)                These bits are used by the audio subsystem for
                        volume and frequency modulation.
```
The raw MFM data that must be presented to the disk controller will be
twice as large as the unencoded data.  The following table shows the
relationship:


```c
               1 -> 01
               0 -> 10   ;if following a 0
               0 -> 00   ;if following a 1
```
With clever manipulation, the blitter can be used to encode and decode the
MFM.

In one common form of GCR recording, each data byte always has the most
significant bit set to a 1.  MSBSYNC, when a 1, tells the disk controller
to look for this sync bit on every disk byte. When reading a GCR formatted
disk, the software must use a translate table called a nybble-izer to
assure that data written to the disk does not have too many consecutive
1's or 0's.

