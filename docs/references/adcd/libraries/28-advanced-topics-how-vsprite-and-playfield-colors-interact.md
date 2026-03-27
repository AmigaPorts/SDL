---
title: 28 / Advanced Topics / How VSprite and Playfield Colors Interact
manual: libraries
chapter: libraries
section: 28-advanced-topics-how-vsprite-and-playfield-colors-interact
functions: []
libraries: []
---

# 28 / Advanced Topics / How VSprite and Playfield Colors Interact

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

At the start of each display, the system loads the colors from the
[ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md)'s color table into the display's hardware registers, so whatever
is rendered into the [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) is displayed correctly. But if the VSprite
system is used, and the colors are specified (via [SprColors](libraries/28-using-virtual-sprites-specifying-the-colors-of-a-vsprite.md)) for each
VSprite, the SprColors will be loaded by the system into the display
hardware, as needed. The system does this by generating Copper
instructions that will jam the colors into the hardware at specific
moments in the display cycle.  Any BitMap rendering, including Bobs, which
share colors with VSprites, may change colors constantly as the video
display beam progresses down the screen.

This color changing can be avoided by taking one of the following
precautions:

  * Use a four bitplane playfield, which only allows the lower 16 colors

```c
    to be rendered into the [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) (and allows Hires display mode).
```
  * If a 32-color playfield display is being used, avoid rendering in

    colors 17-19, 21-23, 25-27, and 29-32, which are the colors affected
    by the VSprite system.
  * Specify the VSprite [SprColors](libraries/28-using-virtual-sprites-specifying-the-colors-of-a-vsprite.md) pointer as a value of NULL to avoid

```c
    changing the contents of any of the hardware sprite color registers.
    This may cause the VSprites to change colors depending on their
    positions relative to each other, as described in the
    [previous section](libraries/28-vsprite-advanced-topics-how-vsprites-are-assigned.md).
```
