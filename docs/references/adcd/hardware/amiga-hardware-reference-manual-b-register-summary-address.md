---
title: Amiga® Hardware Reference Manual: B Register Summary Address Order
manual: hardware
chapter: hardware
section: amiga-hardware-reference-manual-b-register-summary-address
functions: []
libraries: []
---

# Amiga® Hardware Reference Manual: B Register Summary Address Order

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This appendix contains information about the register set in address order.

The following codes and abbreviations are used in this appendix:

  &        Register used by DMA channel only.

  %        Register used by DMA channel usually, processors sometimes.

  +        Address register pair.  Must be an even address pointing to chip

           memory.
  *        Address not writable by the Copper.

  ~        Address not writable by the Copper unless the "copper danger

```c
           bit",  [COPCON](hardware/a-register-summary-copcon.md)  is set true.
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
    [register map](hardware/c-enhanced-chip-set-ecs-registers.md)  in Appendix C for information on which ECS
```
   registers are new and which have been modified.

----------------------------------------------------------------------
NAME        ADD  R/W  CHIP    FUNCTION
----------------------------------------------------------------------
 [BLTDDAT](hardware/a-register-summary-bltddat.md)   & *000  ER  A       Blitter destination early read
```c
                                   (dummy address)
```
 [DMACONR](hardware/a-register-summary-dmacon-dmaconr.md)     *002  R   AP      DMA control (and blitter status) read
 [VPOSR](hardware/a-register-summary-vposr-vposw.md)       *004  R   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-determining-chip.md) )  Read vert most signif. bit (and frame flop)
 [VHPOSR](hardware/a-register-summary-vhposr-vhposw.md)      *006  R   A       Read vert and horiz. position of beam
 [DSKDATR](hardware/a-register-summary-dskdat-dskdatr.md)   & *008  ER  P       Disk data early read (dummy address)
 [JOY0DAT](hardware/a-register-summary-joy0dat-joy1dat.md)     *00A  R   D       Joystick-mouse 0 data (vert,horiz)
 [JOY1DAT](hardware/a-register-summary-joy0dat-joy1dat.md)     *00C  R   D       Joystick-mouse 1 data (vert,horiz)
 [CLXDAT](hardware/a-register-summary-clxdat.md)      *00E  R   D       Collision data register (read and clear)
 [ADKCONR](hardware/a-register-summary-adkcon-adkconr.md)     *010  R   P       Audio, disk control register read
 [POT0DAT](hardware/a-register-summary-pot0dat-pot1dat.md)     *012  R   P( [E](hardware/c-ecs-hardware-and-graphics-library-interpretational.md) )  Pot counter pair 0 data (vert,horiz)
 [POT1DAT](hardware/a-register-summary-pot0dat-pot1dat.md)     *014  R   P( [E](hardware/c-ecs-hardware-and-graphics-library-interpretational.md) )  Pot counter pair 1 data (vert,horiz)
 [POTGOR](hardware/a-register-summary-potgo-potgor.md)      *016  R   P       Pot port data read (formerly POTINP)
 [SERDATR](hardware/a-register-summary-serdat-serdatr.md)     *018  R   P       Serial port data and status read
 [DSKBYTR](hardware/a-register-summary-dskbytr.md)     *01A  R   P       Disk data byte and status read
 [INTENAR](hardware/a-register-summary-intena-intenar.md)     *01C  R   P       Interrupt enable bits read
 [INTREQR](hardware/a-register-summary-intreq-intreqr.md)     *01E  R   P       Interrupt request bits read
 [DSKPTH](hardware/a-register-summary-dskpth-dskptl.md)    + *020  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) )  Disk pointer (high 3 bits, 5 bits if ECS)
 [DSKPTL](hardware/a-register-summary-dskpth-dskptl.md)    + *022  W   A       Disk pointer (low 15 bits)
 [DSKLEN](hardware/a-register-summary-dsklen.md)      *024  W   P       Disk length
 [DSKDAT](hardware/a-register-summary-dskdat-dskdatr.md)    & *026  W   P       Disk DMA data write
 [REFPTR](hardware/a-register-summary-refptr.md)    & *028  W   A       Refresh pointer
 [VPOSW](hardware/a-register-summary-vposr-vposw.md)       *02A  W   A       Write vert most signif. bit (and frame flop)
 [VHPOSW](hardware/a-register-summary-vhposr-vhposw.md)      *02C  W   A       Write vert and horiz position of beam
 [COPCON](hardware/a-register-summary-copcon.md)      *02E  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-interpretational.md) )  Coprocessor control register (CDANG)
 [SERDAT](hardware/a-register-summary-serdat-serdatr.md)      *030  W   P       Serial port data and stop bits write
 [SERPER](hardware/a-register-summary-serper.md)      *032  W   P       Serial port period and control
 [POTGO](hardware/a-register-summary-potgo-potgor.md)       *034  W   P       Pot port data write and start
 [JOYTEST](hardware/a-register-summary-joytest.md)     *036  W   D       Write to all four joystick-mouse counters
                               at once
 [STREQU](hardware/a-register-summary-strequ-strhor-strlong-strvbl.md)    & *038  S   D       Strobe for horiz sync with VB and EQU
 [STRVBL](hardware/a-register-summary-strequ-strhor-strlong-strvbl.md)    & *03A  S   D       Strobe for horiz sync with VB (vert. blank)
 [STRHOR](hardware/a-register-summary-strequ-strhor-strlong-strvbl.md)    & *03C  S   DP      Strobe for horiz sync
 [STRLONG](hardware/a-register-summary-strequ-strhor-strlong-strvbl.md)   & *03E  S   D( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) )  Strobe for identification of long
                                   horiz. line.
 [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)     ~040  W   A       Blitter control register 0
 [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)     ~042  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) )  Blitter control register 1
 [BLTAFWM](hardware/a-register-summary-bltafwm-bltalwm.md)     ~044  W   A       Blitter first word mask for source A
 [BLTALWM](hardware/a-register-summary-bltafwm-bltalwm.md)     ~046  W   A       Blitter last word mask for source A
 [BLTCPTH](hardware/a-register-summary-bltxpth-bltxptl.md)   + ~048  W   A       Blitter pointer to source C (high 3 bits)
 [BLTCPTL](hardware/a-register-summary-bltxpth-bltxptl.md)   + ~04A  W   A       Blitter pointer to source C (low 15 bits)
 [BLTBPTH](hardware/a-register-summary-bltxpth-bltxptl.md)   + ~04C  W   A       Blitter pointer to source B (high 3 bits)
 [BLTBPTL](hardware/a-register-summary-bltxpth-bltxptl.md)   + ~04E  W   A       Blitter pointer to source B (low 15 bits)
 [BLTAPTH](hardware/a-register-summary-bltxpth-bltxptl.md)   + ~050  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) )  Blitter pointer to source A (high 3 bits)
 [BLTAPTL](hardware/a-register-summary-bltxpth-bltxptl.md)   + ~052  W   A       Blitter pointer to source A (low 15 bits)
 [BLTDPTH](hardware/a-register-summary-bltxpth-bltxptl.md)   + ~054  W   A       Blitter pointer to destination D
