---
title: 4 / Forming a Sprite / Size of Sprites
manual: hardware
chapter: hardware
section: 4-forming-a-sprite-size-of-sprites
functions: []
libraries: []
---

# 4 / Forming a Sprite / Size of Sprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sprites are 16 pixels wide and can be almost any height you wish -- as
short as one line or taller than the screen. You would probably move a
very tall sprite vertically to display a portion of it at a time.

Sprite size is based on a pixel that is 1/320th of a screen's width,
1/200th of a NTSC screen's height, or 1/256 of a PAL screen's height. This
pixel size corresponds to the low resolution and non-interlaced modes of
the normal full-size playfield. Sprites, however, are independent of
playfield modes of display, so changing the resolution or interlace mode
of the playfield has no effect on the size or resolution of a sprite.

