---
title: 3 / / Bitplanes and Color / Selecting the Number of Bitplanes
manual: hardware
chapter: hardware
section: 3-bitplanes-and-color-selecting-the-number-of-bitplanes
functions: []
libraries: []
---

# 3 / / Bitplanes and Color / Selecting the Number of Bitplanes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After deciding how many colors you want and how many bitplanes are
required to give you those colors, you tell the system how many bitplanes
to use.

You select the number of bitplanes by writing the number into the register
 [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  (for Bitplane Control Register 0) The relevant bits are bits 14,
13, and 12, named BPU2, BPU1, and BPU0 (for "Bitplanes Used"). Table 3-5
shows the values to write to these bits and how the system assigns
bitplane numbers.




```c
          Table 3-5: Setting the Number of Bitplanes


                    Number of     Name(s) of
          Value     Bitplanes     Bitplanes
          -----     ---------     ----------
           000       None *
           001         1           PLANE 1
           010         2           PLANES 1 and 2
           011         3           PLANES 1 - 3
           100         4           PLANES 1 - 4
           101         5           PLANES 1 - 5
           110         6           PLANES 1 - 6 **
           111                     Value not used.


     *  Shows only a background color; no playfield is visible.

     ** Sixth bitplane is used only in  [dual-playfield mode](hardware/3-dual-playfield-bitplane-assignment-in-dual-playfield-mode.md)  and in
         [hold-and-modify mode](hardware/3-advanced-topics-hold-and-modify-mode.md)  (described in the section called
        Advanced Topics.
```
   About the  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  register.
   ----------------------------
   The bits in the  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  register cannot be set independently.  To set
   any one bit, you must reload them all.


The following example shows how to tell the system to use two low
resolution bitplanes.


```c
        MOVE.W  #$2200,[BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)+CUSTOM   ; Write to it
```
Because register  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  is used for setting other characteristics of the
display and the bits are not independently settable, the example above
also sets other parameters (all of these parameters are described later
in the chapter).

   [*](hardware/3-advanced-topics-hold-and-modify-mode.md)   Hold-and-modify mode is turned off.
   [*](hardware/3-forming-a-dual-playfield-display-activating-dual.md)   Single-playfield mode is set.
   [*](hardware/3-forming-a-basic-playfield-enabling-the-color-display.md)   Composite video color is enabled.  (Not applicable in all models.)
   [*](hardware/3-playfield-hardware-summary-of-playfield-registers.md)   Genlock audio is disabled.
   [*](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)   Light pen is disabled.
   [*](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md)   Interlaced mode is disabled.
   [*](hardware/3-playfield-hardware-summary-of-playfield-registers.md)   External resynchronization is disabled. (genlock)

