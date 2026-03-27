---
title: reaction.lib/OpenLayoutWindowTagList
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-openlayoutwindowtaglist
functions: [RefreshGadgets]
libraries: [intuition.library]
---

# reaction.lib/OpenLayoutWindowTagList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       OpenLayoutWindowTagList -- [Open](autodocs-3.5/dos-library-open-2.md) a window at a suitable size for layout
       OpenLayoutWindowTags -- Varags stub for OpenLayoutWindowTagList
```
   SYNOPSIS

```c
       window = OpenLayoutWindowTagList( layout, screen, taglist )

       struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *OpenLayoutWindowTagList( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *,
               struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, struct TagList * )

       window = OpenLayoutWindowTags( layout, screen, tag, ... )

       struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *OpenLayoutWindowTags( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *,
               struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ... )
```
   FUNCTION

```c
       Determines the minimum size that will fit a layout and opens the window
       at that size. The sizing limits of the window will be set according to
       the layout's limits, and the layout will be added to the window,
       making it relative to window size. The layout will fit the whole inner
       size of the window. It will not be rendered, so you must call
       [RefreshGadgets()](autodocs-3.5/intuition-library-refreshgadgets-2.md), possibly after adding your border gadgets.

       This function will set InnerWidth, InnerHeight, and the screen for the
       window. Other tags you have to pass yourself.
```
   INPUTS

       layout -- the layout hierarcy for the window
       screen -- pointer to the screen the window will be opened on
       taglist -- the additional tags for the window.
   RESULTS

       A pointer to the opened window or NULL if the open failed.

---

## See Also

- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
