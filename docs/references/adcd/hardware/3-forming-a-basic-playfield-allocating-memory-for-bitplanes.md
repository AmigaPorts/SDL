---
title: 3 / Forming a Basic Playfield / Allocating Memory for Bitplanes
manual: hardware
chapter: hardware
section: 3-forming-a-basic-playfield-allocating-memory-for-bitplanes
functions: [AllocMem, AllocRaster]
libraries: [exec.library, graphics.library]
---

# 3 / Forming a Basic Playfield / Allocating Memory for Bitplanes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After you set the number of bitplanes and specify resolution modes, you
are ready to allocate memory. A bitplane consists of an end-to-end
sequence of words at consecutive memory locations. When operating under
the Amiga operating system, use a system call such as AllocMem() to remove
a block of memory from the free list and make it available to the program.

A specialized allocation function named AllocRaster() in the
graphics.library is recommended for all bitplane allocations.
AllocRaster() will pad the allocation to properly align scan lines
for the hardware.

If the machine has been taken over, simply reserve an area of memory for
the bitplanes. Next, set the bitplane pointer registers ( [BPLxPTH/BPLxPTL](hardware/3-allocating-memory-for-bitplanes-ntsc-example-of-bitplane.md) )
to point to the starting memory address of each bitplane you are using.
The starting address is the memory word that contains the bits of the
upper left-hand corner of the bitplane.

Tables 3-7 and 3-8 show how much memory is needed for basic playfield
modes under NTSC and PAL, respectively. You may need to balance your color
and resolution requirements against the amount of available memory you
have.




          Table 3-7: Playfield Memory Requirements, NTSC

                                           Number of Bytes
          Picture Size         Modes        per Bitplane
          ------------         -----       ---------------
           320 X 200      Low resolution,       8,000
                          non-interlaced

           320 X 400      Low resolution,      16,000
                          interlaced

           640 X 200      High resolution,     16,000
                          non-interlaced

           640 X 400      High resolution,     32,000
                          interlaced
Keep in mind that the number of bytes you allocate for a bitplane must be
even.




          Table 3-8: Playfield Memory Requirements, PAL

                                           Number of Bytes
          Picture Size         Modes        per Bitplane
          ------------         -----       ---------------
           320 X 256      Low resolution,       8,192
                          non-interlaced

           320 X 512      Low resolution,      16,384
                          interlaced

           640 X 256      High resolution,     16,384
                          non-interlaced

           640 X 512      High resolution,     32,768
                          interlaced
 [NTSC Example of Bitplane Size](hardware/3-allocating-memory-for-bitplanes-ntsc-example-of-bitplane.md) 

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AllocRaster — graphics.library](../autodocs/graphics.library.md#allocraster)
