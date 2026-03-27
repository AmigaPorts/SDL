---
title: Scrolling Your Life Away
manual: amiga-mail
chapter: amiga-mail
section: scrolling-your-life-away
functions: [ClipBlit, ScrollRaster]
libraries: [graphics.library]
---

# Scrolling Your Life Away

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A scrolling display is a part of many user interfaces.  An easy way
to make people think an application is slow is to give it a sluggish
user interface.  Regardless of the actual speed at which an
application performs its job, if its user interface management is
slow, the user will get the impression the whole application is slow.

The ScrollRaster() and ClipBlit() routines are the two principal ways
of scrolling data within a layer.  ScrollRaster() moves the data
within a RastPort.  ClipBlit() moves data from one RastPort to the
next, but works equally well if the source and destination RastPorts
are the same.

Smart refresh layers are relatively easy to scroll with either
ScrollRaster() or ClipBlit().  Although ClipBlit() has a theoretical
advantage over ScrollRaster(), the performance of these functions is
generally equivalent.  ScrollRaster() does a minimum of two Blitter
operations: one to scroll the data, and a generally smaller one to
erase the area that was scrolled away.  ClipBlit() can do a single
blit to move the data in the layer, and leaves the rest of the
display alone.  Thus, while scrolling large amounts of data, an
application can get better CPU/Blitter processing overlap by using
ClipBlit().  Consider the following pseudo-code of what happens in
ScrollRaster() versus ClipBlit():

Within the ScrollRaster() function:
  Wait for any outstanding Blitter operation to complete
  Initiate a Blitter operation to move the data in the window
  Wait for the Blitter operation to complete
  Initiate a second small Blitter operation to clear the scrolled region
  Return to the caller while the small blit is still in progress

Within the ClipBlit() function:
  Wait for any outstanding Blitter operation to complete
  Initiate a Blitter operation to move the data in the window
  Return to the caller while the blit is still in progress

Since the Blitter and the CPU can run concurrently, the second
approach provides the most throughput, as the Blitter performs most
of the scrolling work at the same time the application code runs
after ClipBlit().  In practice though, ScrollRaster() and ClipBlit()
run at about the same speed.

For a smart refresh window, ScrollRaster() and ClipBlit() do not
present a problem.  As long as the application only scrolls the
contents of the window and not the window borders, the Layers library
will take care of fixing any damage.  Intuition will never know what
happened.  For a simple refresh window however, there is a problem.
The reason has to do with the following:


       +--------------+           +--------------+
       |aaaaaaaaaaaaaa|           |bbbbaaaaaabbbb|
       |bbbb+----+bbbb|           |cccc+----+cccc|
       |cccc|    |cccc|           |dddd|    |dddd|
       |dddd+----+dddd|           |eeee+----+eeee|
       |eeeeeeeeeeeeee|           |              |
       +--------------+           +--------------+

          Figure  1a                 Figure  1b
Figure 1a represents a small window that the user placed on top of a
larger simple refresh window.  When an application scrolls the larger
window's contents upwards with ScrollRaster(), the result looks like
Figure 1b.  This operation exposes two portions of the larger window,
the section at the bottom of the large window (the part
ScrollRaster() clears) and also the area above the smaller window
(which ScrollRaster() leaves intact).

The application that owns the larger window has to refresh the two
portions exposed by ScrollRaster().  The application knows to refresh
the bottom section of the window because the damage is a direct
result of the application calling ScrollRaster().  The problem is the
area above the smaller window.  The application does not know that
there is a window overlapping its larger window, so it does not
directly know about any damage resulting from other overlapping
layers.  Because the application used a graphics.library function to
manipulate the window, Intuition does not know about the damage
either.  The result is that the larger window is damaged and no one
knows it.

If the larger window had been a smart refresh window, the Layers
library would have cached this portion of the larger window and
ScrollRaster() would have taken action to make sure the cached region
got restored.  For a simple refresh window, this portion only gets
added to the window layer's damage list and no rendering actually
occurs.

The solution to this problem is for the application to act as
Intuition would if it were scrolling.  When Intuition manipulates a
layer, it checks the LAYERREFRESH bit of each of its layers to see if
any of them was damaged.  After the application calls ScrollRaster()
on its window, the application has to look at the LAYERREFRESH bit of
the window's layer.  If the bit is set, damage exists and the
application needs to repair the window.  As this window is the only
window that can sustain layer damage as a result of the call to
ScrollRaster(), the application needs to check only its own window's
layer for damage.

Note that to scroll the contents of a simple refresh window, an
application has to use ScrollRaster() rather than ClipBlit().  The
reason is ClipBlit() does not add anything to the window layer's
damage region, so an application will never know about the damage.
Also, unlike ScrollRaster(), ClipBlit() does not scroll the window
layer's damage region.  If the layer already has damage when an
application calls ScrollRaster(), the position of the damage region
will move along with the data in the layer.  Note that prior to
Release 2, ScrollRaster() did not scroll the layer's damage list.

---

## See Also

- [ClipBlit — graphics.library](../autodocs/graphics.library.md#clipblit)
- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
