---
title: Faster Rendering
manual: amiga-mail
chapter: amiga-mail
section: faster-rendering
functions: [ClipBlit, ScrollRaster]
libraries: [graphics.library]
---

# Faster Rendering

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When rendering to a RastPort, an application can improve its
rendering performance if it renders using a limited number of colors.
Each RastPort contains a mask field which specifies the writeable
bitplanes of the RastPort's BitMap.  If a RastPort's bitplane is
write-protected, the system ignores that bitplane when rendering to
the RastPort.

An application can control the BitMap mask by using the SetWrMsk()
macro (defined in <graphics/gfxmacros.h>).  This macro accepts a
pointer to a RastPort, and a new mask.  The mask is an 8 bit value.
Each bit of the value represents a BitMap bitplane.  For example, a
mask of value 5, which is 00000101 in binary, restricts rendering in
that BitMap to planes 0 and 2 which are the only two bits set in the
binary value.

One type of application that can improve its performance by using the
RastPort Mask is the text editor.  Typically, a text editor needs to
render its text in a single color, generally color 1.  This means the
editor only needs to render to bitplane 0.  All other planes will
always remain blank.  If these planes are going to remain blank, why
should the editor bother to render to them or scroll them?

When scrolling large sections of the display, ScrollRaster() can make
the display look unstable because it continuously clears portions of
the display.  ClipBlit() eliminates this visual nuisance as it does
not clear the display.  Unfortunately, ClipBlit() by itself is
useless for scrolling a simple refresh window because it does not
deal with damage regions.  The solution is sneaky but quite
effective.  An application can do the following each time it scrolls
a simple refresh layer:

  Set the RastPort Mask to limit the number of writeable bitplanes.
  Use ClipBlit() to scroll the data.
  Set the RastPort Mask to 0.
  Use ScrollRaster() to scroll the same data.

In the procedure above, ClipBlit() scrolls the window contents but
not the damage regions.  ScrollRaster() scrolls the damage region,
but because the RastPort mask is 0, ScrollRaster() does not affect
the window contents.  Setting the RastPort mask to 0 prevents the
system from disturbing the data in any of the planes of the BitMap.

The above trick can come in quite handy.  It is fairly fast as well,
although it can involve some hidden overhead.  Even though
ScrollRaster() doesn't move data on the display, it still needs to go
through all the layer's clipping regions, which can be time consuming.

---

## See Also

- [ClipBlit — graphics.library](../autodocs/graphics.library.md#clipblit)
- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
