---
title: 2 Coprocessor Hardware / The MOVE Instruction
manual: hardware
chapter: hardware
section: 2-coprocessor-hardware-the-move-instruction
functions: []
libraries: []
---

# 2 Coprocessor Hardware / The MOVE Instruction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The MOVE instruction transfers data from RAM to a register destination.
The transferred data is contained in the second word of the MOVE
instruction; the first word contains the address of the destination
register. This procedure is shown in detail in the section called
 [Summary of Copper Instructions](hardware/2-coprocessor-hardware-summary-of-copper-instructions.md) .




```c
     FIRST MOVE INSTRUCTION WORD (IR1)
     ---------------------------------
     Bit 0           Always set to 0.

     Bits 8 - 1      Register destination address (DA8-1).

     Bits 15 - 9     Not used, but should be set to 0.


     SECOND MOVE INSTRUCTION WORD (IR2)
     ----------------------------------
     Bits 15 - 0     16 bits of data to be transferred (moved)
                     to the register destination.
```
The Copper can store data into the following registers:

   *  Any register whose address is $20 or above.  (Hexadecimal numbers

```c
      are distinguished from decimal numbers by the $ prefix.)
```
   *  Any register whose address is between $10 and $20 if the Copper

```c
      danger bit is a 1. The Copper danger bit is in the Copper's control
      register,  [COPCON](hardware/2-using-the-copper-registers-control-register.md) , which is described in the "Control Register"
      section.
```
   *  The Copper cannot write into any register whose address is lower

      than $10.
 [Appendix B](hardware/amiga-hardware-reference-manual-b-register-summary-address.md)  contains all of the machine register addresses.

The following example MOVE instructions set bitplane pointer 1 to $21000
and bitplane pointer 2 to $25000.  (All sample code segments are in
assembly language.)


```c
        DC.W    $00E0,$0002     ;Move $0002 to register $0E0 (BPL1PTH)
        DC.W    $00E2,$1000     ;Move $1000 to register $0E2 (BPL1PTL)
        DC.W    $00E4,$0002     ;Move $0002 to register $0E4 (BPL2PTH)
        DC.W    $00E6,$5000     ;Move $5000 to register $0E6 (BPL2PTL)
```
Normally, the appropriate assembler ".i" files are included so that names,
rather than addresses, may be used for referencing hardware registers.  It
is strongly recommended that you reference all hardware addresses via their
defined names in the system include files.  This will allow you to more
easily adapt your software to take advantage of future hardware or
enhancements.  For example:


```c
        INCLUDE "hardware/custom.i"

        DC.W    bplpt+$00,$0002 ;Move $0002 into register $0E0 (BPL1PTH)
        DC.W    bplpt+$02,$1000 ;Move $1000 into register $0E2 (BPL1PTL)
        DC.W    bplpt+$04,$0002 ;Move $0002 into register $0E4 (BPL2PTH)
        DC.W    bplpt+$06,$5000 ;Move $5000 into register $0E6 (BPL2PTL)
```
For use in the hardware manual examples, we have made a special include
file (see  [Appendix I](hardware/hard-examples-hw-examples-i.md) ) that defines all of the hardware register names
based off of the "hardware/custom.i" file.  This was done to make the
examples easier to read from a hardware point of view.  Most of the
examples in this manual are here to help explain the hardware and are, in
most cases, not useful without modification and a good deal of additional
code.

