---
title: 3 Playfield Hardware / Forming a Dual-playfield Display
manual: hardware
chapter: hardware
section: 3-playfield-hardware-forming-a-dual-playfield-display
functions: []
libraries: []
---

# 3 Playfield Hardware / Forming a Dual-playfield Display

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For more flexibility in designing your background display, you can specify
two playfields instead of one.  In dual-playfield mode, one playfield is
displayed directly in front of the other.  For example, a computer game
display might have some action going on in one playfield in the
background, while the other playfield is showing a control panel in the
foreground. You can then change either the foreground or the background
without having to redesign the entire display. You can also move the two
playfields independently.

A dual-playfield display is similar to a single-playfield display,
differing only in these aspects:

   *  Each playfield in a dual display is formed from one, two or three

      bitplanes.
   *  The colors in each playfield (up to seven plus transparent) are

      taken from different sets of color registers.
   *  You must set a bit to activate dual-playfield mode.

Figure 3-12 shows a dual-playfield display.


```c
     [Figure 3-12: A Dual-playfield Display](hardware/hard-pics-3-12-pic.md) 
```
In Figure 3-12, one of the colors in each playfield is "transparent"
(color 0 in playfield 1 and color 8 in playfield 2). You can use
transparency to allow selected features of the background playfield to
show through.

In dual-playfield mode, each playfield is formed from up to three
bitplanes.  Color registers 0 through 7 are assigned to playfield 1,
depending upon how many bitplanes you use.  Color registers 8 through 15
are assigned to playfield 2.

 [Bitplane Assignment in Dual-Playfield Mode](hardware/3-dual-playfield-bitplane-assignment-in-dual-playfield-mode.md) 
 [Color Registers in Dual-Playfield Mode](hardware/3-dual-playfield-display-color-registers-in-dual-playfield.md) 
 [Dual-Playfield Priority and Control](hardware/3-dual-playfield-display-dual-playfield-priority-and-control.md) 
 [Activating Dual-Playfield Mode](hardware/3-forming-a-dual-playfield-display-activating-dual.md) 
 [Dual Playfield Summary](hardware/3-forming-a-dual-playfield-display-dual-playfield-summary.md) 

