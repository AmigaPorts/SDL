---
title: 4 / Displaying a Sprite / Resetting the Address Pointers
manual: hardware
chapter: hardware
section: 4-displaying-a-sprite-resetting-the-address-pointers
functions: []
libraries: []
---

# 4 / Displaying a Sprite / Resetting the Address Pointers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For one single display field, the system will automatically read the
 [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md)  and produce the sprite on-screen in the colors that are
specified in the sprite's  [color registers](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md) . If you want the sprite to be
displayed in subsequent display fields, you must rewrite the contents of
the sprite pointers during each  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval. This is
necessary because during the display field, the pointers are incremented
to point to the data which is being fetched as the screen display
progresses.

The rewrite becomes part of the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  routine, which can be
handled by instructions in the Copper lists.

