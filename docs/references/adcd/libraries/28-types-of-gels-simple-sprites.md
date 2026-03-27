---
title: 28 / / Types Of GELs / Simple Sprites
manual: libraries
chapter: libraries
section: 28-types-of-gels-simple-sprites
functions: []
libraries: []
---

# 28 / / Types Of GELs / Simple Sprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Simple Sprites (also known as hardware sprites) are not really part of the
GELs system but are the basis for VSprites.  Simple Sprites are graphic
objects implemented in hardware that are easy to define and easy to
animate. The Amiga hardware has the ability to handle up to eight such
sprite objects.  Each Simple Sprite is produced by one of the Amiga's
eight sprite DMA channels.  They are 16-bits wide and arbitrarily tall.

The Amiga system software offers a choice of how to use these hardware
sprites.  After a sprite DMA channel has displayed the last line of a
Simple Sprite, the system can reuse the channel for a different sprite
lower on the screen.  This is how VSprites are implemented--as a software
construct based on the sprite hardware.

Hence, Simple Sprites are not really part of the animation system (they
are not GELs).  In fact, if Simple Sprites and GELs are used in the same
display, the GELs system must be told specifically which Simple Sprites to
avoid.  Simple Sprites are described in this chapter because they are
alternatives to VSprites.

