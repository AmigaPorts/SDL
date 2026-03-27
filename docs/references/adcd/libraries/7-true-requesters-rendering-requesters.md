---
title: 7 / True Requesters / Rendering Requesters
manual: libraries
chapter: libraries
section: 7-true-requesters-rendering-requesters
functions: [LockLayerInfo]
libraries: [layers.library]
---

# 7 / True Requesters / Rendering Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The application may choose to use Intuition's rendering facilities to
display the requester, or it may define its own custom bitmap.  The
[Requester](libraries/7-intuition-requesters-and-alerts-requester-structure.md) structure is initialized differently according to the rendering
method chosen.

To use Intuition's rendering facilities, you supply a list of one or more
display objects with the [Requester](libraries/7-intuition-requesters-and-alerts-requester-structure.md) structure and submit the Requester  to
Intuition, allowing it to draw the objects.  These objects can include
independent lists of [Border](libraries/8-creating-borders-border-structure-definition.md)s, [IntuiText](libraries/8-creating-text-intuitext-structure.md), [Image](libraries/8-creating-images-image-structure.md)s and [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)s.  Note that
the abilty to provide a list of Image structures is new in V36, and the
[USEREQIMAGE](libraries/7-intuition-requesters-and-alerts-requester-structure.md) flag must be set for them to be rendered.  For more about
Intuition rendering see the chapter on
"[Intuition Images, Line Drawing and Text](libraries/8-intuition-images-line-drawing-and-text.md)".

The gadgets in a requester also have their own borders, images and text to
add to the display imagery.  Intuition will allocate the buffers,
construct a bitmap that lasts for the duration of the display, and render
the requester into the window.  This rendering is all done over a solid
color, filled background specified by the [BackFill](libraries/7-intuition-requesters-and-alerts-requester-structure.md) pen in the [Requester](libraries/7-intuition-requesters-and-alerts-requester-structure.md)
structure.  The backfill may be disabled by setting the [NOREQBACKFILL](libraries/7-intuition-requesters-and-alerts-requester-structure.md) flag
(this also a new feature of V36).

On the other hand, a custom requester may be designed with pre-defined,
bitmap imagery for the entire object.  The image bitmap is submitted to
Intuition through the [ImageBMap](libraries/7-intuition-requesters-and-alerts-requester-structure.md) field of the [Requester](libraries/7-intuition-requesters-and-alerts-requester-structure.md) structure.  The
bitmap should be designed to reduce user confusion; gadgets should line up
with their images, and the designer should attempt to use glyphs (symbols)
familiar to the user.

To provide imagery for the requester, applications should always try to
use data structures attached to the [Requester](libraries/7-intuition-requesters-and-alerts-requester-structure.md) structure as described
above.  Although, rendering directly into the requester layer's [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)
is tolerated, it must be done with great care.

First, a requester is allowed to have gadgets that automatically close the
requester when they are selected ([GACT_ENDGADGET](libraries/5-gadget-structure-gadget-activation-flags.md)).  If such a gadget is
selected, the requester, its layer, and its layer's [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) will be
deleted asynchronously to your application.  If your application is trying
to render directly into the requester at that time, the results are
unpredictable.  Therefore, do not put GACT_ENDGADGET gadgets into a
requester if you plan on rendering directly into its RastPort.

Second, recall that requesters are clipped to the inside of the window
(not including the borders).  If the window can be sized smaller such that
the requester would be entirely clipped, the requester's layer may be
deleted by Intuition.  If your window's minimum size and the requester
size and position are such that the requester can be completely clipped,
then reading [Requester.ReqLayer](libraries/7-intuition-requesters-and-alerts-requester-structure.md) is unsafe without additional protection.
It would be correct to [LockLayerInfo()](libraries/30-layers-working-with-existing-layers.md) the screen's [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md), then check
for the existence of the requester's ReqLayer, then render, then unlock.

For reasons such as these, direct rendering is discouraged.

---

## See Also

- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
