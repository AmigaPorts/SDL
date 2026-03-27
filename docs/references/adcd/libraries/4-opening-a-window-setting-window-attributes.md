---
title: 4 / / Opening A Window / Setting Window Attributes
manual: libraries
chapter: libraries
section: 4-opening-a-window-setting-window-attributes
functions: []
libraries: []
---

# 4 / / Opening A Window / Setting Window Attributes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Depending on which function is used to open a window, the window's
attributes may be specified using [TagItem](autodocs-2.0/includes-utility-tagitem-h.md)s, or a [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure or an
[ExtNewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure.  In the [code above](libraries/lib-examples-openwindowtags-c.md), the window attributes are set
up with an array of TagItems:


```c
    struct TagItem win_tags[] =
        {
        {WA_Left,       MY_WIN_LEFT},
        {WA_Top,        MY_WIN_TOP},
        {WA_Width,      MY_WIN_WIDTH},
        {WA_Height,     MY_WIN_HEIGHT},
        {WA_CloseGadget,TRUE},
        {WA_IDCMP,      IDCMP_CLOSEWINDOW},
        {TAG_DONE, NULL},
        };
```
These window attributes set the window's position ([WA_Left, WA_Top](libraries/4-window-attributes-window-attribute-tags.md)) and
size ([WA_Width, WA_Height](libraries/4-window-attributes-window-attribute-tags.md)), request a close gadget on the window
([WA_CloseGadget](libraries/4-window-attributes-boolean-window-attribute-tags.md)) and ask Intuition to send a message whenever the user
activates the close gadget ([WA_IDCMP](libraries/4-window-attributes-window-attribute-tags.md)).

Throughout this chapter window attributes are referred to by their TagItem
ID name (the name is always prefixed with "WA_").  See the section below
on "[Window Attributes](libraries/4-intuition-windows-window-attributes.md)" for a complete list.


```c
    Old and New Flag Names.
    -----------------------
    The names used for IDCMP flags and window flags have been changed
    under Release 2.  IDCMP flag names are now preceded by "IDCMP_".
    Likewise window flag names are now preceded by "WFLG_".  The old
    names (and their new equivalents) are listed in
    <intuition/[iobsolete.h](autodocs-2.0/includes-intuition-iobsolete-h.md)>.  You may want to refer to this file if
    you are working with example code written for V34 and older versions
    of the OS.
```
