---
title: 3 / Forming a Basic Playfield / Bitplanes and Color
manual: hardware
chapter: hardware
section: 3-forming-a-basic-playfield-bitplanes-and-color
functions: []
libraries: []
---

# 3 / Forming a Basic Playfield / Bitplanes and Color

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You define playfield color by:

   1. Deciding how many colors you need and how you want to color
      each pixel.
   2. Loading the colors into the color registers.
   3. Allocating memory for the number of bitplanes you need and setting
      a pointer to each bitplane.
   4. Writing instructions to place a value in each bit in the bitplanes

      to give you the correct color.
Table 3-1 shows how many bitplanes to use for the color selection you need.




                    Number of     Number of
                     Colors       Bitplanes
                    ---------     ---------
                      1 - 2           1
                      3 - 4           2
                      5 - 8           3
                     9 - 16           4
                    17 - 32           5


           Table 3-1: Colors in a Single Playfield
 [The Color Table](hardware/3-bitplanes-and-color-the-color-table.md) 
 [Selecting the Number of Bitplanes](hardware/3-bitplanes-and-color-selecting-the-number-of-bitplanes.md) 

