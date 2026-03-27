# Amiga® Hardware Reference Manual:A Register Summary Alphabetical Order


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
   in their functionality.  See the  [register map in Appendix C](../Hardware_Manual_guide/node00AD.html)  for
   information on which ECS registers are new and which have been
   modified.

 [ADKCON](../Hardware_Manual_guide/node0012.html)      [BLTSIZH](../Hardware_Manual_guide/node001D.html#line28)     [COP1LCH](../Hardware_Manual_guide/node0028.html)     [DSKDAT](../Hardware_Manual_guide/node0031.html)      [JOY1DAT](../Hardware_Manual_guide/node0038.html)     [STRHOR](../Hardware_Manual_guide/node0042.html) 
 [ADKCONR](../Hardware_Manual_guide/node0012.html)     [BLTxDAT](../Hardware_Manual_guide/node001E.html)     [COP1LCL](../Hardware_Manual_guide/node0028.html)     [DSKDATR](../Hardware_Manual_guide/node0031.html)     [JOYTEST](../Hardware_Manual_guide/node0039.html)     [STRLONG](../Hardware_Manual_guide/node0042.html) 
 [AUDxDAT](../Hardware_Manual_guide/node0013.html)     [BLTxMOD](../Hardware_Manual_guide/node001F.html)     [COP2LCH](../Hardware_Manual_guide/node0028.html)     [DSKLEN](../Hardware_Manual_guide/node0032.html)      [POT0DAT](../Hardware_Manual_guide/node003A.html)     [STRVBL](../Hardware_Manual_guide/node0042.html#line19) 
 [AUDxLCH](../Hardware_Manual_guide/node0014.html)     [BLTxPTH](../Hardware_Manual_guide/node0020.html)     [COP2LCL](../Hardware_Manual_guide/node0028.html)     [DSKPTH](../Hardware_Manual_guide/node0033.html)      [POT1DAT](../Hardware_Manual_guide/node003A.html)     [VBSTOP](../Hardware_Manual_guide/node0043.html) 
 [AUDxLCL](../Hardware_Manual_guide/node0014.html)     [BLTxPTL](../Hardware_Manual_guide/node0020.html)     [COPCON](../Hardware_Manual_guide/node0029.html)      [DSKPTL](../Hardware_Manual_guide/node0033.html)      [POTGO](../Hardware_Manual_guide/node003B.html)       [VBSTRT](../Hardware_Manual_guide/node0043.html) 
 [AUDxLEN](../Hardware_Manual_guide/node0015.html)     [BPL1MOD](../Hardware_Manual_guide/node0021.html)     [COPINS](../Hardware_Manual_guide/node002A.html)      [DSKSYNC](../Hardware_Manual_guide/node0034.html)     [POTGOR](../Hardware_Manual_guide/node003B.html)      [VHPOSR](../Hardware_Manual_guide/node0044.html) 
 [AUDxPER](../Hardware_Manual_guide/node0016.html)     [BPL2MOD](../Hardware_Manual_guide/node0021.html)     [COPJMP1](../Hardware_Manual_guide/node002B.html)     [HBSTOP](../Hardware_Manual_guide/node0035.html)      [REFPTR](../Hardware_Manual_guide/node003C.html)      [VHPOSW](../Hardware_Manual_guide/node0044.html) 
 [AUDxVOL](../Hardware_Manual_guide/node0017.html)     [BPLCON0](../Hardware_Manual_guide/node0022.html)     [COPJMP2](../Hardware_Manual_guide/node002B.html)     [HBSTRT](../Hardware_Manual_guide/node0035.html)      [SERDAT](../Hardware_Manual_guide/node003D.html)      [VPOSR](../Hardware_Manual_guide/node0045.html) 
 [BEAMCON0](../Hardware_Manual_guide/node0018.html)    [BPLCON1](../Hardware_Manual_guide/node0022.html)     [DDFSTOP](../Hardware_Manual_guide/node002C.html)     [HCENTER](../Hardware_Manual_guide/node0035.html)     [SERDATR](../Hardware_Manual_guide/node003D.html#line22)     [VPOSW](../Hardware_Manual_guide/node0045.html) 
 [BLTAFWM](../Hardware_Manual_guide/node0019.html)     [BPLCON2](../Hardware_Manual_guide/node0022.html)     [DDFSTRT](../Hardware_Manual_guide/node002C.html)     [HSSTOP](../Hardware_Manual_guide/node0035.html)      [SERPER](../Hardware_Manual_guide/node003E.html)      [VSSTOP](../Hardware_Manual_guide/node0046.html) 
 [BLTALWM](../Hardware_Manual_guide/node0019.html)     [BPLCON3](../Hardware_Manual_guide/node0022.html#line57)     [DENISEID](../Hardware_Manual_guide/node002D.html)    [HSSTRT](../Hardware_Manual_guide/node0035.html)      [SPRxCTL](../Hardware_Manual_guide/node003F.html)     [VSSTRT](../Hardware_Manual_guide/node0046.html) 
 [BLTCON0](../Hardware_Manual_guide/node001A.html)     [BPLxDAT](../Hardware_Manual_guide/node0023.html)     [DIWHIGH](../Hardware_Manual_guide/node002E.html)     [HTOTAL](../Hardware_Manual_guide/node0035.html)      [SPRxDATA](../Hardware_Manual_guide/node0040.html)    [VTOTAL](../Hardware_Manual_guide/node0046.html) 
 [BLTCON1](../Hardware_Manual_guide/node001A.html)     [BPLxPTH](../Hardware_Manual_guide/node0024.html)     [DIWSTOP](../Hardware_Manual_guide/node002E.html)     [INTENA](../Hardware_Manual_guide/node0036.html)      [SPRxDATB](../Hardware_Manual_guide/node0040.html) 
 [BLTCON0L](../Hardware_Manual_guide/node001B.html)    [BPLxPTL](../Hardware_Manual_guide/node0024.html)     [DIWSTRT](../Hardware_Manual_guide/node002E.html)     [INTENAR](../Hardware_Manual_guide/node0036.html)     [SPRxPOS](../Hardware_Manual_guide/node003F.html) 
 [BLTDDAT](../Hardware_Manual_guide/node001C.html)     [CLXCON](../Hardware_Manual_guide/node0025.html)      [DMACON](../Hardware_Manual_guide/node002F.html)      [INTREQ](../Hardware_Manual_guide/node0037.html)      [SPRxPTH](../Hardware_Manual_guide/node0041.html) 
 [BLTSIZE](../Hardware_Manual_guide/node001D.html)     [CLXDAT](../Hardware_Manual_guide/node0026.html)      [DMACONR](../Hardware_Manual_guide/node002F.html)     [INTREQR](../Hardware_Manual_guide/node0037.html)     [SPRxPTL](../Hardware_Manual_guide/node0041.html) 
 [BLTSIZV](../Hardware_Manual_guide/node001D.html#line28)     [COLORxx](../Hardware_Manual_guide/node0027.html)     [DSKBYTR](../Hardware_Manual_guide/node0030.html)     [JOY0DAT](../Hardware_Manual_guide/node0038.html)     [STREQU](../Hardware_Manual_guide/node0042.html) 

