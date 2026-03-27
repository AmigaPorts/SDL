---
title: 4 / Preserving the Window Display / Optimized Window Refreshing
manual: libraries
chapter: libraries
section: 4-preserving-the-window-display-optimized-window-refreshing
functions: [AutoRequest, BeginRefresh, EndRefresh, OpenWindowTagList, RefreshGadgets, RefreshWindowFrame]
libraries: [intuition.library]
---

# 4 / Preserving the Window Display / Optimized Window Refreshing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bracketing the display updating in the [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md)/[EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) pair
automatically restricts all rendering to the "damaged" areas.


```c
    void BeginRefresh( struct Window *window );
    void EndRefresh  ( struct Window *window, long complete );
```
These functions makes sure that refreshing is done in the most efficient
way, only redrawing those portions of the window that really need to be
redrawn.  The rest of the rendering commands are discarded.

Operations performed between the [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md)/[EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) pair should
be restricted to simple rendering.  All of the rendering functions in
Intuition library and Graphics library are safe.  Calls to
[RefreshGadgets()](libraries/5-intuition-gadgets-function-reference.md) are not permitted.  Avoid calls that may lock the
[LayerInfo](autodocs-2.0/includes-graphics-layers-h.md), or get complicated in Intuition, since BeginRefresh() leaves
the window's layer or layers locked.  Avoid [AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md), and therefore
all direct or indirect disk related DOS calls.  See the
"[Intuition Gadgets](libraries/5-gadget-refreshing-gadget-refreshing-by-intuition.md)" chapter for more information on gadget restrictions
with BeginRefresh()/EndRefresh().

Certain applications do not need to receive refresh events, and can avoid
having to call [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) and [EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) by setting the
WFLG_NOCAREREFRESH flag or the [WA_NoCareRefresh](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag in the
[OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call.

The [EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) function takes a boolean value as an argument (complete
in the prototype above).  This value determines whether refreshing is
completely finished.  When set to FALSE, further refreshing may be
performed between subsequent [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md)/ EndRefresh() pairs.  Set the
boolean to TRUE for the last call to EndRefresh().

It is critical that applications performing multiple
[BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md)/[EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) pairs using EndRefresh(win,FALSE) hold layers
locked through the entire process.  The layer lock may only be released
after the final call to EndRefresh(win,TRUE). See the "[Layers Library](libraries/30-layers-working-with-existing-layers.md)" for
more details.

The procedures outlined in this section take care of refreshing what is
inside the window.  Another function named [RefreshWindowFrame()](autodocs-2.0/intuition-library-refreshwindowframe.md) refreshes
window borders, including the title region and gadgets:


```c
    void RefreshWindowFrame( struct Window *window );
```
Applications can use this function to update window borders after
overwriting them with graphics.

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
- [RefreshWindowFrame — intuition.library](../autodocs/intuition.library.md#refreshwindowframe)
