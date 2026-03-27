---
title: 9 Intuition Input and Output Methods / Intuition Output
manual: libraries
chapter: libraries
section: 9-intuition-input-and-output-methods-intuition-output
functions: []
libraries: []
---

# 9 Intuition Input and Output Methods / Intuition Output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Visual program output, the information written to the display, is sent
through one of three channels.

  * Imagery may be sent to the graphics library primitives.  Graphics

```c
    library includes functions for line drawing, area fill, specialized
    animation and output of text.  See the graphics library chapters
    "[Graphics Primitives](libraries/27-graphics-primitives.md)", "[Graphics Libraries and Text](libraries/29-graphics-library-and-text.md)" and
    "[Graphics Sprites, Bobs and Animation](libraries/28-graphics-sprites-bobs-and-animation.md)" for more on these functions.
```
  * Use the Intuition library support functions for rendering text,

```c
    graphical imagery, and line drawing.  These provide some of the same
    functions as the graphics library routines, but the Intuition
    functions perform more of the detail work for you.  See the chapter
    "[Intuition Images, Line Drawing and Text](libraries/8-intuition-images-line-drawing-and-text.md)" for more information on
    Intuition rendering functions.  Also see, of course, the chapters on
    [screens](libraries/3-intuition-screens.md), [windows](libraries/4-intuition-windows.md), [gadgets](libraries/5-intuition-gadgets.md), [menus](libraries/6-intuition-menus.md) and [requesters](libraries/7-intuition-requesters-and-alerts.md) for information on
    managing the display.
```
  * Output character-based data via the console device. The console

```c
    device is discussed in the [next section](libraries/9-intuition-input-and-output-methods-console-device-i-o.md).
```
