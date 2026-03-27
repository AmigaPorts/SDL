# 3 Playfield Hardware / Summary of Playfield Registers


This section summarizes the registers used in this chapter and the meaning
of their bit settings. The  [color registers](../Hardware_Manual_guide/node0093.html)  are summarized in the next
section. See  [Appendix A](../Hardware_Manual_guide/node0011.html)  for a summary of all registers.

BPLCON0 - Bitplane Control

   (Warning: Bits in this register cannot be independently set.)

   Bit 0 - unused

   Bit 1 - ERSY (external synchronization enable)

```c
      1 = External synchronization enabled (allows genlock
          synchronization to occur)
      0 = External synchronization disabled
```
   Bit 2 -  [LACE](../Hardware_Manual_guide/node0069.html#line94)  (interlace enable)

```c
      1 = interlaced mode enabled
      0 = non-interlaced mode enabled
```
   Bit 3 -  [LPEN](../Hardware_Manual_guide/node018A.html#line26)  (light pen enable)

   Bits 4-7 not used (make 0)

   Bit 8 - GAUD (genlock audio enable)

```c
      1 = Genlock audio enabled
      0 = Genlock audio disabled
      (This bit also appears on Denise pin ZD during blanking period)
```
   Bit 9 -  [COLOR_ON](../Hardware_Manual_guide/node0076.html)  (color enable)

```c
      1 = composite video color-burst enabled
      0 = composite video color-burst disabled
```
   Bit 10 -  [DBLPF](../Hardware_Manual_guide/node007C.html)  (double-playfield enable)

```c
      1 = dual playfields enabled
      0 = single playfield enabled
```
   Bit 11 -  [HOMOD](../Hardware_Manual_guide/node008F.html#line51)  (hold-and-modify enable)

```c
      1 = hold-and-modify enabled
      0 = hold-and-modify disabled; extra-half brite ( [EHB](../Hardware_Manual_guide/node0098.html) ) enabled
          if  [DBLPF](../Hardware_Manual_guide/node007C.html) =0 and  [BPUx](../Hardware_Manual_guide/node0068.html#line4) =6
```
   Bits 14, 13, 12 -  [BPU2, BPU1, BPU0](../Hardware_Manual_guide/node0068.html#line4) 

```c
      Number of bitplanes used.

      000 = only a background color
      001 = 1 bitplane, PLANE 1
      010 = 2 bitplanes, PLANES 1 and 2
      011 = 3 bitplanes, PLANES 1 - 3
      100 = 4 bitplanes, PLANES 1 - 4
      101 = 5 bitplanes, PLANES 1 - 5
      110 = 6 bitplanes, PLANES 1 - 6
      111 not used
```
   Bit 15 -  [HIRES](../Hardware_Manual_guide/node0069.html#line7)  (high resolution enable)


```c
      1 = high resolution mode
      0 = low resolution mode
```
 [BPLCON1](../Hardware_Manual_guide/node008B.html)  - Bitplane Control

   Bits 3-0 - PF1H(3-0)  Playfield 1 delay

   Bits 7-4 - PF2H(3-0)  Playfield 2 delay

   Bits 15-8 not used


 [BPLCON2](../Hardware_Manual_guide/node0159.html)  - Bitplane Control

   Bit 6 - PF2PRI

```c
      1 = Playfield 2 has priority
      0 = Playfield 1 has priority
```
   Bits 0-5  Playfield sprite priority

   Bits 7-15  not used


 [DDFSTRT](../Hardware_Manual_guide/node0072.html#line9)  - Data-fetch Start
   (Beginning position for data fetch)

   Bits 15-8 - not used

   Bits 7-2 - pixel position H8-H3 (bit H3 only respected in Hires Mode.)

   Bits 1-0 - not used


 [DDFSTOP](../Hardware_Manual_guide/node0072.html#line31)  - Data-fetch Stop
   (Ending position for data fetch)

   Bits 15-8 - not used

   Bits 7-2 - pixel position H8-H3 (bit H3 only respected in Hires Mode.)

   Bits 1-0 - not used


 [BPLxPTH](../Hardware_Manual_guide/node006B.html#line32)  - Bitplane Pointer
   (Bitplane pointer high word, where x is the bitplane number)


 [BPLxPTL](../Hardware_Manual_guide/node006B.html#line32)  - Bitplane Pointer
   (Bitplane pointer low word, where x is the bitplane number)


 [DIWSTRT](../Hardware_Manual_guide/node0070.html)  - Display Window Start
   (Starting vertical and horizontal coordinates)

   Bits 15-8 - VSTART (V7-V0)

   Bits 7-0 - HSTART (H7-H0)


 [DIWSTOP](../Hardware_Manual_guide/node0071.html)  - Display Window Stop
   (Ending vertical and horizontal coordinates)

   Bits 15-8 - VSTOP (V7-V0)

   Bits 7-0 - HSTOP (H7-H0)

 [BPL1MOD](../Hardware_Manual_guide/node0072.html#line108)  - Bitplane Modulo
   (Odd-numbered bitplanes, playfield 1)


 [BPL2MOD](../Hardware_Manual_guide/node0072.html#line108)  - Bitplane Modulo
   (Even-numbered bitplanes, playfield 2)

