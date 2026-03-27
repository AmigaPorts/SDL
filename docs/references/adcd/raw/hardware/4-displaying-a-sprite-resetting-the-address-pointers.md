# 4 / Displaying a Sprite / Resetting the Address Pointers


For one single display field, the system will automatically read the
 [data structure](../Hardware_Manual_guide/node00B9.html)  and produce the sprite on-screen in the colors that are
specified in the sprite's  [color registers](../Hardware_Manual_guide/node00D0.html) . If you want the sprite to be
displayed in subsequent display fields, you must rewrite the contents of
the sprite pointers during each  [vertical blanking](../Hardware_Manual_guide/node0169.html)  interval. This is
necessary because during the display field, the pointers are incremented
to point to the data which is being fetched as the screen display
progresses.

The rewrite becomes part of the  [vertical blanking](../Hardware_Manual_guide/node0169.html)  routine, which can be
handled by instructions in the Copper lists.

