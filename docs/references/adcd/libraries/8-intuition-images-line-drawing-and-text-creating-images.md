---
title: 8 Intuition Images, Line Drawing and Text / Creating Images
manual: libraries
chapter: libraries
section: 8-intuition-images-line-drawing-and-text-creating-images
functions: [DrawImage, DrawImageState, EraseImage, EraseRect]
libraries: [graphics.library, intuition.library]
---

# 8 Intuition Images, Line Drawing and Text / Creating Images

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

With an [Image](libraries/8-creating-images-image-structure.md) structure an application can create graphic objects quickly
and easily and display them almost anywhere.  Images have an additional
attribute that makes them even more economical--by changing two simple
data elements in the Image structure, the color of the image may be
changed.

Images are rectangular bitmaps which individually define the color of each
pixel represented.  Images may not be masked to allow part of the
background to show through.  The entire rectangular image is drawn into
the target element, overwriting any data it may overlap.  All bitplanes
defined in the target [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) within the image's rectangle are
overwritten either with image data, ones or zeros.

[Image](libraries/8-creating-images-image-structure.md)s may be directly drawn by the application by using the [DrawImage()](libraries/8-creating-images-directly-drawing-the-image.md)
function, described below.  The image may be rendered into any screen or
window [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) with this function.  ([DrawImageState()](autodocs-2.0/intuition-library-drawimagestate.md) can also be used to
draw the image.

The visual imagery for an [Image](libraries/8-creating-images-image-structure.md) can be removed from the display by calling
[EraseImage()](autodocs-2.0/intuition-library-eraseimage.md).  For a normal Image structure, this will call the graphics
function [EraseRect()](autodocs-2.0/graphics-library-eraserect.md), which clears the Image rectangle by using the
layer's backfill pen to overwrite it.

Alternately, images can be used indirectly by attaching them to menus,
gadgets or requesters when they are initialized.  For instance, in menus
the [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structure has the [ItemFill](libraries/6-menu-data-structures-menuitem-structure.md) and [SelectFill](libraries/6-menu-data-structures-menuitem-structure.md) fields.  If the
[ITEMTEXT](libraries/6-menu-data-structures-menuitem-flags.md) flag is cleared and the [HIGHIMAGE](libraries/6-menu-data-structures-menuitem-flags.md) flag is set, the application
may place a pointer to a list of [Image](libraries/8-creating-images-image-structure.md) structures in each of these fields.
The system will display the ItemFill images when the menu item is not
selected and the SelectFill images when the menu item is selected.  The
application does not have to take any specific action to display these
images.  Once the menus have been added to a window, their management and
display is under Intuition control.

The number of bitplanes in an image does not have to match the number of
bitplanes in the display element in which the image is rendered.  This
provides great flexibility in using [Image](libraries/8-creating-images-image-structure.md) structures, as the same image
may be reused in many places.

If the application's window is on the Workbench or some other public
screen, it must use caution with hard-coded or constant image data, as the
color palette of that screen is subject to change.  If the application has
its own custom screen, and it is appropriate for the colors of that screen
to change, the same situation arises.  Starting with V36, Intuition allows
the screen opener to provide a mapping of pen number and rendering
functions.  For example, pens are specified for the bright and dark edges
of three dimensional objects.  Applications can obtain this mapping from
the [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structure.  See the "[Intuition Screens](libraries/3-intuition-screens-drawinfo-and-the-3d-look.md)" chapter for more
information on DrawInfo and the new 3D look of Intuition in Release 2.

A suitably designed image may be drawn into a screen or window of any
depth.  To accomplish this, the application must ensure that detail is not
lost when the image is displayed in a single bitplane [RastPort](libraries/27-drawing-routines-the-rastport-structure.md), where only
the first bitplane of image data will be displayed.  This is important if
the image will ever be displayed on the Workbench screen or any other
public screen.

 [Image Structure](libraries/8-creating-images-image-structure.md)               [Picking Bitplanes for Image Display](libraries/8-creating-images-picking-bitplanes-for-image-display.md) 
 [Directly Drawing the Image](libraries/8-creating-images-directly-drawing-the-image.md)    [Image Example](libraries/8-creating-images-image-example.md) 
 [Image Data](libraries/8-creating-images-image-data.md) 

---

## See Also

- [DrawImage — intuition.library](../autodocs/intuition.library.md#drawimage)
- [DrawImageState — intuition.library](../autodocs/intuition.library.md#drawimagestate)
- [EraseImage — intuition.library](../autodocs/intuition.library.md#eraseimage)
- [EraseRect — graphics.library](../autodocs/graphics.library.md#eraserect)
