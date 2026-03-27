---
title: Amiga® Hardware Reference Manual:A Register Summary Alphabetical Order
manual: hardware
chapter: hardware
section: amiga-hardware-reference-manual-a-register-summary
functions: [AllocMem]
libraries: [exec.library]
---

# Amiga® Hardware Reference Manual:A Register Summary Alphabetical Order

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This appendix contains the definitive summary, in alphabetical order, of
the Amiga's custom chip register set and the usages of the individual bits.

The addresses shown here are used by the special custom chips (named
"Paula", "Agnus", and "Denise") for transferring data among themselves.
Also, the Copper uses these addresses for writing to the special chip
registers. To write to these registers with the 680x0, calculate the 680x0
address using this formula:


```c
          680x0 address = (chip address) + $DFF000
```
For example, for the 680x0 to write to ADKCON (address = $09E), the
address would be $DFF09E.  No other access address is valid.  Do not
attempt to access any documented or unused registers.

All of the "pointer" type registers are organized as 32 bits on a long
word boundary.  These registers may be written with one MOVE.L
instruction. The lowest bit of all pointers must be written as zero.  The
custom chips can only access Chip memory; using a non-Chip address will
fail (See the AllocMem() documentation or your compiler manual for more
information on Chip memory).  Disk data, sprite data, bitplane data, audio
data, copper lists and anything that will be blitted or accessed by custom
chip DMA must be located in chip memory.

When strobing any register which responds to either a read or a write,
(for example copjmp2) be sure to use a MOVE.W, not CLR.W.  The CLR
instruction causes a read and a clear (two accesses) on a 68000, but only
a single access on 68020 processors.  This will give different results on
different processors.

   Warning:
   --------
   Registers are either read-only or write-only. In the following
   descriptions, if a register is marked as a read-only register, only
   read its contents.  Do not attempt to write to a read-only register,
   as this will cause unpredictable results.  If a register is marked as
   a write-only register, do not attempt to read from it, as this may
   trash the register and crash the system.

