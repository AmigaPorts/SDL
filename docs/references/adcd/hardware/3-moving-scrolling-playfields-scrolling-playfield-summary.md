---
title: 3 / Moving (Scrolling) Playfields / Scrolling Playfield Summary
manual: hardware
chapter: hardware
section: 3-moving-scrolling-playfields-scrolling-playfield-summary
functions: []
libraries: []
---

# 3 / Moving (Scrolling) Playfields / Scrolling Playfield Summary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The steps for defining a scrolled playfield are the same as those for
defining the basic playfield, except for the following steps:

   *   [Defining the data fetch](hardware/3-horiz-scrolling-specifying-data-fetch-in-horizontal.md) .

```c
      -------------------------
      Fetch one extra word per horizontal line and start it 16 pixels
      before the normal (unscrolled) data-fetch start.
```
   *   [Defining the modulo](hardware/3-horiz-scrolling-specifying-the-modulo-in-horizontal.md) .

      ---------------------
      The modulo is two counts less than when there is no scrolling.
These steps are added:

   *  For  [vertical scrolling](hardware/3-moving-scrolling-playfields-vertical-scrolling.md) , reset the bitplane pointers

```c
      -----------------------------------------------------
      for the amount of the scrolling increment.
      -----------------------------------------
      Reset  [BPLxPTH and BPLxPTL](hardware/3-allocating-memory-for-bitplanes-ntsc-example-of-bitplane.md)  during the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval.
```
   *  For  [horizontal scrolling](hardware/3-moving-scrolling-playfields-horizontal-scrolling.md) , specify the delay.

```c
      ---------------------------------------------
      Set bits 7-0 in  [BPLCON1](hardware/3-horizontal-scrolling-specifying-amount-of-delay.md)  for 0 to 15 bits of delay.
```
