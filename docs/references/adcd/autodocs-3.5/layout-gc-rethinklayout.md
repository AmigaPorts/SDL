---
title: layout_gc/RethinkLayout
manual: autodocs-3.5
chapter: autodocs-3.5
section: layout-gc-rethinklayout
functions: [RefreshGList, SetGadgetAttrsA]
libraries: [intuition.library]
---

# layout_gc/RethinkLayout

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  NAME

```c
      RethinkLayout -- Relayout and render the layout. (V39)
```
  SYNOPSIS

```c
      RethinkLayout( layout, window, requester, refresh );
                      a0        a1        a2

      void RethinkLayout( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
                              struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, [BOOL](autodocs-3.5/include-exec-types-h.md) )
```
  FUNCTION

```c
      Relayout and refresh the layout page. Call this function after
      a call SetGadgetAttrs() returns 1 to display the changes in the
      layout.  According to BOOPSI rules, a gadget will return a value
      of 1 from OM_SET to tell the application to refresh. This is what
      this function is for. Basically, it will call the GM_LAYOUT and
      GM_RENDER methods of the layout.
```
  INPUTS

```c
      layout = the layout to refresh. Doesn't have to be the topmost
                  object in the hierarchy, if the changes do not affect
                  it.
      window = the window to which the layout (or its parent) is
                  attached to.
      requester = the window's requester, or NULL.
      refresh = whether layout.gadget should also refresh the display.
```
  NOTES

```c
      This function emulates a DoGadgetMethod() on V37 and V38 systems.

      The refresh flag is provided for several reasons. First, when using
      LAYOUT_DeferLayout, you should not refresh upon receiving a
      LAYOUT_RequestLayout notification. Second, datatypes have an
      asynchronous layout, and should not be attempted to refresh before
      that is finished. [Wait](autodocs-3.5/exec-library-wait-2.md) for DTA_Sync, and then RefreshGList( layout,
      window, requester, 1 ).
```
  SEE ALSO

```c
      [intuition.library/RefreshGList()](autodocs-3.5/intuition-library-refreshglist-2.md), [intuition.library/SetGadgetAttrsA()](autodocs-3.5/intuition-library-setgadgetattrsa-2.md),
      intuition.library/DoGadgetMethod()
```

---

## See Also

- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [SetGadgetAttrsA — intuition.library](../autodocs/intuition.library.md#setgadgetattrsa)
