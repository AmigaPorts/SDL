---
title: 5 / Gadget Refreshing / Gadget Refreshing by Intuition
manual: libraries
chapter: libraries
section: 5-gadget-refreshing-gadget-refreshing-by-intuition
functions: [BeginRefresh, BeginUpdate, EndRefresh, EndUpdate, RefreshGList, RefreshGadgets]
libraries: [intuition.library, layers.library]
---

# 5 / Gadget Refreshing / Gadget Refreshing by Intuition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition will refresh a gadget whenever an operation has damaged the
layer of the window or requester to which it is attached.  Because of
this, the typical application does not need to call [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md) as a
part of its [IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) event handling.

Intuition's refreshing of the gadgets of a damaged layer is done through
the layer's damage list.  This means that rendering is clipped or limited
to the layer's damage region--that part of the window or requester that
needs refreshing.

Intuition directly calls the [Layers library](libraries/30-layers-library-layers.md) functions [BeginUpdate()](libraries/30-layers-creating-and-using-new-layers.md) and
[EndUpdate()](libraries/30-layers-creating-and-using-new-layers.md), so that rendering is restricted to the proper area.
Applications should not directly call these functions under Intuition,
instead, use the [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) and [EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) calls.  Calls to
[RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md) or [RefreshGadgets()](libraries/5-intuition-gadgets-function-reference.md) between BeginRefresh() and EndRefresh()
are not permitted.  Never add or remove gadgets between the BeginRefresh()
and EndRefresh() calls.

For more information on [BeginRefresh()](autodocs-2.0/intuition-library-beginrefresh.md) and [EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md), see the
"[Intuition Windows](libraries/4-preserving-the-window-display-optimized-window-refreshing.md)" chapter and the Amiga ROM Kernel Reference Manual:
Includes and Autodocs.

Gadgets which are positioned using [GFLG_RELBOTTOM](libraries/5-gadget-structure-gadget-flags.md) or [GFLG_RELRIGHT](libraries/5-gadget-structure-gadget-flags.md), or
sized using [GFLG_RELWIDTH](libraries/5-gadget-structure-gadget-flags.md) or [GFLG_RELHEIGHT](libraries/5-gadget-structure-gadget-flags.md) pose a problem for this
scheme.  When the window is sized, the images for these gadgets must
change, even though they are not necessarily in the damage region.
Therefore, Intuition must add the original and new visual regions for such
relative gadgets to the damage region before refreshing the gadgets.  The
result of this is that applications should ensure that any gadgets with
relative position or size do not have [Border](libraries/8-creating-borders-border-structure-definition.md), [Image](libraries/8-creating-images-image-structure.md) or [IntuiText](libraries/8-creating-text-intuitext-structure.md) imagery
that extends beyond their select boxes.

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [BeginUpdate — layers.library](../autodocs/layers.library.md#beginupdate)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [EndUpdate — layers.library](../autodocs/layers.library.md#endupdate)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