```c
                                   (high 3 bits)
```
 [BLTDPTL](hardware/a-register-summary-bltxpth-bltxptl.md)   + ~056  W   A       Blitter pointer to destination D
```c
                                   (low 15 bits)
```
 [BLTSIZE](hardware/a-register-summary-bltsize-bltsizv-bltsizh.md)     ~058  W   A       Blitter start and size (window width,height)
 [BLTCON0L](hardware/a-register-summary-bltcon0l.md)    ~05A  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) )  Blitter control 0, lower 8 bits (minterms)
 [BLTSIZV](hardware/a-register-summary-bltsize-bltsizv-bltsizh.md)     ~05C  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-big-blits.md) )  Blitter V size (for 15 bit vertical size)
 [BLTSIZH](hardware/a-register-summary-bltsize-bltsizv-bltsizh.md)     ~05E  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-big-blits.md) )  Blitter H size and start (for 11 bit H size)
 [BLTCMOD](hardware/a-register-summary-bltxmod.md)     ~060  W   A       Blitter modulo for source C
 [BLTBMOD](hardware/a-register-summary-bltxmod.md)     ~062  W   A       Blitter modulo for source B
 [BLTAMOD](hardware/a-register-summary-bltxmod.md)     ~064  W   A       Blitter modulo for source A
 [BLTDMOD](hardware/a-register-summary-bltxmod.md)     ~066  W   A       Blitter modulo for destination D
             ~068
             ~06A
             ~06C
             ~06E
 [BLTCDAT](hardware/a-register-summary-bltxdat.md)   % ~070  W   A       Blitter source C data register
 [BLTBDAT](hardware/a-register-summary-bltxdat.md)   % ~072  W   A       Blitter source B data register

 [BLTADAT](hardware/a-register-summary-bltxdat.md)   % ~074  W   A       Blitter source A data register
             ~076
 SPRHDAT     ~078  W   A( E )  Ext. logic UHRES sprite pointer and data id
             ~07A
 [DENISEID](hardware/a-register-summary-deniseid.md)    ~07C  R   D( [E](hardware/c-ecs-hardware-and-the-graphics-library-determining-chip.md) )  Chip revision level for Denise