If a bit is described as unused in a write-only register, be sure to keep
that bit clear when writing values to that register.  Similarly, do not
rely on the values of unused bits when reading from a read only register.
Further, do not write to an address or register that is not documented or
defined in this appendix.  Setting unused bits in a write-only register,
reading unused bits from a read only register and writing to undocumented
registers or addresses may cause serious future software incompatibility
if those bits or addresses are implemented in the future by Amiga, Inc.


   About the ECS registers.
   ------------------------
   Registers denoted with an "(E)" in the chip column means that those
   registers have been changed the Enhanced Chip Set(ECS).  The ECS is
   found in the A3000, and is installable in the A500 and A2000.
   Certain ECS registers are completely new, others have been extended
   in their functionality.  See the  [register map in Appendix C](hardware/c-enhanced-chip-set-ecs-registers.md)  for
   information on which ECS registers are new and which have been
   modified.

 [ADKCON](hardware/a-register-summary-adkcon-adkconr.md)      [BLTSIZH](hardware/a-register-summary-bltsize-bltsizv-bltsizh.md)     [COP1LCH](hardware/a-register-summary-cop1lch-cop1lcl-cop2lch-cop2lcl.md)     [DSKDAT](hardware/a-register-summary-dskdat-dskdatr.md)      [JOY1DAT](hardware/a-register-summary-joy0dat-joy1dat.md)     [STRHOR](hardware/a-register-summary-strequ-strhor-strlong-strvbl.md) 
 [ADKCONR](hardware/a-register-summary-adkcon-adkconr.md)     [BLTxDAT](hardware/a-register-summary-bltxdat.md)     [COP1LCL](hardware/a-register-summary-cop1lch-cop1lcl-cop2lch-cop2lcl.md)     [DSKDATR](hardware/a-register-summary-dskdat-dskdatr.md)     [JOYTEST](hardware/a-register-summary-joytest.md)     [STRLONG](hardware/a-register-summary-strequ-strhor-strlong-strvbl.md) 
 [AUDxDAT](hardware/a-register-summary-audxdat.md)     [BLTxMOD](hardware/a-register-summary-bltxmod.md)     [COP2LCH](hardware/a-register-summary-cop1lch-cop1lcl-cop2lch-cop2lcl.md)     [DSKLEN](hardware/a-register-summary-dsklen.md)      [POT0DAT](hardware/a-register-summary-pot0dat-pot1dat.md)     [STRVBL](hardware/a-register-summary-strequ-strhor-strlong-strvbl.md) 
 [AUDxLCH](hardware/a-register-summary-audxlch-audxlcl.md)     [BLTxPTH](hardware/a-register-summary-bltxpth-bltxptl.md)     [COP2LCL](hardware/a-register-summary-cop1lch-cop1lcl-cop2lch-cop2lcl.md)     [DSKPTH](hardware/a-register-summary-dskpth-dskptl.md)      [POT1DAT](hardware/a-register-summary-pot0dat-pot1dat.md)     [VBSTOP](hardware/a-register-summary-vbstop-vbstrt.md) 
 [AUDxLCL](hardware/a-register-summary-audxlch-audxlcl.md)     [BLTxPTL](hardware/a-register-summary-bltxpth-bltxptl.md)     [COPCON](hardware/a-register-summary-copcon.md)      [DSKPTL](hardware/a-register-summary-dskpth-dskptl.md)      [POTGO](hardware/a-register-summary-potgo-potgor.md)       [VBSTRT](hardware/a-register-summary-vbstop-vbstrt.md) 
 [AUDxLEN](hardware/a-register-summary-audxlen.md)     [BPL1MOD](hardware/a-register-summary-bpl1mod-bpl2mod.md)     [COPINS](hardware/a-register-summary-copins.md)      [DSKSYNC](hardware/a-register-summary-dsksync.md)     [POTGOR](hardware/a-register-summary-potgo-potgor.md)      [VHPOSR](hardware/a-register-summary-vhposr-vhposw.md) 
 [AUDxPER](hardware/a-register-summary-audxper.md)     [BPL2MOD](hardware/a-register-summary-bpl1mod-bpl2mod.md)     [COPJMP1](hardware/a-register-summary-copjmp1-copjmp2.md)     [HBSTOP](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)      [REFPTR](hardware/a-register-summary-refptr.md)      [VHPOSW](hardware/a-register-summary-vhposr-vhposw.md) 
 [AUDxVOL](hardware/a-register-summary-audxvol.md)     [BPLCON0](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md)     [COPJMP2](hardware/a-register-summary-copjmp1-copjmp2.md)     [HBSTRT](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)      [SERDAT](hardware/a-register-summary-serdat-serdatr.md)      [VPOSR](hardware/a-register-summary-vposr-vposw.md) 
 [BEAMCON0](hardware/a-register-summary-beamcon0.md)    [BPLCON1](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md)     [DDFSTOP](hardware/a-register-summary-ddfstop-ddfstrt.md)     [HCENTER](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)     [SERDATR](hardware/a-register-summary-serdat-serdatr.md)     [VPOSW](hardware/a-register-summary-vposr-vposw.md) 
 [BLTAFWM](hardware/a-register-summary-bltafwm-bltalwm.md)     [BPLCON2](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md)     [DDFSTRT](hardware/a-register-summary-ddfstop-ddfstrt.md)     [HSSTOP](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)      [SERPER](hardware/a-register-summary-serper.md)      [VSSTOP](hardware/a-register-summary-vsstop-vsstrt-vtotal.md) 
 [BLTALWM](hardware/a-register-summary-bltafwm-bltalwm.md)     [BPLCON3](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md)     [DENISEID](hardware/a-register-summary-deniseid.md)    [HSSTRT](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)      [SPRxCTL](hardware/a-register-summary-sprxctl-sprxpos.md)     [VSSTRT](hardware/a-register-summary-vsstop-vsstrt-vtotal.md) 
 [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)     [BPLxDAT](hardware/a-register-summary-bplxdat.md)     [DIWHIGH](hardware/a-register-summary-diwhigh-diwstop-diwstrt.md)     [HTOTAL](hardware/a-register-summary-hbstop-hbstrt-hcenter-hsstop-hsstrt.md)      [SPRxDATA](hardware/a-register-summary-sprxdata-sprxdatb.md)    [VTOTAL](hardware/a-register-summary-vsstop-vsstrt-vtotal.md) 
 [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)     [BPLxPTH](hardware/a-register-summary-bplxpth-bplxptl.md)     [DIWSTOP](hardware/a-register-summary-diwhigh-diwstop-diwstrt.md)     [INTENA](hardware/a-register-summary-intena-intenar.md)      [SPRxDATB](hardware/a-register-summary-sprxdata-sprxdatb.md) 
 [BLTCON0L](hardware/a-register-summary-bltcon0l.md)    [BPLxPTL](hardware/a-register-summary-bplxpth-bplxptl.md)     [DIWSTRT](hardware/a-register-summary-diwhigh-diwstop-diwstrt.md)     [INTENAR](hardware/a-register-summary-intena-intenar.md)     [SPRxPOS](hardware/a-register-summary-sprxctl-sprxpos.md) 
 [BLTDDAT](hardware/a-register-summary-bltddat.md)     [CLXCON](hardware/a-register-summary-clxcon.md)      [DMACON](hardware/a-register-summary-dmacon-dmaconr.md)      [INTREQ](hardware/a-register-summary-intreq-intreqr.md)      [SPRxPTH](hardware/a-register-summary-sprxpth-sprxptl.md) 
 [BLTSIZE](hardware/a-register-summary-bltsize-bltsizv-bltsizh.md)     [CLXDAT](hardware/a-register-summary-clxdat.md)      [DMACONR](hardware/a-register-summary-dmacon-dmaconr.md)     [INTREQR](hardware/a-register-summary-intreq-intreqr.md)     [SPRxPTL](hardware/a-register-summary-sprxpth-sprxptl.md) 
 [BLTSIZV](hardware/a-register-summary-bltsize-bltsizv-bltsizh.md)     [COLORxx](hardware/a-register-summary-colorxx.md)     [DSKBYTR](hardware/a-register-summary-dskbytr.md)     [JOY0DAT](hardware/a-register-summary-joy0dat-joy1dat.md)     [STREQU](hardware/a-register-summary-strequ-strhor-strlong-strvbl.md) 

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
