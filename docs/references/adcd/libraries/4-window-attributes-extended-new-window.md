---
title: 4 / Window Attributes / Extended New Window
manual: libraries
chapter: libraries
section: 4-window-attributes-extended-new-window
functions: [OpenWindow]
libraries: [intuition.library]
---

# 4 / Window Attributes / Extended New Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Of the three functions for opening a window, only [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) is present
in all versions of the OS.  This function takes a [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure as
its sole argument.  In order to allow applications to use the OpenWindow()
call with Release 2 [TagItem](libraries/4-intuition-windows-basic-window-structures-and-functions.md) attributes, an extended version of the
NewWindow structure has been created named [ExtNewWindow](autodocs-2.0/includes-intuition-intuition-h.md).

Setting WFLG_NW_EXTENDED in the NewWindow.Flags field specifies to the
[OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call that this [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure is really an [ExtNewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md)
structure.  This is simply a standard NewWindow structure with a pointer
to a tag list at the end.  Since WFLG_NW_EXTENDED is ignored prior to V36,
information provided in the tag list will be ignored by earlier versions
of Intuition.  Note that WFLG_NW_EXTENDED may not be specified in the
[WA_Flags](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag.

---

## See Also

- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
