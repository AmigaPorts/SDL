---
title: 8 / / Reading Mouse/Trackball Controllers / Reading the Counters
manual: hardware
chapter: hardware
section: 8-reading-mouse-trackball-controllers-reading-the-counters
functions: []
libraries: []
---

# 8 / / Reading Mouse/Trackball Controllers / Reading the Counters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The mouse/trackball counter contents can be accessed by reading register
addresses named  [JOY0DAT and JOY1DAT](hardware/a-register-summary-joy0dat-joy1dat.md) .  These registers contain counts for
ports 1 and 2 respectively.

The contents of each of these 16-bit registers are as follows:

   Bits 15-8     Mouse/trackball vertical count
   Bits  7-0     Mouse/trackball horizontal count

