---
title: When To Refresh
manual: amiga-mail
chapter: amiga-mail
section: when-to-refresh
functions: []
libraries: []
---

# When To Refresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The way in which an application determines that it needs to refresh a
layer depends on whether an application deals with layers directly
via the Layers library, or indirectly via Intuition.  It is important
to keep in mind that each Intuition window has a Layer at its core.
If an application uses Intuition windows it may not use the Layers
library to create, delete, move, resize, or update the window layers.
The application must use the corresponding Intuition functions
instead.

If an application uses layers directly, it must look at a layer's
LAYERREFRESH bit to tell if the layer sustained damage and needs
repair.  Since the application created and maintains its layers, it
knows when damage can occur, so it checks for damage at those times.

Intuition manages an arbitrary number of layers on behalf of any
number of client applications.  All windowing operations happen on
Intuition's time frame.  Since other applications and the user can
ask Intuition to manipulate window layers around at any time, it is
not possible for a window-based application to know by itself when to
refresh its window.  That would involve polling the window layer's
LAYERREFRESH bit, which is a big no-no in a multitasking system.
Instead, Intuition provides a refresh notification mechanism through
the IDCMP system.

Whenever Intuition performs a layer operation that can damage a
window layer, it checks the damage state of each layer in the current
screen by inspecting each layer's LAYERREFRESH bit.  If Intuition
finds that a layer's LAYERREFRESH bit is set, Intuition takes care of
refreshing the damaged areas of the window that are Intuition's
responsibility (for example, the window borders and gadgets).
Following that, Intuition looks at the WFLG_NOCAREREFRESH bit in the
Window structure.  If this bit is set, Intuition's refresh processing
for the window is complete, and all damage region information is
discarded.  However, If the bit is clear, Intuition sends an
IDCMP_REFRESHWINDOW message to the window's IDCMP port, essentially
asking the window to refresh itself.

So, instead of having to poll the LAYERREFRESH bit, an application
can just wait for Intuition to tell it to refresh its window.  This
is convenient and fits in well with the IDCMP mechanism.

