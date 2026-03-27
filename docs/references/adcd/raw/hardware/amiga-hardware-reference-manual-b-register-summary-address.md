# Amiga® Hardware Reference Manual: B Register Summary Address Order


This appendix contains information about the register set in address order.

The following codes and abbreviations are used in this appendix:

  &        Register used by DMA channel only.

  %        Register used by DMA channel usually, processors sometimes.

  +        Address register pair.  Must be an even address pointing to chip

           memory.
  *        Address not writable by the Copper.

  ~        Address not writable by the Copper unless the "copper danger

```c
           bit",  [COPCON](../Hardware_Manual_guide/node0029.html)  is set true.
```
  A,D,P    A=Agnus chip, D=Denise chip, P=Paula chip.

  W,R      W=write-only; R=read-only,

  ER       Early read. This is a DMA data transfer to RAM, from either the

           disk or the blitter.  RAM timing requires data to be on the bus
           earlier than microprocessor read cycles. These transfers are
           therefore initiated by Agnus timing, rather than a read address
           on the destination address bus.
  S        Strobe (write address with no register bits).  Writing the

           register causes the effect.
  PTL,PTH  Chip memory pointer that addresses DMA data.  Must be reloaded

```c
           by a processor before use (vertical blank for bitplane and
           sprite pointers, and prior to starting the blitter for blitter
           pointers).
```
  LCL,LCH  Chip memory location (starting address) of DMA data.  Used to

```c
           automatically restart pointers, such as the Copper program
           counter (during vertical blank) and the audio sample counter
           (whenever the audio length count is finished).
```
  MOD      15-bit modulo. A number that is automatically added to the

```c
           memory address at the end of each line to generate the address
           for the beginning of the next line. This allows the blitter (or
           the display window) to operate on (or display) a window of data
           that is smaller than the actual picture in memory (memory map).
           Uses 15 bits, plus sign extend.
```
   About the ECS registers.
   ------------------------
   Registers denoted with an "(E)" in the chip column means that
   those registers have been changed in the Enhanced Chip Set
   (ECS).  The ECS is found in the A3000, and is installable in the
   A500 and A2000.  Certain ECS registers are completely new,
   others have been extended in their functionality. See the
```c
    [register map](../Hardware_Manual_guide/node00AD.html)  in Appendix C for information on which ECS
```
   registers are new and which have been modified.

----------------------------------------------------------------------
NAME        ADD  R/W  CHIP    FUNCTION
----------------------------------------------------------------------
 [BLTDDAT](../Hardware_Manual_guide/node001C.html)   & *000  ER  A       Blitter destination early read
