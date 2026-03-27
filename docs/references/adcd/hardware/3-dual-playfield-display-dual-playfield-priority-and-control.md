---
title: 3 / Dual-playfield Display / Dual-Playfield Priority and Control
manual: hardware
chapter: hardware
section: 3-dual-playfield-display-dual-playfield-priority-and-control
functions: []
libraries: []
---

# 3 / Dual-playfield Display / Dual-Playfield Priority and Control

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Either playfield 1 or 2 may have priority; that is, either one may be
displayed in front of the other. Playfield 1 normally has priority. The
bit known as PF2PRI (bit 6) in register  [BPLCON2](hardware/7-video-priorities-setting-the-priority-control-register.md)  is used to control
priority. When PF2PRI = 1, playfield 2 has priority over playfield 1. When
PF2PRI = 0, playfield 1 has priority.

You can also control the relative  [priority of playfields](hardware/7-video-priorities-setting-the-priority-control-register.md)  and  [sprites](hardware/7-video-priorities-fixed-sprite-priorities.md) .
Chapter 7, System Control Hardware, shows you how to control the priority
of these objects.

You can control the two playfields separately as follows:

   *  They can have  [different-sized](hardware/3-playfield-hardware-bitplanes-and-display-windows-of-all.md)  representations in memory, and

      different portions of each one can be selected for display.
   *  They can be  [scrolled](hardware/3-playfield-hardware-moving-scrolling-playfields.md)  separately.

   An important warning.
   ---------------------
   You must take special care when scrolling one playfield and holding
   the other stationary. When you are scrolling low resolution
   playfields, you must fetch one word more than the width of the
   playfield you are trying to scroll (two words more in high resolution
   mode) in order to provide some data to display when the actual
   scrolling takes place. Only one data-fetch start register and one
   data-fetch stop register are available, and these are shared by both
   playfields. If you want to scroll one playfield and hold the other,
   you must adjust the data-fetch start and data-fetch stop to handle
   the playfield being scrolled. Then, you must adjust the modulo and
   the bitplane pointers of the playfield that is not being scrolled to
   maintain its position on the display. In low resolution mode, you
   adjust the pointers by -2 and the modulo by -2. In high resolution
   mode, you adjust the pointers by -4 and the modulo by -4.

