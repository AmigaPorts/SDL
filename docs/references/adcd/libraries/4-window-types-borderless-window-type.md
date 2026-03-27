---
title: 4 / Window Types / Borderless Window Type
manual: libraries
chapter: libraries
section: 4-window-types-borderless-window-type
functions: []
libraries: []
---

# 4 / Window Types / Borderless Window Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The borderless window type has no borders rendered by Intuition.  Such a
window will have no visual delineation from the rest of the display.  Be
aware that a Borderless window which does not cover the entire display may
cause visual confusion for the user.  When using a borderless window that
does not cover the entire display, the application should provide some
form of graphics to replace the borders provided by Intuition.

In general, none of the system gadgets or the window title should be
specified for a borderless window, as they may cause at least part of the
border to be rendered.

A typical application of a borderless window is to simulate graphics drawn
directly into the screen, while remaining compatible with windows and
menus. In this case, the application will often create a full sized,
borderless, backdrop window.

Use the WFLG_BORDERLESS flag or the [WA_Borderless](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag to get this window
type.

