---
title: Damaging Information
manual: amiga-mail
chapter: amiga-mail
section: damaging-information
functions: []
libraries: []
---

# Damaging Information

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Although many people think of Intuition as the Amiga's windowing
system, the lower-level Layers library actually handles most of the
work involved in maintaining Intuition's windowed environment.  The
Layers library divides a single physical display (a BitMap) into
multiple virtual displays.  Each of these virtual displays is known
as a layer.  Intuition uses the functions in the Layers library to
move, resize, and depth arrange these layers.

Normally, each Intuition window consists of a single layer.
Intuition adds borders and gadgetry to the layer to give it the
familiar Intuition window appearance.  Intuition also takes care of
monitoring user input to let the user move, resize, and depth arrange
windows.  When Intuition wishes to change the size or position of a
window, it calls functions in the Layers library to do most of the
grunt work.

One of the main reasons for a layered rendering system is to provide
multiple independent logical rendering regions to applications.  The
layer is the basis for the Intuition Window.  The functions in the
Layers library allow several applications to render into the same
physical display (an Intuition Screen for example) without worrying
about interfering with each other.  As far as the application is
concerned, it has an entire display all to itself.

There is a limit to the isolation that this layered environment
offers applications.  Because layers can overlap, by moving,
resizing, or deleting a layer, a program can uncover portions of
underlying layers.  These newly exposed portions are called "damage
regions".  A layer can sustain damage when a task performs layers
operations on it or other layers in the same display.  When the
Layers library damages a layer, it sets the layer's LAYERREFRESH bit
in the Flags field of the Layer structure.

When damage occurs to a layer, the damaged region of the layer must
be repaired by redrawing it.  The entity responsible for redrawing
the damaged region depends on the type of layer.  The Layers library
offers three types of layers: simple refresh, smart refresh, and
superbitmap.  Subsequently, Intuition bases its three types of
windows on these three types of layers.  The difference between each
type has to do with the way in which each handles damage repair.

When a layers operation damages a simple refresh layer, the entire
burden of repairing the layer's damage rests on the application that
created the layer (if the application is using Intuition windows,
which are built on top of layers, Intuition shares the burden of
damage repair with the application.  More on this later).  This is
because a simple refresh layer does not preserve its contents.  The
advantage of this type of layer is that it doesn't use much memory.
The disadvantage is that every time a layers operation reveals a
portion of a simple refresh layer, the application must explicitly
rerender the exposed damaged regions.

Smart refresh layers help the application by doing some of the
refreshing automatically.  If a layer operation conceals a portion of
a layer, that portion is automatically copied to an off-screen
buffer.  If a layer operation later reveals that portion of the
layer, the Layers library uses the temporary buffer to update the
revealed region.  The Layers library does not leave the LAYERREFRESH
bit set in this case because the Layers library took care of the
damage.  The application still needs to refresh the smart refresh
layer whenever it is made larger, as the Layers library has no idea
what should be in the newly exposed areas.  In this case, the Layers
library will leave the LAYERREFRESH bit set.

Finally, superbitmap layers totally eliminate the need for an
application to refresh the display.  The Layers library maintains a
complete off-screen buffer representing the layer's contents.  When a
layer operation exposes new portions of a layer, the Layers library
automatically updates these regions by copying from the off-screen
buffer.  The Layers library will never leave the LAYERREFRESH bit set
for a superbitmap layer.

For the application programmer, a superbitmap layer offers the
simplest approach to refreshing the layer as the entire burden of
repairing damaged regions falls on the Layers library.  This added
convenience does have a cost--because of its off-screen buffer, the
superbitmap layer requires a significantly larger amount of memory
compared to the simple and smart refresh layers.  The Layers library
allocates this memory even if the layer never sustains damage.

