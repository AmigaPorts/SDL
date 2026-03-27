# 9 Intuition Input and Output Methods / Intuition Output


Visual program output, the information written to the display, is sent
through one of three channels.

  * Imagery may be sent to the graphics library primitives.  Graphics

```c
    library includes functions for line drawing, area fill, specialized
    animation and output of text.  See the graphics library chapters
    "[Graphics Primitives](../Libraries_Manual_guide/node0310.html)", "[Graphics Libraries and Text](../Libraries_Manual_guide/node03D2.html)" and
    "[Graphics Sprites, Bobs and Animation](../Libraries_Manual_guide/node036F.html)" for more on these functions.
```
  * Use the Intuition library support functions for rendering text,

```c
    graphical imagery, and line drawing.  These provide some of the same
    functions as the graphics library routines, but the Intuition
    functions perform more of the detail work for you.  See the chapter
    "[Intuition Images, Line Drawing and Text](../Libraries_Manual_guide/node01B5.html)" for more information on
    Intuition rendering functions.  Also see, of course, the chapters on
    [screens](../Libraries_Manual_guide/node00D7.html), [windows](../Libraries_Manual_guide/node00FE.html), [gadgets](../Libraries_Manual_guide/node012F.html), [menus](../Libraries_Manual_guide/node0178.html) and [requesters](../Libraries_Manual_guide/node019F.html) for information on
    managing the display.
```
  * Output character-based data via the console device. The console

```c
    device is discussed in the [next section](../Libraries_Manual_guide/node01D5.html).
```
