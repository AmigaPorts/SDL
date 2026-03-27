---
title: 4 / Other Window Functions / Custom Pointers
manual: libraries
chapter: libraries
section: 4-other-window-functions-custom-pointers
functions: [ClearPointer, SetPointer]
libraries: [intuition.library]
---

# 4 / Other Window Functions / Custom Pointers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The active window also has control over the pointer.  If the active window
changes the image for the pointer using the functions [SetPointer()](libraries/10-the-pointer-custom-pointer.md) or
[ClearPointer()](libraries/10-the-pointer-custom-pointer.md), the pointer image will change:


```c
    void SetPointer( struct Window *window, UWORD *pointer, long height,
                     long width, long xOffset, long yOffset );

    void ClearPointer( struct Window *window );
```
[SetPointer()](libraries/10-the-pointer-custom-pointer.md) sets up the window with a sprite definition for a custom
pointer.  If the window is active, the change takes place immediately.
The pointer will not change if an inactive window calls SetPointer().  In
this way, each window may have its own custom pointer that is displayed
only when the window is active.

[ClearPointer()](libraries/10-the-pointer-custom-pointer.md) clears the custom pointer from the window and restores it
to the default Intuition pointer, which is set by the user.  Setting a
pointer for a window is discussed further in the chapter
"[Intuition Mouse and Keyboard](libraries/10-the-pointer-custom-pointer.md)".

---

## See Also

- [ClearPointer — intuition.library](../autodocs/intuition.library.md#clearpointer)
- [SetPointer — intuition.library](../autodocs/intuition.library.md#setpointer)
