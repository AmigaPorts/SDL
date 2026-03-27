# 3 / Types of Screens / Multiple Screens


All Intuition display objects (such as windows and menus) take graphical
characteristics from the screen.  These objects are restricted to the same
resolution and maximum number of colors as the screen they operate in.
Other characteristics such as the palette, pens and fonts are inherited
from the screen (but may be changed on a case by case basis).

This is not too much of a restriction because the Amiga can maintain
multiple screens in memory at the same time.  In other words, one
application can use a [high resolution](../Libraries_Manual_guide/node00D8.html#line14) screen (with 16 colors) while
another application uses a [low resolution](../Libraries_Manual_guide/node00D8.html#line14) screen (with 32 colors) at the
same time.  Screens typically take up the entire viewing area so only one
is usually visible.  But screens can be moved up and down or rearranged
allowing the user (or application) to [move between screens](../Libraries_Manual_guide/node00DB.html#line10) easily.

