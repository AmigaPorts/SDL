---
title: 4 / Other Window Functions / Changing the Window or Screen Title
manual: libraries
chapter: libraries
section: 4-other-window-functions-changing-the-window-or-screen-title
functions: []
libraries: []
---

# 4 / Other Window Functions / Changing the Window or Screen Title

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each window has its own window title and local screen title.  The window
title, if specified, is always displayed in the window.  The local screen
title, if specified, is only displayed in the screen's title bar when the
window is active.  If the window does not specify a local screen title,
then the default screen title is used in the screen title bar when this
window is active.


```c
    void SetWindowTitles( struct Window *window, UBYTE *windowTitle,
                          UBYTE *screenTitle );
```
This function changes the window title or local screen title for the given
window.  Both windowTitle and screenTitle can be set to -1, NULL or a NULL
terminated string.  Specifying -1 will not change the title from the
current value.  Specifying NULL will clear the window title or reset the
screen title to the default title for the screen.