```c
                                   (dummy address)
```
 [DMACONR](../Hardware_Manual_guide/node002F.html)     *002  R   AP      DMA control (and blitter status) read
 [VPOSR](../Hardware_Manual_guide/node0045.html)       *004  R   A( [E](../Hardware_Manual_guide/node00A2.html) )  Read vert most signif. bit (and frame flop)
 [VHPOSR](../Hardware_Manual_guide/node0044.html)      *006  R   A       Read vert and horiz. position of beam
 [DSKDATR](../Hardware_Manual_guide/node0031.html)   & *008  ER  P       Disk data early read (dummy address)
 [JOY0DAT](../Hardware_Manual_guide/node0038.html)     *00A  R   D       Joystick-mouse 0 data (vert,horiz)
 [JOY1DAT](../Hardware_Manual_guide/node0038.html)     *00C  R   D       Joystick-mouse 1 data (vert,horiz)
 [CLXDAT](../Hardware_Manual_guide/node0026.html)      *00E  R   D       Collision data register (read and clear)
 [ADKCONR](../Hardware_Manual_guide/node0012.html)     *010  R   P       Audio, disk control register read
 [POT0DAT](../Hardware_Manual_guide/node003A.html)     *012  R   P( [E](../Hardware_Manual_guide/node00AC.html) )  Pot counter pair 0 data (vert,horiz)
 [POT1DAT](../Hardware_Manual_guide/node003A.html)     *014  R   P( [E](../Hardware_Manual_guide/node00AC.html) )  Pot counter pair 1 data (vert,horiz)
 [POTGOR](../Hardware_Manual_guide/node003B.html)      *016  R   P       Pot port data read (formerly POTINP)
 [SERDATR](../Hardware_Manual_guide/node003D.html#line22)     *018  R   P       Serial port data and status read
 [DSKBYTR](../Hardware_Manual_guide/node0030.html)     *01A  R   P       Disk data byte and status read
 [INTENAR](../Hardware_Manual_guide/node0036.html)     *01C  R   P       Interrupt enable bits read
 [INTREQR](../Hardware_Manual_guide/node0037.html)     *01E  R   P       Interrupt request bits read
 [DSKPTH](../Hardware_Manual_guide/node0033.html)    + *020  W   A( [E](../Hardware_Manual_guide/node00AB.html#line4) )  Disk pointer (high 3 bits, 5 bits if ECS)
 [DSKPTL](../Hardware_Manual_guide/node0033.html)    + *022  W   A       Disk pointer (low 15 bits)
 [DSKLEN](../Hardware_Manual_guide/node0032.html)      *024  W   P       Disk length
 [DSKDAT](../Hardware_Manual_guide/node0031.html)    & *026  W   P       Disk DMA data write
 [REFPTR](../Hardware_Manual_guide/node003C.html)    & *028  W   A       Refresh pointer
 [VPOSW](../Hardware_Manual_guide/node0045.html)       *02A  W   A       Write vert most signif. bit (and frame flop)
 [VHPOSW](../Hardware_Manual_guide/node0044.html)      *02C  W   A       Write vert and horiz position of beam
 [COPCON](../Hardware_Manual_guide/node0029.html)      *02E  W   A( [E](../Hardware_Manual_guide/node00AC.html#line17) )  Coprocessor control register (CDANG)
 [SERDAT](../Hardware_Manual_guide/node003D.html)      *030  W   P       Serial port data and stop bits write
 [SERPER](../Hardware_Manual_guide/node003E.html)      *032  W   P       Serial port period and control
 [POTGO](../Hardware_Manual_guide/node003B.html)       *034  W   P       Pot port data write and start
 [JOYTEST](../Hardware_Manual_guide/node0039.html)     *036  W   D       Write to all four joystick-mouse counters
                               at once
 [STREQU](../Hardware_Manual_guide/node0042.html)    & *038  S   D       Strobe for horiz sync with VB and EQU
 [STRVBL](../Hardware_Manual_guide/node0042.html#line19)    & *03A  S   D       Strobe for horiz sync with VB (vert. blank)
 [STRHOR](../Hardware_Manual_guide/node0042.html)    & *03C  S   DP      Strobe for horiz sync
 [STRLONG](../Hardware_Manual_guide/node0042.html)   & *03E  S   D( [E](../Hardware_Manual_guide/node00AB.html#line18) )  Strobe for identification of long
                                   horiz. line.
 [BLTCON0](../Hardware_Manual_guide/node001A.html)     ~040  W   A       Blitter control register 0
 [BLTCON1](../Hardware_Manual_guide/node001A.html)     ~042  W   A( [E](../Hardware_Manual_guide/node00AB.html#line26) )  Blitter control register 1
 [BLTAFWM](../Hardware_Manual_guide/node0019.html)     ~044  W   A       Blitter first word mask for source A
 [BLTALWM](../Hardware_Manual_guide/node0019.html)     ~046  W   A       Blitter last word mask for source A
 [BLTCPTH](../Hardware_Manual_guide/node0020.html)   + ~048  W   A       Blitter pointer to source C (high 3 bits)
 [BLTCPTL](../Hardware_Manual_guide/node0020.html)   + ~04A  W   A       Blitter pointer to source C (low 15 bits)
 [BLTBPTH](../Hardware_Manual_guide/node0020.html)   + ~04C  W   A       Blitter pointer to source B (high 3 bits)
 [BLTBPTL](../Hardware_Manual_guide/node0020.html)   + ~04E  W   A       Blitter pointer to source B (low 15 bits)
 [BLTAPTH](../Hardware_Manual_guide/node0020.html)   + ~050  W   A( [E](../Hardware_Manual_guide/node00AB.html#line4) )  Blitter pointer to source A (high 3 bits)
 [BLTAPTL](../Hardware_Manual_guide/node0020.html)   + ~052  W   A       Blitter pointer to source A (low 15 bits)
 [BLTDPTH](../Hardware_Manual_guide/node0020.html)   + ~054  W   A       Blitter pointer to destination D
```c
                                   (high 3 bits)
```
 [BLTDPTL](../Hardware_Manual_guide/node0020.html)   + ~056  W   A       Blitter pointer to destination D
```c
                                   (low 15 bits)
```
 [BLTSIZE](../Hardware_Manual_guide/node001D.html)     ~058  W   A       Blitter start and size (window width,height)
 [BLTCON0L](../Hardware_Manual_guide/node001B.html)    ~05A  W   A( [E](../Hardware_Manual_guide/node00AB.html#line34) )  Blitter control 0, lower 8 bits (minterms)
 [BLTSIZV](../Hardware_Manual_guide/node001D.html#line28)     ~05C  W   A( [E](../Hardware_Manual_guide/node00AA.html#line13) )  Blitter V size (for 15 bit vertical size)
 [BLTSIZH](../Hardware_Manual_guide/node001D.html#line28)     ~05E  W   A( [E](../Hardware_Manual_guide/node00AA.html#line13) )  Blitter H size and start (for 11 bit H size)
 [BLTCMOD](../Hardware_Manual_guide/node001F.html)     ~060  W   A       Blitter modulo for source C
 [BLTBMOD](../Hardware_Manual_guide/node001F.html)     ~062  W   A       Blitter modulo for source B
 [BLTAMOD](../Hardware_Manual_guide/node001F.html)     ~064  W   A       Blitter modulo for source A
 [BLTDMOD](../Hardware_Manual_guide/node001F.html)     ~066  W   A       Blitter modulo for destination D
             ~068
             ~06A
             ~06C
             ~06E
 [BLTCDAT](../Hardware_Manual_guide/node001E.html)   % ~070  W   A       Blitter source C data register
 [BLTBDAT](../Hardware_Manual_guide/node001E.html)   % ~072  W   A       Blitter source B data register

 [BLTADAT](../Hardware_Manual_guide/node001E.html)   % ~074  W   A       Blitter source A data register
             ~076
 SPRHDAT     ~078  W   A( E )  Ext. logic UHRES sprite pointer and data id
             ~07A
 [DENISEID](../Hardware_Manual_guide/node002D.html)    ~07C  R   D( [E](../Hardware_Manual_guide/node00A2.html#line21) )  Chip revision level for Denise
```c
                                   (video out chip)
```
 [DSKSYNC](../Hardware_Manual_guide/node0034.html)     ~07E  W   P       Disk sync pattern register for disk read
 [COP1LCH](../Hardware_Manual_guide/node0028.html)   +  080  W   A( [E](../Hardware_Manual_guide/node00AB.html#line4) )  Coprocessor first location register
```c
                                  (high 3 bits, high 5 bits if ECS)
```
 [COP1LCL](../Hardware_Manual_guide/node0028.html)   +  082  W   A       Coprocessor first location register
```c
                                  (low 15 bits)
```
 [COP2LCH](../Hardware_Manual_guide/node0028.html)   +  084  W   A( [E](../Hardware_Manual_guide/node00AB.html#line4) )  Coprocessor second location register
```c
                                  (high 3 bits, high 5 bits if ECS)
```
 [COP2LCL](../Hardware_Manual_guide/node0028.html)   +  086  W   A       Coprocessor second location register
```c
                                  (low 15 bits)
```
 [COPJMP1](../Hardware_Manual_guide/node002B.html)      088  S   A       Coprocessor restart at first location
 [COPJMP2](../Hardware_Manual_guide/node002B.html)      08A  S   A       Coprocessor restart at second location
 [COPINS](../Hardware_Manual_guide/node002A.html)       08C  W   A       Coprocessor instruction fetch identify
 [DIWSTRT](../Hardware_Manual_guide/node002E.html)      08E  W   A       Display window start (upper left
```c
                                  vert-horiz position)
```
 [DIWSTOP](../Hardware_Manual_guide/node002E.html)      090  W   A       Display window stop (lower right
```c
                                  vert.-horiz. position)
```
 [DDFSTRT](../Hardware_Manual_guide/node002C.html)      092  W   A       Display bitplane data fetch start
```c
                                  (horiz. position)
```
 [DDFSTOP](../Hardware_Manual_guide/node002C.html)      094  W   A       Display bitplane data fetch stop
```c
                                  (horiz. position)
```
 [DMACON](../Hardware_Manual_guide/node002F.html)       096  W   ADP     DMA control write (clear or set)
 [CLXCON](../Hardware_Manual_guide/node0025.html)       098  W   D       Collision control
 [INTENA](../Hardware_Manual_guide/node0036.html)       09A  W   P       Interrupt enable bits (clear or
```c
                                  set bits)
```
 [INTREQ](../Hardware_Manual_guide/node0037.html)       09C  W   P       Interrupt request bits (clear or
```c
                                  set bits)
```
 [ADKCON](../Hardware_Manual_guide/node0012.html)       09E  W   P       Audio, disk, UART control
 [AUD0LCH](../Hardware_Manual_guide/node0014.html)   +  0A0  W   A( [E](../Hardware_Manual_guide/node00AB.html#line4) )  Audio channel 0 location (high 3 bits,
```c
                                   5 if ECS)
```
 [AUD0LCL](../Hardware_Manual_guide/node0014.html)   +  0A2  W   A       Audio channel 0 location (low 15 bits)
 [AUD0LEN](../Hardware_Manual_guide/node0015.html)      0A4  W   P       Audio channel 0 length
 [AUD0PER](../Hardware_Manual_guide/node0016.html)      0A6  W   P( [E](../Hardware_Manual_guide/node00AC.html#line30) )  Audio channel 0 period
 [AUD0VOL](../Hardware_Manual_guide/node0017.html)      0A8  W   P       Audio channel 0 volume
 [AUD0DAT](../Hardware_Manual_guide/node0013.html)   &  0AA  W   P       Audio channel 0 data
              0AC
              0AE
 [AUD1LCH](../Hardware_Manual_guide/node0014.html)   +  0B0  W   A       Audio channel 1 location (high 3 bits)
 [AUD1LCL](../Hardware_Manual_guide/node0014.html)   +  0B2  W   A       Audio channel 1 location (low 15 bits)
 [AUD1LEN](../Hardware_Manual_guide/node0015.html)      0B4  W   P       Audio channel 1 length
 [AUD1PER](../Hardware_Manual_guide/node0016.html)      0B6  W   P       Audio channel 1 period
 [AUD1VOL](../Hardware_Manual_guide/node0017.html)      0B8  W   P       Audio channel 1 volume
 [AUD1DAT](../Hardware_Manual_guide/node0013.html)   &  0BA  W   P       Audio channel 1 data
              0BC
              0BE
 [AUD2LCH](../Hardware_Manual_guide/node0014.html)   +  0C0  W   A       Audio channel 2 location (high 3 bits)
 [AUD2LCL](../Hardware_Manual_guide/node0014.html)   +  0C2  W   A       Audio channel 2 location (low 15 bits)
 [AUD2LEN](../Hardware_Manual_guide/node0015.html)      0C4  W   P       Audio channel 2 length
 [AUD2PER](../Hardware_Manual_guide/node0016.html)      0C6  W   P       Audio channel 2 period
 [AUD2VOL](../Hardware_Manual_guide/node0017.html)      0C8  W   P       Audio channel 2 volume
 [AUD2DAT](../Hardware_Manual_guide/node0013.html)   &  0CA  W   P       Audio channel 2 data
              0CC
              0CE
 [AUD3LCH](../Hardware_Manual_guide/node0014.html)   +  0D0  W   A       Audio channel 3 location (high 3 bits)
 [AUD3LCL](../Hardware_Manual_guide/node0014.html)   +  0D2  W   A       Audio channel 3 location (low 15 bits)
 [AUD3LEN](../Hardware_Manual_guide/node0015.html)      0D4  W   P       Audio channel 3 length
 [AUD3PER](../Hardware_Manual_guide/node0016.html)      0D6  W   P       Audio channel 3 period
 [AUD3VOL](../Hardware_Manual_guide/node0017.html)      0D8  W   P       Audio channel 3 volume
 [AUD3DAT](../Hardware_Manual_guide/node0013.html)   &  0DA  W   P       Audio channel 3 data
              0DC
              0DE
 [BPL1PTH](../Hardware_Manual_guide/node0024.html)   +  0E0  W   A       Bitplane 1 pointer (high 3 bits)
 [BPL1PTL](../Hardware_Manual_guide/node0024.html)   +  0E2  W   A       Bitplane 1 pointer (low 15 bits)
 [BPL2PTH](../Hardware_Manual_guide/node0024.html)   +  0E4  W   A       Bitplane 2 pointer (high 3 bits)
 [BPL2PTL](../Hardware_Manual_guide/node0024.html)   +  0E6  W   A       Bitplane 2 pointer (low 15 bits)
 [BPL3PTH](../Hardware_Manual_guide/node0024.html)   +  0E8  W   A       Bitplane 3 pointer (high 3 bits)
 [BPL3PTL](../Hardware_Manual_guide/node0024.html)   +  0EA  W   A       Bitplane 3 pointer (low 15 bits)
 [BPL4PTH](../Hardware_Manual_guide/node0024.html)   +  0EC  W   A       Bitplane 4 pointer (high 3 bits)
 [BPL4PTL](../Hardware_Manual_guide/node0024.html)   +  0EE  W   A       Bitplane 4 pointer (low 15 bits)
 [BPL5PTH](../Hardware_Manual_guide/node0024.html)   +  0F0  W   A       Bitplane 5 pointer (high 3 bits)
 [BPL5PTL](../Hardware_Manual_guide/node0024.html)   +  0F2  W   A       Bitplane 5 pointer (low 15 bits)
 [BPL6PTH](../Hardware_Manual_guide/node0024.html)   +  0F4  W   A       Bitplane 6 pointer (high 3 bits)
 [BPL6PTL](../Hardware_Manual_guide/node0024.html)   +  0F6  W   A       Bitplane 6 pointer (low 15 bits)
              0F8
              0FA
              0FC
              0FE
 [BPLCON0](../Hardware_Manual_guide/node0022.html)      100  W   AD( [E](../Hardware_Manual_guide/node00A3.html) ) Bitplane control register
```c
                                   (misc. control bits)
```
 [BPLCON1](../Hardware_Manual_guide/node0022.html)      102  W   D       Bitplane control reg.
```c
                                   (scroll value PF1, PF2)
```
 [BPLCON2](../Hardware_Manual_guide/node0022.html)      104  W   D( [E](../Hardware_Manual_guide/node00A9.html) )  Bitplane control reg. (priority control)
 [BPLCON3](../Hardware_Manual_guide/node0022.html#line57)      106  W   D( [E](../Hardware_Manual_guide/node00A9.html) )  Bitplane control (enhanced features)

 [BPL1MOD](../Hardware_Manual_guide/node0021.html)      108  W   A       Bitplane modulo (odd planes)
 [BPL2MOD](../Hardware_Manual_guide/node0021.html)      10A  W   A       Bitplane modulo (even planes)
              10C
              10E
 [BPL1DAT](../Hardware_Manual_guide/node0023.html)   &  110  W   D       Bitplane 1 data (parallel-to-serial convert)
 [BPL2DAT](../Hardware_Manual_guide/node0023.html)   &  112  W   D       Bitplane 2 data (parallel-to-serial convert)
 [BPL3DAT](../Hardware_Manual_guide/node0023.html)   &  114  W   D       Bitplane 3 data (parallel-to-serial convert)
 [BPL4DAT](../Hardware_Manual_guide/node0023.html)   &  116  W   D       Bitplane 4 data (parallel-to-serial convert)
 [BPL5DAT](../Hardware_Manual_guide/node0023.html)   &  118  W   D       Bitplane 5 data (parallel-to-serial convert)
 [BPL6DAT](../Hardware_Manual_guide/node0023.html)   &  11A  W   D       Bitplane 6 data (parallel-to-serial convert)
              11C
              11E
 [SPR0PTH](../Hardware_Manual_guide/node0041.html)   +  120  W   A       Sprite 0 pointer (high 3 bits)
 [SPR0PTL](../Hardware_Manual_guide/node0041.html)   +  122  W   A       Sprite 0 pointer (low 15 bits)
 [SPR1PTH](../Hardware_Manual_guide/node0041.html)   +  124  W   A       Sprite 1 pointer (high 3 bits)
 [SPR1PTL](../Hardware_Manual_guide/node0041.html)   +  126  W   A       Sprite 1 pointer (low 15 bits)
 [SPR2PTH](../Hardware_Manual_guide/node0041.html)   +  128  W   A       Sprite 2 pointer (high 3 bits)
 [SPR2PTL](../Hardware_Manual_guide/node0041.html)   +  12A  W   A       Sprite 2 pointer (low 15 bits)
 [SPR3PTH](../Hardware_Manual_guide/node0041.html)   +  12C  W   A       Sprite 3 pointer (high 3 bits)
 [SPR3PTL](../Hardware_Manual_guide/node0041.html)   +  12E  W   A       Sprite 3 pointer (low 15 bits)
 [SPR4PTH](../Hardware_Manual_guide/node0041.html)   +  130  W   A       Sprite 4 pointer (high 3 bits)
 [SPR4PTL](../Hardware_Manual_guide/node0041.html)   +  132  W   A       Sprite 4 pointer (low 15 bits)
 [SPR5PTH](../Hardware_Manual_guide/node0041.html)   +  134  W   A       Sprite 5 pointer (high 3 bits)
 [SPR5PTL](../Hardware_Manual_guide/node0041.html)   +  136  W   A       Sprite 5 pointer (low 15 bits)
 [SPR6PTH](../Hardware_Manual_guide/node0041.html)   +  138  W   A       Sprite 6 pointer (high 3 bits)
 [SPR6PTL](../Hardware_Manual_guide/node0041.html)   +  13A  W   A       Sprite 6 pointer (low 15 bits)
 [SPR7PTH](../Hardware_Manual_guide/node0041.html)   +  13C  W   A       Sprite 7 pointer (high 3 bits)
 [SPR7PTL](../Hardware_Manual_guide/node0041.html)   +  13E  W   A       Sprite 7 pointer (low 15 bits)
 [SPR0POS](../Hardware_Manual_guide/node003F.html)   %  140  W   AD      Sprite 0 vert-horiz start position
                                  data
 [SPR0CTL](../Hardware_Manual_guide/node003F.html)   %  142  W   AD( [E](../Hardware_Manual_guide/node00A5.html) ) Sprite 0 vert stop position and
                                  control data
 [SPR0DATA](../Hardware_Manual_guide/node0040.html)  %  144  W   D       Sprite 0 image data register A
 [SPR0DATB](../Hardware_Manual_guide/node0040.html)  %  146  W   D       Sprite 0 image data register B
 [SPR1POS](../Hardware_Manual_guide/node003F.html)   %  148  W   AD      Sprite 1 vert-horiz start position
                                  data
 [SPR1CTL](../Hardware_Manual_guide/node003F.html)   %  14A  W   AD      Sprite 1 vert stop position and
                                  control data
 [SPR1DATA](../Hardware_Manual_guide/node0040.html)  %  14C  W   D       Sprite 1 image data register A
 [SPR1DATB](../Hardware_Manual_guide/node0040.html)  %  14E  W   D       Sprite 1 image data register B
 [SPR2POS](../Hardware_Manual_guide/node003F.html)   %  150  W   AD      Sprite 2 vert-horiz start position
                                  data
 [SPR2CTL](../Hardware_Manual_guide/node003F.html)   %  152  W   AD      Sprite 2 vert stop position and
                                  control data
 [SPR2DATA](../Hardware_Manual_guide/node0040.html)  %  154  W   D       Sprite 2 image data register A
 [SPR2DATB](../Hardware_Manual_guide/node0040.html)  %  156  W   D       Sprite 2 image data register B
 [SPR3POS](../Hardware_Manual_guide/node003F.html)   %  158  W   AD      Sprite 3 vert-horiz start position
                                  data
 [SPR3CTL](../Hardware_Manual_guide/node003F.html)   %  15A  W   AD      Sprite 3 vert stop position and
                                  control data
 [SPR3DATA](../Hardware_Manual_guide/node0040.html)  %  15C  W   D       Sprite 3 image data register A
 [SPR3DATB](../Hardware_Manual_guide/node0040.html)  %  15E  W   D       Sprite 3 image data register B
 [SPR4POS](../Hardware_Manual_guide/node003F.html)   %  160  W   AD      Sprite 4 vert-horiz start position
                                  data
 [SPR4CTL](../Hardware_Manual_guide/node003F.html)   %  162  W   AD      Sprite 4 vert stop position and
                                  control data
 [SPR4DATA](../Hardware_Manual_guide/node0040.html)  %  164  W   D       Sprite 4 image data register A
 [SPR4DATB](../Hardware_Manual_guide/node0040.html)  %  166  W   D       Sprite 4 image data register B
 [SPR5POS](../Hardware_Manual_guide/node003F.html)   %  168  W   AD      Sprite 5 vert-horiz start position
                                  data
 [SPR5CTL](../Hardware_Manual_guide/node003F.html)   %  16A  W   AD      Sprite 5 vert stop position and
                                  control data
 [SPR5DATA](../Hardware_Manual_guide/node0040.html)  %  16C  W   D       Sprite 5 image data register A
 [SPR5DATB](../Hardware_Manual_guide/node0040.html)  %  16E  W   D       Sprite 5 image data register B
 [SPR6POS](../Hardware_Manual_guide/node003F.html)   %  170  W   AD      Sprite 6 vert-horiz start position
                                  data
 [SPR6CTL](../Hardware_Manual_guide/node003F.html)   %  172  W   AD      Sprite 6 vert stop position and
                                  control data
 [SPR6DATA](../Hardware_Manual_guide/node0040.html)  %  174  W   D       Sprite 6 image data register A
 [SPR6DATB](../Hardware_Manual_guide/node0040.html)  %  176  W   D       Sprite 6 image data register B
 [SPR7POS](../Hardware_Manual_guide/node003F.html)   %  178  W   AD      Sprite 7 vert-horiz start position
                                  data
 [SPR7CTL](../Hardware_Manual_guide/node003F.html)   %  17A  W   AD      Sprite 7 vert stop position and
                                  control data
 [SPR7DATA](../Hardware_Manual_guide/node0040.html)  %  17C  W   D       Sprite 7 image data register A
 [SPR7DATB](../Hardware_Manual_guide/node0040.html)  %  17E  W   D       Sprite 7 image data register B
 [COLOR00](../Hardware_Manual_guide/node0027.html)      180  W   D       Color table 00
 [COLOR01](../Hardware_Manual_guide/node0027.html)      182  W   D       Color table 01
 [COLOR02](../Hardware_Manual_guide/node0027.html)      184  W   D       Color table 02
 [COLOR03](../Hardware_Manual_guide/node0027.html)      186  W   D       Color table 03
 [COLOR04](../Hardware_Manual_guide/node0027.html)      188  W   D       Color table 04
 [COLOR05](../Hardware_Manual_guide/node0027.html)      18A  W   D       Color table 05
 [COLOR06](../Hardware_Manual_guide/node0027.html)      18C  W   D       Color table 06
 [COLOR07](../Hardware_Manual_guide/node0027.html)      18E  W   D       Color table 07
 [COLOR08](../Hardware_Manual_guide/node0027.html)      190  W   D       Color table 08
 [COLOR09](../Hardware_Manual_guide/node0027.html)      192  W   D       Color table 09
 [COLOR10](../Hardware_Manual_guide/node0027.html)      194  W   D       Color table 10
 [COLOR11](../Hardware_Manual_guide/node0027.html)      196  W   D       Color table 11
 [COLOR12](../Hardware_Manual_guide/node0027.html)      198  W   D       Color table 12
 [COLOR13](../Hardware_Manual_guide/node0027.html)      19A  W   D       Color table 13
 [COLOR14](../Hardware_Manual_guide/node0027.html)      19C  W   D       Color table 14
 [COLOR15](../Hardware_Manual_guide/node0027.html)      19E  W   D       Color table 15
 [COLOR16](../Hardware_Manual_guide/node0027.html)      1A0  W   D       Color table 16
 [COLOR17](../Hardware_Manual_guide/node0027.html)      1A2  W   D       Color table 17
 [COLOR18](../Hardware_Manual_guide/node0027.html)      1A4  W   D       Color table 18
 [COLOR19](../Hardware_Manual_guide/node0027.html)      1A6  W   D       Color table 19
 [COLOR20](../Hardware_Manual_guide/node0027.html)      1A8  W   D       Color table 20
 [COLOR21](../Hardware_Manual_guide/node0027.html)      1AA  W   D       Color table 21
 [COLOR22](../Hardware_Manual_guide/node0027.html)      1AC  W   D       Color table 22
 [COLOR23](../Hardware_Manual_guide/node0027.html)      1AE  W   D       Color table 23
 [COLOR24](../Hardware_Manual_guide/node0027.html)      1B0  W   D       Color table 24
 [COLOR25](../Hardware_Manual_guide/node0027.html)      1B2  W   D       Color table 25
 [COLOR26](../Hardware_Manual_guide/node0027.html)      1B4  W   D       Color table 26
 [COLOR27](../Hardware_Manual_guide/node0027.html)      1B6  W   D       Color table 27
 [COLOR28](../Hardware_Manual_guide/node0027.html)      1B8  W   D       Color table 28
 [COLOR29](../Hardware_Manual_guide/node0027.html)      1BA  W   D       Color table 29
 [COLOR30](../Hardware_Manual_guide/node0027.html)      1BC  W   D       Color table 30
 [COLOR31](../Hardware_Manual_guide/node0027.html)      1BE  W   D       Color table 31

 [HTOTAL](../Hardware_Manual_guide/node0035.html)       1C0  W   A( [E](../Hardware_Manual_guide/node00A6.html#line8) )  Highest number count, horiz line
```c
                                   (VARBEAMEN=1)
```
 [HSSTOP](../Hardware_Manual_guide/node0035.html)       1C2  W   A( [E](../Hardware_Manual_guide/node00A6.html#line29) )  Horizontal line position for HSYNC stop
 [HBSTRT](../Hardware_Manual_guide/node0035.html)       1C4  W   A( [E](../Hardware_Manual_guide/node00A6.html#line42) )  Horizontal line position for HBLANK start
 [HBSTOP](../Hardware_Manual_guide/node0035.html)       1C6  W   A( [E](../Hardware_Manual_guide/node00A6.html#line42) )  Horizontal line position for HBLANK stop
 [VTOTAL](../Hardware_Manual_guide/node0046.html)       1C8  W   A( [E](../Hardware_Manual_guide/node00A6.html#line21) )  Highest numbered vertical line
```c
                                   (VARBEAMEN=1)
```
 [VSSTOP](../Hardware_Manual_guide/node0046.html)       1CA  W   A( [E](../Hardware_Manual_guide/node00A6.html#line29) )  Vertical line position for VSYNC stop
 [VBSTRT](../Hardware_Manual_guide/node0043.html)       1CC  W   A( [E](../Hardware_Manual_guide/node00A6.html#line42) )  Vertical line for VBLANK start
 [VBSTOP](../Hardware_Manual_guide/node0043.html)       1CE  W   A( [E](../Hardware_Manual_guide/node00A6.html#line42) )  Vertical line for VBLANK stop


              1D0              Reserved
              1D2              Reserved
              1D4              Reserved
              1D6              Reserved
              1D8              Reserved
              1DA              Reserved
 [BEAMCON0](../Hardware_Manual_guide/node0018.html)     1DC  W   A( [E](../Hardware_Manual_guide/node00A7.html) )  Beam counter control register (SHRES,PAL)
 [HSSTRT](../Hardware_Manual_guide/node0035.html)       1DE  W   A( [E](../Hardware_Manual_guide/node00A6.html#line29) )  Horizontal sync start (VARHSY)
 [VSSTRT](../Hardware_Manual_guide/node0046.html)       1E0  W   A( [E](../Hardware_Manual_guide/node00A6.html#line29) )  Vertical sync start   (VARVSY)
 [HCENTER](../Hardware_Manual_guide/node0035.html)      1E2  W   A( [E](../Hardware_Manual_guide/node00A6.html#line29) )  Horizontal position for Vsync on interlace
 [DIWHIGH](../Hardware_Manual_guide/node002E.html)      1E4  W   AD( [E](../Hardware_Manual_guide/node00A8.html#line16) ) Display window -  upper bits for start, stop


 RESERVED     1110X
 RESERVED     1111X
 NO-OP(NULL)  1FE

