# 2 / How the User Sees Intuition / Intuition's 3D Look


The Amiga operating system comes in different [versions](../Libraries_Manual_guide/node0014.html).  The latest
version, [Release 2](../Libraries_Manual_guide/node0015.html), contains significant improvements in the appearance of
the Intuition graphical user interface, usually referred to as the 3D Look
of Intuition.


```c
     [Figure 2-2: An Example of the 3D Look of Intuition](../Libraries_Manual_guide/node05CB.html) 
```
In the new 3D look of Intuition, objects are drawn so that light appears
to come from the upper left of the display with shadows cast to the lower
right.  Using light and shadow gives the illusion of depth so that images
appear to stand out or recede from the display.  By convention, an image
with a raised appearance indicates an object that is available for use or
modifiable.  An image with a recessed appearance indicates an object that
is unmodifiable, or for display purposes only. Applications should follow
the same conventions.

[Release 2](../Libraries_Manual_guide/node0015.html) has other improvements over 1.3 (V34) and earlier [versions](../Libraries_Manual_guide/node0014.html) of
the operating system.  Among these are [new display resolutions](../Libraries_Manual_guide/node0318.html), display
sizes, and [new function libraries](../Libraries_Manual_guide/node000D.html#line42) to support Intuition.  Most of the
[examples](../Libraries_Manual_guide/node0019.html) listed in this book assume Release 2.  Where appropriate, the old
1.3 methods are also described.

