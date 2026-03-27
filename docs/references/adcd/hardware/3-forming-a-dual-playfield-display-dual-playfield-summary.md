---
title: 3 / Forming a Dual-playfield Display / Dual Playfield Summary
manual: hardware
chapter: hardware
section: 3-forming-a-dual-playfield-display-dual-playfield-summary
functions: []
libraries: []
---

# 3 / Forming a Dual-playfield Display / Dual Playfield Summary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The steps for defining dual playfields are almost the same as those for
defining the basic playfield. Only in the following steps does the
dual-playfield creation process differ from that used for the basic
playfield:

   *   [Loading colors into the registers](hardware/3-dual-playfield-display-color-registers-in-dual-playfield.md) .

```c
      -----------------------------------
      Keep in mind that color registers 0-7 are used by playfield 1
      and registers 8 through 15 are used by playfield 2 (if there are
      three bitplanes in each playfield).
```
   *   [Building bitplanes](hardware/3-dual-playfield-bitplane-assignment-in-dual-playfield-mode.md) .

      --------------------
      Recall that playfield 1 is formed from PLANES 1, 3, and 5 and
      playfield 2 from PLANES 2, 4, and 6.
   *   [Setting the modulo registers](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) .

```c
      ------------------------------
      Write the modulo to both  [BPL1MOD and BPL2MOD](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  as you will be
      using both odd- and even-numbered bitplanes.
```
These steps are added:

   *   [Defining priority](hardware/3-dual-playfield-display-dual-playfield-priority-and-control.md) .

```c
      -------------------
      If you want playfield 2 to have priority, set bit 6 (PF2PRI)
      in  [BPLCON2](hardware/7-video-priorities-setting-the-priority-control-register.md)  to 1.
```
   *   [Activating dual-playfield mode](hardware/3-forming-a-dual-playfield-display-activating-dual.md) .

```c
      --------------------------------
      Set bit 10 ( [DBLPF](hardware/3-forming-a-dual-playfield-display-activating-dual.md) ) in  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  to 1.
```
