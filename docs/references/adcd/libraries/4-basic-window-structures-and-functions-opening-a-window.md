---
title: 4 / Basic Window Structures and Functions / Opening a Window
manual: libraries
chapter: libraries
section: 4-basic-window-structures-and-functions-opening-a-window
functions: [OpenWindow, OpenWindowTagList]
libraries: [intuition.library]
---

# 4 / Basic Window Structures and Functions / Opening a Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A window is opened and displayed by a call to one of the OpenWindow()
functions:  [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md), [OpenWindowTagList()](autodocs-2.0/intuition-library-openwindowtaglist.md) or [OpenWindowTags()](autodocs-2.0/intuition-library-openwindowtaglist.md).


```c
    struct Window *OpenWindowTagList( struct NewWindow *newWindow,
                                     struct TagItem *tagList );
    struct Window *OpenWindowTags( struct NewWindow *newWindow,
                                  unsigned long tag1Type, ... );
    struct Window *OpenWindow( struct NewWindow *newWindow );
```
The type of window and its attributes are specified in [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) or
[TagItem](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structures depending on which function is used.  These functions
all return a pointer to a new [Window](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure if they succeed.  A NULL
return indicates failure.

[OpenWindowTagList()](autodocs-2.0/intuition-library-openwindowtaglist.md) and [OpenWindowTags()](autodocs-2.0/intuition-library-openwindowtaglist.md) are available only in Release 2
(V36) and later versions of the OS.  For these functions, window
attributes are specified in [TagItem](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structures which are paired data items
specifying an attribute and its setting.  (See the `[Utility Library](libraries/37-utility-library-tags.md)'
chapter for more information on TagItems.)

[OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) is available in all versions of the OS.  Window attributes
can be specified using a [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure but only a limited set of
window attributes are available this way.  To support both the new window
features of Release 2 and compatibility with older versions of the OS, use
OpenWindow() with an extended version of the [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure named
[ExtNewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).  See the [WFLG_NW_EXTENDED](libraries/4-window-attributes-extended-new-window.md) flag description in the "Window
Attributes" section below for more information on using OpenWindow() with
the extended NewWindow structure.

Further references to OpenWindow() in this chapter will apply to all three
functions.  These calls are the only proper method for allocating a [Window](libraries/4-intuition-windows-basic-window-structures-and-functions.md)
structure.  The tag based versions are recommended for V36 and later
versions of the OS.  Use the [ExtNewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure with OpenWindow() to
provide backward compatibility.

 [OpenWindowTagList() Example](libraries/lib-examples-openwindowtags-c.md)    [Setting Window Attributes](libraries/4-opening-a-window-setting-window-attributes.md) 

---

## See Also

- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
