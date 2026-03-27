---
title: 4 Intuition Windows / Preserving the Window Display
manual: libraries
chapter: libraries
section: 4-intuition-windows-preserving-the-window-display
functions: []
libraries: []
---

# 4 Intuition Windows / Preserving the Window Display

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The layers library is what allows the display and manipulation of multiple
overlapping rectangles, or layers.  Intuition uses the layers library to
manage its windows, by associating a layer to each window.

Each window is a virtual display.  When rendering, the application does
not have to worry about the current size or position of its window, and
what other windows might be partly or fully obscuring its window.  The
window's [RastPort](libraries/4-intuition-windows-basic-window-structures-and-functions.md) is the handle to the its virtual display space.
Intuition and graphics library rendering calls will recognize that this
RastPort belongs to a layer, and act accordingly.

As windows are moved, resized, rearranged, opened, or closed, the
on-screen representation changes.  When part of a window which was visible
now needs to appear in a new location, the layers library will move that
imagery without involving the application.  However, when part of a window
that was previously obscured is revealed, or when a window is made larger,
the imagery for the newly-visible part of the window needs to be redrawn.
Intuition, through layers, offers three choices for how this is managed,
trading off speed, memory usage, and application complexity.

  * The most basic type of window is called Simple Refresh.  When any

    graphics operation takes place in this kind of window, the visible
    parts are updated, but rendering to the obscured parts is discarded.
    When the window arrangement changes to reveal a previously obscured
    part of such a window, the application must refresh that area.
  * Alternately, a window may be made Smart Refresh, which means that

```c
    when rendering occurs, the system will not only update the visible
    parts of the window, but it will maintain the obscured parts as well,
    by using off-screen buffers.  This means that when an obscured part
    of the window is revealed, the system will restore the imagery that
    belongs there.  The application needs only to refresh parts of the
    window that appear when the window is made bigger.  Smart Refresh
    windows use more memory than Simple Refresh windows (for the storage
    of obscured areas), but they are faster.
```
  * The third kind of window is called SuperBitMap.  In such a window,

    the system can refresh the window even when it is sized bigger.  For
    this to work, the application must store a complete bitmap for the
    window's maximum size.  Such a window is more work to manage, and
    uses yet more memory.  SuperBitMap windows are used less often than
    the other two types.
Intuition helps your application manage window refresh.  First, Intuition
will take care of redrawing the window border and any system and
application gadgets in the window.  Your application never has to worry
about that.  Second, Intuition will notify your application when it needs
to refresh its window (by sending the [IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) event).  Third,
Intuition provides functions that restrict your rendering to the
newly-revealed (damaged) areas only, which speeds up your refresh
rendering and makes it look cleaner.

The Intuition, layers, and graphics libraries work together to make
rendering into and managing windows easy.  You obtain your windows through
Intuition, which uses the [Layers library](libraries/30-layers-library-layers.md) to manage the overlapping,
resizing, and re-positioning of the window layers.  The layers library is
responsible for identifying the areas of each window that are visible,
obscured but preserved off-screen, or obscured and not preserved.  The
rendering functions in the graphics library and Intuition library know how
to render into the multiple areas that layers library establishes.

 Note that you may not directly manipulate layers on an Intuition screen.
You cannot create your own layers on an Intuition screen, nor can you use
the layers movement, sizing, or arrangement functions on Intuition
windows.  Use the corresponding Intuition calls instead. Some other
[Layers library](libraries/30-layers-library-layers.md) calls (such as the [locking calls](libraries/30-layers-working-with-existing-layers.md)) are sometimes used on
Intuition screens and windows.

 [Damage Regions](libraries/4-preserving-the-window-display-damage-regions.md)                  [Optimized Window Refreshing](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) 
 [Refreshing Intuition Windows](libraries/4-preserving-the-window-display-refreshing-intuition-windows.md)    [Setting Up a SuperBitMap Window](libraries/4-preserving-the-window-display-setting-up-a-superbitmap.md) 
 [Intuition Refresh Events](libraries/4-preserving-the-window-display-intuition-refresh-events.md) 

