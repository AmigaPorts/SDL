# 4 / Other Window Functions / Custom Pointers


The active window also has control over the pointer.  If the active window
changes the image for the pointer using the functions [SetPointer()](../Libraries_Manual_guide/node01ED.html#line4) or
[ClearPointer()](../Libraries_Manual_guide/node01ED.html#line38), the pointer image will change:


```c
    void SetPointer( struct Window *window, UWORD *pointer, long height,
                     long width, long xOffset, long yOffset );

    void ClearPointer( struct Window *window );
```
[SetPointer()](../Libraries_Manual_guide/node01ED.html#line4) sets up the window with a sprite definition for a custom
pointer.  If the window is active, the change takes place immediately.
The pointer will not change if an inactive window calls SetPointer().  In
this way, each window may have its own custom pointer that is displayed
only when the window is active.

[ClearPointer()](../Libraries_Manual_guide/node01ED.html#line38) clears the custom pointer from the window and restores it
to the default Intuition pointer, which is set by the user.  Setting a
pointer for a window is discussed further in the chapter
"[Intuition Mouse and Keyboard](../Libraries_Manual_guide/node01ED.html)".

