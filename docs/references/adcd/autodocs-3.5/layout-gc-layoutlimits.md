---
title: layout_gc/LayoutLimits
manual: autodocs-3.5
chapter: autodocs-3.5
section: layout-gc-layoutlimits
functions: [OpenWindow, WindowLimits]
libraries: [intuition.library]
---

# layout_gc/LayoutLimits

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  NAME

      LayoutLimits -- easy way to find out max and min size of layout
  SYNOPSIS

```c
      LayoutLimits( layout, limits, font, screen );
                    a0      a1      a2    a3

      void LayoutLimits( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct LayoutLimits *,
                              struct [TextFont](autodocs-3.5/include-graphics-text-h.md) *, struct [Screen](autodocs-3.5/include-intuition-screens-h.md) * )
```
  FUNCTION

```c
      This function is an easy way of getting the minimum and maximum
      limit of the layout group. Effectively it create a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) and
      execute the GM_DOMAIN method for both minimum and maximum size
      of the object filling in the LayoutLimits structure with the size
      values. The font passed to this call will most likely affect the
      results, so use the font you will use with the window. If you
      pass a NULL for the font, the system default font (monospaced)
      will be used. If you pass the optional screen pointer, the
      gadget will be provided a [DrawInfo](autodocs-3.5/include-intuition-screens-h.md). This will let the gadget
      adjust to the aspect ratio of the screen.

      If you use the resulting size for [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md) or [WindowLimits()](autodocs-3.5/intuition-library-windowlimits-2.md),
      remember that the results do not include window borders.
```
  INPUTS

```c
      layout = the layout object to get the size on.
      limits = a pointer to the struct LayoutLimits to fill.
      font = the [TextFont](autodocs-3.5/include-graphics-text-h.md) to use on the domain requests. May be NULL
              for system default font.
      screen = optional pointer to the screen on which the layout
              will be used on, or NULL.
```
  NOTES

```c
      This function will invoke the object's GM_DOMAIN method twice,
      with a NULL [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md). If you call it providing a screen
      pointer, the taglist of the message will contain that screen's
      [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) (GA_DrawInfo) for aspect information.
```
  SEE ALSO

      gadgetclass/GM_DOMAIN

---

## See Also

- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [WindowLimits — intuition.library](../autodocs/intuition.library.md#windowlimits)
