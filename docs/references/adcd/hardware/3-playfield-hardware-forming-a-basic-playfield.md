---
title: 3 Playfield Hardware / Forming a Basic Playfield
manual: hardware
chapter: hardware
section: 3-playfield-hardware-forming-a-basic-playfield
functions: []
libraries: []
---

# 3 Playfield Hardware / Forming a Basic Playfield

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To get you started, this section describes how to directly access hardware
registers to form a single basic playfield that is the same size as the
video screen. Here, "same size" means that the playfield is the same size
as the actual display window. This will leave a small border between the
playfield and the edge of the video screen. The playfield usually does not
extend all the way to the edge of the physical display.

To form a playfield, you need to define these characteristics:

   *  Height and width of the playfield and size of the display window
```c
      (that is, how much of the playfield actually appears on the screen).
```
   *  Color of each pixel in the playfield.
   *  Horizontal resolution.
   *  Vertical resolution, or interlacing.
   *  Data fetch and modulo, which tell the system how much data to put on

      a horizontal line and how to fetch data from memory to the screen.
In addition, you need to allocate memory to store the playfield, set
pointers to tell the system where to find the data in memory, and
(optionally) write a Copper routine to handle redisplay of the playfield.

 [Height and Width of the Playfield](hardware/3-forming-a-basic-playfield-height-and-width-of-the.md) 
 [Bitplanes and Color](hardware/3-forming-a-basic-playfield-bitplanes-and-color.md) 
 [Selecting Horizontal and Vertical Resolution](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md) 
 [Allocating Memory for Bitplanes](hardware/3-forming-a-basic-playfield-allocating-memory-for-bitplanes.md) 
 [Coding the Bitplanes for Correct Coloring](hardware/3-basic-playfield-coding-the-bitplanes-for-correct-coloring.md) 
 [Defining the Size of the Display Window](hardware/3-forming-basic-playfield-defining-the-size-of-the-display.md) 
 [Telling the System How to Fetch and Display Data](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) 
 [Displaying and Redisplaying the Playfield](hardware/3-basic-playfield-displaying-and-redisplaying-the-playfield.md) 
 [Enabling the Color Display](hardware/3-forming-a-basic-playfield-enabling-the-color-display.md) 
 [Basic Playfield Summary](hardware/3-forming-a-basic-playfield-basic-playfield-summary.md) 
 [Example of Forming a Basic LORES Playfield](hardware/hard-examples-lores-playfield-asm.md) 
 [Example of Forming a Basic HIRES Playfield](hardware/hard-examples-hires-playfield-asm.md) 

