---
title: 3 / Advanced Topics / Hold-And-Modify Mode
manual: hardware
chapter: hardware
section: 3-advanced-topics-hold-and-modify-mode
functions: []
libraries: []
---

# 3 / Advanced Topics / Hold-And-Modify Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is a special mode that allows you to produce up to 4,096 colors on
the screen at the same time. Normally, as each value formed by the
combination of bitplanes is selected, the data contained in the selected
color register is loaded into the color output circuit for the pixel being
written on the screen. Therefore, each pixel is colored by the contents of
the selected color register.

In hold-and-modify mode, however, the value in the color output circuitry
is held, and one of the three components of the color (red, green, or
blue) is modified by bits coming from certain preselected bitplanes. After
modification, the pixel is written to the screen.

The hold-and-modify mode allows very fine gradients of color or shading to
be produced on the screen. For example, you might draw a set of 16 vases,
each a different color, using all 16 colors in the color palette. Then,
for each vase, you use hold-and-modify to very finely shade or highlight
or add a completely different color to each of the vases. Note that a
particular hold-and-modify pixel can only change one of the three color
values at a time. Thus, the effect has a limited control.

In hold and modify mode, you use all six bitplanes. Planes 5 and 6 are
used to modify the way bits from planes 1 - 4 are treated, as follows:

   *  If the 6-5 bit combination from planes 6 and 5 for any given pixel is

```c
      00,  normal color selection procedure is followed. Thus, the bit
      combinations from planes 4 - 1, in that order of significance, are
      used to choose one of 16 color registers (registers 0 - 15).

      If only five bitplanes are used, the data from the sixth plane is
      automatically supplied with the value as 0.
```
   *  If the 6-5 bit combination is 01, the color of the pixel immediately

      to the left of this pixel is duplicated and then modified. The bit
      combinations from planes 4 - 1 are used to replace the four
      "blue" bits in the corresponding color register.
   *  If the 6-5 bit combination is 10, the color of the pixel immediately

      to the left of this pixel is duplicated and then modified. The bit
      combinations from planes 4 - 1 are used to replace the four "red"
      bits.
   *  If the 6-5 bit combination is 11, the color of the pixel immediately

      to the left of this pixel is duplicated and then modified. The bit
      combinations from planes 4 - 1 are used to replace the four
      "green" bits.
Using hold-and-modify mode, it is possible to get by with defining only
one color register, which is  [COLOR00](hardware/3-bitplanes-and-color-the-color-table.md) , the color of the background. You
treat the entire screen as a modification of that original color,
according to the scheme above.

Bit 11 of register  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  selects hold-and-modify mode. The following
bits in  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  must be set for hold-and-modify mode to be active:

   *  Bit HOMOD, bit 11, is 1.
   *  Bit  [DBLPF](hardware/3-forming-a-dual-playfield-display-activating-dual.md) , bit 10, is 0 (single-playfield mode specified).
   *  Bit  [HIRES](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md) , bit 15, is 0 (low resolution mode specified).
   *  Bits  [BPU2, BPU1, and BPU0](hardware/3-bitplanes-and-color-selecting-the-number-of-bitplanes.md)  - bits 14, 13, and 12, are 101 or 110

```c
                                    (five or six bitplanes active).

     [HAM_playfield.asm](hardware/hard-examples-ham-playfield-asm.md) 
```