```c
                                   (video out chip)
```
 [DSKSYNC](hardware/a-register-summary-dsksync.md)     ~07E  W   P       Disk sync pattern register for disk read
 [COP1LCH](hardware/a-register-summary-cop1lch-cop1lcl-cop2lch-cop2lcl.md)   +  080  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) )  Coprocessor first location register
```c
                                  (high 3 bits, high 5 bits if ECS)
```
 [COP1LCL](hardware/a-register-summary-cop1lch-cop1lcl-cop2lch-cop2lcl.md)   +  082  W   A       Coprocessor first location register
```c
                                  (low 15 bits)
```
 [COP2LCH](hardware/a-register-summary-cop1lch-cop1lcl-cop2lch-cop2lcl.md)   +  084  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) )  Coprocessor second location register
```c
                                  (high 3 bits, high 5 bits if ECS)
```
 [COP2LCL](hardware/a-register-summary-cop1lch-cop1lcl-cop2lch-cop2lcl.md)   +  086  W   A       Coprocessor second location register
```c
                                  (low 15 bits)
```
 [COPJMP1](hardware/a-register-summary-copjmp1-copjmp2.md)      088  S   A       Coprocessor restart at first location
 [COPJMP2](hardware/a-register-summary-copjmp1-copjmp2.md)      08A  S   A       Coprocessor restart at second location
 [COPINS](hardware/a-register-summary-copins.md)       08C  W   A       Coprocessor instruction fetch identify
 [DIWSTRT](hardware/a-register-summary-diwhigh-diwstop-diwstrt.md)      08E  W   A       Display window start (upper left
```c
                                  vert-horiz position)
```
 [DIWSTOP](hardware/a-register-summary-diwhigh-diwstop-diwstrt.md)      090  W   A       Display window stop (lower right
```c
                                  vert.-horiz. position)
```
 [DDFSTRT](hardware/a-register-summary-ddfstop-ddfstrt.md)      092  W   A       Display bitplane data fetch start
```c
                                  (horiz. position)
```
 [DDFSTOP](hardware/a-register-summary-ddfstop-ddfstrt.md)      094  W   A       Display bitplane data fetch stop
```c
                                  (horiz. position)
```
 [DMACON](hardware/a-register-summary-dmacon-dmaconr.md)       096  W   ADP     DMA control write (clear or set)
 [CLXCON](hardware/a-register-summary-clxcon.md)       098  W   D       Collision control
 [INTENA](hardware/a-register-summary-intena-intenar.md)       09A  W   P       Interrupt enable bits (clear or
```c
                                  set bits)
```
 [INTREQ](hardware/a-register-summary-intreq-intreqr.md)       09C  W   P       Interrupt request bits (clear or
```c
                                  set bits)
```
 [ADKCON](hardware/a-register-summary-adkcon-adkconr.md)       09E  W   P       Audio, disk, UART control
 [AUD0LCH](hardware/a-register-summary-audxlch-audxlcl.md)   +  0A0  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) )  Audio channel 0 location (high 3 bits,
```c
                                   5 if ECS)
```
 [AUD0LCL](hardware/a-register-summary-audxlch-audxlcl.md)   +  0A2  W   A       Audio channel 0 location (low 15 bits)
 [AUD0LEN](hardware/a-register-summary-audxlen.md)      0A4  W   P       Audio channel 0 length
 [AUD0PER](hardware/a-register-summary-audxper.md)      0A6  W   P( [E](hardware/c-ecs-hardware-and-graphics-library-interpretational.md) )  Audio channel 0 period
 [AUD0VOL](hardware/a-register-summary-audxvol.md)      0A8  W   P       Audio channel 0 volume
 [AUD0DAT](hardware/a-register-summary-audxdat.md)   &  0AA  W   P       Audio channel 0 data
              0AC
              0AE
 [AUD1LCH](hardware/a-register-summary-audxlch-audxlcl.md)   +  0B0  W   A       Audio channel 1 location (high 3 bits)
 [AUD1LCL](hardware/a-register-summary-audxlch-audxlcl.md)   +  0B2  W   A       Audio channel 1 location (low 15 bits)
 [AUD1LEN](hardware/a-register-summary-audxlen.md)      0B4  W   P       Audio channel 1 length
 [AUD1PER](hardware/a-register-summary-audxper.md)      0B6  W   P       Audio channel 1 period
 [AUD1VOL](hardware/a-register-summary-audxvol.md)      0B8  W   P       Audio channel 1 volume
 [AUD1DAT](hardware/a-register-summary-audxdat.md)   &  0BA  W   P       Audio channel 1 data
              0BC
              0BE
 [AUD2LCH](hardware/a-register-summary-audxlch-audxlcl.md)   +  0C0  W   A       Audio channel 2 location (high 3 bits)
 [AUD2LCL](hardware/a-register-summary-audxlch-audxlcl.md)   +  0C2  W   A       Audio channel 2 location (low 15 bits)
 [AUD2LEN](hardware/a-register-summary-audxlen.md)      0C4  W   P       Audio channel 2 length
 [AUD2PER](hardware/a-register-summary-audxper.md)      0C6  W   P       Audio channel 2 period
 [AUD2VOL](hardware/a-register-summary-audxvol.md)      0C8  W   P       Audio channel 2 volume
 [AUD2DAT](hardware/a-register-summary-audxdat.md)   &  0CA  W   P       Audio channel 2 data
              0CC
              0CE
 [AUD3LCH](hardware/a-register-summary-audxlch-audxlcl.md)   +  0D0  W   A       Audio channel 3 location (high 3 bits)
 [AUD3LCL](hardware/a-register-summary-audxlch-audxlcl.md)   +  0D2  W   A       Audio channel 3 location (low 15 bits)
 [AUD3LEN](hardware/a-register-summary-audxlen.md)      0D4  W   P       Audio channel 3 length
 [AUD3PER](hardware/a-register-summary-audxper.md)      0D6  W   P       Audio channel 3 period
 [AUD3VOL](hardware/a-register-summary-audxvol.md)      0D8  W   P       Audio channel 3 volume
 [AUD3DAT](hardware/a-register-summary-audxdat.md)   &  0DA  W   P       Audio channel 3 data
              0DC
              0DE
 [BPL1PTH](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0E0  W   A       Bitplane 1 pointer (high 3 bits)
 [BPL1PTL](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0E2  W   A       Bitplane 1 pointer (low 15 bits)
 [BPL2PTH](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0E4  W   A       Bitplane 2 pointer (high 3 bits)
 [BPL2PTL](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0E6  W   A       Bitplane 2 pointer (low 15 bits)
 [BPL3PTH](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0E8  W   A       Bitplane 3 pointer (high 3 bits)
 [BPL3PTL](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0EA  W   A       Bitplane 3 pointer (low 15 bits)
 [BPL4PTH](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0EC  W   A       Bitplane 4 pointer (high 3 bits)
 [BPL4PTL](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0EE  W   A       Bitplane 4 pointer (low 15 bits)
 [BPL5PTH](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0F0  W   A       Bitplane 5 pointer (high 3 bits)
 [BPL5PTL](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0F2  W   A       Bitplane 5 pointer (low 15 bits)
 [BPL6PTH](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0F4  W   A       Bitplane 6 pointer (high 3 bits)
 [BPL6PTL](hardware/a-register-summary-bplxpth-bplxptl.md)   +  0F6  W   A       Bitplane 6 pointer (low 15 bits)
              0F8
              0FA
              0FC
              0FE
 [BPLCON0](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md)      100  W   AD( [E](hardware/c-ecs-hardware-and-the-graphics-library-superhires-mode.md) ) Bitplane control register
```c
                                   (misc. control bits)
```
 [BPLCON1](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md)      102  W   D       Bitplane control reg.
```c
                                   (scroll value PF1, PF2)
```
 [BPLCON2](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md)      104  W   D( [E](hardware/c-ecs-hardware-and-the-graphics-library-genlock-extensions.md) )  Bitplane control reg. (priority control)
 [BPLCON3](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md)      106  W   D( [E](hardware/c-ecs-hardware-and-the-graphics-library-genlock-extensions.md) )  Bitplane control (enhanced features)

 [BPL1MOD](hardware/a-register-summary-bpl1mod-bpl2mod.md)      108  W   A       Bitplane modulo (odd planes)
 [BPL2MOD](hardware/a-register-summary-bpl1mod-bpl2mod.md)      10A  W   A       Bitplane modulo (even planes)
              10C
              10E
 [BPL1DAT](hardware/a-register-summary-bplxdat.md)   &  110  W   D       Bitplane 1 data (parallel-to-serial convert)
 [BPL2DAT](hardware/a-register-summary-bplxdat.md)   &  112  W   D       Bitplane 2 data (parallel-to-serial convert)
 [BPL3DAT](hardware/a-register-summary-bplxdat.md)   &  114  W   D       Bitplane 3 data (parallel-to-serial convert)
 [BPL4DAT](hardware/a-register-summary-bplxdat.md)   &  116  W   D       Bitplane 4 data (parallel-to-serial convert)
 [BPL5DAT](hardware/a-register-summary-bplxdat.md)   &  118  W   D       Bitplane 5 data (parallel-to-serial convert)
 [BPL6DAT](hardware/a-register-summary-bplxdat.md)   &  11A  W   D       Bitplane 6 data (parallel-to-serial convert)
              11C
              11E
 [SPR0PTH](hardware/a-register-summary-sprxpth-sprxptl.md)   +  120  W   A       Sprite 0 pointer (high 3 bits)
 [SPR0PTL](hardware/a-register-summary-sprxpth-sprxptl.md)   +  122  W   A       Sprite 0 pointer (low 15 bits)
 [SPR1PTH](hardware/a-register-summary-sprxpth-sprxptl.md)   +  124  W   A       Sprite 1 pointer (high 3 bits)
 [SPR1PTL](hardware/a-register-summary-sprxpth-sprxptl.md)   +  126  W   A       Sprite 1 pointer (low 15 bits)
 [SPR2PTH](hardware/a-register-summary-sprxpth-sprxptl.md)   +  128  W   A       Sprite 2 pointer (high 3 bits)
 [SPR2PTL](hardware/a-register-summary-sprxpth-sprxptl.md)   +  12A  W   A       Sprite 2 pointer (low 15 bits)
 [SPR3PTH](hardware/a-register-summary-sprxpth-sprxptl.md)   +  12C  W   A       Sprite 3 pointer (high 3 bits)
 [SPR3PTL](hardware/a-register-summary-sprxpth-sprxptl.md)   +  12E  W   A       Sprite 3 pointer (low 15 bits)
 [SPR4PTH](hardware/a-register-summary-sprxpth-sprxptl.md)   +  130  W   A       Sprite 4 pointer (high 3 bits)
 [SPR4PTL](hardware/a-register-summary-sprxpth-sprxptl.md)   +  132  W   A       Sprite 4 pointer (low 15 bits)
 [SPR5PTH](hardware/a-register-summary-sprxpth-sprxptl.md)   +  134  W   A       Sprite 5 pointer (high 3 bits)
 [SPR5PTL](hardware/a-register-summary-sprxpth-sprxptl.md)   +  136  W   A       Sprite 5 pointer (low 15 bits)
 [SPR6PTH](hardware/a-register-summary-sprxpth-sprxptl.md)   +  138  W   A       Sprite 6 pointer (high 3 bits)
 [SPR6PTL](hardware/a-register-summary-sprxpth-sprxptl.md)   +  13A  W   A       Sprite 6 pointer (low 15 bits)
 [SPR7PTH](hardware/a-register-summary-sprxpth-sprxptl.md)   +  13C  W   A       Sprite 7 pointer (high 3 bits)
 [SPR7PTL](hardware/a-register-summary-sprxpth-sprxptl.md)   +  13E  W   A       Sprite 7 pointer (low 15 bits)
 [SPR0POS](hardware/a-register-summary-sprxctl-sprxpos.md)   %  140  W   AD      Sprite 0 vert-horiz start position
                                  data
 [SPR0CTL](hardware/a-register-summary-sprxctl-sprxpos.md)   %  142  W   AD( [E](hardware/c-ecs-hardware-graphics-library-superhires-70ns-sprite.md) ) Sprite 0 vert stop position and
                                  control data
 [SPR0DATA](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  144  W   D       Sprite 0 image data register A
 [SPR0DATB](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  146  W   D       Sprite 0 image data register B
 [SPR1POS](hardware/a-register-summary-sprxctl-sprxpos.md)   %  148  W   AD      Sprite 1 vert-horiz start position
                                  data
 [SPR1CTL](hardware/a-register-summary-sprxctl-sprxpos.md)   %  14A  W   AD      Sprite 1 vert stop position and
                                  control data
 [SPR1DATA](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  14C  W   D       Sprite 1 image data register A
 [SPR1DATB](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  14E  W   D       Sprite 1 image data register B
 [SPR2POS](hardware/a-register-summary-sprxctl-sprxpos.md)   %  150  W   AD      Sprite 2 vert-horiz start position
                                  data
 [SPR2CTL](hardware/a-register-summary-sprxctl-sprxpos.md)   %  152  W   AD      Sprite 2 vert stop position and
                                  control data
 [SPR2DATA](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  154  W   D       Sprite 2 image data register A
 [SPR2DATB](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  156  W   D       Sprite 2 image data register B
 [SPR3POS](hardware/a-register-summary-sprxctl-sprxpos.md)   %  158  W   AD      Sprite 3 vert-horiz start position
                                  data
 [SPR3CTL](hardware/a-register-summary-sprxctl-sprxpos.md)   %  15A  W   AD      Sprite 3 vert stop position and
                                  control data
 [SPR3DATA](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  15C  W   D       Sprite 3 image data register A
 [SPR3DATB](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  15E  W   D       Sprite 3 image data register B
 [SPR4POS](hardware/a-register-summary-sprxctl-sprxpos.md)   %  160  W   AD      Sprite 4 vert-horiz start position
                                  data
 [SPR4CTL](hardware/a-register-summary-sprxctl-sprxpos.md)   %  162  W   AD      Sprite 4 vert stop position and
                                  control data
 [SPR4DATA](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  164  W   D       Sprite 4 image data register A
 [SPR4DATB](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  166  W   D       Sprite 4 image data register B
 [SPR5POS](hardware/a-register-summary-sprxctl-sprxpos.md)   %  168  W   AD      Sprite 5 vert-horiz start position
                                  data
 [SPR5CTL](hardware/a-register-summary-sprxctl-sprxpos.md)   %  16A  W   AD      Sprite 5 vert stop position and
                                  control data
 [SPR5DATA](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  16C  W   D       Sprite 5 image data register A
 [SPR5DATB](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  16E  W   D       Sprite 5 image data register B
 [SPR6POS](hardware/a-register-summary-sprxctl-sprxpos.md)   %  170  W   AD      Sprite 6 vert-horiz start position
                                  data
 [SPR6CTL](hardware/a-register-summary-sprxctl-sprxpos.md)   %  172  W   AD      Sprite 6 vert stop position and
                                  control data
 [SPR6DATA](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  174  W   D       Sprite 6 image data register A
 [SPR6DATB](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  176  W   D       Sprite 6 image data register B
 [SPR7POS](hardware/a-register-summary-sprxctl-sprxpos.md)   %  178  W   AD      Sprite 7 vert-horiz start position
                                  data
 [SPR7CTL](hardware/a-register-summary-sprxctl-sprxpos.md)   %  17A  W   AD      Sprite 7 vert stop position and
                                  control data
 [SPR7DATA](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  17C  W   D       Sprite 7 image data register A
 [SPR7DATB](hardware/a-register-summary-sprxdata-sprxdatb.md)  %  17E  W   D       Sprite 7 image data register B
 [COLOR00](hardware/a-register-summary-colorxx.md)      180  W   D       Color table 00
 [COLOR01](hardware/a-register-summary-colorxx.md)      182  W   D       Color table 01
 [COLOR02](hardware/a-register-summary-colorxx.md)      184  W   D       Color table 02
 [COLOR03](hardware/a-register-summary-colorxx.md)      186  W   D       Color table 03
 [COLOR04](hardware/a-register-summary-colorxx.md)      188  W   D       Color table 04
 [COLOR05](hardware/a-register-summary-colorxx.md)      18A  W   D       Color table 05
 [COLOR06](hardware/a-register-summary-colorxx.md)      18C  W   D       Color table 06
 [COLOR07](hardware/a-register-summary-colorxx.md)      18E  W   D       Color table 07
 [COLOR08](hardware/a-register-summary-colorxx.md)      190  W   D       Color table 08
 [COLOR09](hardware/a-register-summary-colorxx.md)      192  W   D       Color table 09
 [COLOR10](hardware/a-register-summary-colorxx.md)      194  W   D       Color table 10
 [COLOR11](hardware/a-register-summary-colorxx.md)      196  W   D       Color table 11
 [COLOR12](hardware/a-register-summary-colorxx.md)      198  W   D       Color table 12
 [COLOR13](hardware/a-register-summary-colorxx.md)      19A  W   D       Color table 13
 [COLOR14](hardware/a-register-summary-colorxx.md)      19C  W   D       Color table 14
 [COLOR15](hardware/a-register-summary-colorxx.md)      19E  W   D       Color table 15
 [COLOR16](hardware/a-register-summary-colorxx.md)      1A0  W   D       Color table 16
 [COLOR17](hardware/a-register-summary-colorxx.md)      1A2  W   D       Color table 17
 [COLOR18](hardware/a-register-summary-colorxx.md)      1A4  W   D       Color table 18
 [COLOR19](hardware/a-register-summary-colorxx.md)      1A6  W   D       Color table 19
 [COLOR20](hardware/a-register-summary-colorxx.md)      1A8  W   D       Color table 20
 [COLOR21](hardware/a-register-summary-colorxx.md)      1AA  W   D       Color table 21
 [COLOR22](hardware/a-register-summary-colorxx.md)      1AC  W   D       Color table 22
 [COLOR23](hardware/a-register-summary-colorxx.md)      1AE  W   D       Color table 23
 [COLOR24](hardware/a-register-summary-colorxx.md)      1B0  W   D       Color table 24
 [COLOR25](hardware/a-register-summary-colorxx.md)      1B2  W   D       Color table 25
 [COLOR26](hardware/a-register-summary-colorxx.md)      1B4  W   D       Color table 26
 [COLOR27](hardware/a-register-summary-colorxx.md)      1B6  W   D       Color table 27
 [COLOR28](hardware/a-register-summary-colorxx.md)      1B8  W   D       Color table 28
 [COLOR29](hardware/a-register-summary-colorxx.md)      1BA  W   D       Color table 29
 [COLOR30](hardware/a-register-summary-colorxx.md)      1BC  W   D       Color table 30
 [COLOR31](hardware/a-register-summary-colorxx.md)      1BE  W   D       Color table 31

 [HTOTAL](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)       1C0  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Highest number count, horiz line
```c
                                   (VARBEAMEN=1)
```
 [HSSTOP](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)       1C2  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Horizontal line position for HSYNC stop
 [HBSTRT](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)       1C4  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Horizontal line position for HBLANK start
 [HBSTOP](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)       1C6  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Horizontal line position for HBLANK stop
 [VTOTAL](hardware/a-register-summary-vsstop-vsstrt-vtotal.md)       1C8  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Highest numbered vertical line
```c
                                   (VARBEAMEN=1)
```
 [VSSTOP](hardware/a-register-summary-vsstop-vsstrt-vtotal.md)       1CA  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Vertical line position for VSYNC stop
 [VBSTRT](hardware/a-register-summary-vbstop-vbstrt.md)       1CC  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Vertical line for VBLANK start
 [VBSTOP](hardware/a-register-summary-vbstop-vbstrt.md)       1CE  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Vertical line for VBLANK stop


              1D0              Reserved
              1D2              Reserved
              1D4              Reserved
              1D6              Reserved
              1D8              Reserved
              1DA              Reserved
 [BEAMCON0](hardware/a-register-summary-beamcon0.md)     1DC  W   A( [E](hardware/c-ecs-hardware-and-the-graphics-library-new-beamcon0.md) )  Beam counter control register (SHRES,PAL)
 [HSSTRT](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)       1DE  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Horizontal sync start (VARHSY)
 [VSSTRT](hardware/a-register-summary-vsstop-vsstrt-vtotal.md)       1E0  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Vertical sync start   (VARVSY)
 [HCENTER](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)      1E2  W   A( [E](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) )  Horizontal position for Vsync on interlace
 [DIWHIGH](hardware/a-register-summary-diwhigh-diwstop-diwstrt.md)      1E4  W   AD( [E](hardware/c-ecs-hardware-and-graphics-library-display-window.md) ) Display window -  upper bits for start, stop


 RESERVED     1110X
 RESERVED     1111X
 NO-OP(NULL)  1FE

